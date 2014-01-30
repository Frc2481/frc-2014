#ifndef TURNOFFINTAKECOMMAND_H
#define TURNOFFINTAKECOMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/Intake.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class TurnOffIntakeCommand: public CommandBase {
public:
	TurnOffIntakeCommand();
	virtual void Initialize();
	virtual void Execute(){
		intake->Stop();
	}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End();
	virtual void Interrupted();
};

#endif
