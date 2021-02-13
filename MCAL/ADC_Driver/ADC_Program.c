/*
 * ADC_Program.c
 *
 *  Created on: Feb 13, 2021
 *      Author: Elsaeed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_Interface.h"
#include "ADC_Privet.h"
#include "ADC_Config.h"

void ADC_voidInitialize(void){

	//CLR_BIT(ADC1 -> CR2,0);	/* ADC1 disable */
	ADC1 -> CR2 = 0; 			/* ADC1 disable */



}
void ADC_voidEnable(void){

	SET_BIT(ADC1 -> CR2,0);
}
void ADC_voidDisable(void){
	CLR_BIT(ADC1 -> CR2,0);
}
void ADC_voidStartConv (void){
	u16 Local_u32TimeOut = 0;
	SET_BIT(ADC1 -> CR2,22);
/*	while((GET_BIT(ADC1 -> SR,4)==0) && Local_u32TimeOut<10000){  	wait for conversion start
		Local_u32TimeOut++;
	}
	*/
}


void ADC_voidIntEnable(void)
{
	SET_BIT(ADC1 -> CR1,5);
}
void ADC_voidIntDisable(void)
{
	CLR_BIT(ADC1 -> CR1,5);
}
