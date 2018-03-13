#include <MecanumDrive.h>
#include <math.h>
#include <WPIlib.h>
#include <Spark.h>

void MecanumDrive::setWheels(int fl, int fr, int bl, int br) {
		FL = new frc::Spark(fl);
		FR = new frc::Spark(fr);
		BL = new frc::Spark(bl);
		BR = new frc::Spark(br);

}

void MecanumDrive::setPolarity(int flp, int frp, int blp, int brp) {
	FLP = flp;
	FRP = frp;
	BLP = blp;
	BRP = brp;
}

void MecanumDrive::drive(float x, float y, float z) {
	enum caseswitch {cx, cy, cz};
	int sw = 0;

	if(std::fabs(x) > std::fabs(y) && std::fabs(x) > std::fabs(z)) {
		sw = cx;
	} else if (std::fabs(y) > std::fabs(x) && std::fabs(y) > std::fabs(z)) {
		sw = cy;
	} else if (std::fabs(z) > std::fabs(y) && std::fabs(z) > std::fabs(x)) {
		sw = cz;
	}

	//Making sure that the speed is zero unless it is above a certain value
	if (std::fabs(x) < threshold) {
		x = 0;
	}
	if (std::fabs(y) < threshold) {
		y = 0;
	}
	if (std::fabs(z) < threshold) {
		z = 0;
	}


	//Each drive type is determined by the largest float
	switch(sw) {
	case cy:
		MecanumDrive::FL->Set(y * MecanumDrive::FLP);
		MecanumDrive::FR->Set(y * MecanumDrive::FRP);
		MecanumDrive::BL->Set(y * MecanumDrive::BLP);
		MecanumDrive::BR->Set(y * MecanumDrive::BRP);
		break;
	case cx:
		MecanumDrive::FL->Set(x * MecanumDrive::FLP);
		MecanumDrive::FR->Set(x * MecanumDrive::FRP * -1);
		MecanumDrive::BL->Set(x * MecanumDrive::BLP);
		MecanumDrive::BR->Set(x * MecanumDrive::BRP * -1);
		break;
	case cz:
		MecanumDrive::FL->Set(z * MecanumDrive::FLP);
		MecanumDrive::FR->Set(z * MecanumDrive::FRP);
		MecanumDrive::BL->Set(z * MecanumDrive::BLP * -1);
		MecanumDrive::BR->Set(z * MecanumDrive::BRP * -1);
		break;
	default:
		MecanumDrive::FL->Set(0);
		MecanumDrive::FR->Set(0);
		MecanumDrive::BL->Set(0);
		MecanumDrive::BR->Set(0);
	}
	Wait(0.005);
}
