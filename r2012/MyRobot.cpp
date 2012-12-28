#include "WPILib.h"
#include "Vision/RGBImage.h"
#include "Vision/BinaryImage.h"
#include "MyRobot.h"
#include "DashboardDataSender.h"
#include "RoEncoder.h"
#include "BallManager.h"
#include <string>
#include "ROAutoSwitch.h"
//#include "SpeedLookup.h"

//!!!!SET THIS TO FALSE DURING COMPETITION!!!!!
#define TUNE_PID false

#define MINIMUM_SCORE 			0.01
#define ENCODER_RANGE_MIN 		0
#define ENCODER_RANGE_MAX 		48
#define SHOOTER_RANGE_MIN   	0
#define SHOOTER_RANGE_MAX   	1
#define ENCODER_P				0.28
#define ENCODER_I				0.03
#define ENCODER_D				0.001
#define ENCODER_PERIOD			0.1
#define ENCODER_PULSE_PER_REV	3
#define ENCODER_P_LAYUP			0.1
#define ENCODER_I_LAYUP			0.013
#define ENCODER_D_LAYUP			0.001
#define TOGGLE_TIMER_DURATION	3.0
#define SLOW_DRIVE_SPEED		0.50

//RPM
#define SHOOTER_TOLERANCE 		30.0	

//double outputValue;

const char inputShape[255] = {0,0,0,0,0,0,0,0,0,0,12,13,15,16,17,18,19,21,22,23,24,25,27,28,29,30,31,
	        33,34,35,36,37,38,40,41,42,43,44,46,47,48,49,50,52,53,54,55,56,58,59,60,61,62,
	        64,65,66,67,68,70,71,72,73,74,76,77,78,79,80,82,83,84,85,86,88,89,90,91,92,94,
	        95,96,97,98,100,101,102,103,104,106,107,108,109,110,112,113,114,115,116,117,
	        118,119,120,121,121,122,123,123,124,124,125,125,125,126,126,126,126,126,127,
	        127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
	        128,128,128,128,128,129,129,129,130,130,131,131,132,133,133,134,135,136,
	        137,138,139,140,141,142,144,145,146,147,148,150,151,152,153,154,156,157,158,
	        159,160,162,163,164,165,166,168,169,170,171,172,174,175,176,177,178,180,181,
	        182,183,184,186,187,188,189,190,192,193,194,195,196,198,199,200,201,202,204,
	        205,206,207,208,210,211,212,213,214,216,217,218,219,220,221,223,224,225,226,
	        227,229,230,231,232,233,235,236,237,238,239,241,242,243,255,255,255,255,255,
	        255,255,255,255,255};
/*
const char inputShape[255] = {0,1,3,4,5,6,7,9,10,11,12,13,15,16,17,18,19,21,22,23,24,25,27,28,29,30,31,
	        33,34,35,36,37,38,40,41,42,43,44,46,47,48,49,50,52,53,54,55,56,58,59,60,61,62,
	        64,65,66,67,68,70,71,72,73,74,76,77,78,79,80,82,83,84,85,86,88,89,90,91,92,94,
	        95,96,97,98,100,101,102,103,104,106,107,108,109,110,112,113,114,115,116,117,
	        118,119,120,121,121,122,123,123,124,124,125,125,125,126,126,126,126,126,127,
	        127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
	        128,128,128,128,128,129,129,129,130,130,131,131,132,133,133,134,135,136,
	        137,138,139,140,141,142,144,145,146,147,148,150,151,152,153,154,156,157,158,
	        159,160,162,163,164,165,166,168,169,170,171,172,174,175,176,177,178,180,181,
	        182,183,184,186,187,188,189,190,192,193,194,195,196,198,199,200,201,202,204,
	        205,206,207,208,210,211,212,213,214,216,217,218,219,220,221,223,224,225,226,
	        227,229,230,231,232,233,235,236,237,238,239,241,242,243,244,245,247,248,249,
	        250,251,253,254,255};
*/
float InputShape(float userValue)
	{
		int iUserValue;

		iUserValue = (int)(userValue * 127);
		iUserValue += 127;
		iUserValue = inputShape[iUserValue];
		userValue = iUserValue - 127;
		userValue /= 127;
		return userValue;
	}

