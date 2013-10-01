#ifndef __ACCELEROMETER_H__
#define __ACCELEROMETER_H__

#include "vec.h"

#include <Arduino.h>

class Accelerometer
{
  public:
    Accelerometer();
    void initialize();

    Vec3 get_angles() const;
    
  private:
  	Vec3 _offset;
    Vec3 get_raw_acceleration() const;
  	Vec3 get_average_acceleration(int numOfSamples) const;
};

#endif