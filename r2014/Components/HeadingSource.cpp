/*
 * HeadingSource.cpp
 *
 *  Created on: Jan 13, 2014
 *      Author: Team2481
 */

#include "HeadingSource.h"
#include <cmath>

#define PI 3.14159265358979323846264338327950288419716939

HeadingSource::HeadingSource(uint32_t gyroChannel, uint8_t compassChannel)
		: csvFile(CSVRecord::getInstance()){
	gyro = new Gyro(gyroChannel);
	wiiGyro = new WiiGyro(compassChannel);
	//compass = new Compass(compassChannel);
	//compass = new LSM303(compassChannel);
	//compass->init();
	prevHeading = 0;
	compassCounter = 0;
	gyroCounter = 0;
	prevCompass = 0;
	heading = 0;
	fieldHeadingOffset = 0;
	runningMax.x = 	runningMax.y = runningMax.z = -32768;
	runningMin.x = runningMin.y = runningMin.z = 32767;
	
	csvFile.Write("Gyro Angle,Gyro Rate,Compass X,Compass Y,Compass Z");

//	compass->m_max.x = (int16_t)PersistedSettings::GetInstance().Get("compassXMax");
//	compass->m_max.y = (int16_t)PersistedSettings::GetInstance().Get("compassYMax");
//	compass->m_max.z = (int16_t)PersistedSettings::GetInstance().Get("compassZMax");
//	compass->m_min.x = (int16_t)PersistedSettings::GetInstance().Get("compassXMin");
//	compass->m_min.y = (int16_t)PersistedSettings::GetInstance().Get("compassYMin");
//	compass->m_min.x = (int16_t)PersistedSettings::GetInstance().Get("compassZMin");
	
	printf("xMin %d, yMin %d, zMin %d, xMax %d, yMax %d, zMin %d \n", runningMin.x, runningMin.y, runningMin.z, runningMax.x, runningMax.y, runningMax.z);	
}

HeadingSource::~HeadingSource() {
	delete gyro;
//	delete compass;
}

float HeadingSource::GetHeading(){
	periodic();
	return heading;
}


void HeadingSource::setFieldHeadingOffset(float offset){

	printf("reseting heading \n");
    fieldHeadingOffset = offset;
}

void HeadingSource::periodic(){
	
	//wiiGyro->loop();
//	compass->read();
	SmartDashboard::PutNumber("GyroRate",gyro->GetRate());
    //float rawCompassAngle = compass->heading();

   //_compassAccum.add(compass->heading());
    
    _gyroSinAccum.add(sin(gyro->GetAngle() / 180 * PI));
    _gyroCosAccum.add(cos(gyro->GetAngle() / 180 * PI));
    float gyroAvg = (int)((atan2(_gyroSinAccum.avg(), _gyroCosAccum.avg()) * 180 / PI) + 360) % 360;
    
//    _compassSinAccum.add(sin(compass->heading() / 180 * PI));
//    _compassCosAccum.add(cos(compass->heading() / 180 * PI));
//    float compassAngle = (int)((atan2(_compassSinAccum.avg(), _compassCosAccum.avg()) * 180 / PI) + 360) % 360;
//    
    
   // SmartDashboard::PutNumber("GyroAngle", (int)(gyroAvg) % 360);
//    SmartDashboard::PutNumber("CompassHeading", (int)(compassAngle) % 360);
    SmartDashboard::PutNumber("RawGyroAngle", gyro->GetAngle());
//    SmartDashboard::PutNumber("RawCompassAngle", compass->heading());
    
    _gyroRateAccum.add(fabs(gyro->GetRate()));
    
    
    if(_gyroRateAccum.avg() < 20){
        gyroCounter++;
    }else{
        gyroCounter = 0;
    }

//    if(fabs(compassAngle - prevCompass) < 10){
//        compassCounter++;
//    }else{
//        compassCounter = 0;
//    }
//    
//    prevCompass = compassAngle;
    
    if(gyroCounter > 25 && compassCounter > 15){
   // if (_compassAccum.stddev() < 2){
//        prevHeading = compassAngle;
       // gyro->Reset();
//        compassCounter = 0;
        gyroCounter = 0;
        printf("Zeroing gyro\n");
    }
   
    //prevCompass = compassAngle;

    SmartDashboard::PutNumber("prevHeading", prevHeading);
    
    heading = (int)gyroAvg % 360;
    //heading = (int)(fieldHeadingOffset + prevHeading + gyroAvg + 360) %360;
    //printf("%f %f %f %f \n", heading, fieldHeadingOffset, prevHeading, gyro->GetAngle());
    SmartDashboard::PutNumber("RobotHeading", heading);

    SmartDashboard::PutNumber("gyroAngle", gyro->GetAngle());
    
//    stringstream headingValues;
//    headingValues << gyro->GetAngle() << "," << gyro->GetRate() << "," << compass->m.x << "," << compass->m.y << "," << compass->m.z;
//    
//    csvFile.Write(headingValues.str());
    
}
void HeadingSource::ResetGyro(){
	gyro->Reset();
}
void HeadingSource::CompassPeriodic(bool done){
//	printf("xMin %d, yMin %d, zMin %d, xMax %d, yMax %d, zMin %d \n", runningMin.x, runningMin.y, runningMin.z, runningMax.x, runningMax.y, runningMax.z);	
//
//	runningMin.x = min(runningMin.x, compass->m.x);
//	runningMin.y = min(runningMin.y, compass->m.y);
//	runningMin.z = min(runningMin.z, compass->m.z);
//
//	runningMax.x = max(runningMax.x, compass->m.x);
//	runningMax.y = max(runningMax.y, compass->m.y);
//	runningMax.z = max(runningMax.z, compass->m.z);
//	
//	if (done)
//	{
//		PersistedSettings::GetInstance().Set("compassXMin", (double)runningMin.x);
//		PersistedSettings::GetInstance().Set("compassYMin", (double)runningMin.y);
//		PersistedSettings::GetInstance().Set("compassZMin", (double)runningMin.z);
//		
//		PersistedSettings::GetInstance().Set("compassXMax", (double)runningMax.x);
//		PersistedSettings::GetInstance().Set("compassYMax", (double)runningMax.y);
//		PersistedSettings::GetInstance().Set("compassZMax", (double)runningMax.z);
//		
//		compass->m_max.x = runningMax.x;
//		compass->m_max.y = runningMax.y;
//		compass->m_max.z = runningMax.z;
//		compass->m_min.x = runningMin.x;
//		compass->m_min.y = runningMin.y;
//		compass->m_min.x = runningMin.z;
//	}
}

/*void HeadingSource::SetOffset(){
	fieldHeadingOffset = -compass->heading();
	printf("reseting heading \n");
}*/
