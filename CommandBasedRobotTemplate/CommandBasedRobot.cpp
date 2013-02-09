#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/ShifterUpdateCommand.h"
#include "Commands/ExampleAutonomous.h"
#include "Commands/ShiftUpCommand.h"
#include "Commands/ShiftDownCommand.h"

#include "Commands/FullyExtendArmCommand.h"
#include "Commands/FullyRetractArmCommand.h"
#include "Commands/FirstRungPositionArmCommand.h"
#include "Commands/StartingPositionArmCommand.h"
#include "Commands/LatchCommand.h"
#include "Commands/UnlatchCommand.h"
#include "Commands/SafeUnlatchCommand.h"
#include "Commands/LiftRobotCommand.h"
#include "Commands/LowerRobotCommand.h"
#include "Commands/ClimbingCommandGroup.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command *autonomousCommand;
	ShifterUpdateCommand *shifterUpdateCommand;
	LiveWindow *lw;
	ExampleAutonomousCommand *xAutoCommand;
	
	virtual void RobotInit() {
		CommandBase::init();
		autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();
		shifterUpdateCommand = new ShifterUpdateCommand();
		xAutoCommand = new ExampleAutonomousCommand();
		SmartDashboard::PutData("ShifterUpdateCommand", new ShifterUpdateCommand());
		SmartDashboard::PutData("ShiftUp", new ShiftUpCommand());
		SmartDashboard::PutData("ShiftDownCommand", new ShiftDownCommand());
		SmartDashboard::PutData(CommandBase::driveTrain);
		//SmartDashboard::PutData(CommandBase::climbingArm);
		SmartDashboard::PutData("FullyExtendArmCommand", new FullyExtendArmPositionCommand());
		SmartDashboard::PutData("FullyRetractArmCommand", new FullyRetractArmPositionCommand());
		SmartDashboard::PutData("FirstRungPositionArmCommand", new FirstRungArmPositionCommand());
		SmartDashboard::PutData("StartingPositionArmCommand", new StartingPositionArmCommand());
		SmartDashboard::PutData("LatchCommand", new LatchCommand());
		SmartDashboard::PutData("UnlatchCommand", new UnlatchCommand());
		SmartDashboard::PutData("LiftRobotCommand", new LiftRobotCommand());
		SmartDashboard::PutData("LowerRobotCommand", new LowerRobotCommand());
		SmartDashboard::PutData("ClimbingCommandGroup", new ClimbingCommandGroup());
		SmartDashboard::PutData("Shooter", CommandBase::shooter);
		SmartDashboard::PutData("SafeUnlatch", new SafeUnlatchCommand());
//		SmartDashboard::PutData(CommandBase::shooter);
		//lw->AddActuator("Shooter", "Shooter", CommandBase::shooter);
	}
	
	virtual void AutonomousInit() {
		xAutoCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
		Wait(0.005);
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		xAutoCommand->Cancel();
		shifterUpdateCommand->Start();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
		
		//If this is enabled we can't manually adjust the arm.
		//This is called in absolute arm position commands.
		//CommandBase::climbingArm->run();
		Wait(0.005);
	}
	/*
	virtual void TestInit() {
		
	}
	*/
	
	virtual void TestPeriodic() {
		lw->Run();
		Wait(0.005);
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

