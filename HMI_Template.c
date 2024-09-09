/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/9/2024 05:10 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"


#define MULTI_STATE_BTN_INIT  0
#define MULTI_STATE_BTN_MINUS 1
#define MULTI_STATE_BTN_PLUS  2

/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	MultiStateBtnType InclineBtnState;
	MultiStateBtnType SlideBtnState;
	uint8 Height;
	uint8 Incline;
	uint8 Slide;
	
	
	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlData_Height(&Height);
	status = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	status = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	
	if( Height == 0 )
	{
		HeightBtnState = MULTI_STATE_BTN_INIT;
	}
	else if( Height == 1 )
	{
		HeightBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if( Height == 2 )
	{
		HeightBtnState = MULTI_STATE_BTN_PLUS;
	}
	
	/* Data Send Points */
	status = Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	status = Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	status = Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	
}

