#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/ShifterUpdateCommand.h"

#include "Commands/FullyExtendArmCommand.h"
#include "Commands/FullyRetractArmCommand.h"
#include "Commands/FirstRungPositionArmCommand.h"
#include "Commands/LatchCommand.h"
#include "Commands/UnlatchCommand.h"
#include "Commands/SafeUnlatchCommand.h"
#include "Commands/LiftRobotCommand.h"
#include "Commands/LowerRobotCommand.h"
#include "Commands/ClimbingCommandGroup.h"
#include "Commands/AutonomousCommandGroup.h"
#include "Commands/UpdateLightsCommand.h"
#include "Commands/SetLightsCommand.h"
#include "Commands/AutoFireCommandGroup.h"
#include "Commands/TipDetectionCommand.h"
#include "Commands/TurningTestCommand.h"
#include "Commands/AutonomousFireBackRightCorner.h"
#include "Commands/AutonomousBackReturnFire.h"
#include "Commands/AutonomousCommandGroupNoBack.h"
#include "Commands/AutonomousBackNoFire.h"
#include "Commands/AutonomousNoFireBackLeftCorner.h"
#include "Commands/AutonomousNoFireBackRightCorner.h"

class CommandBasedRobot : public IterativeRobot {
private:
	Command *autonomousCommand;
	ShifterUpdateCommand *shifterUpdateCommand;
	LiveWindow *lw;
	CommandGroup *autoCommand;
	SendableChooser *autoOptions;
	//SendableChooser *allianceColour;
	UpdateLightsCommand *updateLightsCommand;
	SetLightsCommand *autoLightsCommand;
	SetLightsCommand *teleLightsCommand;
	LowerRobotCommand *lowerRobotCommand;
	TipDetectionCommand *tipDetection;
	
	virtual void RobotInit() {
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		shifterUpdateCommand = new ShifterUpdateCommand();
		autoLightsCommand = new SetLightsCommand(1,1,0);
		autoOptions = new SendableChooser();
		autoOptions->AddDefault("Middle - Fire 3 back up", new AutonomousCommandGroup());
		autoOptions->AddObject("Middle - Fire 3 - no back", new AutonomousNoBack());
		autoOptions->AddObject("Middle - No Fire - Back Up", new AutonomousBackNoFire);
		autoOptions->AddObject("Right Corner - Fire 3 - Back & Turn", new AutonomousFireBackRightCorner());
		autoOptions->AddObject("Right Corner - No Fire - Back & Turn", new AutonomousNoFireBackRightCorner());
		autoOptions->AddObject("Left Corner - No Fire - Back & Turn", new AutonomousNoFireBackLeftCorner());
		SmartDashboard::PutData("Autonomous Delay Options", autoOptions);
		/*allianceColour->AddDefault("auto", (void*)0);
		allianceColour->AddObject("red", (void*)1);
		allianceColour->AddObject("green", (void*)2);
		allianceColour->AddObject("blue", (void*)3);
		allianceColour->AddObject("yellow", (void*)4);
		allianceColour->AddObject("purple", (void*)5);
		allianceColour->AddObject("teal", (void*)6);
		allianceColour->AddObject("white", (void*)7);
		SmartDashboard::PutData("Alliance Colour", allianceColour);*/
		SmartDashboard::PutData("ShifterUpdateCommand", new ShifterUpdateCommand());
		SmartDashboard::PutData(CommandBase::driveTrain);
		SmartDashboard::PutData("AutoFireCommandGroup", new AutoFireCommandGroup());
		//SmartDashboard::PutData(CommandBase::climbingArm);
		//SmartDashboard::PutData("FullyExtendArmCommand", new FullyExtendArmPositionCommand());
		//SmartDashboard::PutData("FullyRetractArmCommand", new FullyRetractArmPositionCommand());
		//SmartDashboard::PutData("FirstRungPositionArmCommand", new FirstRungArmPositionCommand());
		//SmartDashboard::PutData("StartingPositionArmCommand", new StartingPositionArmCommand());
		SmartDashboard::PutData("LatchCommand", new LatchCommand());
		//SmartDashboard::PutData("UnlatchCommand", new UnlatchCommand());
		SmartDashboard::PutData("LiftRobotCommand", new LiftRobotCommand());
		SmartDashboard::PutData("LowerRobotCommand", new LowerRobotCommand());
		SmartDashboard::PutData("ClimbingCommandGroup", new ClimbingCommandGroup());
		//SmartDashboard::PutData("Shooter", CommandBase::shooter);
		//SmartDashboard::PutData("SafeUnlatch", new SafeUnlatchCommand());
		//lw->AddActuator("Shooter", "Shooter", CommandBase::shooter);
		SmartDashboard::PutData("TurningTestCommand", new TurningTestCommand);
		SmartDashboard::PutData("AutoFireBackRightCorner", new AutonomousFireBackRightCorner());
		SmartDashboard::PutData("AutoBackReturnFire", new AutonomousBackReturnFire);
		updateLightsCommand = new UpdateLightsCommand(0);
		teleLightsCommand = new SetLightsCommand(1,0,0);
		lowerRobotCommand = new LowerRobotCommand();
		autoCommand = 0;
		tipDetection = new TipDetectionCommand();
	}
	
	virtual void AutonomousInit() {
		autoCommand = (CommandGroup*)autoOptions->GetSelected();
		autoCommand->Start();
		autoLightsCommand->Start();
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
		CommandBase::driveTrain->Periodic();
		Wait(0.005);
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autoCommand){
			autoCommand->Cancel();
		}
		teleLightsCommand->Start();
		tipDetection->Start();
		//updateLightsCommand = new UpdateLightsCommand(0);//(int)allianceColour->GetSelected());
		//updateLightsCommand->Start();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
		CommandBase::driveTrain->Periodic();
		CommandBase::tipSensor->Periodic();
		SmartDashboard::PutNumber("Accel_Y_Axis", CommandBase::tipSensor->GetYAxis());
		SmartDashboard::PutNumber("Accel_Z_Axis", CommandBase::tipSensor->GetZAxis());
		SmartDashboard::PutNumber("Accel_Z_Axis_Filtered", CommandBase::tipSensor->IsTipped());
		//If this is enabled we can't manually adjust the arm.
		//This is called in absolute arm position commands.
		//CommandBase::climbingArm->run();
		Wait(0.005);
	}
	virtual void DisabledInit(){
		Scheduler::GetInstance()->RemoveAll();
		lowerRobotCommand->Start();
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

