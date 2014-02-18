#ifndef SPITOUTBALLCOMMAND_H
#define SPITOUTBALLCOMMAND_H

#include "../CommandBase.h"
#include "../Subsystems/Intake.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class SpitOutBallCommand : public CommandBase {
public:
	SpitOutBallCommand(){
		Requires(intake);
	}
	virtual void Initialize(){
		
	}
	virtual void Execute(){
		if(intake->GetPosition()){
			intake->Vomit();
		}
	}
	virtual bool IsFinished(){
		return false;
	}
	virtual void End(){
		intake->RollerOff();
	}
	virtual void Interrupted(){
		End();
	}
};

#endif
