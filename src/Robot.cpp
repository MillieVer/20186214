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
	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";
	std::string m_autoSelected;

	MechanumDrive *drive;
	frc::Joystick *stick;
	LiftMechanism *lift;


public:

	void RobotInit() override {
		m_chooser.AddDefault(kAutoNameDefault, kAutoNameDefault);
		m_chooser.AddObject(kAutoNameCustom, kAutoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
		drive = new MechanumDrive;
		lift = new LiftMechanism;
		drive->threshold = .1;
		drive->setWheels(2,3,1,0);
		drive->setPolarity(-1, 1, 1, -1);
		lift->SetIntake(15);
	}
	void DisabledInit() override {
		delete[] stick;
	}

	void AutonomousInit() override {
		m_autoSelected = m_chooser.GetSelected();
		// m_autoSelected = SmartDashboard::GetString(
		// 		"Auto Selector", kAutoNameDefault);
		std::cout << "Auto selected: " << m_autoSelected << std::endl;

		if (m_autoSelected == kAutoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}
	void AutonomousPeriodic() override {
		if (m_autoSelected == kAutoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void TeleopInit() override {
		stick = new Joystick(0);
		lift->SetIntake(15);
		//lift->SetLift(1);
	}
	void TeleopPeriodic() override {

		//drive->drive(stick->GetX(), stick->GetY(), stick->GetTwist());

		if (stick->GetPOV(0) == 0) {
			lift->Intake(.5);
		} else if (stick->GetPOV(0) == 180) {
			lift->Intake(-.5);
		} else {
			lift->Intake(0);
		}

/**
		if (stick->GetPOV(0) == 0) {
			lift->Lift(.1);
		} else if (stick->GetPOV(0) == 180) {
			lift->Lift(-.1);
		} else {
			lift->Lift(0);
		}
		**/
	}

	void TestInit() override {

	}
	void TestPeriodic() override {}

private:

};

START_ROBOT_CLASS(Robot)
