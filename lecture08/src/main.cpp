// Quotes for our class
#include "point.hpp"
// Brackets for C++ standard library headers
#include <iostream>
using namespace std;

// We *must* have a main() function somewhere in the executable. If we don't,
// we should compile it to a library, which is just a collection of objects
// and functions
int main(int argc, char* argv[]) {
  // Same business as before
  Point pt;
  pt.set_x(10.0);
  pt.set_y(20.0);
  Point pt2(5000., 1e15);

  cout << "pt.x: " << pt.get_x() << endl;
  cout << "pt.y: " << pt.get_y() << endl;
  cout << "pt2.x: " << pt2.get_x() << endl;
  cout << "pt2.y: " << pt2.get_y() << endl;
  return 0;
}
