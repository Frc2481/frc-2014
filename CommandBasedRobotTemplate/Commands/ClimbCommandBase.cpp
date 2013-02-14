/*
 * ClimbCommandBase: Any command that is used in the autonomouse
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
class ClimbCommandBase : public CommandBase {
protected:
	static int _curSeqNumber;
	int _seqNumber;
	bool _finished;
	bool _autoCmd;
	
public:
	ClimbCommandBase(int seqNum, const char *name, bool autoCmd=false) : CommandBase(name) {
		_seqNumber = seqNum;
		_finished = false;
		_autoCmd = autoCmd;
	}
	
	/*
	 * Initialize: Subclases should not reimplement this. 
	 */
	void Initialize() {
		//Check whether or not to skip this command.
		if (_curSeqNumber != _seqNumber - 1) {
			_finished = true;
			return;
		}	
	}
	
	/*
	 * ClimbInitialize: The functionality normall acheived 
	 * 					through the Initialize() method should
	 * 					be placed in ClimbInitialize.
	 */
	virtual void ClimbInitialize() = 0;
	
	
	/*
	 * Execute: Subclasses should not reimplement this.
	 */
	void Execute() {
		
		//Check that both deadman buttons are pressed.
		if (oi->GetDeadMan1() && oi->GetDeadMan2()) {
			ClimbExecute();
		} else {
			_finished = true;
		}
	}
	
	/*
	 * ClimbExecute: The functionality normally acheived through 
	 * 				 the Execute() method should be placed in 
	 * 				 ClimbExecute.
	 */
	virtual void ClimbExecute() = 0;
	
	/*
	 * IsFinished: Subclasses should reimplement this using the
	 * 			   following format.
	 * 			   
	 * 	return [condition] || ClimbCommandBase::IsFinished();
	 */
	virtual bool IsFinished() {
		return _finished;
	}
	
	/*
	 * End: Subclasses should not reimplement this.
	 */
	void End() {
		_curSeqNumber = seqNumber;
		ClimbEnd();
	}
	
	/*
	 * ClimbExecute: The functionality normally acheived through 
	 * 				 the End() method should be placed in 
	 * 				 ClimbEnd.
	 */
	virtual void ClimbEnd() = 0;
	
	
	virtual void Interrupted();
}
int ClimbCommandBase::_curSeqNumber = 0;
