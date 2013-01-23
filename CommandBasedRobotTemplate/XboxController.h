/*
 * XboxController.h
 *
 *  Created on: Jan 22, 2013
 *      Author: Team2481
 */

#ifndef XBOXCONTROLLER_H_
#define XBOXCONTROLLER_H_

#include "WPILib.h"



class XboxController: public Joystick {
public:
	static const UINT32 XboxController::xbLeftXAxis;
	static const UINT32 XboxController::xbLeftYAxis;
	static const UINT32 XboxController::xbZAxis;
	static const UINT32 XboxController::xbRightXAxis;
	static const UINT32 XboxController::xbRightYAxis;
	static const UINT32 XboxController::xbAButton;
	static const UINT32 XboxController::xbBButton;
	static const UINT32 XboxController::xbXButton;
	static const UINT32 XboxController::xbYButton;
	static const UINT32 XboxController::xbStartButton;
	static const UINT32 XboxController::xbSelectButton;
	static const UINT32 XboxController::xbRightBumper;
	static const UINT32 XboxController::xbLeftBumper;
	static const UINT32 XboxController::xbRightStickCLick;
	static const UINT32 XboxController::xbLeftStickClick;
	
	XboxController(UINT32 port);
	virtual ~XboxController();
	
};

#endif /* XBOXCONTROLLER_H_ */
