#include "DashboardDataSender.h"
#include "WPILib.h"

/**
 * Send data to the dashboard.
 * This class sends two types of data to the dashboard program:
 * 1. Data representing all the ports on the robot
 * 2. Camera tracking data so the dashboard can annotate the video stream with
 *    target information.
 */
DashboardDataSender::DashboardDataSender()
{
	// these timers make sure that the data is not sent to the dashboard more
	// than 10 times per second for efficiency.
	IOTimer = new Timer();
	IOTimer->Start();
}


void DashboardDataSender::sendTeamCustomData(	float baseDist, float adjDist, float totalDist,
												float botRPM, float topRPM, float shooterPWM,
												bool btnA, bool btnB, bool btnX, bool btnY,
												bool btnStart, bool btnSel,
												bool ballOne, bool ballTwo, bool ballThree, bool tunePid, bool camera
											) {
	if (IOTimer->Get() < 0.1)
		return;
	IOTimer->Reset();
	Dashboard &dash = DriverStation::GetInstance()->GetLowPriorityDashboardPacker();
	dash.AddCluster();
	{
		dash.AddBoolean(ballOne);
		dash.AddBoolean(ballTwo);
		dash.AddBoolean(ballThree);
		dash.AddBoolean(btnA);
		dash.AddBoolean(btnB);
		dash.AddBoolean(btnX);
		dash.AddBoolean(btnY);
		dash.AddBoolean(btnStart);
		dash.AddBoolean(btnSel);
		dash.AddDouble(baseDist);
		dash.AddDouble(adjDist);
		dash.AddDouble(totalDist);
		dash.AddBoolean(tunePid);
		dash.AddDouble(topRPM);
		dash.AddDouble(botRPM);
		dash.AddDouble(shooterPWM);
		dash.AddBoolean(camera);
	}
	dash.FinalizeCluster();
	dash.Finalize();
}
