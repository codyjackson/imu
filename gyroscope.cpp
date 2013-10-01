#include "gyroscope.h"
#include "i2c.h"
#include <Wire.h>

namespace
{
	const byte WHO_AM_I(0x0F);
	const byte CTRL_REG1(0x20);
	const byte CTRL_REG2(0x21);

	const byte CTRL_REG3(0x22);
	const byte CTRL_REG4(0x23);
	const byte CTRL_REG5(0x24);

	const byte REFERENCE(0x25);
	const byte OUT_TEMP(0x26);
	const byte STATUS_REG(0x27);

	const byte OUT_X_L(0x28);
	const byte OUT_X_H(0x29);
	const byte OUT_Y_L(0x2A);

	const byte OUT_Y_H(0x2B);
	const byte OUT_Z_L(0x2C);
	const byte OUT_Z_H(0x2D);

	const byte FIFO_CTRL_REG(0x2E);
	const byte FIFO_SRC_REG(0x2F);
	const byte INT1_CFG(0x30);

	const byte INT1_SRC(0x31);
	const byte INT1_THS_XH(0x32);
	const byte INT1_THS_XL(0x33);

	const byte INT1_THS_YH(0x34);
	const byte INT1_THS_YL(0x35);
	const byte INT1_THS_ZH(0x36);

	const byte INT1_THS_ZL(0x37);
	const byte INT1_DURATION(0x38);
	const byte DEVICE(0xD2 >> 1);
}

Gyroscope::Gyroscope()
{}

void Gyroscope::initialize()
{
	I2C::write_to_register(DEVICE, CTRL_REG1, 0x0F);
	I2C::write_to_register(DEVICE, CTRL_REG4, 0x90);
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

const Vec3 Gyroscope::get_angles(float dt) const
{
	return (get_raw_angular_velocity()+_offset)*dt;
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
	Vec3 v(-y, x, z);
	v*=0.0175;
	return v;
}