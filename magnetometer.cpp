#include "magnetometer.h"
#include "i2c.h"
#include <math.h>

Magnetometer::Magnetometer()
	:_offset(0.0f), DEVICE(0x1E),
	CONFIGURATION_A(0x0), CONFIGURATION_B(0x1), MODE(0x2),
	OUT(0x3), STATUS(0x9),
	IDENTIFICATION_A(0xA), IDENTIFICATION_B(0xB), IDENTIFICATION_C(0xC)
{}

void Magnetometer::initialize()
{
	//Continuous-Measurement Mode
	I2C::write_to_register(DEVICE, MODE, 0x0);
	//Select highest output rate.
	I2C::write_to_register(DEVICE, CONFIGURATION_A, 0x6<<2);
}

float Magnetometer::get_angle() const
{
	byte buffer[6];
	I2C::read_from_register(DEVICE, OUT, 6, buffer);
	const float x = (((short)buffer[0]) << 8) | buffer[1];   
	const float z = (((short)buffer[2]) << 8) | buffer[3];
	const float y = (((short)buffer[4]) << 8) | buffer[5];

	const float heading = atan2(y, x)*57.2957795;
	return heading >= 0 ? heading : heading + 360.0f;
}

