/*
 * EXTI__APP.c
 *
 *  Created on: Feb 11, 2021
 *      Author: Elsaeed
 */



#include <stdint.h>

#include "../MCAL/SysTick_Driver/STK_Interface.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void Delay_ms(u32 Copy_u32Time)
{
	for(u32 i=0 ; i<Copy_u32Time ; i++ )
	{
		for(u16 j=0; j<565; j++)
		{
			asm("NOP");
		}
	}
}

void Ahmed1(void)
{
	GPIO_voidSetPinValue(PORTA, PIN5,HIGH);
	Delay_ms(1000);
	GPIO_voidSetPinValue(PORTA, PIN5, LOW);
	Delay_ms(1000);
}

void ahmed(void)
{
	GPIO_voidSetPinValue(PORTA, PIN4,HIGH);
	Delay_ms(1000);
	GPIO_voidSetPinValue(PORTA, PIN4, LOW);
	Delay_ms(1000);
}

int main(void)
{
	/*		RCC								*/
	RCC_voidInit();
	/*		GPIOA Enable					*/
	RCC_voidEnablePeripheralClock(RCC_APB2, 2);
	EXTI0_voidSetCallBack(ahmed);
	EXTI1_voidSetCallBack(Ahmed1);
	//EXTI9_5_voidSetCallBack(5, ahmed);
	/*		GPIO							*/
	/*		A0 input pull up for EXTI0		*/
	GPIO_voidSetPinDirection(PORTA, PIN0, GPIO_INPUT_PULL_UP_DOWN);
	GPIO_voidSetPinValue(PORTA, PIN0, HIGH);

	GPIO_voidSetPinDirection(PORTA, PIN1, GPIO_INPUT_PULL_UP_DOWN);
	GPIO_voidSetPinValue(PORTA, PIN1, HIGH);

	GPIO_voidSetPinDirection(PORTA, PIN4, GPIO_OUTPUT_2MHZ_PP);
	//GPIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_2MHZ_PP);

	/*		NVIC					*/
	NVIC_voidInit();
	NVIC_voidEnableInterrupt(6);
	NVIC_voidEnableInterrupt(7);
	NVIC_voidEnableInterrupt(23);

	//NVIC_voidSetPendingFlag(6);
	NVIC_voidSetPriority(6, 0b0101);
	NVIC_voidSetPriority(7, 0b0001);

	/*		EXTI					*/

	EXTI_voidInit();
	EXTI_voidEnableLine(0);
	EXTI_voidEnableLine(1);
	//EXTI_voidEnableLine(5);




	//EXTI_voidSetSoftwareTrigger(5);

    /* Loop forever */
	for(;;);
}
