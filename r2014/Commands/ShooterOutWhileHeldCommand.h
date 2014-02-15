#ifndef SHOOTEROUTWHILEHELDCOMMAND_H
#define SHOOTEROUTWHILEHELDCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class ShooterOutWhileHeldCommand : public CommandBase {
public:
	ShooterOutWhileHeldCommand(){
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
