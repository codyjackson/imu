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
	//Select highest output rate.
	I2C::write_to_register(DEVICE, CONFIGURATION_A, 0x6<<2);
	I2C::write_to_register(DEVICE, MODE, 0x0);
}

float Magnetometer::get_angle() const
{
	byte buffer[6];
	I2C::read_from_register(DEVICE, OUT, 6, buffer);
	const float x = (((short)buffer[1]) << 8) | buffer[0];   
	const float y = (((short)buffer[3]) << 8) | buffer[2];
	const float z = (((short)buffer[5]) << 8) | buffer[4];
	return atan2(x, y)*57.2957795;
}

