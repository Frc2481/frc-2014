#ifndef CONTROLLERMAP_H
#define CONTROLLERMAP_H

#include "XboxController.h"


//Tune Stick
#define FR_OFFSET_BUTTON			new JoystickButton(tuningStick, XboxController::xbBButton)
#define FL_OFFSET_BUTTON 			new JoystickButton(tuningStick, XboxController::xbYButton)
#define BR_OFFSET_BUTTON			new JoystickButton(tuningStick, XboxController::xbAButton)
#define BL_OFFSET_BUTTON 			new JoystickButton(tuningStick, XboxController::xbXButton)

//Driver Stick
#define CALIBRATE_COMPASS_BUTTON 	new AnalogJoystickButton(driverStick, XboxController::xbZAxis, -.5)
#define SET_FIELD_OFFSET_BUTTON 	new JoystickButton(driverStick, XboxController::xbStartButton)
#define RESET_GYRO_BUTTON 			new JoystickButton(driverStick, XboxController::xbBackButton)
#define TOGGLE_FIELD_CENTRIC_BUTTON new AnalogJoystickButton(driverStick, XboxController::xbZAxis, -.5)
#define TOGGLE_FORWARD_BUTTON		new JoystickButton(driverStick, XboxController::xbAButton)

#define TURN_ON_INTAKE_BUTTON 		new JoystickButton(driverStick, XboxController::xbRightBumper)
#define TURN_OFF_INTAKE_BUTTON 		new JoystickButton(driverStick, XboxController::xbLeftBumper)

//Aux Stick
#define RETRACT_SHOOTER_BUTTON 		new AnalogJoystickButton(auxStick, XboxController::xbRightYAxis, -.5)
#define RELEASE_SHOOTER_BUTTON 		new AnalogJoystickButton(auxStick, XboxController::xbRightYAxis, .5)
#define AUTO_SET_SHOOTER_BUTTON		new JoystickButton (auxStick, XboxController::xbAButton)
#define FIRE_BUTTON_NUM				XboxController::xbZAxis
#define FIRE_BUTTON 				new AnalogJoystickButton(auxStick, FIRE_BUTTON_NUM, -.5)

#define VOMIT_BUTTON 				new JoystickButton(auxStick, XboxController::xbBButton)
#define TOGGLE_INTAKE_READY_BUTTON 	new JoystickButton(auxStick, XboxController::xbLeftStickClick)

#define TOGGLE_RIGHT_EAR_BUTTON 	new JoystickButton(auxStick, XboxController::xbRightBumper)
#define TOGGLE_LEFT_EAR_BUTTON 		new JoystickButton(auxStick, XboxController::xbLeftBumper)

#define AUTO_COCK_SHOOTER_BUTTON 	new AnalogJoystickButton (auxStick, XboxController::xbZAxis, .5)
#define SHOOTER_TO_THROTTLE_BUTTON	new JoystickButton(auxStick, XboxController::xbXButton)

#endif 
