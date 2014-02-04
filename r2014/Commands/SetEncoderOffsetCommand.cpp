/*
 * SetEncoderOffsetCommand.cpp
 *
 *  Created on: Jan 18, 2014
 *      Author: Team2481
 */

#include "SetEncoderOffsetCommand.h"
#include "../Robotmap.h"

SetEncoderOffsetCommand::SetEncoderOffsetCommand(int wheel) 
		:	mWheel(wheel){
	// TODO Auto-generated constructor stub
}

SetEncoderOffsetCommand::~SetEncoderOffsetCommand() {
	// TODO Auto-generated destructor stub
}

void SetEncoderOffsetCommand::Initialize() {
	
}

void SetEncoderOffsetCommand::Execute() {
	return;
	int wheel = mWheel;
	printf("Wheel: %d value: %f", wheel, driveTrain->GetEncoderValue(wheel));
	if (wheel == FRENCODER) {
		PersistedSettings::GetInstance().Set("FR_ENCODER_OFFSET", (int)(driveTrain->GetEncoderValue(wheel) + 180) % 360);
	}else if (wheel == FLENCODER) {
		PersistedSettings::GetInstance().Set("FL_ENCODER_OFFSET", (int)(driveTrain->GetEncoderValue(wheel) + 180) % 360);
	}else if (wheel == BRENCODER) {
		PersistedSettings::GetInstance().Set("BR_ENCODER_OFFSET", (int)(driveTrain->GetEncoderValue(wheel) + 180) % 360);
	}else if (wheel == BLENCODER) {
		PersistedSettings::GetInstance().Set("BL_ENCODER_OFFSET", (int)(driveTrain->GetEncoderValue(wheel) + 180) % 360);
	}
	PersistedSettings::GetInstance().WriteToFile(ENCODER_OFFSET_FILENAME);
}

bool SetEncoderOffsetCommand::IsFinished() {
	return true;
}

void SetEncoderOffsetCommand::End() {
	
}

void SetEncoderOffsetCommand::Interrupted() {
	
}
