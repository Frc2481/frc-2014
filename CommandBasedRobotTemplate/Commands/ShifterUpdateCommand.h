#ifndef SHIFTER_UPDATE_COMMAND_H
#define SHIFTER_UPDATE_COMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author jacobM
 */
class ShifterUpdateCommand: public CommandBase {
public:
	ShifterUpdateCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
