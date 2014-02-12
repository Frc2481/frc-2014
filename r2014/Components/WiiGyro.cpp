/*
 * WiiGyro.cpp
 *
 *  Created on: Jan 14, 2014
 *      Author: Team2481
 */
#include "wiiGyro.h"
#include <cmath>
#define steps_per_deg_slow 25.6 //20
#define steps_per_deg_fast 2.85  //4

WiiGyro::WiiGyro(uint8_t moduleNumber)  : 
	wiiSemaphore(semMCreate(SEM_Q_PRIORITY)),
	wiiUpdate(new Notifier(WiiGyro::LoopPeriodic, this)){
	
	dm = DigitalModule::GetInstance(moduleNumber);
	wiiGyroInitial = dm->GetI2C(0xa6);
	wiiGyro = dm->GetI2C(0xa4);
	startTag=0xDEAD;
	timer = new Timer();
	timer->Start();
	time = 0;
	last_time = 0;
	yaw0 = 0;
	pitch0 = 0;
	roll0 = 0;
	yaw = 0;
	pitch = 0;
	roll = 0;
	yaw_deg = 0;
	pitch_deg = 0;
	roll_deg = 0;
	first = true;
	resetWii = false;
	
	memset(data, 0, sizeof(uint8_t) * 6);
	memset(last_pitch, 0, sizeof(int) * 3);
	memset(last_yaw, 0, sizeof(int) * 3);
	memset(last_roll, 0, sizeof(int) * 3);
//	for (uint32_t i = 0; i < 255; ++i) {
//		I2C* i2c = dm->GetI2C(i);
//		printf("Address %x: %d", (int)i, i2c->AddressOnly());
//	}
//	wmpOn();					//turn WM+ on
//	calibrateZeroes();		  //calibrate zeroes
//	setup();

	wiiUpdate->StartPeriodic(.01);
}

WiiGyro::~WiiGyro(){
	delete wiiGyro; 
}

void WiiGyro::wmpOn(){
	uint8_t temp;
	wiiGyroInitial->Write(0xfe, 0x04);		     //send 0x04 to address 0xFE to activate WM+
	
//	uint8_t msg[2];
//	msg[0] = 0xfe;
//	msg[1] = 0x04;
//	wiiGyroInitial->Transaction(&msg[0],2,NULL,0);
}
/*
void WiiGyro::wmpSendZero(){
  //wiiGyro->Write(0x00, 0x00);		     //send zero to signal we want info
	wiiGyro->Transaction(0x00,1,NULL,0);
}
*/
void WiiGyro::calibrateZeroes(){
	uint8_t temp;
	wiiGyro->Transaction(0,0,&temp,1);
	printf("%#010x\n", temp);
	
    yaw0 = 0;	  //average 10 readings for each zero
    pitch0 = 0;
    roll0 = 0;
  for (int i=0;i<10;i++){
    //wmpSendZero();
    //wiiGyro->Read(0xa400fa, 6 , &data[0]);
	  //uint8_t sendBuffer[1]={0};
	  wiiGyro->Transaction(0x00, 1, 0, 0);
//	  wiiGyro->Transaction(sendBuffer,1,0,0);
	  wiiGyro->Transaction(0,0,&data[0],1);
	  wiiGyro->Transaction(0,0,&data[1],1);
	  wiiGyro->Transaction(0,0,&data[2],1);
	  wiiGyro->Transaction(0,0,&data[3],1);
	  wiiGyro->Transaction(0,0,&data[4],1);
	  wiiGyro->Transaction(0,0,&data[5],1);
    yaw0+=(((data[3]>>2)<<8)+data[0])/10;	  //average 10 readings for each zero
    pitch0+=(((data[4]>>2)<<8)+data[1])/10;
    roll0+=(((data[5]>>2)<<8)+data[2])/10;
    
     // printf("%d %d %d %d %d %d \n", data[0], data[1],data[2],data[3],data[4],data[5]);
  }
  printf("Zeros: %d \n", yaw0);
}

void WiiGyro::receiveData(){
	//wmpSendZero();			 
	//send zero before each request (same as nunchuck)
	
//  wiiGyro->Transaction(0x00,1,&data[0],6);
  
  //WPI Lib can't handle reading more than 4 bytes at a time
  //so we are reading these 1 byte at a time.
//  uint8_t sendBuffer[1]={0};
//  wiiGyro->Transaction(sendBuffer,1,0,0);
  wiiGyro->Transaction(0x00, 1, 0, 0);
  wiiGyro->Transaction(0,0,&data[0],1);
  wiiGyro->Transaction(0,0,&data[1],1);
  wiiGyro->Transaction(0,0,&data[2],1);
  wiiGyro->Transaction(0,0,&data[3],1);
  wiiGyro->Transaction(0,0,&data[4],1);
  wiiGyro->Transaction(0,0,&data[5],1);
  if(bitRead(data[3], 1)==1) yaw= - (int)((((data[3]>>2)<<8)+data[0]-yaw0)/steps_per_deg_slow);	  //see http://wiibrew.org/wiki/Wiimote/Extension_Controllers#Wii_Motion_Plus
  else yaw= - (int)((((data[3]>>2)<<8)+data[0]-yaw0)/steps_per_deg_fast);
  
  //if(bitRead(data[3], 0)==1) pitch=(int)((((data[4]>>2)<<8)+data[1]-pitch0)/steps_per_deg_slow);    //for info on what each byte represents
  //else pitch=(int)((((data[4]>>2)<<8)+data[1]-pitch0)/steps_per_deg_fast);
  
  //if(bitRead(data[4], 1)==1) roll=(int)((((data[5]>>2)<<8)+data[2]-roll0)/steps_per_deg_slow);
  //else roll=(int)((((data[5]>>2)<<8)+data[2]-roll0)/steps_per_deg_fast);
  //printf("%d %d %d %d %d %d", data[0], data[1],data[2],data[3],data[4],data[5]);

  SmartDashboard::PutNumber("Wii Gyro Yaw Rate", yaw);
  static int i = 0;
  SmartDashboard::PutNumber("Wii Gyro Yaw Mode", bitRead(data[3], 1)*100 + (++i % 2) );
}

