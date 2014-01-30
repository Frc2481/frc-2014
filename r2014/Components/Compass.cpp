/*
 * Compass.cpp
 *
 *  Created on: Jan 14, 2014
 *      Author: Team2481
 */

#include "Compass.h"
#include <cmath>

Compass::Compass(uint8_t moduleNumber) {
	// TODO Auto-generated constructor stub
	printf("step 1");
	DigitalModule* dm = DigitalModule::GetInstance(moduleNumber);
	printf("step 2");
	
//	for (int i = 0; i < 127; ++i) {
//		I2C* compass1 = dm->GetI2C((uint32_t)i);
//		printf("%d %d\n", i, compass1->AddressOnly());
//		delete compass1;
//	}
	
	compass = dm->GetI2C(COMPASS_ADDRESS);
	printf("step 3");
	heading = 0;
	semaphore = semMCreate(SEM_Q_PRIORITY);
	update = new Notifier(Compass::UpdateCompass, this);
	update->StartPeriodic(.2);
	Init();
}

Compass::~Compass() {
	// TODO Auto-generated destructor stub
}

void Compass::Init(){		
	compass->Write(CTRL5, 0x64);
	compass->Write(CTRL6, 0x20);
	compass->Write(CTRL7, 0x00);
	
	//	compass->Write(CRA_REG_M,0x14);
//	compass->Write(MR_REG_M,0x00);
//	
}	

double Compass::GetAngle(){
	double heading;
	CRITICAL_REGION(semaphore) {
		heading = this->heading;
	}
	END_REGION;
	return heading;
}

void Compass::Update(){
	unsigned char MR_Data[6];
	int16_t Mx,My,Mz;
	
	//Read x,y,z magnetometer registers.
	compass->Read(OUT_X_H_M,1,&MR_Data[0]);
	compass->Read(OUT_X_L_M,1,&MR_Data[1]);
	compass->Read(OUT_Y_H_M,1,&MR_Data[2]);
	compass->Read(OUT_Y_L_M,1,&MR_Data[3]);
	compass->Read(OUT_Z_H_M,1,&MR_Data[4]);
	compass->Read(OUT_Z_L_M,1,&MR_Data[5]);
	
	//Combine low and high register values into single ints.
	Mx = (int16_t)(MR_Data[0]<<8 | MR_Data[1]);
	My = (int16_t)(MR_Data[2]<<8 | MR_Data[3]);
	Mz = (int16_t)(MR_Data[4]<<8 | MR_Data[5]);
	
	//Calculate angle of x * y vector to get heading.
	double heading = atan2((int)Mx, (int)My) * 180 / 3.1415;
	printf("%d \n", compass->AddressOnly());
	printf("%d %d %d %d %d %d", 
			MR_Data[0], MR_Data[1], MR_Data[2],
			MR_Data[3], MR_Data[4], MR_Data[5]);
	printf("X: %d, Y: %d, heading: %f\n", Mx, My, heading);
	SmartDashboard::PutNumber("Compass Heading", heading);
	CRITICAL_REGION(semaphore) {
		this->heading = heading;
	}
	END_REGION;
}

void Compass::UpdateCompass(void* compass) {
	Compass* theCompass = (Compass*)compass;
	theCompass->Update();
}
