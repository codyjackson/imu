#include "i2c.h"

#include <Wire.h>

void I2C::write_to_register(byte deviceAddress, byte registerAddress, byte val) {
  Wire.beginTransmission(deviceAddress);  
  Wire.write(registerAddress);
  Wire.write(val);
  Wire.endTransmission();
}

void I2C::read_from_register(byte deviceAddress, byte registerAddress, int numOfBytes, byte buff[]) {
  Wire.beginTransmission(deviceAddress);
  Wire.write(registerAddress);
  Wire.endTransmission();

  Wire.beginTransmission(deviceAddress);
  Wire.requestFrom((int)deviceAddress, numOfBytes);

  int i = 0;
  while(Wire.available())
    buff[i++] = Wire.read();
  Wire.endTransmission();
}