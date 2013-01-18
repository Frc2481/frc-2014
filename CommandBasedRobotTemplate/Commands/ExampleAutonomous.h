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
		AddSequential(new DriveForwardCommand(1,1));
		AddSequential(new DriveBackwardCommand(1,1));
		AddSequential(new TurnRightCommand(1,1));
		AddSequential(new TurnLeftCommand(1,1));
		AddSequential(new StopDriveCommand());
	}
};

#endif
