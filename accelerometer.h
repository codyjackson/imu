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

    const byte POWER_CTL;
    const byte DATA_FORMAT;
    const byte DATAX0;
    const byte DEVICE;
};

#endif