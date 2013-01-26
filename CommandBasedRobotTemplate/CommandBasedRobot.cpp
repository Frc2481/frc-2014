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
		SmartDashboard::PutData(CommandBase::shooter);
		SmartDashboard::PutData("FullyExtendArmCommand", new FullyExtendArmPositionCommand());
		SmartDashboard::PutData("FullyRetractArmCommand", new FullyRetractArmPositionCommand());
		SmartDashboard::PutData("FirstRungPositionArmCommand", new FirstRungArmPositionCommand());
		SmartDashboard::PutData("StartingPositionArmCommand", new StartingPositionArmCommand());
		SmartDashboard::PutData("LatchCommand", new LatchCommand());
		SmartDashboard::PutData("UnlatchCommand", new UnlatchCommand());
		SmartDashboard::PutData("LiftRobotCommand", new LiftRobotCommand());
		SmartDashboard::PutData("LowerRobotCommand", new LowerRobotCommand());
		SmartDashboard::PutData("ClimbingCommandGroup", new ClimbingCommandGroup());
	}
	
	virtual void AutonomousInit() {
		xAutoCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
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
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

