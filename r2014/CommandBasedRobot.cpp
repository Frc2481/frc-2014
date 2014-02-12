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
		SmartDashboard::PutData(CommandBase::shooter);
	}
	
	virtual void AutonomousInit() {
		CommandBase::intake->SetReadySolenoid(true);
		autonomousCommand->Start();
		CommandBase::driveTrain->SetFieldOffset();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		CommandBase::intake->SetReadySolenoid(true);
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
		SmartDashboard::PutNumber("Raw 10 turn Pot", CommandBase::shooter->GetRawPosition());
		SmartDashboard::PutNumber("10 turn Pot", CommandBase::shooter->GetPosition());
		SmartDashboard::PutNumber("Shooter Switch", CommandBase::shooter->GetSwitch());
		SmartDashboard::PutNumber("DistanceSensors", CommandBase::distanceSensors->GetRight());
		SmartDashboard::PutNumber("DistanceToShoot", CommandBase::shooter->GetDistance());
		SmartDashboard::PutNumber("throttle value", CommandBase::oi->GetThrottleStick()->GetRawAxis(4));
		Wait(0.003);
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
	
	virtual void DisabledInit() {
		CSVRecord::getInstance().CloseFile();
	}
	virtual void DisabledPeriodic(){
		SmartDashboard::PutNumber("Raw 10 turn Pot", CommandBase::shooter->GetRawPosition());
		SmartDashboard::PutNumber("10 turn Pot", CommandBase::shooter->GetPosition());
		SmartDashboard::PutNumber("Shooter Switch", CommandBase::shooter->GetSwitch());
		SmartDashboard::PutNumber("DistanceSensors", CommandBase::distanceSensors->GetRight());
		SmartDashboard::PutNumber("DistanceToShoot", CommandBase::shooter->GetDistance());
		SmartDashboard::PutNumber("throttle value", CommandBase::oi->GetThrottleStick()->GetRawAxis(4));
	}
	
};

START_ROBOT_CLASS(CommandBasedRobot);

