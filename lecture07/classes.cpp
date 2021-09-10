#include <iostream>
using namespace std;

// A simple data container
struct Point {
  float x;
  float y;
};

// They can be nested - member variables can be whatever type we want, including
// a pointer
struct Event {
  Point position;
  float timestamp;
  int event_id;
};

// The input argument is a "reference to a constant Point called p"
// This means we can't change the value of p within this function
void do_something(Point const& p) {
  cout << "p.x: " << p.x << endl;
  cout << "p.y: " << p.y << endl;
  return;
}

// Passing a pointer - we need to use the pointer syntax to access elements
void do_something_ptr(Point* p) {
  cout << "p->x: " << p->x << endl;
  cout << "p->y: " << p->y << endl;
  return;
}

int main(int argc, char* argv[]) {
  // "Point" is just a new type that we defined
  Point pt;
  //Point pt = Point();
  //auto pt = Point();
  pt.x = 1000.;
  pt.y = 5000.;
  Point pt2 = {1000., 5000.};

  do_something(pt);

  // We can heap allocate it too
  //Point* pt_ptr = new Point;
  Point* pt_ptr = new Point {100., 500.};
  cout << "pt_ptr->x: " << pt_ptr->x << endl;
  cout << "pt_ptr->y: " << pt_ptr->y << endl;
  // It's the same thing as above - just a shorthand
  cout << "pt_ptr->x: " << (*pt_ptr).x << endl;
  cout << "pt_ptr->y: " << (*pt_ptr).y << endl;
  do_something(*pt_ptr);
  delete pt_ptr;

  // Accessing nested structs
  Event event;
  event.position.x = 500.;

  return 0;
}
