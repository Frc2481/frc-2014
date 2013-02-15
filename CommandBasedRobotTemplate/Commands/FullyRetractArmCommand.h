#ifndef FULLY_RETRACT_ARM_POSITION_COMMAND_H
#define FULLY_RETRACT_ARM_POSITION_COMMAND_H

#include "ArmPositionCommandBase.h"

/**
 *
 *
 * @author jonathanB
 */
class FullyRetractArmPositionCommand: public ArmPositionCommandBase {
private:
	static const float retractPosition = .91;
public:
	FullyRetractArmPositionCommand(int seq, bool autoCmd=false): ArmPositionCommandBase(retractPosition, seq, autoCmd, "FullyRetractArmPositionCommand") {}
};

#endif
