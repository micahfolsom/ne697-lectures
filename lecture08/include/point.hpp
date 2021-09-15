// Include guards. These are pre-processor commands (starting with the #)
// It's just an if statement: "if not defined"
#ifndef POINT_HPP
#define POINT_HPP

// This is the same as the Point class in classes2.cpp, except we split up the
// class into header (declaration) and implementation (definition) files
class Point {
  public:
    Point();
    Point(float const& x, float const& y);

    float const& get_x() const;
    void set_x(float const& x);
    float const& get_y() const;
    void set_y(float const& y);

  private:
    float m_x;
    float m_y;
};

// Gotta end the if statement!
#endif