class RobotDemo : public SimpleRobot {
	AxisCamera *camera;
	RobotDrive *base;
	Joystick *stick;
	Joystick *stickAux;
	Gyro *gyro;
	DashboardDataSender *dds;
	AnalogChannel *depressorChannel;
	AnalogChannel *angleAdjustChannel;
	Servo *roCamPan;
	Servo *roCamTilt;
	Jaguar *shooterRight;
	Jaguar *shooterLeft;
	Jaguar *bridgeDepressor;
	//Jaguar *lift;
	//Jaguar *intakeRoller;
	Jaguar *shooterAdjust;
	RoEncoder *encoderShooter;
	//RoEncoder *encoderLeft;
	DriverStationLCD *userMessage;
	PIDController *shooterRightPID;
	PIDController *shooterLeftPID;
	BallManager *ballManager;
	Timer autonomousTimer;
	Timer mTimer;
	ROAutoSwitch *AutoSwitch;
	float shooterSpeed;
	float shooterPWM;
	bool previousAButtonState;
	bool previousBButtonState;
	bool previousXButtonState;
	bool previousYButtonState;
	BridgeDepressorStateEnum bridgeDepressorState;
	ShooterAdjustStateEnum shooterAdjustState;
	AutonomousStateEnum autonomousState;
	int speedCounter;
	bool prevSens;
	bool prevBridgeBttn;
	bool currentBridgeBttn;
	bool shooterIsOff;
	float startTime;
	bool currentShooterToggle;
	bool prevShooterToggle;
	float shooterAdjustValue;
	float currentTime;
	int minTime;
	int maxTime;
	float maxTimeValue;
	bool prevFwdAdjBtnState;
	bool prevBwdAdjBtnState;
	bool prevShooterAdjBtnState;
	bool prevLayupBtnState;
	bool onTargetValues[ON_TARGET_DEBOUNCE];
	int onTargetDebounceSum;
	//float onTargetTimerAuto;
	//bool onTargetPrevAuto;
	//Jaguar *testJag;
	float p, i, d, per;
	int PID;
	int autonBallCount;
	float delayTime;
	float prevShooterSpeed;
	float toggleTimer;
	bool cameraToggle;
	bool currentCameraBttn;
	bool prevCameraBttn;
	
public:
	RobotDemo(void) {
		// initialize all variables
		base = new RobotDrive(	PWM_RIGHT_DRIVE,
								PWM_LEFT_DRIVE );
		base->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
		base->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
		stick = new Joystick(STICK_DRIVER);
		stickAux = new Joystick(STICK_AUX);
		gyro = new Gyro(1,1);
		dds = new DashboardDataSender();
		base->SetExpiration(0.5);
		shooterRight = new Jaguar(PWM_RIGHT_SHOOTER);
		shooterLeft = new Jaguar(PWM_LEFT_SHOOTER);
		encoderShooter = new RoEncoder(	DIO_ENCODER_CH, 
									ENCODER_PULSE_PER_REV );
		//encoderLeft = new RoEncoder(	DIO_BOT_ENCODER_CH);
		userMessage = DriverStationLCD::GetInstance();
		shooterRightPID = new PIDController(	ENCODER_P,  
											ENCODER_I, 
											ENCODER_D, 
											encoderShooter, 
											shooterRight, 
											ENCODER_PERIOD	);
		shooterRightPID->SetInputRange(ENCODER_RANGE_MIN, ENCODER_RANGE_MAX);
		shooterRightPID->SetOutputRange(SHOOTER_RANGE_MIN, SHOOTER_RANGE_MAX);
		//TODO set tolerance
		shooterRightPID->SetTolerance(.2);
		shooterRightPID->Disable();
		previousAButtonState = stick->GetRawButton(1);
		previousBButtonState = stick->GetRawButton(2);
		previousXButtonState = stick->GetRawButton(3);
		previousYButtonState = stick->GetRawButton(4);
		//shooterSpeed = 29.16;
		shooterSpeed = 27.5;
		shooterPWM = 0;
		ballManager = new BallManager (	DIO_BALL_BOT_CH, 
										DIO_BALL_TOP_CH,
										DIO_BALL_MID_CH,
										PWM_BALL_MNGR_INTAKE,
										PWM_BALL_MNGR_LIFT);
		bridgeDepressor = new Jaguar (PWM_BRDG_DPRSSR);
		angleAdjustChannel = new AnalogChannel (ANA_ANGLE_ADJUST);
		depressorChannel = new AnalogChannel (ANA_BRDG_DPRSSR);
		AutoSwitch = new ROAutoSwitch(6);
		bridgeDepressorState = TOP;
		shooterAdjustState = KEY;
		autonomousState = INIT;
		//intakeRoller = new Jaguar (PWM_BALL_MNGR_INTAKE);
		//lift = new Jaguar (PWM_BALL_MNGR_LIFT);
		shooterAdjust = new Jaguar (PWM_SHOOTER_ADJUST);
		speedCounter = 0;
		prevSens = false;
		prevBridgeBttn = false;
		currentBridgeBttn = false;
		currentShooterToggle = false;
		prevShooterToggle = false;
		startTime = 0;
		shooterIsOff = true;
		shooterAdjustValue = 0;
		currentTime = 0;
		minTime = 0;
		maxTime = 0;
		maxTimeValue = 0;
		prevFwdAdjBtnState = false;
		prevBwdAdjBtnState = false;
		prevShooterAdjBtnState = false;
		for (int t = 0; t < ON_TARGET_DEBOUNCE; t++) onTargetValues[t] = 0;
		onTargetDebounceSum = 0;
		//onTargetTimerAuto = 0;
		//onTargetPrevAuto = 0;
		//testJag = new Jaguar (1);
		p = ENCODER_P;
		i = ENCODER_I;
		d = ENCODER_D;
		per = ENCODER_PERIOD;
		PID = 4;
		autonBallCount = 0;
		delayTime = 2;
		prevShooterSpeed = shooterSpeed;
		toggleTimer = 0;
		autonomousTimer.Start();
		mTimer.Start();
		cameraToggle = false;
		currentCameraBttn = false;
		prevCameraBttn = false;
		
	}
	void GyroBalanceUpdate(){
		if (abs((int)gyro->GetAngle()) > 10) {
			base->SetLeftRightMotorOutputs(gyro->GetAngle()/10 - 10,gyro->GetAngle()/10 - 10);
		}
	}
	
