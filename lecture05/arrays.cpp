#include <iostream>
#include <array>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
  // C-style array definition. "arr" is a pointer to the first element. Best
  // used when you need a temporary, local list of things that you know the size
  // of ahead of time.
  int arr[10];
  for (int i=0;i < 10;++i) {
    // This will print out junk because it's uninitialized memory! Maybe you'll
    // get lucky and you'll have some 0s. It's a dice roll
    std::cout << arr[i] << std::endl;
  }
  // Range-based. I wasn't sure if this worked in class. It does!
  for (auto a : arr) {
    std::cout << a << " ";
  }
  std::cout << std::endl;
  // If you provide the values, you don't have the specify the size. Goes
  // against best practices - be explicit!
  int arr2[] = { 1, 2, 3 };

  // C++ style array definition
  std::array<int, 10> arr3;
  // Access elements is the same
  std::cout << arr3[5] << std::endl;
  arr3[0] = 50;
  // You can still get the C-style array underneath
  int* arr4 = arr3.data();
  // Because it's an object, instead of a primitive, it has some helper
  // functions
  arr3.fill(1);
  std::cout << "arr3 has " << arr3.size() << " elements" << std::endl;

  // Vectors
  // This one is empty, but not uninitialized! std::vector is a class, so this
  // is an object that has a "constructor" (similar to __init__ in python) that
  // will initialize the object attributes to something reasonable
  std::vector<int> vec;
  // vec.size() == 0
  // We can specify the number of elements
  std::vector<int> vec2(10);
  std::cout << vec2[5] << std::endl;
  // The elements in vec2 will be initialized to 0, but if that's our intent,
  // we should be explicit by providing an initial value:
  std::vector<int> vec3(10, 0);
  // Just specify the contents and deduce the size
  std::vector<int> vec4 {1, 2, 3, 4};
  // std::vector<Typename>, it's templated, so we can put anything in it
  std::vector<std::string> vec_strings(5, "Initial string value");
  for (auto s : vec_strings) {
    std::cout << s << ",";
  }
  std::cout << std::endl;

  // We use std::size_t instead of int because that's what size() returns, and
  // we want the types to match
  for (std::size_t i=0;i < arr3.size();++i) {
    std::cout << arr3[i] << std::endl;
  }
  // This works on vectors too. Any std:: collection that has .begin() and .end()
  // defined
  for (auto v : vec2) {
  // auto will figure out that vec2 is filled with ints
  //for (int v : vec2) {
    std::cout << v << std::endl;
  }

  // The reasons will be explained when we go over pointers, but note that you
  // need the & if you want to modify the value!
  for (auto v : vec2) {
    v = 5000;
  }
  for (auto v : vec2) {
    // Uh oh - it prints 0 still! v = 5000 didn't assign to the actual elements
    // in vec2, it assigned to copies of them. We need to specify & to get the
    // actual elements
    std::cout << v << ", ";
    // To be totally clear: when you access using vec2[i] like with arr3 above,
    // that isn't a copy - it's the actual element. It's just with this range-
    // based loop, because you're creating a new variable "v" that is only in
    // the for() loop scope and is taking on the value of the elements
  }
  std::cout << std::endl;
  for (auto& v : vec2) {
  // Same as:
  //for (int& v : vec2) {
    v = 5555;
  }
  for (auto v : vec2) {
    // Ahh, that's better
    std::cout << v << ", ";
  }
  std::cout << std::endl;

  // There's an additional "safe" access method for vectors: .at()
  // It will throw an exception, rather than just segfaulting
  // Not available for std::array
  std::cout << "vec2.at(2): " << vec2.at(2) << std::endl;
  // Kaboom! Possible segfault for accessing out-of-bounds element
  //std::cout << "vec2[100]: " << vec2[100] << std::endl;
  // Kaboom! Thrown exception for out-of-bounds access:
  // vector::_M_range_check: __n (which is 100) >= this->size() (which is 10)
  // You could "catch" this exception and handle it, returning useful feedback
  // to the user
  //std::cout << "vec2.at(100): " << vec2.at(100) << std::endl;

  // 2D arrays/vectors? Just an array of arrays / vector of vectors
  // Each element of the outer vector is a vector, and each element of the
  // inner vector is a float
  std::vector<std::vector<float>> vec_2d(5, std::vector<float>(5));
  // Use the "typedef" keyword to make life easier!
  typedef std::vector<std::vector<float>> vector2d;
  // It's just an alias
  vector2d vec_2d_2(10, std::vector<float>(10));

  // Element access
  std::cout << "vec_2d[2][2]: " << vec_2d[2][2] << std::endl;
  std::cout << "vec_2d.at(2).at(2): " << vec_2d.at(2).at(2) << std::endl;
  // Outer vector
  std::cout << "vec_2d.size(): " << vec_2d.size() << std::endl;
  // Inner vector (1 row or 1 column depending on your preference)
  std::cout << "vec_2d[0].size(): " << vec_2d[0].size() << std::endl;
  // How do we loop over 2D containers?
  // Range-based
  for (auto vi : vec_2d) {
    for (auto vj : vi) {
      std::cout << vj << " ";
    }
  }
  std::cout << std::endl;
  // Using indices
  for (std::size_t i=0;i < vec_2d.size();++i) {
    for (std::size_t j=0;j < vec_2d[i].size();++j) {
      std::cout << vec_2d[i][j] << " ";
    }
  }
  std::cout << std::endl;
  return 0;
}
