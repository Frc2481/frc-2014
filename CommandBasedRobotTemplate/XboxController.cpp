/*
 * XboxController.cpp
 *
 *  Created on: Jan 22, 2013
 *      Author: Team2481
 */

#include "XboxController.h"

const UINT32 XboxController::xbLeftXAxis = 1;
const UINT32 XboxController::xbLeftYAxis = 2;
const UINT32 XboxController::xbZAxis = 3;
const UINT32 XboxController::xbRightXAxis = 4;
const UINT32 XboxController::xbRightYAxis = 5;
const UINT32 XboxController::xbAButton = 1;
const UINT32 XboxController::xbBButton = 2; 
const UINT32 XboxController::xbXButton = 3;
const UINT32 XboxController::xbYButton = 4;
const UINT32 XboxController::xbStartButton = 8;
const UINT32 XboxController::xbBackButton = 7;
const UINT32 XboxController::xbRightBumper = 6;
const UINT32 XboxController::xbLeftBumper = 5;
const UINT32 XboxController::xbRightStickCLick = 10;
const UINT32 XboxController::xbLeftStickClick = 9;


XboxController::XboxController(UINT32 port) : Joystick(port){}

XboxController::~XboxController() {}