	void CameraSelectUpdate () {
		currentCameraBttn = stickAux->GetRawButton(BTN_CAM_TOGGLE);
		if (currentCameraBttn && (currentCameraBttn != prevCameraBttn)) {
			cameraToggle = !cameraToggle;
		}
		prevCameraBttn = currentCameraBttn;
	}

	void ShooterAdjustUpdate() {
		/*if (stickAux->GetRawAxis(2) < -.25) {
			shooterAdjust->Set(AUX_SPEED_BACKWARD);
		}
		else if (stickAux->GetRawAxis(2) > .25) {
			shooterAdjust->Set(AUX_SPEED_FORWARD);
		}
		else {
			shooterAdjust->Set(0);
		}*/
		
		/*if (angleAdjustChannel->GetVoltage() < SHOT_ADJUST_KEY_VLTG - 0.05) {
			shooterAdjust->Set(AUX_SPEED_BACKWARD);
		}
		else if(angleAdjustChannel->GetVoltage() > SHOT_ADJUST_KEY_VLTG + 0.05){
			shooterAdjust->Set(AUX_SPEED_FORWARD);
		}
		else {
			shooterAdjust->Set(0);
			//shooterAdjust->Disable();
		}*/
		
	
	}
	
	void BridgeDepressorUpdate() {
		/*
		// set the state of the bridge to down
		if (stick->GetRawButton(BTN_BRDG_DWN)) {
			bridgeDepressorState = LOWERING;
		}
		// set the state of the bridge to up
		else if (stick->GetRawButton(BTN_BRDG_UP)) {
			bridgeDepressorState = RAISING;
		*/
		currentBridgeBttn = stick->GetRawButton(BTN_BRDG_UP);
		if (currentBridgeBttn && (currentBridgeBttn != prevBridgeBttn)) {
			if ((bridgeDepressorState == TOP) || (bridgeDepressorState == RAISING)) {
				bridgeDepressorState = LOWERING;
			}
			else if ((bridgeDepressorState == BOT) || (bridgeDepressorState == LOWERING)) {
				bridgeDepressorState = RAISING;
			}
		}
		prevBridgeBttn = currentBridgeBttn;
		// if we are raising the bridge
		if (bridgeDepressorState == RAISING) {
			// and we are not at the top raise the bridge
			if (depressorChannel->GetVoltage() < BRDG_UP_VLTG) {
				bridgeDepressor->Set(BRDG_SPEED_BACKWARD);
			}
			// otherwise stop
			else{
				bridgeDepressor->Set(0);
				bridgeDepressorState = TOP;
			}
		}
		// if we are lowering the bridge
		else if (bridgeDepressorState == LOWERING) {
			// and we are not at the bottom lower bridge
			if (depressorChannel->GetVoltage() > BRDG_DWN_VLTG) {
				bridgeDepressor->Set(BRDG_SPEED_FORWARD);
			}
			// otherwise stop
			else{
				bridgeDepressor->Set(0);
				bridgeDepressorState = BOT;
			}
		}
		// if we think we are at the top
		else if (bridgeDepressorState == TOP) {
			// and we really aren't then raise the bridge
			if (depressorChannel->GetVoltage() < BRDG_UP_VLTG  - .5) {
				bridgeDepressorState = RAISING;
			}
		}
		// if we think we are at the bottom
		else if (bridgeDepressorState == BOT) {
			// and we really aren't then lower the bridge
			if (depressorChannel->GetVoltage() > BRDG_DWN_VLTG  + .5) {
				bridgeDepressorState = LOWERING;
			}
		} 	
	}

