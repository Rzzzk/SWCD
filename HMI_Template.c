/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/19/2024 12:02 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

void HMI_MainFunction (void)
{
	Std_ReturnType Height_status;
	Std_ReturnType Incline_status;
	Std_ReturnType Slide_status;
	
	MultiStateBtnType HeightBtnState;
	MultiStateBtnType InclineBtnState;
	MultiStateBtnType SlideBtnState;
	
	
	uint8 Height;
	uint8 Incline;
	uint8 Slide;
	
	
	/* Data Receive Points */
	Height_status  = Rte_Read_rpSeatCtrlData_Height(&Height);
	Incline_status = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	Slide_status   = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	
	
	/*1. Convert Hight command to button command*/
	if( Height_status == RTE_E_NEVER_RECEIVED ||  Height == 0 )
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
	
	/*2. Convert incline command to button command*/
	if( Incline_status == RTE_E_NEVER_RECEIVED ||  Incline == 0 )
	{
		InclineBtnState = MULTI_STATE_BTN_INIT;
	}
	else if( Incline == 1 )
	{
		InclineBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if( Incline == 2 )
	{
		InclineBtnState = MULTI_STATE_BTN_PLUS;
	}
	
	/*3. Convert slide command to button command*/
	if( Slide_status == RTE_E_NEVER_RECEIVED ||  Slide == 0 )
	{
		SlideBtnState = MULTI_STATE_BTN_INIT;
	}
	else if( Slide == 1 )
	{
		SlideBtnState = MULTI_STATE_BTN_MINUS;
	}
	else if( Slide == 2 )
	{
		SlideBtnState = MULTI_STATE_BTN_PLUS;
	}
	
	/* Data Send Points */
	Height_status  = Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	Incline_status = Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	Slide_status   = Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	
}


/**
 *
 * Runnable SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_SeatModeBtn
 *
 */

void SeatModeChanged (void)
{
	Std_ReturnType status;
	SeatModeBtnType SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	/* Data Receive Points */
	status = Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);
	
	/* Mode Switch Points */
	status = Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
	
}