float WiiGyro::rk4Integrate(int y4, int y3, int y2, int y1, float deltax){
  float area=0;
  area=((y4+2*y3+2*y2+y1)/6)*deltax/1000;
  return area;
}

void WiiGyro::setup(){
  //wiiGyro.begin();
	wmpOn();	//turn WM+ on
	while(wiiGyro->AddressOnly()){
		Wait(1);
	}
  calibrateZeroes();		  //calibrate zeroes
  //Wait(10);

  //pinMode(4, INPUT);
  }

void WiiGyro::loop(){
	if (!wiiGyroInitial->AddressOnly()) {
		wmpOn();
	}
	else if(!wiiGyro->AddressOnly()){
		uint8_t progress;
		wiiGyro->Read(0xf7, 1, &progress);
		if (progress != 0xE){
			first = true;
			CRITICAL_REGION(wiiSemaphore){
				yaw_deg = 0;
			}
			END_REGION;
			return;
		}
		else if(first) {
			printf("calibrating zeroes \n");
			Wait(5);
			calibrateZeroes();
			calibrateZeroes();
			resetWii = true;
			first = false;
		}
	}
	
	if (resetWii){
		time = last_time = 0;
		yaw = pitch = roll = 0;
		yaw_deg = pitch_deg = roll_deg = 0;
		memset(data, 0, sizeof(uint8_t) * 6);
		memset(last_pitch, 0, sizeof(int) * 3);
		memset(last_yaw, 0, sizeof(int) * 3);
		memset(last_roll, 0, sizeof(int) * 3);
		resetWii = false;
	  }
	
	float yawTemp;
	float pitchTemp;
	float rollTemp;
	

	receiveData();	
	//receive data and calculate yaw pitch and roll

  /* Runge-kutta 4th Order Integration */
  
  time = timer->Get() * 1000;
  delta_t = time - last_time;
  last_time = timer->Get() * 1000;

  CRITICAL_REGION(wiiSemaphore) {
	  yawTemp = yaw_deg;
	  pitchTemp = pitch_deg;
	  rollTemp = roll_deg;		

	  yawTemp+=rk4Integrate(yaw, last_yaw[0], last_yaw[1], last_yaw[2], delta_t);
	 // pitchTemp+=rk4Integrate(pitch, last_pitch[0], last_pitch[1], last_pitch[2], delta_t);
	 // rollTemp+=rk4Integrate(roll, last_roll[0], last_roll[1], last_roll[2], delta_t);

	  yaw_deg = yawTemp;
	  pitch_deg = pitchTemp;
	  roll_deg = rollTemp;
  }
  END_REGION;

  SmartDashboard::PutNumber("Wii Gyro Yaw", yawTemp);
  SmartDashboard::PutNumber("Wii Gyro pitch", pitchTemp);
  SmartDashboard::PutNumber("Wii Gyro roll",rollTemp);
  

  
  last_yaw[2]=last_yaw[1];
  last_pitch[2]=last_pitch[1];
  last_roll[2]=last_roll[1];
  last_yaw[1]=last_yaw[0];
  last_pitch[1]=last_pitch[0];
  last_roll[1]=last_roll[0];
  last_yaw[0]=yaw;
  last_pitch[0]=pitch;
  last_roll[0]=roll;
//
//  SmartDashboard::PutNumber("Delta t", delta_t);
  
  
  printf("wiiInitial %d \n", wiiGyroInitial->AddressOnly());
  printf("wiiGryo %d \n", wiiGyro->AddressOnly());
  /* Runge-kutta 4th Order Integration */

  /*if (digitalRead(4) == 1)
    {
    last_yaw[2]=0;
    last_pitch[2]=0;
    last_roll[2]=0;
    last_yaw[1]=0;
    last_pitch[1]=0;
    last_roll[1]=0;
    last_yaw[0]=0;
    last_pitch[0]=0;
    last_roll[0]=0;
    yaw = 0;
    pitch = 0;
    roll = 0;
    yawTemp = 0;
    pitchTemp = 0;
    rollTemp = 0;
    }*/
  //printf("Wii %d\n", wiiGyro->AddressOnly());
  //Wait(.01);

	//dprintf("postYawCalc %f \n", yaw_deg);
}

unsigned char WiiGyro::bitRead(unsigned char in, unsigned char n){
	return (in >> n)& 0x01;
}
void WiiGyro::reset(){
	resetWii = true;
	printf("\n \n Reset Wii \n \n");
}
float WiiGyro::GetYaw(){
	float temp_yaw_deg;
	CRITICAL_REGION(wiiSemaphore){
		temp_yaw_deg = yaw_deg;
	}
	END_REGION;
	return temp_yaw_deg;
}
float WiiGyro::GetRate()
{
	float temp_yaw_rate;
	CRITICAL_REGION(wiiSemaphore){
		temp_yaw_rate = yaw;
	}
	END_REGION;
	return temp_yaw_rate;
}

void WiiGyro::LoopPeriodic(void* instance) {
	WiiGyro* gyro = (WiiGyro*) instance;
	gyro->loop();
}

