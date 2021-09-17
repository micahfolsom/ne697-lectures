// The "" tells the compiler to look in the locally include files (which we
// specify in the CMakeLists.txt)
// This is the form we'll use for classes we define
// The <> version tells the compiler to look in the system header folders
// The <> form is for external headers - system, standard library, or external
// library headers
#include "point.hpp"
#include <iostream>
using namespace std;

// Now we have to "scope" the class functions by prefixing with Point::
Point::Point():
// We can use the same initialization syntax here
  m_x(0.0),
  m_y(0.0)
{
}

// All of this is the same as before, we just added the scoping since we are
// in a different file from the class declaration
Point::Point(float x, float y):
  m_x(x),
  m_y(y)
{
}

float Point::get_x() const {
  return m_x;
}

void Point::set_x(float x) {
  m_x = x;
  return;
}

float Point::get_y() const {
  return m_y;
}

void Point::set_y(float y) {
  m_y = y;
  return;
}

void Point::do_something() {
  cout << "Doing something!" << endl;
  return;
}
