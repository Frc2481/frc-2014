#ifndef EXAMPLE_COMMAND_H
#define EXAMPLE_COMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/Intake.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class TurnOnIntakeCommand :  public CommandBase {
public:
	TurnOnIntakeCommand() {
		Requires(intake);
	}
	virtual void Initialize(){}
	virtual void Execute(){
		if(!intake->HasBall()){
			intake->SuckIn();	
		}
	}
	virtual bool IsFinished(){
		return true;
	}
	virtual void End() {}
	virtual void Interrupted() {
		End();
	}
};

#endif
