#include "imu.h"
#include "vec.h"
#include "magnetometer.h"
#include <Wire.h>

Imu imu;
Magnetometer magnetometer;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  magnetometer.initialize();
}

void loop()
{
  float a = magnetometer.get_angle();
  Serial.print(a);
  Serial.print("\n");

  delay(10);
}
