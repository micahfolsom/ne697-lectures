#include <iostream>
#include <vector>

void do_heavy_lifting(int* my_data, int data_size) {
  std::cout << "It's a heavy lift! " << data_size << " elements" << std::endl;
  for (int i=0;i < data_size;++i) {
    if ((i % 10000) == 0) {
      std::cout << "DHL(): my_data[" << i << "]: " << my_data[i] << std::endl;
    }
  }
  return;
}

int main(int argc, char* argv[]) {
  // Let's make a "big" array (400 KB)
  int const SIZE = 100000;
  // Same as above
  // const int SIZE = 100000;
  int* my_data = new int[SIZE];
  // Same as above
  //int *my_data = new int[SIZE];
  //auto my_data = new int[SIZE];
  for (int i=0;i < SIZE;++i) {
    my_data[i] = i;
  }
  do_heavy_lifting(my_data, SIZE);
  // Array syntax (follow the [])
  delete[] my_data;

  // There's a limit to the stack
  // 1 billion * 4 bytes each = 4 GB
  int const REALLY_BIG = 1000000000;
  // Kaboom! Stack is only 8 MB
  //int my_big_data[REALLY_BIG] {};
  // We can put it on the heap, though!
  auto my_big_data_heap = new int[REALLY_BIG];
  std::cout << "sizeof(my_big_data_heap): " << sizeof(my_big_data_heap)
    << std::endl;
  std::cout << "sizeof(*my_big_data_heap): " << sizeof(*my_big_data_heap)
    << std::endl;
  std::cout << "sizeof(*my_big_data_heap) * REALLY_BIG: "
    << sizeof(*my_big_data_heap) * REALLY_BIG << " bytes" << std::endl;
  std::cout << "my_big_data_heap[1000]: " << my_big_data_heap[1000] << std::endl;
  delete[] my_big_data_heap;

  // What about a vector?
  std::vector<int> vec(REALLY_BIG);
  // std::vector is storing an int* that uses "new" to allocate! Aha!
  // Note that this takes way longer to run than the new allocation above
  // It's because std::vector initializes its elements, and we aren't
  // initializing the elements above
  std::cout << "vec[" << REALLY_BIG / 2 << "]: " << vec[REALLY_BIG / 2]
    << std::endl;
  return 0;
}
