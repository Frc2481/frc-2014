/*
 * Camera.cpp
 *
 *  Created on: Jan 10, 2014
 *      Author: Team2481
 */

#include "Camera2481.h"

Camera2481::Camera2481() : Subsystem("Camera2481"){
	cameraTable = NetworkTable::GetTable("camera");
}

bool Camera2481::HasTarget(){	
	printf("Targets: %d", cameraTable->GetNumber("BLOB_COUNT"));
	return cameraTable->GetBoolean("HOT_TARGET");
}

Camera2481::~Camera2481() {
	delete cameraTable;
}
