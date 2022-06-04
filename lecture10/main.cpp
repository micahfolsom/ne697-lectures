#include "point.hpp"
#include <iostream>
using namespace std;

int main(int, char**) {
  // Yeah sure, we can make an instance
  BasePoint base_point;
  cout << "base_point.magnitude(): " << base_point.magnitude() << endl;
  BasePoint* bp_ptr = nullptr;

  // Nope, can't do that - abstract
  //AbsBasePoint abs_base_point;

  // Instantiating the derived classes is the same as usual
  Point2DFromBase* p2dfb = new Point2DFromBase(1., 2.);
  cout << "p2dfb->magnitude(): " << p2dfb->magnitude() << endl;
  Point2DFromAbsBase* p2dfab = new Point2DFromAbsBase(10., 20.);
  cout << "p2dfab->magnitude(): " << p2dfab->magnitude() << endl;

  // Inheritance lets us do this
  // C-style implicit
  bp_ptr = p2dfb;
  // C-style explicit
  bp_ptr = (BasePoint*)p2dfb;
  // C++-style
  bp_ptr = dynamic_cast<BasePoint*>(p2dfb);
  // Calls Point2DFromBase::magnitude()
  cout << "bp_ptr[p2dfb]->magnitude(): " << bp_ptr->magnitude() << endl;
  bp_ptr = dynamic_cast<BasePoint*>(p2dfab);
  // Calls Point2DFromAbsBase::magnitude()
  cout << "bp_ptr[p2dfab]->magnitude(): " << bp_ptr->magnitude() << endl;

  // No problem
  Point1DFromBase* p1dfb = new Point1DFromBase(100.);
  // Calls BasePoint::magnitude()
  cout << "p1dfb->magnitude(): " << p1dfb->magnitude() << endl;
  // Nope - Point1DFromAbsBase is still abstract
  //Point1DFromAbsBase* p1dfab = new Point1DFromAbsBase(100.);
  return 0;
}
