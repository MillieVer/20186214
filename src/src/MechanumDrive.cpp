#include <MechanumDrive.h>
#include <math.h>
#include <WPIlib.h>
#include <Spark.h>

void MechanumDrive::setWheels(int fl, int fr, int bl, int br) {
		FL = new frc::Spark(fl);
		FR = new frc::Spark(fr);
		BL = new frc::Spark(bl);
		BR = new frc::Spark(br);

}

void MechanumDrive::setPolarity(int flp, int frp, int blp, int brp) {
	FLP = flp;
	FRP = frp;
	BLP = blp;
	BRP = brp;
}

void MechanumDrive::drive(float x, float y, float z) {
	enum caseswitch {cx, cy, cz};
	int sw = 0;

	if(std::fabs(x) > std::fabs(y) && std::fabs(x) > std::fabs(z)) {
		sw = cx;
	} else if (std::fabs(y) > x && std::fabs(y) > std::fabs(z)) {
		sw = cy;
	} else if (std::fabs(z) > std::fabs(y) && std::fabs(z) > std::fabs(x)) {
		sw = cz;
	}

	//Making sure that the speed is zero unless it is above a certain value
	if (std::fabs(x) < threshold) {
		x = 0;
	} else if (std::fabs(y) < threshold) {
		y = 0;
	} else if (std::fabs(z) < threshold) {
		z = 0;
	}


	//Each drive type is determined by the largest float
	switch(sw) {
	case cy:
		MechanumDrive::FL->Set(y * MechanumDrive::FLP);
		MechanumDrive::FR->Set(y * MechanumDrive::FRP);
		MechanumDrive::BL->Set(y * MechanumDrive::BLP);
		MechanumDrive::BR->Set(y * MechanumDrive::BRP);
		break;
	case cx:
		MechanumDrive::FL->Set(x * MechanumDrive::FLP);
		MechanumDrive::FR->Set(x * MechanumDrive::FRP * -1);
		MechanumDrive::BL->Set(x * MechanumDrive::BLP);
		MechanumDrive::BR->Set(x * MechanumDrive::BRP * -1);
		break;
	case cz:
		MechanumDrive::FL->Set(z * MechanumDrive::FLP);
		MechanumDrive::FR->Set(z * MechanumDrive::FRP);
		MechanumDrive::BL->Set(z * MechanumDrive::BLP * -1);
		MechanumDrive::BR->Set(z * MechanumDrive::BRP * -1);
		break;
	default:
		MechanumDrive::FL->Set(0);
		MechanumDrive::FR->Set(0);
		MechanumDrive::BL->Set(0);
		MechanumDrive::BR->Set(0);
	}
	Wait(0.005);
}
