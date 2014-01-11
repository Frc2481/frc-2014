/*
 * Camera.cpp
 *
 *  Created on: Jan 10, 2014
 *      Author: Team2481
 */

#include "Camera2481.h"

Camera2481::Camera2481() : Subsystem("Camera2481"){
	//cameraTable = new NetworkTable();
}

bool Camera2481::HasTarget(){	
	if(cameraTable->GetBoolean("BOUNDING_COORDINATES")){
		return 1;
	}
	return 0;
}

Camera2481::~Camera2481() {
	delete cameraTable;
}
