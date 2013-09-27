#include "accelerometer.h"
#include "i2c.h"
#include "vec.h"
#include <Arduino.h>
#include <math.h>

Accelerometer::Accelerometer()
  :POWER_CTL(0x2D), DATA_FORMAT(0x31), DATAX0(0x32), DEVICE(0x53)
{}

void Accelerometer::initialize()
{
  I2C::write_to_register(DEVICE, DATA_FORMAT, 0x0B);
  I2C::write_to_register(DEVICE, POWER_CTL, 0x08);
}

Vec3 Accelerometer::get_angles() const
{
  const int bytesPerAxis = 2;
  const int totalNumOfBytes = bytesPerAxis * 3; 
  byte buffer[totalNumOfBytes];
  I2C::read_from_register(DEVICE, DATAX0, totalNumOfBytes, buffer);
  const short x = (((short)buffer[1]) << 8) | buffer[0];   
  const short y = (((short)buffer[3]) << 8) | buffer[2];
  const short z = (((short)buffer[5]) << 8) | buffer[4];
  
  Vec3 accelerations(x, y, z);
  accelerations *= 0.004;
  const float radiansToDegrees = 57.2957795;
  const float xangle = -atan2(accelerations.x(),accelerations.z())*radiansToDegrees;
  const float yangle = -atan2(accelerations.y(),accelerations.z())*radiansToDegrees;

  return Vec3(xangle, yangle, 0.0f);
}