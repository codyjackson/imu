#ifndef __MAGNETOMETER_H__
#define __MAGNETOMETER_H__

#include <Arduino.h>

class Magnetometer
{
public:
	Magnetometer();
	void initialize();
	float get_angle() const;

private:
	float _offset;
	const byte DEVICE;
	const byte CONFIGURATION_A;
	const byte CONFIGURATION_B;
	const byte MODE;
	const byte OUT;
	const byte STATUS;
	const byte IDENTIFICATION_A;
	const byte IDENTIFICATION_B;
	const byte IDENTIFICATION_C;
};

#endif