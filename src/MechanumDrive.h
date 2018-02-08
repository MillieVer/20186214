#pragma once
#include <Spark.h>

class MechanumDrive {
public:

	float threshold = 0.2; //Dead Zone

	void setWheels(int fl, int fr, int bl, int br);
	void setPolarity(int flp, int frp, int blp, int brp);

	frc::Spark *FL; //Front left motor
	int FLP; // Front left polarity

	frc::Spark *FR;
	int FRP;

	frc::Spark *BL;
	int BLP;

	frc::Spark *BR;
	int BRP;



	void drive(float x, float y, float z); //X and Y are the ones that are important Y = forward/back X = LeftRight
};
