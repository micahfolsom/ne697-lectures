// Quotes for our class
#include "point.hpp"
// Brackets for C++ standard library headers
#include <iostream>
using namespace std;

void print_point(Point const& p) {
  cout << "p.x: " << p.get_x() << endl;
  cout << "p.y: " << p.get_y() << endl;
  return;
}


// We *must* have a main() function somewhere in the executable. If we don't,
// we should compile it to a library, which is just a collection of objects
// and functions
int main(int argc, char* argv[]) {
  // Same business as before
  Point pt;
  pt.set_x(10.0);
  pt.set_y(20.0);
  Point pt2(5000., 1e15);

  print_point(pt);
  print_point(pt2);

  // Can access static members either the usual way
  cout << "MAX_VALUE: " << pt.MAX_VALUE << endl;
  // Or using the class scope
  cout << "MAX_VALUE: " << Point::MAX_VALUE << endl;
  pt.do_something();
  Point::do_something();

  // If we define the operators, we get some nice syntax for our objects
  Point pt3 = pt + pt2;
  print_point(pt3);
  Point pt4 = pt - pt2;
  print_point(pt4);
  pt4 += pt;
  pt4 += Point(500, 1000);
  print_point(pt4);
  cout << "pt4[0]: " << pt4[0] << endl;
  
  // This will throw an exception. Uncomment to see what happens if we don't
  // catch it
  //cout << "pt4[0]: " << pt4[100] << endl;
  try {
    cout << "pt4[100]: " << pt4[100] << endl;
  } catch (exception const& ex) {
    cout << "Caught an exception! what(): " << ex.what() << endl;
  }
  return 0;
}
