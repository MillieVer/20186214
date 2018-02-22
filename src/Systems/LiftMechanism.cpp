#include <LiftMechanism.h>

LiftMechanism::LiftMechanism() {
	// TODO Auto-generated constructor stub

}

void LiftMechanism::SetIntake(int number) {
	intake = new WPI_TalonSRX(number);
}

void LiftMechanism::Intake(double speed) {
	LiftMechanism::intake->Set(ControlMode::PercentOutput, speed);
}

void LiftMechanism::SetLift(int number) {
//	lift = new TalonSRX(number);
}

void LiftMechanism::Lift(double speed) {
 //	lift->Set(ControlMode::PercentOutput, speed);
}

LiftMechanism::~LiftMechanism() {
	// TODO Auto-generated destructor stub
	delete intake;
}

