#ifndef __GYROSCOPE_H__
#define __GYROSCOPE_H__

#include "vec.h"
#include <Arduino.h>

class Gyroscope
{
  public:
    Gyroscope();
    void initialize();

    const Vec3 get_angles(float dt) const;

  private:
    const Vec3 get_raw_angular_velocity() const;
    const Vec3 get_average_reading(int numOfSamples) const;

    Vec3 _offset;
};

#endif