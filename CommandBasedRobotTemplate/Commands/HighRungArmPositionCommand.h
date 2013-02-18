/*
 * HighRungArmPositionCommand.h
 *
 *  Created on: Feb 17, 2013
 *      Author: Team2481
 */

#ifndef HIGHRUNGARMPOSITIONCOMMAND_H_
#define HIGHRUNGARMPOSITIONCOMMAND_H_

#include "ArmPositionCommandBase.h"

class HighRungArmPositionCommand: public ArmPositionCommandBase{
private:
	static const float highRungPosition = HIGH_RUNG_POSITION;
public:
	HighRungArmPositionCommand(): ArmPositionCommandBase(highRungPosition, "FullyExtendArmPositionCommand"){}
};

#endif /* HIGHRUNGARMPOSITIONCOMMAND_H_ */
