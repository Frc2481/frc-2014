/*
 * Camera.cpp
 *
 *  Created on: Jan 10, 2014
 *      Author: Team2481
 */

#include "Camera2481.h"

Camera2481::Camera2481() : Subsystem("Camera2481"){
	mTable = NetworkTable::GetTable("RoboRealm");
}

bool Camera2481::HasTarget(){
	try{
		int ht = (int)mTable->GetNumber("HOTTARGET", 2);
		SmartDashboard::PutNumber("HOTTARGET", ht);
		return ht == 1;
	} 
	catch(int e){
		return false;
	}
}

Camera2481::~Camera2481() {
}
