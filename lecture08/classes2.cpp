#include <iostream>
using namespace std;

// Now we use class instead of struct
class Point {
  // Access specifier: these things are publicly accessible
  public:
    // Default constructor. We initialize the parameters using a special syntax
    Point():
      m_x(0.0),
      m_y(0.0)
    {
    }
    // Another constructor. This one takes initial parameters. This is
    // "function overloading" - the same name, but different arguments. The
    // compiler will figure out which one you want when you use it.
    Point(float const& x, float const& y):
      m_x(x),
      m_y(y)
    {
    }
    // Destructor. Clean up any memory, close things, etc.
    ~Point();

    // We made our data members private, so we need to provide functions to
    // access and modify their values. Accessors: getters and setters
    float const& get_x() const { return m_x; }
    void set_x(float const& x) { m_x = x; return;}
    float const& get_y() const { return m_y; }
    void set_y(float const& y) { m_y = y; return;}
    // We use "float const&" to avoid copies and guarantee the values do not
    // change where they're not supposed to, since we're dealing with private
    // variables.
    // The const after the function means that the function cannot change the
    // object it's attached to. It's guaranteed at compile time - it won't
    // compile if you break the rules!

  // These things are not publicly accessible. p.x no longer works!
  private:
    float m_x;
    float m_y;
};

void do_something(Point const& p) {
  // This is now an error! x is "private"
  //cout << "p.x: " << p.x << endl;
  // Use the interface defined for getting x's value
  float x = p.get_x();
  //p.get_x() = 1.0; // Not allowed
  cout << "p.get_x(): " << p.get_x() << endl;
  cout << "p.get_y(): " << p.get_y() << endl;
  return;
}
// Function overloading - same name, different signature
void do_something(Point const& p, Point const& p2) {
  cout << "p.get_x(): " << p.get_x() << endl;
  cout << "p.get_y(): " << p.get_y() << endl;
  cout << "p2.get_x(): " << p2.get_x() << endl;
  cout << "p2.get_y(): " << p2.get_y() << endl;
  return;
}

int main(int argc, char* argv[]) {
  // Creating a point object is the same, but we can't use the {} syntax
  // anymore, because x and y are private and thus unassignable:
  //Point pt = {100., 500.}; // Nope
  Point pt;
  // Use the interface defined for setting x's value
  pt.set_x(1000.);

  // On the stack
  Point pt1(1., 5.);
  // Same as above
  Point pt2 = Point(1., 5.);
  // Calls the default constructor (no args)
  Point pt3 = Point();
  // On the heap
  Point* pt4 = new Point;
  // Same as above
  Point* pt6 = new Point();
  Point* pt5 = new Point(5., 1.);
  // For pointers, initialize to nullptr
  Point* pt7 = nullptr;
  // Then later, we can check it, and do what's needed
  if (pt7 == nullptr) {
    pt7 = new Point;
  } else {
    cout << pt7->get_x() << endl;
  }
  delete pt4;
  delete pt5;
  delete pt6;
  // Calling "delete" on nullptr won't segfault, which is nice!
  delete pt7;

  // pt *cannot be changed*, because the function takes "Point const&"
  do_something(pt);
  // Overloaded call. We dereference since p5 is a pointer
  do_something(pt1, *pt5);
  return 0;
}
