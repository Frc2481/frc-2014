#define SHOT_RELEASE_HEIGHT					(1.0668)
//#define SHOOTER_WHEEL_RADIUS 		 		(0.1016)
#define SHOOTER_STALL_TORQUE				(4.7000)
#define SHOOTER_NO_LOAD_RPM					(4875.0000)
#define TOP_RIM_HEIGHT			 			(2.4892)
#define MID_RIM_HEIGHT 			 			(1.5494)
#define CENTER_OF_SQUARE_TO_RIM_HEIGHT  	(0.2794)
#define SQUARE_TO_CENTER_OF_RIM_DISTANCE	(0.3810)
//#define BALL_RADIUS 			 			(0.1011)
#define BALL_MASS							(0.3175)
#define ACCELERATION_DUE_TO_GRAVITY 	 	(9.8)
#define ESTIMATED_CONTACT_ANGLE				(150)
#define LAYUP_DISTANCE						(4)
#define TARGET_DISTANCE_OVERRIDE 			(12)
#define OUTLET_PASS_DISTANCE 		 		(10)
#define TOP_BANK_HEIGHT_ADJ_FACTOR 	 		(1.0000)
#define TOP_SWISH_DISTANCE_ADJ_FACTOR	 	(1.0000)
#define MID_BANK_HEIGHT_ADJ_FACTOR 	 		(1.0000)
#define MID_SWISH_DISTANCE_ADJ_FACTOR 		(1.0000)
#define BANK_BASE_ANGLE						(45.0000)
#define SWISH_BASE_ANGLE					(50.0000)
#define EFFICIENCY_CORRECTION_FACTOR		(1.281)
#define PI 									(3.141592654)

#include <math.h>
#include "BeastAlgorithm.h"
BeastAlgorithm::BeastAlgorithm(){
	//currentShotType = Top_Bank;
	manualDistanceAdj = 0.0;
	convOutletPassDistance = OUTLET_PASS_DISTANCE * 0.3048;
	convManualDistanceAdj = manualDistanceAdj * 0.3048;
	convTargetDistance = targetDistance * 0.3048;
	topToMidRimHeight = TOP_RIM_HEIGHT - MID_RIM_HEIGHT;
	relativeTargetHeight = TOP_RIM_HEIGHT - SHOT_RELEASE_HEIGHT;	
	//backspinVelocity = 2 * PI * DESIRED_BACKSPIN * BALL_RADIUS;
	//backspinSpeed = (backspinVelocity * 60) / (2 * PI) * SHOOTER_WHEEL_RADIUS;
	//shooterWheelSpeedTop = (ballVelocity * 60) / 2 * PI * SHOOTER_WHEEL_RADIUS;
	//shooterWheelSpeedBot =  shooterWheelSpeedTop + backspinSpeed;
	//TODO targetDistanceCamera = some math
	targetDistance = 12.0000; //this may be wrong
	//manualDistanceOverride = false;
	convLayupDistance = LAYUP_DISTANCE * 0.3048;
	shooterRPMCommand = shooterWheelSpeed * EFFICIENCY_CORRECTION_FACTOR;
	shooterAngleCommand = 90 - shooterAngleOfAttack;
	
}

