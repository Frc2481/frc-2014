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
	static const float extendPosition = 2.575;
public:
	FullyExtendArmPositionCommand(int seq, bool autoCmd=false) : ArmPositionCommandBase(extendPosition, seq, autoCmd,"FullyExtendArmPositionCommand") {}
};

#endif
