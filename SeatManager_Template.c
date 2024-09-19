/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/19/2024 06:10 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManager.h"

/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */
 
 
 StepMotorStepType setMotorSetAuto(SensorPositionType position, SensorWeightTupe weight)
 {
	 StepMotorStepType step;
	if(weight > 100 )
	{
		if(position > SENSOR_POSITION_STEP_3)
		{
			step = MOTOR_STEP_MINUS;
		}
		else if(position < SENSOR_POSITION_STEP_3)
		{
			step = MOTOR_STEP_PLUS;
		}
	}
	else if(weight > 80)
	{
		if(position > SENSOR_POSITION_STEP_2)
		{
			step = MOTOR_STEP_MINUS;
		}
		else if(position < SENSOR_POSITION_STEP_2)
		{
			step = MOTOR_STEP_PLUS;
		}
	}
	else if(weight > 60)
	{
		if(position > SENSOR_POSITION_STEP_1)
		{
			step = MOTOR_STEP_MINUS;
		}
		else if(position < SENSOR_POSITION_STEP_1)
		{
			step = MOTOR_STEP_PLUS;
		}
	}
	else
	{
		if(position > SENSOR_POSITION_STEP_0)
		{
			step = MOTOR_STEP_MINUS;
		}
		else if(position < SENSOR_POSITION_STEP_0)
		{
			step = MOTOR_STEP_PLUS;
		}
	}
 }

void SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightTupe weight;

	/* Server Call Points */
	status = Rte_Call_rpSlideSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	
	step = setMotorSetAuto(position, weight);
	Rte_Call_rpHeightMotor_Move(step);
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightTupe weight;

	/* Server Call Points */
	status = Rte_Call_rpSlideSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	
	step = setMotorSetAuto(position, weight);
	Rte_Call_rpInclineMotor_Move(step);
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightTupe weight;

	/* Server Call Points */
	status = Rte_Call_rpSlideSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&weight);
	
	step = setMotorSetAuto(position, weight);
	Rte_Call_rpSlideMotor_Move(step);
}



/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(HeightBtnState == MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
	}
	
}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpInclineMototor_Move(MOTOR_STEP_MINUS);
	}
	else if(InclineBtnState == MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
	}
	
}



/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */
void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType SlideBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	}
	else if(SlideBtnState == MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
	}
	
	
}

