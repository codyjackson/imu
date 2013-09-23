#include "i2c.h"

#include <Wire.h>

void I2C::write_to_register(byte deviceAddress, byte registerAddress, byte val) {
  Wire.beginTransmission(deviceAddress);
  //We first tell the device which register we would like to write to. 
  Wire.write(registerAddress);
  //We then give the device what we want to write to the register.
  Wire.write(val);
  Wire.endTransmission();
}

void I2C::read_from_register(byte deviceAddress, byte registerAddress, int numOfBytes, byte buff[]) {
  //This tells the device which register we would like to read from in our subsequent transmission.
  Wire.beginTransmission(deviceAddress);
  Wire.write(registerAddress);
  Wire.endTransmission();

  Wire.beginTransmission(deviceAddress);
  Wire.requestFrom((int)deviceAddress, numOfBytes);
  Wire.endTransmission();

  for(int i=0; Wire.available(); ++i)
    buff[i] = Wire.read();
}