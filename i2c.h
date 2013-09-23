#include <Arduino.h>

namespace I2C
{
  void write_to_register(byte deviceAddress, byte registerAddress, byte val);
  void read_from_register(byte deviceAddress, byte registerAddress, int numOfBytes, byte buff[]);
}