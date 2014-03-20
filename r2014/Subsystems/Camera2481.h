	/*
 * Camera.h
 *
 *  Created on: Jan 10, 2014
 *      Author: Team2481
 */

#ifndef CAMERA_2481_H_
#define CAMERA_2481_H_
#include <WPILib.h>

class Camera2481 : public Subsystem {
private:
	NetworkTable* mTable;
	bool hotTarget;
public:
	Camera2481();
	void CheckHotTarget();
	bool HasTarget();
	virtual ~Camera2481();
};

#endif /* CAMERA_H_ */
