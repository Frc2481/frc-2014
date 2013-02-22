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

class CommandBasedRobot : public IterativeRobot {
private:
	Command *autonomousCommand;
	ShifterUpdateCommand *shifterUpdateCommand;
	LiveWindow *lw;
	AutonomousCommandGroup *autoCommand;
	SendableChooser *autoDelayOptions;
	//SendableChooser *allianceColour;
	UpdateLightsCommand *updateLightsCommand;
	
	virtual void RobotInit() {
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		shifterUpdateCommand = new ShifterUpdateCommand();
		autoDelayOptions = new SendableChooser();
		autoDelayOptions->AddDefault("no delay", (void*)0);
		autoDelayOptions->AddObject("1 second", (void*)1);
		autoDelayOptions->AddObject("2 seconds", (void*)2);
		autoDelayOptions->AddObject("3 seconds", (void*)3);
		autoDelayOptions->AddObject("4 seconds", (void*)4);
		autoDelayOptions->AddObject("5 seconds", (void*)5);
		SmartDashboard::PutData("Autonomous Delay Options", autoDelayOptions);
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
		updateLightsCommand = new UpdateLightsCommand(0);
		autoCommand = 0;
	}
	
	virtual void AutonomousInit() {
		autoCommand = new AutonomousCommandGroup((int)autoDelayOptions->GetSelected(), true);
		autoCommand->Start();
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
		if (autoCommand){
			autoCommand->Cancel();
		}
		//updateLightsCommand = new UpdateLightsCommand(0);//(int)allianceColour->GetSelected());
		updateLightsCommand->Start();
		shifterUpdateCommand->Start();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
		
		//If this is enabled we can't manually adjust the arm.
		//This is called in absolute arm position commands.
		//CommandBase::climbingArm->run();
		Wait(0.005);
	}
	virtual void DisabledInit(){
		Scheduler::GetInstance()->RemoveAll();
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

