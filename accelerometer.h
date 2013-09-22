#ifndef __ACCELEROMETER_H__
#define __ACCELEROMETER_H__

#include "vec.h"

#include <Arduino.h>

class Accelerometer
{
  public:
    Accelerometer();
    void initialize();

    const Vec3i get_acceleration() const;
    
  private:
    const byte POWER_CTL;
    const byte DATA_FORMAT;
    const byte DATAX0;
    const byte DEVICE;
};

#endif