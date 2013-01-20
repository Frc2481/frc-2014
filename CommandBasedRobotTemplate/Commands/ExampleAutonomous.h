#ifndef EXAMPLE_AUTONOMOUS_COMMAND_H
#define EXAMPLE_AUTONOMOUS_COMMAND_H

#include "Commands/CommandGroup.h"
#include "DriveForwardCommand.h"
#include "DriveBackwardCommand.h"
#include "TurnRightCommand.h"
#include "TurnLeftCommand.h"
#include "StopDriveCommand.h"

/**
 *
 *
 * @author jacobM
 */
class ExampleAutonomousCommand: public CommandGroup {
public:
	ExampleAutonomousCommand() {
		AddSequential(new DriveForwardCommand(.5,5));
		AddSequential(new DriveBackwardCommand(.5,5));
		AddSequential(new TurnRightCommand(.5,1));
		AddSequential(new TurnLeftCommand(.5,1));
		AddSequential(new StopDriveCommand());
	}
};

#endif
