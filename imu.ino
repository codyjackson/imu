#include "accelerometer.h"
#include "gyroscope.h"
#include "vec.h"
#include <Wire.h>

Gyroscope gyroscope;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  
  gyroscope.initialize();
}

void loop()
{
  Vec3i v = gyroscope.get_angular_velocity();
  Serial.print("\nx: ");
  Serial.print(v.x());
  Serial.print(" y: ");
  Serial.print(v.y());
  Serial.print(" z: ");
  Serial.print(v.z());
  delay(50);
}