	/**
	 * Camera Image Processing
	 * 
	 */

	float CalculateDistanceToTarget (void) {
		/*if (stickAux->GetRawButton(3) && previousAButtonState != stickAux->GetRawButton(1)) {	
		} else {
			return 0.0;
		}*/
		//previousXButtonState = stickAux->GetRawButton(3);
		
		if (camera->IsFreshImage()) {

			// Get the camera image
			ColorImage *image = camera->GetImage();
			
			//Apply color threshold to image from camera.  May have to adjust hreshold in MyRobot.h
			BinaryImage *thresholdImage = image->ThresholdRGB(threshold);
			
			//Remove small blobs of pixels from image.
			BinaryImage *bigObjectsImage = thresholdImage->RemoveSmallObjects(false, 2);
			
			//Apply convex hull to make rectangles solid.
			BinaryImage *convexHullImage = bigObjectsImage->ConvexHull(false);
			
			//Apply particle filter with the specs of our rectangles.
			BinaryImage *filteredImage = convexHullImage->ParticleFilter(criteria, 2);
			
			//Retrieve the particle analysis for each rectangle in the image. 
			vector<ParticleAnalysisReport> *reports = filteredImage->GetOrderedParticleAnalysisReports();
			
			//Check for no rectangles
			if (reports->size() == 0) {
				return -1;
			}
			
			//TODO:
			//Process ParticleAnalysisReport
			
			/*for (unsigned i = 0; i < reports->size(); i++) {
				ParticleAnalysisReport *topReport = &(reports->at(i));
				widthString.append((char*)topReport->boundingRect.width);
				widthString.append(" ");
			}*/
			
			userMessage->Printf(DriverStationLCD::kUser_Line1,1, "%d", reports->size());
			
			//Unallocate all dynimically allocated memory.
			delete reports;
			delete filteredImage;
			delete convexHullImage;
			delete bigObjectsImage;
			delete thresholdImage;
			delete image;
		}

		return 0;
	}

	void ShooterUpdate (double systemTime) {
		
		//Get distance to target.
		//TODO:			
		
		//Calculate Wheel Speed
		//TODO:

		if(stickAux->GetRawButton(5) && stickAux->GetRawButton(5) != prevLayupBtnState){
			prevShooterSpeed = shooterSpeed;
			shooterSpeed = SHOOTER_SPEED_LAYUP;
			delayTime = 1;
		}
		else if (!stickAux->GetRawButton(5) && stickAux->GetRawButton(5) != prevLayupBtnState){
			shooterSpeed =  prevShooterSpeed;
			//shooterSpeed = SHOOTER_SPEED_KEY;
			delayTime = 2.0;
		}
		
		if (shooterSpeed < 25){
			shooterRightPID->SetPID(ENCODER_P_LAYUP,ENCODER_I_LAYUP,ENCODER_D_LAYUP);
		}
		else{
			shooterRightPID->SetPID(ENCODER_P,ENCODER_I,ENCODER_D);	
		}
		
		prevLayupBtnState = stickAux->GetRawButton(5);
		//Ignore this adjustment if we are tunning pid.
		if (!TUNE_PID) {
			if (stickAux->GetRawButton(1) && previousAButtonState != stickAux->GetRawButton(1)) {
				shooterSpeed += 0.25; //increase 30 RPM
			}
			else if (stickAux->GetRawButton(2) && previousBButtonState != stickAux->GetRawButton(2)) {
				shooterSpeed -= 0.25; //decrease 30 RPM
			}
			previousAButtonState = stickAux->GetRawButton(1);
			previousBButtonState = stickAux->GetRawButton(2);
		}
		//previousXButtonState = stickAux->GetRawButton(3);
		previousYButtonState = stickAux->GetRawButton(4);
		//check if our motor speed PID is within range and it wasn't before 
		
		//if left trigger is pulled
		if (stickAux->GetZ() < -.5) {
			
			//shoot only if you have been in range for half of the loops.
			if ((encoderShooter->get() > shooterSpeed - (SHOOTER_TOLERANCE / 60.0)) && 
				(encoderShooter->get() < shooterSpeed + (SHOOTER_TOLERANCE / 60.0))) {
				// wait after the shooter is enabled bofore you fire 
				if (toggleTimer + TOGGLE_TIMER_DURATION < mTimer.Get()){
					ballManager->fire(delayTime);	
				}
			}
			//otherwise queue balls
			else {
				ballManager->queue();
			}
		} //else {
		//	shooterRightPID->Enable();
		//}
		

		//Button 4 toggle shooter on and off
		currentShooterToggle = stickAux->GetRawButton(4);
		if (currentShooterToggle && currentShooterToggle != prevShooterToggle) {
			cameraToggle = shooterIsOff = !shooterIsOff;
			if (!shooterIsOff){
				toggleTimer = mTimer.Get();
				//CalculateDistanceToTarget();
			}
		}
		prevShooterToggle = currentShooterToggle;
		
		//Enable or disable based on ShooterIsOff
		if (shooterIsOff) {
			shooterRightPID->Disable();
		} else {
			shooterRightPID->Enable();
		}
		
		shooterRightPID->SetSetpoint(shooterSpeed);
		shooterLeft->Set(-shooterRight->Get());
	}
	
