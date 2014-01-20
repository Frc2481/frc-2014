/*
 * Compass.cpp
 *
 *  Created on: Jan 14, 2014
 *      Author: Team2481
 */

#include "Compass.h"

Compass::Compass(uint8_t moduleNumber) {
	// TODO Auto-generated constructor stub
	compass = DigitalModule::GetInstance().GetI2C(COMPASS_ADDRESS);
	heading = 0;
}

Compass::~Compass() {
	// TODO Auto-generated destructor stub
}

void Compass::Init(){
	compass->Write(CRA_REG_M,0x14);
	compass->Write(MR_REG_M,0x00);
	
}

double Compass::GetAngle(){
	return heading;
}

void Compass::Update(){
	unsigned char temp, MR_Data[6];
	int Mx,My,Mz;
	
	//Read x,y,z magnetometer registers.
	compass->Read(OUT_X_H_M,1,&MR_Data[0]);
	compass->Read(OUT_X_L_M,1,&MR_Data[1]);
	compass->Read(OUT_Y_H_M,1,&MR_Data[2]);
	compass->Read(OUT_Y_L_M,1,&MR_Data[3]);
	compass->Read(OUT_Z_H_M,1,&MR_Data[4]);
	compass->Read(OUT_Z_L_M,1,&MR_Data[5]);
	
	//Combine low and high register values into single ints.
	Mx = (int) (MR_Data[0]<<8)+MR_Data[1];
	My = (int) (MR_Data[2]<<8)+MR_Data[3];
	Mz = (int) (MR_Data[4]<<8)+MR_Data[5];
	
	//Calculate angle of x * y vector to get heading.
	heading = atan2(Mx, My) * 180 / 3.1415;	                                
}
