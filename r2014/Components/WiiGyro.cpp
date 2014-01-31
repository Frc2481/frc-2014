/*
 * WiiGyro.cpp
 *
 *  Created on: Jan 14, 2014
 *      Author: Team2481
 */

#include "WiiGyro.h"
#include <cmath>

WiiGyro::WiiGyro(uint8_t moduleNumber) {
	// TODO Auto-generated constructor stub
	printf("step 1");
	DigitalModule* dm = DigitalModule::GetInstance(moduleNumber);
	printf("step 2");
	
//	for (int i = 0; i < 127; ++i) {
//		I2C* wiiGyro1 = dm->GetI2C((uint32_t)i);
//		printf("%d %d\n", i, WiiGyro1->AddressOnly());
//		delete WiiGyro1;
//	}
	
	wiiGyro = dm->GetI2C(WIIGYRO_ADDRESS);
	printf("step 3");
	heading = 0;
	semaphore = semMCreate(SEM_Q_PRIORITY);
	update = new Notifier(WiiGyro::UpdateWiiGyro, this);
	update->StartPeriodic(.2);
	Init();
}

WiiGyro::~WiiGyro() {
	// TODO Auto-generated destructor stub
}

void WiiGyro::Init(){		
	wiiGyro->Write(CTRL5, 0x64);
	wiiGyro->Write(CTRL6, 0x20);
	wiiGyro->Write(CTRL7, 0x00);
	
	//	WiiGyro->Write(CRA_REG_M,0x14);
//	WiiGyro->Write(MR_REG_M,0x00);
//	
}	

double WiiGyro::GetAngle(){
	double heading;
	CRITICAL_REGION(semaphore) {
		heading = this->heading;
	}
	END_REGION;
	return heading;
}

void WiiGyro::Update(){
	unsigned char MR_Data[6];
	int16_t Mx,My,Mz;
	
	//Read x,y,z magnetometer registers.
	wiiGyro->Read(OUT_X_H_M,1,&MR_Data[0]);
	wiiGyro->Read(OUT_X_L_M,1,&MR_Data[1]);
	wiiGyro->Read(OUT_Y_H_M,1,&MR_Data[2]);
	wiiGyro->Read(OUT_Y_L_M,1,&MR_Data[3]);
	wiiGyro->Read(OUT_Z_H_M,1,&MR_Data[4]);
	wiiGyro->Read(OUT_Z_L_M,1,&MR_Data[5]);
	
	//Combine low and high register values into single ints.
	Mx = (int16_t)(MR_Data[0]<<8 | MR_Data[1]);
	My = (int16_t)(MR_Data[2]<<8 | MR_Data[3]);
	Mz = (int16_t)(MR_Data[4]<<8 | MR_Data[5]);
	
	//Calculate angle of x * y vector to get heading.
	double heading = atan2((int)Mx, (int)My) * 180 / 3.1415;
	printf("%d \n", wiiGyro->AddressOnly());
	printf("%d %d %d %d %d %d", 
			MR_Data[0], MR_Data[1], MR_Data[2],
			MR_Data[3], MR_Data[4], MR_Data[5]);
	printf("X: %d, Y: %d, heading: %f\n", Mx, My, heading);
	SmartDashboard::PutNumber("WiiGyro Heading", heading);
	CRITICAL_REGION(semaphore) {
		this->heading = heading;
	}
	END_REGION;
}

void WiiGyro::UpdateWiiGyro(void* wiiGyro) {
	WiiGyro* theWiiGyro = (WiiGyro*)wiiGyro;
	theWiiGyro->Update();
}
