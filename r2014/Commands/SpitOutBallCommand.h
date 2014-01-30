#ifndef EXAMPLE_COMMAND_H
#define EXAMPLE_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/Intake.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class SpitOutBallCommand: public CommandBase {
public:
	SpitOutBallCommand();
	virtual void Initialize();
	virtual void Execute(){
		intake->SpitOut();
	}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End();
	virtual void Interrupted();
};

#endif
