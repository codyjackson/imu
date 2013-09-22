#include "i2c_helper.h"

#include <Wire.h>

void i2c_helper::write_to_register(byte deviceAddress, byte registerAddress, byte val) {
  Wire.beginTransmission(deviceAddress);  
  Wire.write(registerAddress);
  Wire.write(val);
  Wire.endTransmission();
}

void i2c_helper::read_from_register(byte deviceAddress, byte registerAddress, int numOfBytes, byte buff[]) {
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