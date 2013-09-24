#include "gyroscope.h"
#include "i2c.h"
#include <Wire.h>

Gyroscope::Gyroscope()
   :WHO_AM_I(0x0F),      CTRL_REG1(0x20),    CTRL_REG2(0x21), 
   CTRL_REG3(0x22),     CTRL_REG4(0x23),    CTRL_REG5(0x24), 
   REFERENCE(0x25),     OUT_TEMP(0x26),     STATUS_REG(0x27), 
   OUT_X_L(0x28),       OUT_X_H(0x29),      OUT_Y_L(0x2A), 
   OUT_Y_H(0x2B),       OUT_Z_L(0x2C),      OUT_Z_H(0x2D), 
   FIFO_CTRL_REG(0x2E), FIFO_SRC_REG(0x2F), INT1_CFG(0x30),      
   INT1_SRC(0x31),      INT1_THS_XH(0x32),  INT1_THS_XL(0x33),   
   INT1_THS_YH(0x34),   INT1_THS_YL(0x35),  INT1_THS_ZH(0x36),   
   INT1_THS_ZL(0x37),   INT1_DURATION(0x38), DEVICE(0xD2 >> 1)
{}

void Gyroscope::initialize()
{
	I2C::write_to_register(DEVICE, CTRL_REG1, 0x0F);
	I2C::write_to_register(DEVICE, CTRL_REG4, 0x30);
	_offset = get_average_reading(10)*(-1.0f);
}

const Vec3 Gyroscope::get_average_reading(int numOfSamples) const
{
	Vec3 accumulator;
	for(int i = 0; i < numOfSamples; ++i)
	{
		accumulator += get_raw_angular_velocity();
		delay(50);
	}
	return accumulator * (1.0f/numOfSamples);
}

const Vec3 Gyroscope::get_angular_velocity() const
{
	return get_raw_angular_velocity()+_offset;
}

const Vec3 Gyroscope::get_current_angle(float timeStepInSeconds) const
{
	return _currentAngle += get_angular_velocity()*timeStepInSeconds;
}

const Vec3 Gyroscope::get_raw_angular_velocity() const
{
	const int bytesPerAxis = 2;
	const int totalNumOfBytes = bytesPerAxis * 3; 
	byte buffer[totalNumOfBytes];
	I2C::read_from_register(DEVICE, OUT_X_L | (1 << 7), totalNumOfBytes, buffer);
	const float x = (((short)buffer[1]) << 8) | buffer[0];   
	const float y = (((short)buffer[3]) << 8) | buffer[2];
	const float z = (((short)buffer[5]) << 8) | buffer[4];

	//The gyroscope reports in mili degrees per second. I'm converting to degrees per second.
	//http://electronics.stackexchange.com/questions/39024/how-do-i-get-gyro-sensor-data-l3g4200d-into-degrees-sec
	Vec3 v(x, y, z);
	v*=(1.0f/14.286f);
	return v;
}