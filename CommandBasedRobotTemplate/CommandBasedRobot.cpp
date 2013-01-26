#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/ShifterUpdateCommand.h"
#include "Commands/ExampleAutonomous.h"
#include "Commands/ShiftUpCommand.h"
#include "Commands/ShiftDownCommand.h"

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

