/*
 * SysTick_Interface.h
 *
 *  Created on: Feb 9, 2021
 *      Author: Elsaeed
 */

#ifndef MCAL_SYSTICK_DRIVER_STK_INTERFACE_H_
#define MCAL_SYSTICK_DRIVER_STK_INTERFACE_H_


void STK_voidInit(void);
void STK_voidSetBusyWait(u32);
void STK_voidSetCallBack(void (*pf) (void) );



void STK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void STK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void STK_voidStopInterval(void);
u32  STK_u32GetElapsedTime(void);
u32  STK_u32GetRemainingTime(void);






#endif /* MCAL_SYSTICK_DRIVER_STK_INTERFACE_H_ */
