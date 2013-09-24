#ifndef __VEC_H__
#define __VEC_H__
class Vec3
{
  public:
    Vec3();
    Vec3(float x, float y, float z);
    
    const float x() const;
    const float y() const;
    const float z() const;
    
    const Vec3 operator*(const float scalar) const;
    const Vec3& operator*=(const float scalar);

    const Vec3 operator+(const Vec3& rhs) const;
    const Vec3& operator+=(const Vec3& rhs);
    const Vec3 operator-(const Vec3& rhs) const;
    const Vec3& operator-=(const Vec3& rhs);

    friend const Vec3& operator*(const float scalar, const Vec3& vec);
    friend const Vec3& operator+(const Vec3& rhs);
  private:
    float _x, _y, _z;
};

const Vec3& operator*(const float scalar, const Vec3& vec);

#endif