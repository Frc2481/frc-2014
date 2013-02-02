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
	static const float retractPosition = .3;
public:
	FullyRetractArmPositionCommand( ): ArmPositionCommandBase(retractPosition, "FullyRetractArmPositionCommand") {}
};

#endif
