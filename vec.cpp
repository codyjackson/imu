#include "vec.h"

Vec3::Vec3()
  :_x(0.0f), _y(0.0f), _z(0.0f)
{}

Vec3::Vec3(float x, float y, float z)
  :_x(x), _y(y), _z(z)
{}

const Vec3 Vec3::operator*(const float scalar) const
{
  return Vec3(_x*scalar, _y*scalar, _z*scalar);
}

const Vec3& Vec3::operator*=(const float scalar)
{
  return (*this) = ((*this)*scalar);
}

const Vec3 Vec3::operator+(const Vec3& rhs) const
{
  return Vec3(_x+rhs._x, _y+rhs._y, _z+rhs._z);
}

const Vec3& Vec3::operator+=(const Vec3& rhs)
{
  return (*this) = ((*this)+rhs);
}

const Vec3 Vec3::operator-(const Vec3& rhs) const
{
  return (*this)+(rhs*-1.0f);
}

const Vec3& Vec3::operator-=(const Vec3& rhs)
{
  return (*this) = (*this)-rhs;
}

const float Vec3::x() const
{
  return _x;
}

const float Vec3::y() const
{
  return _y;
}

const float Vec3::z() const
{
  return _z;
}

const Vec3& operator*(const float scalar, const Vec3& vec)
{
  return vec*scalar;
}