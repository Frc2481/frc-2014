/*
 * Shooter.h
 *
 *  Created on: Jan 30, 2014
 *      Author: Team2481
 * 		Editor: paulRich, thomasSpeciale
 */

#ifndef SHOOTER_H_
#define SHOOTER_H_

#include "WPILib.h"
#include "../Components/PController.h"
#include "../RobotParameters.h"
#include "../Components/ContinuousEncoderCounter.h"

class Shooter : public Subsystem, public LiveWindowSendable, public ITableListener {
private:
	Talon *winch;
	ContinuousEncoderCounter *winchSensor;
	Solenoid *shooterEarLeft;
	Solenoid *shooterEarRight;
	Solenoid *release;
	float position;
	DigitalInput *potSwitch;
	float offset;
	int switchCounter;
	bool latched;
	ITable *m_table;
	bool hasSetPosition;
	int onTargetCounter;
	
public:
	Shooter(uint32_t winchChannel, uint32_t winchSensorChannel, uint32_t earChannelL, uint32_t earChannelR, uint32_t releaseChannel, uint32_t potSwitchChannel);
	virtual ~Shooter();
	void Fire(float distance);
	void Load();
	void SetRightEar(bool position);
	void SetLeftEar(bool position);
	bool GetLeftEar();
	bool GetRightEar();
	void Periodic();
	void ManualRetractWinch(float speed = 1);
	void ManualReleaseWinch(float speed = 1);
	void ManualFire();
	void ManualStopWinch();
	void ManualLatch();
	void ManualUnlatch();
	void SetPosition(float pos);
	void SetPosition(float pos, bool earsUp);
	float GetSetPoint();
	float GetPosition();
	bool GetSwitch();
	bool IsLatched();
	void InitDefaultCommand();
	void InitTable(ITable* table);
	virtual ITable* GetTable();
	virtual std::string GetSmartDashboardType();
	virtual void ValueChanged(ITable* source, const std::string& key, EntryValue value, bool isNew);
	virtual void UpdateTable();
	virtual void StartLiveWindowMode();
	virtual void StopLiveWindowMode();
	float GetRawPosition();
	void RetractSlack();
	void CockWinch();
	void SetPositionVolts(float userPosition);
	float GetDistance();
	bool OnTarget();
	bool HasSetPosition();
	void ManualSetDistance(float pos, bool earsUp);
};

#endif /* SHOOTER_H_ */
