/*
 * SS_Program.c
 *
 *  Created on: Feb 5, 2021
 *      Author: Elsaeed
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "SSD_interface.h"
#include "SSD_Privet.h"
#include "SSD_Config.h"

#include "GPIO_interface.h"

void SSD_voidDisplayNumberOnPortA(u8 Copy_u8SSNumber,u8 Copy_u8DisNumber){

#if SSD_COMMON_TYPE == COMMON_CATHODE
	#if SSD_MODE_TYPE == _4_BIT_MODE
		switch(Copy_u8SSNumber){
		case SSD_NUMBER_ONE  :
			switch(Copy_u8DisNumber){
			case 0  :	GPIO_voidSetPortValue(PORTA, 0b010000);	break; /* set Bits 0,1,2,3 to Equivalent digit*/
			case 1  :	GPIO_voidSetPortValue(PORTA, 0b010001);	break; /*set Bit 4 for Enable SS number one  */
			case 2  :	GPIO_voidSetPortValue(PORTA, 0b010010);	break;
			case 3  :	GPIO_voidSetPortValue(PORTA, 0b010011);	break;
			case 4  :	GPIO_voidSetPortValue(PORTA, 0b010100);	break;
			case 5  :	GPIO_voidSetPortValue(PORTA, 0b010101);	break;
			case 6  :	GPIO_voidSetPortValue(PORTA, 0b010110);	break;
			case 7  :	GPIO_voidSetPortValue(PORTA, 0b010111);	break;
			case 8  :	GPIO_voidSetPortValue(PORTA, 0b011000);	break;
			case 9  :	GPIO_voidSetPortValue(PORTA, 0b011001);	break;
			default: /* Return error */;
			}
			break;
		case SSD_NUMBER_TWO  :
			switch(Copy_u8DisNumber){
			case 0  :	GPIO_voidSetPortValue(PORTA, 0b100000);	break; /* set Bits 0,1,2,3 to equivalent digit*/
			case 1  :	GPIO_voidSetPortValue(PORTA, 0b100001);	break; /* set Bit 5 for Enable SS number two  */
			case 2  :	GPIO_voidSetPortValue(PORTA, 0b100010);	break;
			case 3  :	GPIO_voidSetPortValue(PORTA, 0b100011);	break;
			case 4  :	GPIO_voidSetPortValue(PORTA, 0b100100);	break;
			case 5  :	GPIO_voidSetPortValue(PORTA, 0b100101);	break;
			case 6  :	GPIO_voidSetPortValue(PORTA, 0b100110);	break;
			case 7  :	GPIO_voidSetPortValue(PORTA, 0b100111);	break;
			case 8  :	GPIO_voidSetPortValue(PORTA, 0b101000);	break;
			case 9  :	GPIO_voidSetPortValue(PORTA, 0b101001);	break;
			default: /* Return error */;
			}
			break;
		default: /* Return error */;
		}

	#elif SSD_MODE_TYPE == _8_BIT_MODE
		switch(Copy_u8SSNumber){
		case SSD_NUMBER_ONE  :
			switch(Copy_u8DisNumber){
			case 0  :	GPIO_voidSetPortValue(PORTA, 0b10000000);	break;/* set first 7 Bits to equivalent digit*/
			case 1  :	GPIO_voidSetPortValue(PORTA, 0b10000110);	break;/* set Bit 8 for Enable SS number one  */
			case 2  :	GPIO_voidSetPortValue(PORTA, 0b11011011);	break;
			case 3  :	GPIO_voidSetPortValue(PORTA, 0b11111001);	break;
			case 4  :	GPIO_voidSetPortValue(PORTA, 0b11100110);	break;
			case 5  :	GPIO_voidSetPortValue(PORTA, 0b11101101);	break;
			case 6  :	GPIO_voidSetPortValue(PORTA, 0b11111101);	break;
			case 7  :	GPIO_voidSetPortValue(PORTA, 0b10000111);	break;
			case 8  :	GPIO_voidSetPortValue(PORTA, 0b11111111);	break;
			case 9  :	GPIO_voidSetPortValue(PORTA, 0b11101111);	break;
			default: /* Return error */;
			}
			break;
		case SSD_NUMBER_TWO  :
			switch(Copy_u8DisNumber){
			case 0  :	GPIO_voidSetPortValue(PORTA, 0b00000000);	break;/* set first 7 Bits to equivalent digit*/
			case 1  :	GPIO_voidSetPortValue(PORTA, 0b00000110);	break;/* Clear Bit 8 for Enable SS number two*/
			case 2  :	GPIO_voidSetPortValue(PORTA, 0b01011011);	break;
			case 3  :	GPIO_voidSetPortValue(PORTA, 0b01111001);	break;
			case 4  :	GPIO_voidSetPortValue(PORTA, 0b01100110);	break;
			case 5  :	GPIO_voidSetPortValue(PORTA, 0b01101101);	break;
			case 6  :	GPIO_voidSetPortValue(PORTA, 0b01111101);	break;
			case 7  :	GPIO_voidSetPortValue(PORTA, 0b00000111);	break;
			case 8  :	GPIO_voidSetPortValue(PORTA, 0b01111111);	break;
			case 9  :	GPIO_voidSetPortValue(PORTA, 0b01101111);	break;
			default: /* Return error */;
			}
			break;
		default: /* Return error */;
		}
	#endif


