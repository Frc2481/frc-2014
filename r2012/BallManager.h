#include "WPILib.h"
#include "DebounceDigitalInput.h"
//#define LIFT_SPEED .5
#define VOMIT_SPEED_INTAKE 		.5
#define VOMIT_SPEED_LIFT 		-1
#define INTAKE_SPEED			-1
#define LIFT_SPEED				1
#define FIRE_LOCKOUT_DURATION	0.5
#define INTAKE_DURATION			1.0
class BallManager {
private :
	int mBallCount;
	DigitalInput *mBotSensor;
	DebounceDigitalInput *mMidSensor;
	DebounceDigitalInput *mTopSensor;
	Jaguar *mLift;
	Jaguar *mIntake;
	bool mLastBotState;
	bool mLastTopState;
	bool mLastMidState;
	bool mFireState;
	//int loopCounter;
	bool mVomitState;
	bool mIntakeState;
	bool mQueueState;
	float mIntakeTimer;
	float mFireTimer;
	float mFireLockoutDuration;
	Timer mTimer;
	
public:
	BallManager(int botChannel, int topChannel, int midChannel, int intakeChannel, int liftChannel);
	void update();
	int get();
	void liftBalls();
	void fire(float lockout);
	void vomit();
	void setIntake(bool intakeState);
	int getSensor();
	bool getBotIO() { return mBotSensor->Get(); }
	bool getMidIO() { return mMidSensor->Get(); }
	bool getTopIO() { return mTopSensor->Get(); }
	void queue();
	void resetBalls() { mBallCount = 0; }
};
