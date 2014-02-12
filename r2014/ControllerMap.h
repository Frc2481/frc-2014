#ifndef CONTROLLERMAP_H
#define CONTROLLERMAP_H

#include "XboxController.h"


//Tune Stick
#define FR_OFFSET_BUTTON 			XboxController::xbBButton
#define FL_OFFSET_BUTTON 			XboxController::xbYButton
#define BR_OFFSET_BUTTON			XboxController::xbAButton
#define BL_OFFSET_BUTTON 			XboxController::xbXButton

//Driver Stick
#define CALIBRATE_COMPASS_BUTTON 	XboxController::xbZAxis
#define TOGGLE_RIGHT_EAR_BUTTON 	XboxController::xbXButton
#define TOGGLE_LEFT_EAR_BUTTON 		XboxController::xbYButton

#define SET_FIELD_OFFSET_BUTTON 	XboxController::xbStartButton
#define RESET_GYRO_BUTTON 			XboxController::xbBackButton

//Aux Stick
#define RETRACT_SHOOTER_BUTTON 		XboxController::xbRightYAxis
#define RELEASE_SHOOTER_BUTTON 		XboxController::xbRightYAxis
#define AUTO_SET_SHOOTER_BUTTON		XboxController::xbAButton
#define FIRE_BUTTON 				XboxController::xbZAxis
//#define MANUAL_LATCH_BUTTON 		XboxController::xbBButton
#define TURN_ON_INTAKE_BUTTON 		XboxController::xbRightBumper
#define TURN_OFF_INTAKE_BUTTON 		XboxController::xbLeftBumper
#define VOMIT_BUTTON 				XboxController::xbBButton
#define TOGGLE_INTAKE_READY_BUTTON 	XboxController::xbLeftStickClick
#define AUTO_COCK_SHOOTER_BUTTON 	XboxController::xbZAxis
#define SHOOTER_TO_THROTTLE_BUTTON	XboxController::xbXButton
//#define INC_SHOOTER_BUTTON			XboxController::xbYButton
//#define DEC_SHOOTER_BUTTON			XboxController::xbXButton



#endif 
