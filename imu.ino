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
  Vec3 v = gyroscope.get_current_angle(0.01f);
  Serial.print("\nz: ");
  Serial.print(v.z());
  delay(10);
}
