#include "point.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main(int, char**) {
  // Yeah sure, we can make an instance, because we implemented magnitude()
  BasePoint base_point;
  cout << "base_point.magnitude(): " << base_point.magnitude() << endl;
  BasePoint* bp_ptr = nullptr;

  // Nope, can't do that - abstract base class
  //AbsBasePoint abs_base_point;

  // Instantiating the derived classes is the same as usual
  // We're going to use pointers so we can take advantage of inheritance
  // Remember, pointers are just addresses
  Point2DFromBase* p2dfb = new Point2DFromBase(1., 2.);
  cout << "p2dfb->magnitude(): " << p2dfb->magnitude() << endl;
  Point2DFromAbsBase* p2dfab = new Point2DFromAbsBase(10., 20.);
  cout << "p2dfab->magnitude(): " << p2dfab->magnitude() << endl;

  // Inheritance lets us do this
  // C-style
  bp_ptr = p2dfb;
  bp_ptr = (BasePoint*)p2dfb;
  // C++-style
  // static_cast: trust us, we know what we're doing (very much like the line
  // above)
  // dynamic_cast: will check at runtime if the 2 types are compatible
  // In this case, the latter is safer but has a small performance cost
  bp_ptr = static_cast<BasePoint*>(p2dfb);
  bp_ptr = dynamic_cast<BasePoint*>(p2dfb);
  // Calls Point2DFromBase::magnitude()
  cout << "bp_ptr[p2dfb]->magnitude(): " << bp_ptr->magnitude() << endl;
  bp_ptr = dynamic_cast<BasePoint*>(p2dfab);
  // Calls Point2DFromAbsBase::magnitude()
  cout << "bp_ptr[p2dfab]->magnitude(): " << bp_ptr->magnitude() << endl;

  // No problem
  Point1DFromBase* p1dfb = new Point1DFromBase(100.);
  // Calls BasePoint::magnitude() since it was not overridden in Point1DFromBase
  cout << "p1dfb->magnitude(): " << p1dfb->magnitude() << endl;
  // Nope - Point1DFromAbsBase is still abstract
  //Point1DFromAbsBase* p1dfab = new Point1DFromAbsBase(100.);

  // In addition to passing on member functions and vars, we can now refer to
  // a bunch of different objects with the same type, in the same collection,
  // even though the instances that are pointed to are different types!
  vector<BasePoint*> some_points(4);
  some_points[0] = p2dfb; // Point2DFromBase
  some_points[1] = p2dfab; // Point2DFromAbsBase
  some_points[2] = new Point3D(300., 200., 100.); // Point3D
  some_points[3] = p1dfb; // Point1DFromBase
  for (int i=0;i < 4;++i) {
    // For classes that have magnitude() overridden, this will call the
    // correct one for that instance
    cout << "some_points[i]->magnitude(): " << some_points[i]->magnitude()
      << endl;
  }
  return 0;
}
