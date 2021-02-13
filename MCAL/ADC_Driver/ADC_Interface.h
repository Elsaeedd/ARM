/*
 * ADC_Interface.h
 *
 *  Created on: Feb 13, 2021
 *      Author: Elsaeed
 */

#ifndef MCAL_ADC_DRIVER_ADC_INTERFACE_H_
#define MCAL_ADC_DRIVER_ADC_INTERFACE_H_



void ADC_voidInitialize(void);
void ADC_voidEnable(void);
void ADC_voidDisable(void);
void ADC_voidStartConv (void);
void ADC_voidIntEnable(void);
void ADC_voidIntDisable(void);


#endif /* MCAL_ADC_DRIVER_ADC_INTERFACE_H_ */
