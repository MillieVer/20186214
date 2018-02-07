#pragma once
#include <Spark.h>

class MechanumDrive {
public:

	float threshold = 0.2; //Dead Zone

	struct wheels {
		frc::Spark FL; //Front left motor
		int FLP; // Front left polarity

		frc::Spark FR;
		int FRP;

		frc::Spark BL;
		int BLP;

		frc::Spark BR;
		int BRP;

	} wheel;

	void drive(float x, float y, float z); //X and Y are the ones that are important Y = forward/back X = LeftRight
};
