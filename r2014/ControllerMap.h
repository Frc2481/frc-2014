#ifndef CONTROLLERMAP_H
#define CONTROLLERMAP_H

#include "XboxController.h"


//Tune Stick
#define FR_OFFSET_BUTTON			new JoystickButton(tuningStick, XboxController::xbBButton)
#define FL_OFFSET_BUTTON 			new JoystickButton(tuningStick, XboxController::xbYButton)
#define BR_OFFSET_BUTTON			new JoystickButton(tuningStick, XboxController::xbAButton)
#define BL_OFFSET_BUTTON 			new JoystickButton(tuningStick, XboxController::xbXButton)

//Driver Stick
//#define CALIBRATE_COMPASS_BUTTON 	new AnalogJoystickButton(driverStick, XboxController::xbZAxis, -.5)
//#define SET_FIELD_OFFSET_BUTTON 	new JoystickButton(driverStick, XboxController::xbStartButton)
//#define RESET_GYRO_BUTTON 			new JoystickButton(driverStick, XboxController::xbBackButton)
#define LEFT_JUKE_COMMAND_BUTTON    new JoystickButton(driverStick, XboxController::xbLeftBumper)
#define RIGHT_JUKE_COMMAND_BUTTON   new JoystickButton(driverStick, XboxController::xbRightBumper)
#define TOGGLE_FIELD_CENTRIC_BUTTON new JoystickButton(driverStick, XboxController::xbXButton)
#define FORWARD_BUTTON				new JoystickButton(driverStick, XboxController::xbAButton)
#define BACKWARD_BUTTON				new JoystickButton(driverStick, XboxController::xbBButton)

#define TURN_ON_INTAKE_BUTTON 		new AnalogJoystickButton(driverStick, XboxController::xbZAxis, -.5)
#define TURN_OFF_INTAKE_BUTTON 		new AnalogJoystickButton(driverStick, XboxController::xbZAxis, -.5)

#define VOMIT_BUTTON 				new JoystickButton(driverStick, XboxController::xbYButton)
//Aux Stick
//#define RETRACT_SHOOTER_BUTTON 		new AnalogJoystickButton(auxStick, XboxController::xbRightYAxis, -.5)
//#define RELEASE_SHOOTER_BUTTON 		new AnalogJoystickButton(auxStick, XboxController::xbRightYAxis, .5)
#define AUTO_SET_SHOOTER_BUTTON		new JoystickButton (auxStick, XboxController::xbAButton)
#define FIRE_BUTTON_NUM				XboxController::xbZAxis
#define FIRE_BUTTON 				new AnalogJoystickButton(auxStick, FIRE_BUTTON_NUM, -.5)

#define TOGGLE_INTAKE_READY_BUTTON 	new JoystickButton(auxStick, XboxController::xbYButton)

#define TOGGLE_RIGHT_EAR_BUTTON 	new JoystickButton(auxStick, XboxController::xbLeftBumper)
#define TOGGLE_LEFT_EAR_BUTTON 		new JoystickButton(auxStick, XboxController::xbLeftBumper)

#define AUTO_COCK_SHOOTER_BUTTON 	new JoystickButton (auxStick, XboxController::xbRightBumper)
#define SHOOTER_TO_THROTTLE_BUTTON	new JoystickButton(auxStick, XboxController::xbXButton)

#define NORMAL_SHOT_BUTTON			new AnalogJoystickButton(auxStick, XboxController::xbLeftYAxis, -.8)
#define TRUSS_PASS_BUTTON			new AnalogJoystickButton(auxStick, XboxController::xbRightYAxis, .8)
#define OUTLET_PASS_BUTTON			new AnalogJoystickButton(auxStick, XboxController::xbRightYAxis, -.8)
#define CORNER_SHOT_BUTTON			new AnalogJoystickButton(auxStick, XboxController::xbLeftYAxis, .8)

#define SHOOTER_PASS_BUTTON			new AnalogJoystickButton(auxStick, XboxController::xbZAxis, .5);

#endif 
