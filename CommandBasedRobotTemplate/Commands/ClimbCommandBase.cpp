#include "ClimbCommandBase.h"


/*
 * ClimbCommandBase: Any command that is used in the autonomous
 * 					 climb must inherit this class and provide a 
 * 					 sequence number.
 * 					 
 * 					 When running the command manually create it
 * 					 like normal with the same sequence number that
 * 					 would be used for auto.
 * 					 
 * 					 When running the command in auto create it
 * 					 passing in true for autoCmd with the correct
 * 					 sequence number.
 */

int ClimbCommandBase::curSeqNumber = 0;
int ClimbCommandBase::climbLevel = 0;
ClimbCommandBase::ClimbCommandBase(int seqNum, const char *name, bool autoCmd) : CommandBase(name) {
	seqNumber = seqNum;
	finished = false;
	this->autoCmd = autoCmd;
	this->name = name;
}

/*
 * Initialize: Subclases should not reimplement this. 
 */
void ClimbCommandBase::Initialize() {
	//Check whether or not to skip this command.
	//TODO: May need to check if it's the previous command.
	if (curSeqNumber > seqNumber) {
		finished = true;
		return;
	}
	ClimbInitialize();
	printf("Initialize %s \n", name);
}

/*
 * Execute: Subclasses should not reimplement this.
 */
void ClimbCommandBase::Execute() {
	
	//Check that both deadman buttons are pressed.
	if ((oi->GetDeadMan1() && oi->GetDeadMan2()) || !autoCmd) {
		ClimbExecute();
	} else {
		finished = true;
	}
	//printf("    Execute %s sequence#: %d\n", name, seqNumber);
}

/*
 * ClimbExecute: The functionality normally acheived through 
 * 				 the Execute() method should be placed in 
 * 				 ClimbExecute.
 */

bool ClimbCommandBase::IsFinished() {
	return finished;
	//printf("    IsFinished %s \n", name);
}

/*
 * End: Subclasses should not reimplement this.
 */
void ClimbCommandBase::End() {
	if ((oi->GetDeadMan1() && oi->GetDeadMan2()) || !autoCmd) {
		curSeqNumber = seqNumber;
		if(strcmp(name, "LatchCommand") == 0){
			climbLevel ++;
			curSeqNumber = 0;
		}
	}
	ClimbEnd();
	printf("End %s \n", name);
}

/*
 * ClimbExecute: The functionality normally acheived through 
 * 				 the End() method should be placed in 
 * 				 ClimbEnd.
 */
