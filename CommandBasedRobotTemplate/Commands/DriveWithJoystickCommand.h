#ifndef DRIVE_WITH_JOYSTICK_COMMAND_H
#define DRIVE_WITH_JOYSTICK_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/DriveTrain.h"

/**
 *
 *
 * @author jacobM
 */
class DriveWithJoystickCommand: public CommandBase {
public:
	DriveWithJoystickCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
