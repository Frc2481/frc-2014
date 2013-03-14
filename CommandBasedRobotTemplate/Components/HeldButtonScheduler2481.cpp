/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/
#include "HeldButtonScheduler2481.h"
#include "WPILib.h"

HeldButtonScheduler2481::HeldButtonScheduler2481(bool last, Trigger *button, Command *orders) :
	ButtonScheduler(last, button, orders)
{
}

void HeldButtonScheduler2481::Execute()
{
	if (m_button->Grab())
	{
		m_pressedLast = true;
		m_command->Start();
	}
	else
	{
		if (m_pressedLast && m_command->IsInterruptible())
		{
			m_pressedLast = false;
			m_command->Cancel();
		}
	}
}
