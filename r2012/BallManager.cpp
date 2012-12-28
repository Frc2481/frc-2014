#include "BallManager.h"

BallManager::BallManager (int botChannel, int topChannel, int midChannel, int intakeChannel, int liftChannel) {
	mMidSensor = new DebounceDigitalInput(midChannel);
	mBotSensor = new DigitalInput(botChannel);
	mTopSensor = new DebounceDigitalInput(topChannel);
	mLift = new Jaguar(liftChannel);
	mIntake = new Jaguar(intakeChannel);
	mBallCount = 2;
	mLastBotState = false;
	mLastTopState = false;
	mLastMidState = false;
	mFireState = false;
	//loopCounter = 0;
	mVomitState = false;
	mIntakeState = false;
	mQueueState = false;
	mFireLockoutDuration = 0;
	mIntakeTimer = 0;
	mFireTimer = 0;
	mTimer.Start();
}

void BallManager::update() {
	
	bool topState = !mTopSensor->Get();
	bool botState = mBotSensor->Get();
	bool topStateD = !mTopSensor->GetD();
	bool midStateD = mMidSensor->GetD();
	
	//Cancel Firing if we fired with in a second.
	if (mFireTimer + mFireLockoutDuration > mTimer.Get()) {
		mFireState = false;
	}
	
	//Cancel ball pickup after a second of not seeing a ball. 
	if (mIntakeTimer + INTAKE_DURATION < mTimer.Get()) {
		mIntakeState = false;
	}
	
	// if we want to vomit spin everythig backwards
	if (mVomitState) {
		mIntake->Set(VOMIT_SPEED_INTAKE);
		mLift->Set(VOMIT_SPEED_LIFT);
	}
	
	else if (topState && (topState != mLastTopState) ) {
		mFireTimer = mTimer.Get();
	}
	
	// else if we want to fire run the lift
	else if (mFireState) {
			mLift->Set(LIFT_SPEED);
	}

	// if we don't want to fire and we see the top stop lift
	else if (topState){
		mLift->Set(0);
	}
	 
	
	// if we don't see the top and we have three then run the lift
	/*
	else if (mBallCount == 3) {
		mLift->Set(LIFT_SPEED);
		
	}*/
	else if (mQueueState){
		mLift->Set(LIFT_SPEED);
	}
	
	// if count isn't 3 and and we see the bottom then run the lift
	
	else if (botState) {
		mIntakeState = true;
		mIntakeTimer = mTimer.Get();
		mLift->Set(LIFT_SPEED);	
	}
	
	//if the middle just sees a ball and it didn't previously see one
	
	else if (midStateD && midStateD != mLastMidState) {
		//set the motor state to false
		mIntakeState = false;
		mLift->Set(0);
	}
	// set the motor to its state
	
	else if (mIntakeState) {
		mLift->Set(LIFT_SPEED);	
	}
	
	// if we don't see the bottom then stop the lift
	
	else {
		mLift->Set(0);
	}
	
	// if we vomit count down on the bottom sensor.
	if (mVomitState) {
		if (!midStateD && (midStateD != mLastMidState)) {
			mBallCount = (mBallCount > 0) ? (mBallCount - 1) : 0;
		}
	}
	
	//while not vomitting count normally 
	
	else {
		// if  a ball leaves the top  decrement ball count while keeping it positive
		if (!topStateD && (topStateD != mLastTopState)) {
			mBallCount = (mBallCount > 0) ? (mBallCount - 1) : 0;
		}
		
		// if a ball enters the bottom increment ball counter while keeping it below four 
		if (midStateD && (midStateD != mLastMidState)) {
			mBallCount = (mBallCount < 3) ? (mBallCount + 1) : 3;
		}
	}
	// set the current state to last state for the next loop
	mLastTopState = topStateD;
	mLastMidState = midStateD;
	
	//TODO:  WHY???
	if (!topStateD) {
		mFireState = false;
	}
	
	mVomitState = false;
	mQueueState = false;
}

int BallManager::get() {
	return mBallCount;
}

void BallManager::fire(float lockout) {
	//TODO: Timer disable shooter after firing.
	//TODO: Turn PID off.
	mFireState = true;
	mFireLockoutDuration = lockout;
}

void BallManager::vomit() {
	mVomitState = true;
}
void BallManager::queue(){
	mQueueState = true;
}

void BallManager::setIntake(bool intakeState){
	if (intakeState){
		
		//if (mBallCount < 3){
			mIntake->Set(INTAKE_SPEED);
		//}
		/*else{
			mIntake->Set(0);
		}*/
			
	}
	else{
		mIntake->Set(0);
	}
}
int BallManager::getSensor(){
	int sensorCount = 0;
	if(!mTopSensor->Get()){
		sensorCount+=4;
	}
	if (!mMidSensor->Get()){
		sensorCount+=2;
	}
	if( !mBotSensor->Get()){
		sensorCount++;
	}
	return sensorCount;
}
