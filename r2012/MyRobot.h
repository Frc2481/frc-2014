#define DIO_BALL_BOT_CH			1			
#define DIO_BALL_MID_CH			2
#define DIO_BALL_TOP_CH			3
#define DIO_ENCODER_CH 			4

#define PWM_LEFT_DRIVE			1
#define PWM_RIGHT_DRIVE			2

#define PWM_SHOOTER_ADJUST		3

#define PWM_RIGHT_SHOOTER		5
#define PWM_LEFT_SHOOTER		6
#define PWM_BALL_MNGR_LIFT		7
#define PWM_BALL_MNGR_INTAKE	8
#define PWM_BRDG_DPRSSR			9

#define ANA_BRDG_DPRSSR			2
#define ANA_ANGLE_ADJUST		4

#define BRDG_DWN_VLTG			1.26
#define BRDG_UP_VLTG			4.95

#define SHOT_ADJUST_DWN_VLTG	0
#define SHOT_ADJUST_UP_VLTG		0
#define SHOT_ADJUST_KEY_VLTG	1.16
#define SHOT_ADJUST_LAYUP_VLTG	0

#define STICK_DRIVER			1
#define STICK_AUX				2

#define BTN_TOP_BANK        	1
#define BTN_TOP_SWISH			2
#define BTN_MID_BANK			3
#define BTN_MID_SWISH			4
#define BTN_BRDG_DWN			5
#define BTN_BRDG_UP				6

#define BTN_CAM_TOGGLE			5

#define BRDG_SPEED_FORWARD		0.75
#define BRDG_SPEED_BACKWARD		-0.75

#define AUX_SPEED_FORWARD		-.75
#define AUX_SPEED_BACKWARD		.75

#define SHOOTER_ERROR			2	//RPM

#define ON_TARGET_DEBOUNCE		10

#define SHOOTER_SPEED_LAYUP		20.0
#define SHOOTER_SPEED_KEY		27.5
enum BridgeDepressorStateEnum {TOP, RAISING, LOWERING, BOT};
enum ShooterAdjustStateEnum {LAYUP, KEY, FAR};
enum AutonomousStateEnum {INIT, DELAY, SHOOTER_SPINUP1, FIRE1, SHOOTER_SPINUP2, FIRE2, BACKUP, ROTATE, FORWARD, STOP};
Threshold threshold(25, 255, 0, 45, 0, 47);
ParticleFilterCriteria2 criteria[] = {
		{IMAQ_MT_BOUNDING_RECT_WIDTH, 30, 400, false, false},
		{IMAQ_MT_BOUNDING_RECT_HEIGHT, 40, 400, false, false}
};
