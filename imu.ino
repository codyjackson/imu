#include "imu.h"
#include "vec.h"

Imu imu;

void setup()
{
  Serial.begin(9600);
  imu.initialize();
}

void loop()
{
  Vec3 a = imu.get_orientation();
  Serial.print(a.x());
  Serial.print(" ");
  Serial.print(a.y());
  Serial.print(" ");
  Serial.print(a.z());
  Serial.print("\n");

  delay(10);
}
