#ifndef STARTING_POSITION_ARM_COMMAND_H
#define STARTING_POSITION_ARM_COMMAND_H

#include "ArmPositionCommandBase.h"

/**
 *
 *
 * @author jonathanB
 */
class StartingPositionArmCommand: public ArmPositionCommandBase {
private:
	static const float startingPosition = .5;
public:
	StartingPositionArmCommand(): ArmPositionCommandBase(startingPosition, "StartingPositionArmCommand") {}
};


#endif
