#ifndef __IMU_H__
#define __IMU_H__

#include "accelerometer.h"
#include "gyroscope.h"

class Imu
{
public:
	Imu();
	void initialize();
	Vec3 get_orientation();

private:
	unsigned long _timestamp;
	Vec3 _orientationAccumulator;

	Accelerometer _accelerometer;
	Gyroscope _gyroscope;
};

#endif