#include <iostream>
using namespace std;

// Now we use class instead of struct
class Point {
  // Access specifier: these things are publicly accessible
  public:
    // We made our data members private, so we need to provide functions to
    // access and modify their values. Accessors: getters and setters
    // We'll change these function signatures slightly to be more "best
    // practices" later
    float get_x() { return m_x; }
    void set_x(float x) { m_x = x; return;}
    float get_y() { return m_y; }
    void set_y(float y) { m_y = y; return;}

  // These things are not publicly accessible. p.x no longer works!
  private:
    float m_x;
    float m_y;
};

void do_something(Point p) {
  // This is now an error! x is "private"
  //cout << "p.x: " << p.x << endl;
  // Use the interface defined for getting x's value
  cout << "p.get_x(): " << p.get_x() << endl;
  cout << "p.get_y(): " << p.get_y() << endl;
  return;
}

int main(int argc, char* argv[]) {
  // Creating a point object is the same, but we can't use the {} syntax
  // anymore, because x and y are private and thus unassignable:
  //Point pt = {100., 500.}; // Nope
  Point pt;
  // Use the interface defined for setting x's value
  pt.set_x(1000.0);

  do_something(pt);
  return 0;
}
