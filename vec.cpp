#include "vec.h"

Vec3i::Vec3i(short x, short y, short z)
  :_x(x), _y(y), _z(z)
{}

const short Vec3i::x() const
{
  return _x;
}

const short Vec3i::y() const
{
  return _y;
}

const short Vec3i::z() const
{
  return _z;
}