float BeastAlgorithm::calculate(float targetDistanceCamera, ShotType currentShotType, bool manualDistanceOverride){
	
	if (manualDistanceOverride) {
		targetDistance = TARGET_DISTANCE_OVERRIDE;
	}
	
	else {
		targetDistance = targetDistanceCamera;
	}
	
	
	if (currentShotType == Top_Bank){
		heightToTarget = relativeTargetHeight + (CENTER_OF_SQUARE_TO_RIM_HEIGHT * TOP_BANK_HEIGHT_ADJ_FACTOR);
		shooterAngleOfAttack = BANK_BASE_ANGLE + 0.5 * (atan(heightToTarget / distanceToTarget));
		distanceToTarget = convTargetDistance + convManualDistanceAdj;
		velocityCalculationNumerator =  -1 * ACCELERATION_DUE_TO_GRAVITY * (( distanceToTarget ) * ( distanceToTarget ));
		velocityCalculationDenominator = 2 * ( heightToTarget - ( tan(shooterAngleOfAttack) * distanceToTarget ) ) * (( cos(shooterAngleOfAttack) ) * ( cos(shooterAngleOfAttack) ));
		ballVelocity = sqrt( velocityCalculationNumerator / velocityCalculationDenominator );
		shooterWheelTorque = ( 90 * BALL_MASS * ((ballVelocity) * (ballVelocity)) ) / ( PI * ESTIMATED_CONTACT_ANGLE );
		shooterWheelSpeed = ( ( SHOOTER_STALL_TORQUE - shooterWheelTorque ) * SHOOTER_NO_LOAD_RPM ) / SHOOTER_STALL_TORQUE;
		shooterWheelPower = ( shooterWheelTorque * shooterWheelSpeed * PI ) / 180;
		maxShooterWheelPower = ( 0.25 * SHOOTER_STALL_TORQUE * SHOOTER_NO_LOAD_RPM * PI ) / 180;
		shooterPowerPercent = ( shooterWheelPower / maxShooterWheelPower ) * 100;

	}
	else if (currentShotType == Top_Swish){
		heightToTarget = relativeTargetHeight;
		distanceToTarget = convTargetDistance - (SQUARE_TO_CENTER_OF_RIM_DISTANCE * TOP_SWISH_DISTANCE_ADJ_FACTOR);
		
		shooterAngleOfAttack = SWISH_BASE_ANGLE + 0.5 * (atan(heightToTarget / distanceToTarget));
		velocityCalculationNumerator =  -1 * ACCELERATION_DUE_TO_GRAVITY * (( distanceToTarget ) * ( distanceToTarget ));
		velocityCalculationDenominator = 2 * ( heightToTarget - ( tan(shooterAngleOfAttack) * distanceToTarget ) ) * (( cos(shooterAngleOfAttack) ) * ( cos(shooterAngleOfAttack) ));
		ballVelocity = sqrt( velocityCalculationNumerator / velocityCalculationDenominator );
		shooterWheelTorque = ( 90 * BALL_MASS * ((ballVelocity) * (ballVelocity)) ) / ( PI * ESTIMATED_CONTACT_ANGLE );
		shooterWheelSpeed = ( ( SHOOTER_STALL_TORQUE - shooterWheelTorque ) * SHOOTER_NO_LOAD_RPM ) / SHOOTER_STALL_TORQUE;
		shooterWheelPower = ( shooterWheelTorque * shooterWheelSpeed * PI ) / 180;
		maxShooterWheelPower = ( 0.25 * SHOOTER_STALL_TORQUE * SHOOTER_NO_LOAD_RPM * PI ) / 180;
		shooterPowerPercent = ( shooterWheelPower / maxShooterWheelPower ) * 100;
	}
	else if (currentShotType == Mid_Bank){
		heightToTarget = relativeTargetHeight - topToMidRimHeight + (CENTER_OF_SQUARE_TO_RIM_HEIGHT * MID_BANK_HEIGHT_ADJ_FACTOR);
		distanceToTarget = convTargetDistance + convManualDistanceAdj;
		shooterAngleOfAttack = BANK_BASE_ANGLE + 0.5 * (atan(heightToTarget / distanceToTarget));
		velocityCalculationNumerator =  -1 * ACCELERATION_DUE_TO_GRAVITY * (( distanceToTarget ) * ( distanceToTarget ));
		velocityCalculationDenominator = 2 * ( heightToTarget - ( tan(shooterAngleOfAttack) * distanceToTarget ) ) * (( cos(shooterAngleOfAttack) ) * ( cos(shooterAngleOfAttack) ));
		ballVelocity = sqrt( velocityCalculationNumerator / velocityCalculationDenominator );
		shooterWheelTorque = ( 90 * BALL_MASS * ((ballVelocity) * (ballVelocity)) ) / ( PI * ESTIMATED_CONTACT_ANGLE );
		shooterWheelSpeed = ( ( SHOOTER_STALL_TORQUE - shooterWheelTorque ) * SHOOTER_NO_LOAD_RPM ) / SHOOTER_STALL_TORQUE;
		shooterWheelPower = ( shooterWheelTorque * shooterWheelSpeed * PI ) / 180;
		maxShooterWheelPower = ( 0.25 * SHOOTER_STALL_TORQUE * SHOOTER_NO_LOAD_RPM * PI ) / 180;
		shooterPowerPercent = ( shooterWheelPower / maxShooterWheelPower ) * 100;
	}
	else if (currentShotType == Mid_Swish){
		heightToTarget = relativeTargetHeight - topToMidRimHeight;
		distanceToTarget = convTargetDistance - (SQUARE_TO_CENTER_OF_RIM_DISTANCE *  MID_SWISH_DISTANCE_ADJ_FACTOR) + convManualDistanceAdj;
		shooterAngleOfAttack = SWISH_BASE_ANGLE + 0.5 * (atan(heightToTarget / distanceToTarget));
		velocityCalculationNumerator =  -1 * ACCELERATION_DUE_TO_GRAVITY * (( distanceToTarget ) * ( distanceToTarget ));
		velocityCalculationDenominator = 2 * ( heightToTarget - ( tan(shooterAngleOfAttack) * distanceToTarget ) ) * (( cos(shooterAngleOfAttack) ) * ( cos(shooterAngleOfAttack) ));
		ballVelocity = sqrt( velocityCalculationNumerator / velocityCalculationDenominator );
		shooterWheelTorque = ( 90 * BALL_MASS * ((ballVelocity) * (ballVelocity)) ) / ( PI * ESTIMATED_CONTACT_ANGLE );
		shooterWheelSpeed = ( ( SHOOTER_STALL_TORQUE - shooterWheelTorque ) * SHOOTER_NO_LOAD_RPM ) / SHOOTER_STALL_TORQUE;
		shooterWheelPower = ( shooterWheelTorque * shooterWheelSpeed * PI ) / 180;
		maxShooterWheelPower = ( 0.25 * SHOOTER_STALL_TORQUE * SHOOTER_NO_LOAD_RPM * PI ) / 180;
		shooterPowerPercent = ( shooterWheelPower / maxShooterWheelPower ) * 100;
	}
	else if (currentShotType == Outlet_Pass){
		heightToTarget = -1 * SHOT_RELEASE_HEIGHT;
		distanceToTarget = convOutletPassDistance + convManualDistanceAdj;
		shooterAngleOfAttack = BANK_BASE_ANGLE;
		velocityCalculationNumerator =  -1 * ACCELERATION_DUE_TO_GRAVITY * (( distanceToTarget ) * ( distanceToTarget ));
		velocityCalculationDenominator = 2 * ( heightToTarget - ( tan(shooterAngleOfAttack) * distanceToTarget ) ) * (( cos(shooterAngleOfAttack) ) * ( cos(shooterAngleOfAttack) ));
		ballVelocity = sqrt( velocityCalculationNumerator / velocityCalculationDenominator );
		shooterWheelTorque = ( 90 * BALL_MASS * ((ballVelocity) * (ballVelocity)) ) / ( PI * ESTIMATED_CONTACT_ANGLE );
		shooterWheelSpeed = ( ( SHOOTER_STALL_TORQUE - shooterWheelTorque ) * SHOOTER_NO_LOAD_RPM ) / SHOOTER_STALL_TORQUE;
		shooterWheelPower = ( shooterWheelTorque * shooterWheelSpeed * PI ) / 180;
		maxShooterWheelPower = ( 0.25 * SHOOTER_STALL_TORQUE * SHOOTER_NO_LOAD_RPM * PI ) / 180;
		shooterPowerPercent = ( shooterWheelPower / maxShooterWheelPower ) * 100;
	}
	else if (currentShotType == Layup) {
		heightToTarget = relativeTargetHeight - topToMidRimHeight + (CENTER_OF_SQUARE_TO_RIM_HEIGHT + MID_BANK_HEIGHT_ADJ_FACTOR);
		distanceToTarget = convLayupDistance + convManualDistanceAdj;
		shooterAngleOfAttack = BANK_BASE_ANGLE + 0.5 * (atan(heightToTarget / distanceToTarget));
		velocityCalculationNumerator =  -1 * ACCELERATION_DUE_TO_GRAVITY * (( distanceToTarget ) * ( distanceToTarget ));
		velocityCalculationDenominator = 2 * ( heightToTarget - ( tan(shooterAngleOfAttack) * distanceToTarget ) ) * (( cos(shooterAngleOfAttack) ) * ( cos(shooterAngleOfAttack) ));
		ballVelocity = sqrt( velocityCalculationNumerator / velocityCalculationDenominator );
		shooterWheelTorque = ( 90 * BALL_MASS * ((ballVelocity) * (ballVelocity)) ) / ( PI * ESTIMATED_CONTACT_ANGLE );
		shooterWheelSpeed = ( ( SHOOTER_STALL_TORQUE - shooterWheelTorque ) * SHOOTER_NO_LOAD_RPM ) / SHOOTER_STALL_TORQUE;
		shooterWheelPower = ( shooterWheelTorque * shooterWheelSpeed * PI ) / 180;
		maxShooterWheelPower = ( 0.25 * SHOOTER_STALL_TORQUE * SHOOTER_NO_LOAD_RPM * PI ) / 180;
		shooterPowerPercent = ( shooterWheelPower / maxShooterWheelPower ) * 100;
	}
	return shooterWheelSpeed;
}
