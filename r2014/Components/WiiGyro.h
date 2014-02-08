/*
 * WiiGyro.h
 *
 *  Created on: Jan 14, 2014
 *      Author: Team2481
 */

#ifndef WiiGyro_H_
#define WiiGyro_H_
#include <WPILib.h>

class WiiGyro {
private:
	int yaw, pitch, roll;  //three axes
	int yaw0, pitch0, roll0;  //calibration zeroes
	double time, last_time;
	float delta_t;
	int last_yaw[3], last_pitch[3], last_roll[3];
	int yaw_deg2, pitch_deg2, roll_deg2;
	int startTag;
	int accel_x_axis, accel_y_axis, accel_z_axis;
	float yaw_deg, pitch_deg, roll_deg;
	bool first;
	bool resetWii;
	I2C *wiiGyroInitial;
	I2C *wiiGyro;
	DigitalModule *dm;
	Timer *timer;
	SEM_ID wiiSemaphore;
	Notifier* wiiUpdate;
	uint8_t data[6];	    //six data bytes
	void loop();

public:
	WiiGyro(uint8_t moduleNumber);
	~WiiGyro();
	void wmpOn();
	//void wmpSendZero();
	void calibrateZeroes();
	void receiveData();
	float rk4Integrate(int y4, int y3, int y2, int y1, float deltax);
	void setup();
	unsigned char bitRead(unsigned char in, unsigned char n);
	void reset();
	float GetYaw();
	float GetRate();
	static void LoopPeriodic(void *controller);
};

#endif /* WiiGyro_H_ */
