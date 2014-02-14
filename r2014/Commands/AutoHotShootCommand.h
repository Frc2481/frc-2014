/*
 * ShootWhenHotCommand.h
 *
 *  Created on: Jan 11, 2014
 *      Author: Team2481
 */

#ifndef SHOOTWHENHOTCOMMAND_H_
#define SHOOTWHENHOTCOMMAND_H_

#include "../CommandBase.h"
#include "ManualFireShooterCommand.h"

class ShootWhenHotCommand: public CommandBase{
private:
	static bool hot;
	static bool shot;
public:
	ShootWhenHotCommand(){
	}
	virtual ~ShootWhenHotCommand(){
		
	}
	
	virtual void Initialize() {
		
	}
	
	virtual void Execute() {
		if (camera->HasTarget()) {
			hot = true;
		}
		
		double t = TimeSinceInitialized();
		if (t > 3 && t < 7) {
			
			if (hot && !shot) {
				shot = true;
				//TODO: Fire
			}
			
		} else if (t >= 7){
			
			if (!shot) {
				shot = true;
				//TODO: Fire
			}
		}
			
	}
	
	virtual bool IsFinished() {
		return hot && shot;
	}
	
	virtual void End() {
		
	}
	
	virtual void Interrupted() {
		
	}
};
bool ShootWhenHotCommand::hot = false;
bool ShootWhenHotCommand::shot = false;

#endif