	void TunePid () {
		if (stickAux->GetRawButton(3) && previousXButtonState != stickAux->GetRawButton(3)) {
			PID = (PID == 4) ? 1 : PID + 1; 		
		}
		
		if (stickAux->GetRawButton(1) && previousAButtonState != stickAux->GetRawButton(1)) {
			if (PID == 1) {
				p += .01;
			} else if (PID == 2) {
				i += .001;
			} else if (PID == 3) {
				d += .0001;
			} else if (PID == 4) {
				shooterSpeed += 0.5; //increase 30 RPM
			}
		}
		
		else if (stickAux->GetRawButton(2) && previousBButtonState != stickAux->GetRawButton(2)) {
			if (PID == 1) {
				p -= .01;
			} else if (PID == 2) {
				i -= .001;
			} else if (PID == 3) {
				d -= .0001;
			}else if (PID == 4) {
				shooterSpeed -= 0.5; //increase 30 RPM
			}
		}
		//shooterRightPID->SetPID(p,i,d);
			
		previousAButtonState = stickAux->GetRawButton(1);
		previousBButtonState = stickAux->GetRawButton(2);
		previousXButtonState = stickAux->GetRawButton(3);
		//previousYButtonState = stickAux->GetRawButton(4);
	}
	
	/**
	 * Main test program in operator control period.
	 * Aquires images from the camera and determines if they match FRC targets.
	 */
	void OperatorControl(void) {

		float lx, ly, rx, ry, rightAdjust, leftAdjust;
						
		
		// Create and set up a camera instance. first wait for the camera to start
		// if the robot was just powered on. This gives the camera time to boot.
		//printf("Getting camera instance\n");
		
		/*camera = &AxisCamera::GetInstance("10.24.81.11");
		//printf("Setting camera parameters\n");
		camera->WriteResolution(AxisCamera::kResolution_320x240);
		camera->WriteCompression(30);
		//camera->WriteBrightness(0);
		// set sensitivity for the 2010 kit gyro
		//gyro->SetSensitivity(0.007);*/

		// set MotorSafety expiration
		//base->SetExpiration(1.0);

		// loop getting images from the camera and finding targets
		printf("Starting operator control loop\n");
		Timer timer;
		timer.Start();
		
		base->SetSafetyEnabled(true);
		gyro->Reset();
		speedCounter = 0;
		startTime = timer.Get();
		shooterRightPID->Enable();
		
		while (IsOperatorControl())
		{
			userMessage->Clear();
			/*if (encoderShooter->getIO() != prevSens && encoderShooter->getIO())
				speedCounter++;
			
			prevSens = encoderShooter->getIO();*/
			
			/*if(stickAux->getRawButton(BTN_TOP_BANK)== 1){
				
			}
			else if(stickAux->getRawButton(BTN_TOP_SWISH)== 1){
				
			}
			else if(stickAux->getRawButton(BTN_MID_BANK)== 1){
				
			}
			else if(stickAux->getRawButton(BTN_MID_SWISH)== 1){
				
			}*/
			
			/*Temporarily used to adjust the speed of the shooter wheel manually.
			 * Previous[]ButtonState is used to debounce the buttons to only increment
			 * by .025
			if (stick->GetRawButton(1) && previousAButtonState != stick->GetRawButton(1)){
				shooterPWM += .025;
			}
			else if (stick->GetRawButton(2) && previousBButtonState != stick->GetRawButton(2)){
				shooterPWM -= .025;
			}
			previousAButtonState = stick->GetRawButton(1);
			previousBButtonState = stick->GetRawButton(2);
			previousXButtonState = stick->GetRawButton(3);
			previousYButtonState = stick->GetRawButton(4);
			shooterRight->Set(-shooterPWM);
			shooterLeft->Set(shooterPWM);
			End Temp Manual Shooter code*/
			
			// If user presses right trigger (Z axis < 0), start ball intake

			if (stick->GetZ() < -.5)
				ballManager->setIntake(1);
			else
				ballManager->setIntake(0);
			
			if (stickAux->GetRawButton(7)) {
				ballManager->vomit();
			}
			if (stickAux->GetRawButton(6)){
				ballManager->queue();
			}
			if (stickAux->GetRawButton(8)) {
				ballManager->resetBalls();
			}
			// Update ball angle adjustment per user input
			ShooterAdjustUpdate();
			
			//Update Bridge Depressor
			BridgeDepressorUpdate();
			
			//Update shooter speed
			ShooterUpdate(timer.Get()); 
			
			//if () {
				//CalculateDistanceToTarget();
			//}
			
			ballManager->update();
				
			//Zero the gyro.
			if (stick->GetRawButton(3)) {
				gyro->Reset();
			}
			
			//If button 4 is presson drivers stick then balance with gyro.
			if (stick->GetRawButton(4)) {
				GyroBalanceUpdate();
			}
			//Drive normally with tank.
			else {
				//base->TankDrive(InputShape(stick->GetRawAxis(2)), InputShape(stick->GetRawAxis(5)));
				//Add the ABS of the X axis to the input value. 
				
				//scale x axies by 100 then abs then divide by 100. 
				lx = (float)abs((int)(100 * stick->GetRawAxis(1))) / 100.0; 
				rx = (float)abs((int)(100 * stick->GetRawAxis(4))) / 100.0;
				
				ly = InputShape(stick->GetRawAxis(2)); 
				ry = InputShape(stick->GetRawAxis(5));
				
				//Adjust y axies by abs of x based on if y is - or +
				leftAdjust = ( ly < 0 ) ? (ly + ( -1 * lx ) ) : ( ly + lx );
				rightAdjust = ( ry < 0 ) ? (ry + ( -1 * rx ) ) : ( ry + rx );
				userMessage->Printf(DriverStationLCD::kUser_Line2,1,"%f %f", leftAdjust, rightAdjust);
				leftAdjust += (InputShape(stickAux->GetRawAxis(2)) * 0.75);
				rightAdjust += (InputShape(stickAux->GetRawAxis(5)) * 0.75);
				
				userMessage->Printf(DriverStationLCD::kUser_Line3,1,"%f %f", leftAdjust, rightAdjust);
				
				base->TankDrive(leftAdjust, rightAdjust);
				//base->TankDrive(stick->GetRawAxis(2) + abs(stick->GetRawAxis(1)),
				//				stick->GetRawAxis(5) + abs(stick->GetRawAxis(4)));
			}
			CameraSelectUpdate();
			DashBoardUpdater();
			
			
			
			
			
			//printf("Time: %f\n", 1.0 / timer.Get());
			
			currentTime = timer.Get() - startTime;
			
			if (currentTime > maxTimeValue) {
				maxTimeValue = currentTime;
			}
			
			if (currentTime > .001) {
				maxTime++;
			}
			else if (currentTime < .0003) {
				minTime++;
			}
			
			encoderShooter->update();
			

			
			userMessage->Printf(DriverStationLCD::kUser_Line2,1,"adj: %f", angleAdjustChannel->GetVoltage());
			
			//userMessage->Printf(DriverStationLCD::kUser_Line4,1,"%d", shooterRightPID->OnTarget());
			//userMessage->Printf(DriverStationLCD::kUser_Line5,1,"%f %f", stick->GetRawAxis(2), stick->GetRawAxis(5));
			//userMessage->Printf(DriverStationLCD::kUser_Line4,1,"%f", (float)encoderShooter->get());
			//userMessage->Printf(DriverStationLCD::kUser_Line5,1,"%d", speedCounter);
			//userMessage->Printf(DriverStationLCD::kUser_Line5,1,"%f", angleAdjustChannel->GetVoltage());
			//currentTime = timer.Get() - startTime;
			
			
			if (TUNE_PID) {
				TunePid ();
				userMessage->Printf(DriverStationLCD::kUser_Line1,1,"p: %f    %d", shooterRightPID->GetP(), PID);
				//userMessage->Printf(DriverStationLCD::kUser_Line2,1,"i: %f", shooterRightPID->GetI());
				//userMessage->Printf(DriverStationLCD::kUser_Line3,1,"d: %f", shooterRightPID->GetD());
				userMessage->Printf(DriverStationLCD::kUser_Line4,1,"per: %f", per);
				userMessage->Printf(DriverStationLCD::kUser_Line5,1,"%f %1.2f %1.2f", (shooterSpeed * 60), ((float)encoderShooter->get()) * 60, shooterPWM);
			} else { 
				
				userMessage->Printf(DriverStationLCD::kUser_Line5,1,"%f %1.2f %1.2f", (shooterSpeed * 60), ((float)encoderShooter->get()) * 60, shooterPWM);
				//userMessage->Printf(DriverStationLCD::kUser_Line5,1,"%1.2f %1.2f %1.2f %1.2f", lx, ly, rx, ry);
				//userMessage->Printf(DriverStationLCD::kUser_Line5,1,"%f %1.2f %1.2f", (shooterSpeed * 60), ((float)encoderShooter->get()) * 60, shooterPWM);
				//userMessage->Printf(DriverStationLCD::kUser_Line2,1,"adj: %f", angleAdjustChannel->GetVoltage());
				//userMessage->Printf(DriverStationLCD::kUser_Line3,1,"%d", bridgeDepressorState);
			}
			
			userMessage->Printf(DriverStationLCD::kUser_Line4,1,"%d %d", AutoSwitch->GetDelay(),AutoSwitch->GetMode());

			
			
			if (currentTime > maxTimeValue) {
				maxTimeValue = currentTime;
			}
						
			if (currentTime > .001) {
				maxTime++;
			}
			else if (currentTime < .0003) {
				minTime++;
			}
		
			userMessage->Printf(DriverStationLCD::kUser_Line6,1,"%f %d %d %f", currentTime, minTime, maxTime, maxTimeValue);
			
			Wait(.002);
			
			startTime = timer.Get();
			userMessage->UpdateLCD();
		}
	}
	void Autonomous() {
		//Timer autoTimer;
			
		//shooterSpeed = beastAlgorithm->calculate(CalculateDistanceToTarget(), BeastAlgorithm::Top_Bank, 0);
		
		shooterSpeed = 30.33;
		shooterRightPID->SetSetpoint(shooterSpeed);
		shooterLeft->Set(-shooterRight->Get());
		
		int delayTime = (AutoSwitch->GetDelay() == 0) ? 0 : AutoSwitch->GetDelay() + 3;
		int timeState = AutoSwitch->GetMode();
		//int delayTime = 2;
		//int timeState = 2;
		float backupTime;
		float fireTime;
		float rotateTime;
		float forwardTime;
		
		//middle front 
		if(timeState ==  0){
			fireTime = 6;
			backupTime = 0;
			rotateTime = 0;
			forwardTime = 0;
			shooterSpeed = 1750 / 60.0;	
		}
		//middle front and bridge
		else if(timeState ==  1){
			fireTime = 4;
			backupTime = 1;
			rotateTime = 2.4;
			forwardTime = 2.7;
			shooterSpeed = 1750 / 60.0;			
		}
		//middle back
		else if(timeState ==  2){
			fireTime = 6;
			backupTime = 0;
			rotateTime = 0;
			forwardTime = 0;
			shooterSpeed = 1900 / 60.0;
		}
		//middle back and bridge
		else if(timeState ==  3){
			fireTime = 4;
			backupTime = 0.5;
			rotateTime = 2.4;
			forwardTime = 2.1;
			shooterSpeed = 1900 / 60.0;
		}
		//middle back bridge no fire.
		else if(timeState ==  4){
			fireTime = 0;
			backupTime = 0.5;
			rotateTime = 2.4;
			forwardTime = 2.1;
			shooterSpeed = 1900 / 60.0;
		}
		//left
		else if (timeState == 5){
			fireTime = 4;
			backupTime = 0;
			rotateTime = 0;
			forwardTime = 0;
			shooterSpeed = 1850 / 60.0; 
		}
		//left and bridge
		else if (timeState == 6){
			fireTime = 4;
			backupTime = 0.5;
			rotateTime = 2.7;
			forwardTime = 1.5;
			shooterSpeed = 1850 / 60.0; 
		}
		//right
		else if (timeState == 7){
			fireTime = 4;
			backupTime = 0;
			rotateTime = 0;
			forwardTime = 0;
			shooterSpeed = 1850 / 60.0;
		}
		//right and bridge
		else if (timeState == 8){
			fireTime = 4;
			backupTime = 1;
			rotateTime = 7;		//fire
			forwardTime = 0;
			shooterSpeed = 1850 / 60.0;
			/*fireTime = 4;
			backupTime = 0.5;
			rotateTime = 2.3;
			forwardTime = 1.5;
			shooterSpeed = 1850 / 60.0;*/
		}
		// fire everything
		else if(timeState ==  9){
			rotateTime = 20;
			fireTime = 20;
			backupTime = 20;
			forwardTime = 20;
			shooterSpeed = 1900 / 60.0;
		}
		//if it is entered wrong default to front middle
		else{
			rotateTime = 2.3;
			fireTime = 4;
			backupTime = 1.5;
			forwardTime = 2;
			//shooterSpeed = 30.33;
			shooterSpeed = 29.17;

		}
		//shooterRightPID->SetSetpoint();
		
		
		//shooterRightPID->Disable();
		//base->SetSafetyEnabled(false);
		autonomousTimer.Reset();
		autonomousTimer.Start();
		
		while (IsAutonomous()) {
			Wait(.001);
			//printf("%f", autonomousTimer.Get());
			//printf("%f", GetTime());
			DashBoardUpdater();
			BridgeDepressorUpdate();
			shooterRightPID->SetSetpoint(shooterSpeed);
			shooterLeft->Set(-shooterRight->Get());
			shooterRightPID->Enable();
			encoderShooter->update();
			ballManager->update();
			/*if (autonomousState == INIT){
				autonomousState = DELAY;
			}*/
			//if we are firing every thing
			if (timeState == 9){
				//intake untill we have more than 2 balls 
				//if (ballManager->get() < 2){
					ballManager->setIntake(1);
				//}
				//else if (ballManager->get() >= 2){
					shooterRightPID->Enable();	
					if ((encoderShooter->get() > shooterSpeed - (SHOOTER_TOLERANCE / 60.0)) && 
						(encoderShooter->get() < shooterSpeed + (SHOOTER_TOLERANCE / 60.0))) {
									// wait after the shooter is enabled bofore you fire 
							ballManager->fire(2);	
					}
					else{
						ballManager->queue();
					}
				//}
			}
			//in any other autonomous mode
			else {
				//ballManager->setIntake(1);
				if (autonomousState == INIT) {
					ballManager->queue();
					if ( autonomousTimer.Get() > delayTime){
						autonomousState = FIRE1;
						autonomousTimer.Reset();
						autonomousTimer.Start();
					}
					shooterRightPID->Enable();	
				}
				else if (autonomousState == FIRE1) {
					//ballManager->fire();
					
					
					
					if ((encoderShooter->get() > shooterSpeed - (SHOOTER_TOLERANCE / 60.0)) && 
						(encoderShooter->get() < shooterSpeed + (SHOOTER_TOLERANCE / 60.0))) {
									// wait after the shooter is enabled bofore you fire 
							ballManager->fire(2);	
					}
					else{
						ballManager->queue();
					}
					
					if (autonomousTimer.Get() > fireTime){
						autonomousState = BACKUP;
						
						//autonomousState = ROTATE;
						
						autonomousTimer.Reset();
						autonomousTimer.Start();
					}
					
					
					
					//shooterRightPID->SetSetpoint(20);
	
						
				}
				
				else if (autonomousState == BACKUP){
					
					if (timeState == 8) {
						ballManager->setIntake(1);
					}
					else {
						shooterRightPID->Disable();
						base->TankDrive(.85, .85);
						if (autonomousTimer.Get()  > backupTime){
							autonomousState = ROTATE;
							autonomousTimer.Reset();
							autonomousTimer.Start();
						}
					}
				}
				
				else if (autonomousState == ROTATE){
					
					if (timeState == 8) {
						
						ballManager->setIntake(1);
						if ((encoderShooter->get() > shooterSpeed - (SHOOTER_TOLERANCE / 60.0)) && 
							(encoderShooter->get() < shooterSpeed + (SHOOTER_TOLERANCE / 60.0))) {
							// wait after the shooter is enabled bofore you fire 
							ballManager->fire(2);	
						}
						else{
							ballManager->queue();
						}
					}
					else {
						shooterRightPID->Disable();
						base->TankDrive(.75, -.75);
						/*if (autonomousTimer.Get()  > 3.5){
							autonomousState = FORWARD;
						}*/
						if (autonomousTimer.Get()  > rotateTime){
							autonomousState = FORWARD;
							autonomousTimer.Reset();
							autonomousTimer.Start();
						}
					}
				}
				else if (autonomousState == FORWARD){
					bridgeDepressorState = LOWERING;
					base->TankDrive(-.65,-.65);
					/*if (autonomousTimer.Get()  > 5.5){
						autonomousState = STOP;
					}*/
					if (autonomousTimer.Get()  > forwardTime){
						autonomousState = STOP;
					}
					shooterRightPID->Disable();
				}
				else if (autonomousState == STOP){
					base->TankDrive(0.0,0.0);
					shooterRightPID->Disable();
				}
			}
		}
	}
		
	
	
	void DashBoardUpdater() {
		bool ball1 = (ballManager->get() > 0) ? true : false;
		bool ball2 = (ballManager->get() > 1) ? true : false;
		bool ball3 = (ballManager->get() > 2) ? true : false;
		
		//((encoderShooter->get()) - shooterSpeed)  * 60, shooterSpeed * 60,
		
		dds->sendTeamCustomData(0, 0, 0,
								shooterSpeed * 60,encoderShooter->get() * 60, shooterRight->Get(),
								stickAux->GetRawButton(BTN_TOP_BANK), stickAux->GetRawButton(BTN_TOP_SWISH),
								stickAux->GetRawButton(BTN_MID_BANK), stickAux->GetRawButton(BTN_MID_SWISH),
								0, 0,
								ball1, ball2, ball3, TUNE_PID, cameraToggle);
		
	}
};

START_ROBOT_CLASS(RobotDemo)
;

