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
	static const float retractPosition = ARM_IN_LIMIT;
public:
	FullyRetractArmPositionCommand(): ArmPositionCommandBase(retractPosition, "FullyRetractArmPositionCommand") {}
};

#endif
