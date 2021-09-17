// Include guards. These are pre-processor commands (starting with the #)
// It's just an if statement: "if not defined"
#ifndef POINT_HPP
#define POINT_HPP
#include <stdexcept>

// This is the same as the Point class in classes2.cpp, except we split up the
// class into header (declaration) and implementation (definition) files
class Point {
  public:
    Point();
    Point(float x, float y);

    float get_x() const;
    void set_x(float x);
    float get_y() const;
    void set_y(float y);

    // Static members and functions can be accessed without a class instance
    static int const MAX_VALUE = 1024;
    static void do_something();

    // Operators
    // friend: access to private/protected, but can call it globally!
    friend Point operator+(Point lhs, Point const& rhs) {
      lhs.m_x += rhs.m_x;
      lhs.m_y += rhs.m_y;
      return lhs;
    }
    friend Point operator-(Point lhs, Point const& rhs) {
      lhs.m_x -= rhs.m_x;
      lhs.m_y -= rhs.m_y;
      return lhs;
    }
    // Modifying the object, so we return the address of ourself
    Point& operator+=(Point const& other) {
      m_x += other.get_x();
      m_y += other.get_y();
      return *this;
    }
    Point& operator-=(Point const& other) {
      m_x -= other.get_x();
      m_y -= other.get_y();
      return *this;
    }
    float operator[](int index) {
      switch (index) {
        case 0:
          return m_x;
        case 1:
          return m_y;
        default:
          throw std::invalid_argument("Index out of range");
      }
    }

  private:
    float m_x;
    float m_y;
};

// Gotta end the if statement!
#endif
