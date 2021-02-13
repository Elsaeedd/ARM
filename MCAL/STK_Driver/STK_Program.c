/*
 * STK_Program.c
 *
 *  Created on: Feb 9, 2021
 *      Author: Elsaeed
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_Interface.h"
#include "STK_Config.h"
#include "STK_Privet.h"


static void (*STK_pfCallBack)(void) ;
STK_Interval_Type STK_BoolModeOfInterval;

void STK_voidInit(void){
#if STK_CLK == STK_AHB
	/* Disable STK - Disable STK Interrupt - Set clock source AHB */
	STK -> CTRL = 0x00000004;
#elif  STK_CLK == STK_AHB_DIV_8
	/* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
	STK -> CTRL = 0x00000000;
#else
#error " Your STK_CLK choice is wrong "

#endif

}
void STK_voidSetBusyWait(u32 Copy_u32Ticks){
	/*		Range check on 24 Bits		*/
	if(Copy_u32Ticks <= 0x00FFFFFF)
	{
#if STK_CLK == STK_AHB
	/* Load ticks to load register */
	STK -> LOAD = ( Copy_u32Ticks * 1000/125 ) * 1000;
#elif  STK_CLK == STK_AHB_DIV_8
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks * 1000;

#else
#error " Your STK_CLK choice is wrong "

#endif


	/* Start Timer */
	SET_BIT(STK->CTRL, 0);


	/* Wait till flag is raised */
	while( (GET_BIT(STK->CTRL,16)) == 0);

	/* Stop Timer */
	//SET_BIT(STK->CTRL, 0);
	CLR_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
	}
	else
		{	/*		Return ERROR	*/	}

}

void STK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/*		Range check on 24 Bits		*/
	if(Copy_u32Ticks <= 0x00FFFFFF)
	{
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks * 1000;

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Save CallBack */
	STK_pfCallBack = Copy_ptr;

	/* Set Mode to Single */
	STK_BoolModeOfInterval = STK_SINGLE_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
	}
	else
		{	/*		Return ERROR	*/	}
}

void STK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{

	/*		Range check on 24 Bits		*/
	if(Copy_u32Ticks <= 0x00FFFFFF)
	{
		/* Load ticks to load register */
		STK -> LOAD = Copy_u32Ticks;

		/* Start Timer */
		SET_BIT(STK->CTRL, 0);

		/* Save CallBack */
		STK_pfCallBack = Copy_ptr;

		/* Set Mode to Periodic */
		STK_BoolModeOfInterval = STK_PERIODIC_INTERVAL;

		/* Enable STK Interrupt */
		SET_BIT(STK->CTRL, 1);
	}
	else
		{	/*		Return ERROR	*/	}
}

void STK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK->CTRL, 1);

	/* Stop Timer */
	SET_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
}

u32  STK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;

	Local_u32ElapsedTime = STK -> LOAD - STK -> VAL ;

	return Local_u32ElapsedTime;
}

u32  STK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime;

	Local_u32RemainTime = STK -> VAL ;

	return Local_u32RemainTime;
}


void STK_voidSetCallBack(void (*pf) (void) ){

	STK_pfCallBack = pf;

}


void SysTick_Handler(void)
{

	if (STK_BoolModeOfInterval == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK->CTRL, 1);

		/* Stop Timer */
		SET_BIT(STK->CTRL, 0);
		STK -> LOAD = 0;
		STK -> VAL  = 0;
	}

	/* Callback notification */
	STK_pfCallBack();

	/* Clear interrupt flag */
	GET_BIT(STK->CTRL,16);

}

