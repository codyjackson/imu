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
  Vec3 v = gyroscope.get_current_angle();
  Serial.print(v.z());
  Serial.print('\n');
  delay(10);
}
