/*
 * GPIO_Program.c
 *
 *  Created on: Feb 3, 2021
 *      Author: Elsaeed
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_Privet.h"
#include "GPIO_Config.h"



void GPIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Mode){

	/* Range Check*/
	if(Copy_u8PortID < 3 && Copy_u8PinID <16 ){
		switch(Copy_u8PortID){
		case PORTA:
			if(Copy_u8PinID < 8){/* Low Port */
				/* to deal with bit masking
				 * 1 clear a specific bits
				 * 2 assign a  specific bits*/
				GPIOA_CRL &= ~((u32)(0b1111	  	)<<(Copy_u8PinID * 4));
				GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
			}
			else {				/* High Port */
				Copy_u8PinID -= 8 ;
				GPIOA_CRH &= ~((u32)(0b1111	  	)<<(Copy_u8PinID * 4));
				GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
			}
			break;
		case PORTB:
			if(Copy_u8PinID < 8){/* Low Port */
				GPIOB_CRL &= ~((u32)(0b1111	  	)<<(Copy_u8PinID * 4));
				GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
			}
			else {				/* High Port */
				Copy_u8PinID -= 8 ;
				GPIOB_CRH &= ~((u32)(0b1111	  	)<<(Copy_u8PinID * 4));
				GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
			}
			break;
		case PORTC:
			if(Copy_u8PinID < 8){/* Low Port */
				GPIOC_CRL &= ~((u32)(0b1111	  	)<<(Copy_u8PinID * 4));
				GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
			}
			else {				/* High Port */
				Copy_u8PinID -= 8 ;
				GPIOC_CRH &= ~((u32)(0b1111	  	)<<(Copy_u8PinID * 4));
				GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
			}
			break;
		}

	}
	else {
		/* return Error */;
	}

}

void GPIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Value){

	/* Range Check*/
	if(Copy_u8PortID < 3 && Copy_u8PinID <16 ){
		switch(Copy_u8PortID){
		case PORTA:
			switch(Copy_u8Value){
			case HIGH:	SET_BIT(GPIOA_ODR, Copy_u8PinID);	break;
			case LOW :	CLR_BIT(GPIOA_ODR, Copy_u8PinID);	break;
			default	 : /* return error */;
			}
		break;
		case PORTB:
			switch(Copy_u8Value){
			case HIGH:	SET_BIT(GPIOB_ODR, Copy_u8PinID);	break;
			case LOW :	CLR_BIT(GPIOB_ODR, Copy_u8PinID);	break;
			default	 : /* return error */;
			}
		break;
		case PORTC:
			switch(Copy_u8Value){
			case HIGH:	SET_BIT(GPIOC_ODR, Copy_u8PinID);	break;
			case LOW :	CLR_BIT(GPIOC_ODR, Copy_u8PinID);	break;
			default	 : /* return error */;
			}
		break;
		}
	}
	else {
		/* return error*/;
	}
}

u8 GPIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID){

	u8 Local_u8Value = 0xFF;

	if(Copy_u8PortID < 3 && Copy_u8PinID <16 ){
		switch(Copy_u8PortID){
		case PORTA:	Local_u8Value = GET_BIT(GPIOA_IDR, Copy_u8PinID);	break;
		case PORTB: Local_u8Value = GET_BIT(GPIOB_IDR, Copy_u8PinID);	break;
		case PORTC:	Local_u8Value = GET_BIT(GPIOC_IDR, Copy_u8PinID); 	break;
		}
	}
	return Local_u8Value;
}


/* Optional functions */
#if  SET_PORT_DIRICTION == 1
void GPIO_voidSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8Mode){
	/* Check range */
	if (Copy_u8PortID < 3){
		switch (Copy_u8PortID){
		case PORTA:
			GPIOA_CRL &=   (u32)0;
			GPIOA_CRH &=   (u32)0;
			GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(0 * 4));
			GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(1 * 4));
			GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(2 * 4));
			GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(3 * 4));
			GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(4 * 4));
			GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(5 * 4));
			GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(6 * 4));
			GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(7 * 4));
			GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(0 * 4));
			GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(1 * 4));
			GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(2 * 4));
			GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(3 * 4));
			GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(4 * 4));
			GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(5 * 4));
			GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(6 * 4));
			GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(7 * 4));
			break;
		case PORTB:
			GPIOB_CRL &=   (u32)0;
			GPIOB_CRH &=   (u32)0;
			GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(0 * 4));
			GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(1 * 4));
			GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(2 * 4));
			GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(3 * 4));
			GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(4 * 4));
			GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(5 * 4));
			GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(6 * 4));
			GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(7 * 4));
			GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(0 * 4));
			GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(1 * 4));
			GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(2 * 4));
			GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(3 * 4));
			GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(4 * 4));
			GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(5 * 4));
			GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(6 * 4));
			GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(7 * 4));
			break;
		case PORTC:
			GPIOC_CRL &=   (u32)0;
			GPIOC_CRH &=   (u32)0;
			GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(0 * 4));
			GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(1 * 4));
			GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(2 * 4));
			GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(3 * 4));
			GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(4 * 4));
			GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(5 * 4));
			GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(6 * 4));
			GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(7 * 4));
			GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(0 * 4));
			GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(1 * 4));
			GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(2 * 4));
			GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(3 * 4));
			GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(4 * 4));
			GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(5 * 4));
			GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(6 * 4));
			GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(7 * 4));
			break;
		}
	}
	else {
		/* return error */
	}
}
#endif

#if  SET_PORT_VALUE	    == 1
void GPIO_voidSetPortValue(u8 Copy_u8PortID,u16 Copy_u16Value){
	/* check range */
	if (Copy_u8PortID < 3){
		switch (Copy_u8PortID){
		case PORTA:	GPIOA_ODR = (u32)Copy_u16Value;	break;
		case PORTB:	GPIOB_ODR = (u32)Copy_u16Value;	break;
		case PORTC:	GPIOC_ODR = (u32)Copy_u16Value;	break;

		default			  : /* return error */;
		}
	}
	else {
							/* return error */
	}
}
#endif

#if  SET_PIN_VALUE_FAST == 1
void GPIO_voidSetPinValueFast(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Value){
	/* Range Check*/
	if(Copy_u8PortID < 3 && Copy_u8PinID <16 ){
		switch(Copy_u8PortID){
		case PORTA:
			switch(Copy_u8Value){
			case HIGH:	 GPIOA_BSRR = (1<<Copy_u8PinID);	break;
			case LOW :	 GPIOA_BRR  = (1<<Copy_u8PinID);	break;
			default: /* return error */;
			}
		break;

		case PORTB:
			switch(Copy_u8Value){
			case HIGH:	 GPIOB_BSRR = (1<<Copy_u8PinID);	break;
			case LOW :	 GPIOB_BRR  = (1<<Copy_u8PinID);	break;
			default: /* return error */;
			}
		break;

		case PORTC:
			switch(Copy_u8Value){
			case HIGH:	 GPIOC_BSRR = (1<<Copy_u8PinID);	break;
			case LOW :	 GPIOC_BRR  = (1<<Copy_u8PinID);	break;
			default: /* return error */;
		}
		break;
		default: 	/* return error*/;
		}
	}
	else {
					/* return error */
		}
}
#endif

