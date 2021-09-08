#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
  // Uninitialized local variable
  int a;
  // Uninitialized pointer
  int* b;
  // Proper zero-initialization
  int* c = nullptr;
  // Both may be filled with junk (uninitialized -> dealer's choice)
  std::cout << "a (value): " << a << std::endl;
  std::cout << "b (pointer): " << b << std::endl;
  // So we definitely don't want to dereference b!
  // Kabooooom (possible segfault)
  //std::cout << "b (value): " << (*b) << std::endl;
  // We can assign the pointer to the address of another variable
  b = &a;
  std::cout << "b (pointer): " << b << std::endl;
  std::cout << "*b (value): " << *b << std::endl;
  // We can also have a reference type. We will almost never use this form
  // explicitly
  int& d = a;
  std::cout << "d (value): " << d << std::endl;

  // We can't just assign it arbitrary numeric values
  // What is the *type* of "1"?
  //b = 1;
  // Allocating a single variable of type "int"
  // The memory for "b" is NOW YOUR RESPONSIBILITY! You must have a
  // corresponding "delete" statement somewhere or this is a memory leak!
  b = new int;
  std::cout << "b (pointer): " << b << std::endl;
  // On my system: 4 bytes
  std::cout << "Sizeof a: " << sizeof(a) << std::endl;
  // On my system: 8 bytes (64 bits for pointers (addresses)!)
  std::cout << "Sizeof b: " << sizeof(b) << std::endl;
  // On my system: 4 bytes
  std::cout << "Sizeof *b: " << sizeof(*b) << std::endl;
  delete b;
  // Don't you dare! Kaboom!
  //delete b;
  // Danger zone!!! b was deleted!!! Possible segfault
  std::cout << "b (pointer): " << b << std::endl;
  std::cout << "*b (value): " << *b << std::endl;

  // Allocating an array
  b = new int[100];
  // We can use the other syntax we saw before to make it all 0s
  //b = new int[100]();
  //b = new int[100]{};
  //b = new int[argc]();
  // Access the 51st element
  b[50] = 100;
  std::cout << "Sizeof b: " << sizeof(b) << std::endl;
  // Notice how [50] is dereferencing the pointer for us
  std::cout << "b[50]: " << b[50] << std::endl;
  // When we dereference b, the value is the value of the first element (=b[0])
  // In other words, b is a pointer to the first element of the array
  std::cout << "*b: " << *b << std::endl;
  // "Pointer arithmetic": the 100 int values are packed together in memory,
  // so incrementing the pointer increments by 1 int address. We use the ()
  // so it adds first, then we dereference that address, obtaining the value
  // of that element
  std::cout << "*b+50: " << *(b+50) << std::endl;
  // Here we actually make an assignment, so now we've moved b to point to the
  // 51st element of the array, instead of the first
  // Note: this is now danger zone! This pointer, when used as an C-array, will
  // not behave as expected
  b += 50;
  std::cout << "*b+50: " << *b << std::endl;
  // Oops! Out-of-bounds access! b is pointing to the 51st element
  std::cout << "*b+1050: " << *(b+1000) << std::endl;
  b -= 50;
  // Notice the [] for deleting an array
  delete[] b;

  // Either syntax works, they're the same. The first is more common
  //std::string my_stack_str("Hello, stack string!");
  auto my_stack_str = std::string("Hello, stack string!");
  // We can allocate anything! std::string is just an object (a class)
  auto my_heap_str = new std::string("Hello, heap string!");
  // Valid syntax but not what we want!
  std::cout << "my_heap_str: " << my_heap_str << std::endl;
  // We need to dereference to get the value
  std::cout << "*my_heap_str: " << *my_heap_str << std::endl;
  std::cout << "my_stack_str: " << my_stack_str << std::endl;
  // Remember, pointer access is different; requires a dereference
  std::cout << "my_stack_str.size(): " << my_stack_str.size() << std::endl;
  std::cout << "my_heap_str->size(): " << my_heap_str->size() << std::endl;
  std::cout << "(*my_heap_str).size(): " << (*my_heap_str).size() << std::endl;
  delete my_heap_str;
  return 0;
}
