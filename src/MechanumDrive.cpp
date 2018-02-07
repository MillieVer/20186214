#include <MechanumDrive.h>
#include <math.h>
#include <wpilib.h>
void MechanumDrive::drive(float x, float y, float z) {
	enum caseswitch {cx, cy, cz};
	int sw = 0;

	if(x > y && x > z) {
		sw = cx;
	} else if (y > x && y > z) {
		sw = cy;
	} else if (z > y && z > x) {
		sw = cz;
	}

	//Making sure that the speed is zero unless it is above a certain value
	if (x < threshold) {
		x = 0;
	} else if (y < threshold) {
		y = 0;
	} else if (z < threshold) {
		z = 0;
	}


	//Each drive type is determined by the largest float
	switch(sw) {
	case cy:
		MechanumDrive::wheel.FL.Set(y * MechanumDrive::wheel.FLP);
		MechanumDrive::wheel.FR.Set(y * MechanumDrive::wheel.FRP);
		MechanumDrive::wheel.BL.Set(y * MechanumDrive::wheel.BLP);
		MechanumDrive::wheel.BR.Set(y * MechanumDrive::wheel.BRP);
		break;
	case cx:
		MechanumDrive::wheel.FL.Set(x * MechanumDrive::wheel.FLP);
		MechanumDrive::wheel.FR.Set(x * MechanumDrive::wheel.FRP * -1);
		MechanumDrive::wheel.BL.Set(x * MechanumDrive::wheel.BLP * -1);
		MechanumDrive::wheel.BR.Set(x * MechanumDrive::wheel.BRP);
		break;
	case cz:
		MechanumDrive::wheel.FL.Set(y * MechanumDrive::wheel.FLP);
		MechanumDrive::wheel.FR.Set(y * MechanumDrive::wheel.FRP * -1);
		MechanumDrive::wheel.BL.Set(y * MechanumDrive::wheel.BLP);
		MechanumDrive::wheel.BR.Set(y * MechanumDrive::wheel.BRP * -1);
		break;
	default:
		MechanumDrive::wheel.FL.Set(0);
		MechanumDrive::wheel.FR.Set(0);
		MechanumDrive::wheel.BL.Set(0);
		MechanumDrive::wheel.BR.Set(0);
	}
	Wait(0.005);
}
