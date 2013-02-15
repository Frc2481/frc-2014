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
	static const float firstRungPosition = 1.35;
public:
	FirstRungArmPositionCommand(int seq, bool autoCmd=false):ArmPositionCommandBase(firstRungPosition, seq, autoCmd, "firstRungPositionCommand") {}
};

#endif
