#ifndef WAITFORBALLCOMMAND_H
#define WAITFORBALLCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class WaitForBallCommand: public CommandBase {
public:
	WaitForBallCommand() : CommandBase("WaitForBallCommand"){
	}
	virtual ~WaitForBallCommand(){}
	virtual void Initialize() {}
	virtual void Execute() {}
	virtual bool IsFinished(){
		return intake->HasBall();
	}
	virtual void End() {}
	virtual void Interrupted() {}
};

#endif
