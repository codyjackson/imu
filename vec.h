#ifndef __VEC_H__
#define __VEC_H__
class Vec3i
{
  public:
    Vec3i(short x, short y, short z);
    
    const short x() const;
    const short y() const;
    const short z() const;
    
  private:
    const short _x, _y, _z;
};
#endif