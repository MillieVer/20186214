#pragma once
#include <Spark.h>

class MecanumDrive {
public:

	float threshold = 0.2; //Dead Zone

	void setWheels(int fl, int fr, int bl, int br);
	void setPolarity(int flp, int frp, int blp, int brp);

	frc::Spark *FL; //Front left motor
	int FLP = 1; // Front left polarity

	frc::Spark *FR;
	int FRP = 1;

	frc::Spark *BL;
	int BLP = 1;

	frc::Spark *BR;
	int BRP = 1;



	void drive(float x, float y, float z); //X and Y are the ones that are important Y = forward/back X = LeftRight
};