#elif SSD_COMMON_TYPE == COMMON_ANODE
	#if SSD_MODE_TYPE == _4_BIT_MODE
		switch(Copy_u8SSNumber){
		case SSD_NUMBER_ONE  :
			switch(Copy_u8DisNumber){
			case 0  :	GPIO_voidSetPortValue(PORTA, 0b011111);	break; /* set Bits 0,1,2,3 to Equivalent digit*/
			case 1  :	GPIO_voidSetPortValue(PORTA, 0b011110);	break; /*set Bit 4 for Enable SS number one  */
			case 2  :	GPIO_voidSetPortValue(PORTA, 0b011101);	break;
			case 3  :	GPIO_voidSetPortValue(PORTA, 0b011100);	break;
			case 4  :	GPIO_voidSetPortValue(PORTA, 0b011011);	break;
			case 5  :	GPIO_voidSetPortValue(PORTA, 0b011010);	break;
			case 6  :	GPIO_voidSetPortValue(PORTA, 0b011001);	break;
			case 7  :	GPIO_voidSetPortValue(PORTA, 0b011000);	break;
			case 8  :	GPIO_voidSetPortValue(PORTA, 0b010111);	break;
			case 9  :	GPIO_voidSetPortValue(PORTA, 0b010110);	break;
			default: /* Return error */;
			}
			break;
		case SSD_NUMBER_TWO  :
			switch(Copy_u8DisNumber){
			case 0  :	GPIO_voidSetPortValue(PORTA, 0b101111);	break; /* set Bits 0,1,2,3 to Equivalent digit*/
			case 1  :	GPIO_voidSetPortValue(PORTA, 0b101110);	break; /*set Bit 4 for Enable SS number two  */
			case 2  :	GPIO_voidSetPortValue(PORTA, 0b101101);	break;
			case 3  :	GPIO_voidSetPortValue(PORTA, 0b101100);	break;
			case 4  :	GPIO_voidSetPortValue(PORTA, 0b101011);	break;
			case 5  :	GPIO_voidSetPortValue(PORTA, 0b101010);	break;
			case 6  :	GPIO_voidSetPortValue(PORTA, 0b101001);	break;
			case 7  :	GPIO_voidSetPortValue(PORTA, 0b101000);	break;
			case 8  :	GPIO_voidSetPortValue(PORTA, 0b100111);	break;
			case 9  :	GPIO_voidSetPortValue(PORTA, 0b100110);	break;
			default: /* Return error */;
			}
			break;
		default: /* Return error */;
		}




	#elif SSD_MODE_TYPE == _8_BIT_MODE
		switch(Copy_u8SSNumber){
		case SSD_NUMBER_ONE  :
			switch(Copy_u8DisNumber){
			case 0  :	GPIO_voidSetPortValue(PORTA, 0b11111111);	break;/* set first 7 Bits to equivalent digit*/
			case 1  :	GPIO_voidSetPortValue(PORTA, 0b11111001);	break;/* Clear Bit 8 for Enable SS number one*/
			case 2  :	GPIO_voidSetPortValue(PORTA, 0b10100100);	break;
			case 3  :	GPIO_voidSetPortValue(PORTA, 0b10000110);	break;
			case 4  :	GPIO_voidSetPortValue(PORTA, 0b10011001);	break;
			case 5  :	GPIO_voidSetPortValue(PORTA, 0b10010010);	break;
			case 6  :	GPIO_voidSetPortValue(PORTA, 0b10000010);	break;
			case 7  :	GPIO_voidSetPortValue(PORTA, 0b11111000);	break;
			case 8  :	GPIO_voidSetPortValue(PORTA, 0b10000000);	break;
			case 9  :	GPIO_voidSetPortValue(PORTA, 0b10010000);	break;
			default: /* Return error */;
			}
		break;
		case SSD_NUMBER_TWO  :
			switch(Copy_u8DisNumber){
			case 0  :	GPIO_voidSetPortValue(PORTA, 0b01111111);	break;/* set first 7 Bits to equivalent digit*/
			case 1  :	GPIO_voidSetPortValue(PORTA, 0b01111001);	break;/* Clear Bit 8 for Enable SS number two*/
			case 2  :	GPIO_voidSetPortValue(PORTA, 0b00100100);	break;
			case 3  :	GPIO_voidSetPortValue(PORTA, 0b00000110);	break;
			case 4  :	GPIO_voidSetPortValue(PORTA, 0b00011001);	break;
			case 5  :	GPIO_voidSetPortValue(PORTA, 0b00010010);	break;
			case 6  :	GPIO_voidSetPortValue(PORTA, 0b00000010);	break;
			case 7  :	GPIO_voidSetPortValue(PORTA, 0b01111000);	break;
			case 8  :	GPIO_voidSetPortValue(PORTA, 0b00000000);	break;
			case 9  :	GPIO_voidSetPortValue(PORTA, 0b00010000);	break;
			default: /* Return error */;
			}

		break;
		default: /* Return error */;
		}
	#endif

#endif


}
