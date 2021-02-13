/*
 * SysTick_Privet.h
 *
 *  Created on: Feb 9, 2021
 *      Author: Elsaeed
 */

#ifndef MCAL_SYSTICK_DRIVER_STK_PRIVET_H_
#define MCAL_SYSTICK_DRIVER_STK_PRIVET_H_


typedef struct
{
	volatile u32 	CTRL;
	volatile u32	LOAD;
	volatile u32 	VAL;
	volatile u32	CALIB;

}STK_Type;

typedef enum {
	STK_SINGLE_INTERVAL,
	STK_PERIODIC_INTERVAL
}STK_Interval_Type;


#define 	STK 		((STK_Type *)0xE000E010)


#define     STK_AHB      		     0
#define     STK_AHB_DIV_8      			 1


#endif /* MCAL_SYSTICK_DRIVER_STK_PRIVET_H_ */
