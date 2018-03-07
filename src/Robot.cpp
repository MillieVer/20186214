/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Joystick.h>

#include "Systems/MechanumDrive.h"
#include "Systems/LiftMechanism.h"

class Robot : public frc::IterativeRobot {
private:

	frc::LiveWindow& m_lw = *LiveWindow::GetInstance();
	MechanumDrive *drive;
	frc::Joystick *stick;
	LiftMechanism *lift;


public:

	/**This is where you will set all your initial starting conditions.
	 * Any mechanisms that are used during autonomous and user operated periods will be set here.
	 * This is done once and will not happen again until the robot code is restarted.**/
	void RobotInit() override {
		//Setting the drive system variables.
		drive = new MechanumDrive;
		drive->threshold = .1;
		drive->setWheels(2,3,1,0);
		drive->setPolarity(-1, 1, 1, -1);

		//Setting the Lift system variables.
		lift = new LiftMechanism;
		lift->SetIntake(15);
		//lift->SetLift(1);
	}

	/**Disabled Init is called whenever the robot is disabled. If something should be killed
	 * when the robot is disabled do it here. Usually you don't use this.**/
	void DisabledInit() override {
		delete[] stick;
	}

	void DisabledPeriodic() override {
		//DO NOT PUT ANYTHING IN HERE THAT MOVES WHEN THE ROBOT IS DISABLED IT NEEDS TO BE STILL.
	}


	void AutonomousInit() override {
	}

	void AutonomousPeriodic() override {
	}

	/**Teleop is the period of time that we mortals control the robot. This is done through any sort of control mechanism we want.
	 * The catch? You actually have to program stuff.**/
	void TeleopInit() override {
		stick = new Joystick(0);
	}

	void TeleopPeriodic() override {

		drive->drive(stick->GetX(), stick->GetY(), stick->GetTwist());

		if (stick->GetButton(1) ){
			lift->Intake(.5);
		} else if (stick->GetButton(2) ) {
			lift->Intake(-.5);
		} else {
			lift->Intake(0);
		}

		if (stick->GetPOV(0) == 0) {
			lift->Lift(.1);
		} else if (stick->GetPOV(0) == 180) {
			lift->Lift(-.1);
		} else {
			lift->Lift(0);
		}
	}

	void TestInit() override {
	}

	void TestPeriodic() override {
	}

};

START_ROBOT_CLASS(Robot)
