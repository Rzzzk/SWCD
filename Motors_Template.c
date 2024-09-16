/**
 *
 * \file Motors_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: Motors
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/16/2024 12:03 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_Motors.h"


#define MOTOR_STEP_MINUS   0
#define MOTOR_STEP_PLUS    1

/**
***   configure DIO channel IDs for each motor
**/
#define HeightMotor_ChannelId    10
#define SlideMotor_ChannelId     11
#define InclineMotor_ChannelId   12

/**
 *
 * Runnable HeightMotor
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightMotor_Move
 *
 */

void HeightMotor (StepMotorStepType step)
{
	
	if(step == MOTOR_STEP_MINUS)
	{
		Dio_WriteChannel(HeightMotor_ChannelId, MOTOR_STEP_MINUS);
	}
	else if(step == MOTOR_STEP_PLUS)
	{
		Dio_WriteChannel(HeightMotor_ChannelId, MOTOR_STEP_PLUS);
	}

}


/**
 *
 * Runnable SlideMotor
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Move
 *
 */

void SlideMotor (StepMotorStepType step)
{

	if(step == MOTOR_STEP_MINUS)
	{
		Dio_WriteChannel(SlideMotor_ChannelId, MOTOR_STEP_MINUS);
	}
	else if(step == MOTOR_STEP_PLUS)
	{
		Dio_WriteChannel(SlideMotor_ChannelId, MOTOR_STEP_PLUS);
	}
}


/**
 *
 * Runnable InclineMotor
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Move
 *
 */

void InclineMotor (StepMotorStepType step)
{
	if(step == MOTOR_STEP_MINUS)
	{
		Dio_WriteChannel(InclineMotor_ChannelId, MOTOR_STEP_MINUS);
	}
	else if(step == MOTOR_STEP_PLUS)
	{
		Dio_WriteChannel(InclineMotor_ChannelId, MOTOR_STEP_PLUS);
	}
}

