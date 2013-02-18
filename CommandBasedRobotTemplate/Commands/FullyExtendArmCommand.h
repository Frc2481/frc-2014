#ifndef FULLY_EXTEND_ARM_COMMAND_COMMAND_H
#define FULLY_EXTEND_ARM_COMMAND_COMMAND_H

#include "ArmPositionCommandBase.h"

/**
 *
 *
 * @author jonathanB
 */
class FullyExtendArmPositionCommand: public ArmPositionCommandBase {
private:
	static const float extendPosition = ARM_OUT_LIMIT;
public:
	FullyExtendArmPositionCommand() : ArmPositionCommandBase(extendPosition, "FullyExtendArmPositionCommand") {}
};

#endif
