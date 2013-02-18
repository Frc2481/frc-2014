#ifndef FIRST_RUNG_POSITION_ARM_COMMAND_H
#define FIRST_RUNG_POSITION_ARM_COMMAND_H

#include "ArmPositionCommandBase.h"

/**
 *
 *
 * @author jonathanB
 */
class FirstRungArmPositionCommand: public ArmPositionCommandBase {
private:
	static const float firstRungPosition = ARM_FIRST_RUNG;
public:
	FirstRungArmPositionCommand():ArmPositionCommandBase(firstRungPosition, "firstRungPositionCommand") {}
};

#endif
