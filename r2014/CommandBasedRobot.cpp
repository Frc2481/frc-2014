#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Robotmap.h"
#include "CSVRecord.h"
#include "Commands/AutoDriveShootCommandGroup.h"
#include "Commands/IncWheelAngleCommand.h"
#include "Commands/DecWheelAngleCommand.h"
#include "Commands/SetEncoderOffsetCommand.h"
#include "Commands/OptimizeSwerveCommand.h"
#include "Commands/AutoDriveShootHotCommandGroup.h"
#include "Commands/AutoTwoBallCommandGroup.h"
#include "Commands/AutoDriveShootCornerCommandGroup.h"
#include "Components/CurrentMonitor.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *autoOptions;
	CommandGroup *autoCommand;
	CurrentMonitor *currentMonitor;
	
	virtual void RobotInit() {
		CommandBase::init();
		autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();
		currentMonitor = new CurrentMonitor(ULTRASONIC_RIGHT);
		SmartDashboard::PutData(CommandBase::shooter);
		autoOptions = new SendableChooser();
		autoOptions->AddObject("Corner - No Hot", new AutoDriveShootCornerCommandGroup());
		autoOptions->AddObject("Forward + Fire - No Hot", new AutoDriveShootCommandGroup());
		autoOptions->AddDefault("Forward + Fire - Hot", new AutoDriveShootHotCommandGroup());
		autoOptions->AddObject("Two Ball", new AutoTwoBallCommandGroup());
		SmartDashboard::PutData("Autonomous Delay Options", autoOptions);
		autoCommand = 0;
		
		SmartDashboard::PutData("FL Angle + 1", new IncWheelAngleCommand(FLENCODER));
		SmartDashboard::PutData("FR Angle + 1", new IncWheelAngleCommand(FRENCODER));
		SmartDashboard::PutData("BL Angle + 1", new IncWheelAngleCommand(BLENCODER));
		SmartDashboard::PutData("BR Angle + 1", new IncWheelAngleCommand(BRENCODER));
		
		SmartDashboard::PutData("FL Angle - 1", new DecWheelAngleCommand(FLENCODER));
		SmartDashboard::PutData("FR Angle - 1", new DecWheelAngleCommand(FRENCODER));
		SmartDashboard::PutData("BL Angle - 1", new DecWheelAngleCommand(BLENCODER));
		SmartDashboard::PutData("BR Angle - 1", new DecWheelAngleCommand(BRENCODER));

		SmartDashboard::PutData("FL Reset Offset", new SetEncoderOffsetCommand(FLENCODER));
		SmartDashboard::PutData("FR Reset Offset", new SetEncoderOffsetCommand(FRENCODER));
		SmartDashboard::PutData("BL Reset Offset", new SetEncoderOffsetCommand(BLENCODER));
		SmartDashboard::PutData("BR Reset Offset", new SetEncoderOffsetCommand(BRENCODER));
		

		SmartDashboard::PutData("DisableOptimization", new OptimizeSwerveCommand());
	}
	
	virtual void AutonomousInit() {
		CommandBase::intake->SetReadySolenoid(true);
		CommandBase::driveTrain->ResetGyro();
		CommandBase::driveTrain->SetGyroCorrection(true);
		autonomousCommand->Start();
		autoCommand = (CommandGroup*)autoOptions->GetSelected();
		autoCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
//		SmartDashboard::PutNumber("Raw 10 turn Pot", CommandBase::shooter->GetRawPosition());
//		SmartDashboard::PutNumber("10 turn Pot", CommandBase::shooter->GetPosition());
//		SmartDashboard::PutNumber("Shooter Switch", CommandBase::shooter->GetSwitch());
//		SmartDashboard::PutNumber("DistanceSensors", CommandBase::distanceSensors->GetRight() / 12);
//		SmartDashboard::PutNumber("DistanceToShoot", CommandBase::shooter->GetDistance());
//		SmartDashboard::PutNumber("throttle value", 16- (((CommandBase::oi->GetThrottleStick()->GetThrottle()) + 1) / 2) * 16);

		SmartDashboard::PutBoolean("HotTarget", CommandBase::camera->HasTarget());
		SmartDashboard::PutNumber("Current ", currentMonitor->GetScaledAmps());
		Scheduler::GetInstance()->Run();
		CommandBase::shooter->Periodic();
	}
	
	virtual void TeleopInit() {
		CommandBase::intake->SetReadySolenoid(true);
		CommandBase::driveTrain->SetGyroCorrection(false);
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		autonomousCommand->Cancel();
		//CommandBase::driveTrain->ResetGyro();
		//CommandBase::driveTrain->SetGyroCorrection(true);
	}
	
	virtual void TeleopPeriodic() {
		
//		double timeBefore = GetTime();
		Scheduler::GetInstance()->Run();
////		printf("%f \r\n", GetTime()-timeBefore);
//		SmartDashboard::PutNumber("Raw 10 turn Pot", CommandBase::shooter->GetRawPosition());
//		SmartDashboard::PutNumber("10 turn Pot", CommandBase::shooter->GetPosition());
//		SmartDashboard::PutNumber("Shooter Switch", CommandBase::shooter->GetSwitch());
//		SmartDashboard::PutNumber("DistanceSensors", CommandBase::distanceSensors->GetRight() / 12);
//		SmartDashboard::PutNumber("DistanceToShoot", CommandBase::shooter->GetDistance());
//		SmartDashboard::PutNumber("throttle value", 16 - (((CommandBase::oi->GetThrottleStick()->GetThrottle()) + 1) / 2) * 16);

		SmartDashboard::PutBoolean("HotTarget", CommandBase::camera->HasTarget());
		SmartDashboard::PutNumber("Current ", currentMonitor->GetScaledAmps());
		CommandBase::shooter->Periodic();
		
		Wait(0.003);
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
	
	virtual void DisabledInit() {
		CSVRecord::getInstance().CloseFile();
	}
	virtual void DisabledPeriodic(){
//		SmartDashboard::PutNumber("Raw 10 turn Pot", CommandBase::shooter->GetRawPosition());
//		SmartDashboard::PutNumber("10 turn Pot", CommandBase::shooter->GetPosition());
//		SmartDashboard::PutNumber("Shooter Switch", CommandBase::shooter->GetSwitch());
//		SmartDashboard::PutNumber("DistanceSensors", CommandBase::distanceSensors->GetRight() / 12);
//		SmartDashboard::PutNumber("DistanceToShoot", CommandBase::shooter->GetDistance());
//		SmartDashboard::PutNumber("throttle value", 16- (((CommandBase::oi->GetThrottleStick()->GetThrottle()) + 1) / 2) * 16);

		SmartDashboard::PutBoolean("HotTarget", CommandBase::camera->HasTarget());
		CommandBase::camera->HasTarget();
	}
	
};

START_ROBOT_CLASS(CommandBasedRobot);

