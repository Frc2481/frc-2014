#ifndef INTAKEOUTWHILEHELDCOMMAND_H
#define INTAKEOUTWHILEHELDCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class IntakeOutWhileHeldCommand : public CommandBase {
public:
	IntakeOutWhileHeldCommand(){
		Requires(intake);
	}
	virtual void Initialize(){
		
	}
	virtual void Execute(){
		
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){
		
	}
	virtual void Interrupted(){
		End();
	}
};

#endif
