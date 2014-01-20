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
	int wheel = mWheel;
	printf("Wheel: %d value: %f", wheel, driveTrain->GetEncoderValue(wheel));
	if (wheel == FRENCODER) {
		CommandBase::persistedSettings->data["FR_ENCODER_OFFSET"] = driveTrain->GetEncoderValue(wheel);
	}else if (wheel == FLENCODER) {
		CommandBase::persistedSettings->data["FL_ENCODER_OFFSET"] = driveTrain->GetEncoderValue(wheel);
	}else if (wheel == BRENCODER) {
		CommandBase::persistedSettings->data["BR_ENCODER_OFFSET"] = driveTrain->GetEncoderValue(wheel);
	}else if (wheel == BLENCODER) {
		CommandBase::persistedSettings->data["BL_ENCODER_OFFSET"] = driveTrain->GetEncoderValue(wheel);
	}
	CommandBase::persistedSettings->WriteToFile(ENCODER_OFFSET_FILENAME);
	
}

bool SetEncoderOffsetCommand::IsFinished() {
	return true;
}

void SetEncoderOffsetCommand::End() {
	
}

void SetEncoderOffsetCommand::Interrupted() {
	
}
