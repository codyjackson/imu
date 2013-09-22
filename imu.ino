#include <Wire.h>

 // Device address as specified in data sheet 

byte _buff[6];

char POWER_CTL = 0x2D;	//Power Control Register
char DATA_FORMAT = 0x31;
char DATAX0 = 0x32;	//X-Axis Data 0

class Vec3i
{
  public:
    Vec3i(short x, short y, short z)
      :_x(x), _y(y), _z(z)
    {}
    
    const short x() const
    {
      return _x;
    }
    
    const short y() const
    {
      return _y;
    }
    
    const short z() const
    {
      return _z;
    }
    
  private:
    const short _x, _y, _z;
};

class Accelerometer
{
  public:
    Accelerometer()
      :POWER_CTL(0x2D), DATA_FORMAT(0x31), DATAX0(0x32), DEVICE(0x53)
    {}
    
    void initialize()
    {
      write_to_register(DEVICE, DATA_FORMAT, 0x0A);
      write_to_register(DEVICE, POWER_CTL, 0x08);
    }
    
    const Vec3i get_acceleration() const
    {
      const int bytesPerAxis = 2;
      const int totalNumOfBytes = bytesPerAxis * 3; 
      byte buffer[totalNumOfBytes];
      read_from_register(DEVICE, DATAX0, totalNumOfBytes, buffer);
      const short x = (((short)buffer[1]) << 8) | buffer[0];   
      const short y = (((short)buffer[3]) << 8) | buffer[2];
      const short z = (((short)buffer[5]) << 8) | buffer[4];
      
      return Vec3i(x, y, z);
    }
    
  private:
    const byte POWER_CTL;
    const byte DATA_FORMAT;
    const byte DATAX0;
    const byte DEVICE;
};

Accelerometer accelerometer;

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output. Make sure you set your Serial Monitor to the same!
  Serial.print("init");
  
  accelerometer.initialize();
}

void loop()
{
  Vec3i v = accelerometer.get_acceleration();
  Serial.print("\nx: ");
  Serial.print(v.x());
  Serial.print(" y: ");
  Serial.print(v.y());
  Serial.print(" z: ");
  Serial.print(v.z());
  delay(500); // only read every 0,5 seconds
}

void write_to_register(byte deviceAddress, byte registerAddress, byte val) {
  Wire.beginTransmission(deviceAddress);  
  Wire.write(registerAddress);
  Wire.write(val);
  Wire.endTransmission();
}

void read_from_register(byte deviceAddress, byte registerAddress, int numOfBytes, byte buff[]) {
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
