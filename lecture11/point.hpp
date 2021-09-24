#ifndef POINT_HPP
#define POINT_HPP
#include <cmath>

// Regular base class. The magnitude() function is virtual because we intend
// to override it in the derived class, but we still provided a BasePoint
// implementation
class BasePoint {
  public:
    virtual float magnitude() const {
      return 100000.;
    }
};

// Abstract base class. The magnitude() function is virtual, and = 0, so there
// is no implementation. This forces any class that derives from AbsBasePoint
// to provide one!
class AbsBasePoint {
  public:
    // We *must* declare a virtual destructor. If we don't add the virtual so
    // that it gets overridden, when we call delete on this object, it is
    // undefined behavior!
    // This is because we didn't put the virtual to tell it to override it,
    // but you have a pointer to an object with a different destructor, so...
    virtual ~AbsBasePoint() {}
    virtual float magnitude() const = 0;
};

// Now we inherit from one of the base classes
class Point2DFromBase: public BasePoint {
  public:
    Point2DFromBase(float x, float y):
      m_x(x),
      m_y(y) {}

    float get_x() const { return m_x; }
    float get_y() const { return m_y; }
    void set_x(float x) { m_x = x; return; }
    void set_y(float y) { m_y = y; return; }

    virtual float magnitude() const override {
      return std::sqrt(std::pow(m_x, 2) + std::pow(m_y, 2));
    }

  protected:
    float m_x;
    float m_y;
};

class Point2DFromAbsBase: public BasePoint {
  public:
    Point2DFromAbsBase(float x, float y):
      m_x(x),
      m_y(y) {}

    float get_x() const { return m_x; }
    float get_y() const { return m_y; }
    void set_x(float x) { m_x = x; return; }
    void set_y(float y) { m_y = y; return; }

    virtual float magnitude() const override {
      return std::sqrt(std::pow(m_x, 2) + std::pow(m_y, 2));
    }

  protected:
    float m_x;
    float m_y;
};

class Point3D: public Point2DFromBase {
  public:
    Point3D(float x, float y, float z):
      Point2DFromBase(x, y),
      m_z(z) {}

    float get_z() const { return m_z; }
    void set_z(float z) { m_z = z; return; }

    float magnitude() const override final {
      return std::sqrt(std::pow(m_x, 2) + std::pow(m_y, 2) + std::pow(m_z, 2));
    }

  private:
    float m_z;
};

// What if we don't override/implement the magnitude() function?
// For a non-abstract base class, it just goes up the inheritance chain until
// it finds an implementation, then calls that
class Point1DFromBase: public BasePoint {
  public:
    Point1DFromBase(float x):
      m_x(x) {}

    // No magnitude(), that's fine, will call BasePoint::magnitude()

  protected:
    float m_x;
};

// For abstract base classes, there is no implementation, so Point1DFromAbsBase
// is still abstract if it remains unimplemented
class Point1DFromAbsBase: public AbsBasePoint {
  public:
    Point1DFromAbsBase(float x):
      m_x(x) {}

    // No magnitude(), Point1DFromAbsBase is still abstract! This compiles
    // but we cannot instantiate this object

  protected:
    float m_x;
};

#endif
