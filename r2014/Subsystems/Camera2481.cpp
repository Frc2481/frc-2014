/*
 * Camera.cpp
 *
 *  Created on: Jan 10, 2014
 *      Author: Team2481
 */

#include "Camera2481.h"

Camera2481::Camera2481() : Subsystem("Camera2481"){
	mTable = NetworkTable::GetTable("RoboRealm");
	hotTarget = 0;
}

void Camera2481::CheckHotTarget(){
	try{
		int ht = (int)mTable->GetNumber("HOTTARGET", 2);
		SmartDashboard::PutNumber("HOTTARGET", ht);
		hotTarget = ht;
	} 
	catch(int e){;
	}
}
bool Camera2481::HasTarget(){
	return hotTarget;
}

Camera2481::~Camera2481() {
}
