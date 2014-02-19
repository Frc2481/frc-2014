/*
 * Camera.cpp
 *
 *  Created on: Jan 10, 2014
 *      Author: Team2481
 */

#include "Camera2481.h"

Camera2481::Camera2481() : Subsystem("Camera2481"){
	
}

bool Camera2481::HasTarget(){
	try{
//		printf("Hot Target: %f \n", SmartDashboard::GetNumber("HOTTARGET"));
		return SmartDashboard::GetBoolean("HOTTARGET");
	} 
	catch(int e){}
}

Camera2481::~Camera2481() {
}
