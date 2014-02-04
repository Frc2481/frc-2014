#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "CSVRecord.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	
	virtual void RobotInit() {
		CommandBase::init();
		autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();
	}
	
	virtual void AutonomousInit() {
		autonomousCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		autonomousCommand->Cancel();
	}
	
	virtual void TeleopPeriodic() {
//		double timeBefore = GetTime();
		Scheduler::GetInstance()->Run();
//		printf("%f \r\n", GetTime()-timeBefore);
		Wait(0.003);
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
	
	virtual void DisabledInit() {
		CSVRecord::getInstance().CloseFile();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

