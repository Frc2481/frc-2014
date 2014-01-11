/*
 * Camera.cpp
 *
 *  Created on: Jan 10, 2014
 *      Author: Team2481
 */

#include "Camera2481.h"

Camera2481::Camera2481() : Subsystem("Camera2481"){
	cameraTable = new NetworkTable();
}

bool Camera2481::HasTarget(){	
	int *ptr;
	if(cameraTable->GetValue("BOUNDING_COORDINATES")){
		ptr = cameraTable->GetValue("BOUNDING_COORDINATES");
		if (((ptr[0] - boundingBox[4]) > (boundingBox[1] - boundingBox[5]) && boundingBox[]
	}
	return 0;
	}
	else return 0;
}

Camera2481::~Camera2481() {
	delete cameraTable;
}
