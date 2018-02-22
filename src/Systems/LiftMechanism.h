#pragma once

#include "ctre/Phoenix.h"

class LiftMechanism {
public:


	WPI_TalonSRX *intake;
	//TalonSRX *lift;

	void SetIntake(int number);
	void Intake(double speed);

	void SetLift(int number);
	void Lift(double speed);

	LiftMechanism();
	virtual ~LiftMechanism();
};
