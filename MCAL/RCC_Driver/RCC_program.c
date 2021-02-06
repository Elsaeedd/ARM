/*
 * RCC_program.c
 *
 *  Created on: Feb 2, 2021
 *      Author: Elsaeed
 */
/*in new version will add
 *1- clock security will be added
 **/

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_Privet.h"
#include "RCC_Config.h"

void RCC_voidInit(void){
	u32 Local_u32TimeOut=0;
#if 	CLOCK_TYPE == RCC_HSI
	RCC_CR   = 0x00000081;		/*HSI Enable + Trimming =0		*/
	RCC_CFGR = 0x00000000;		/* Select HSI to be clock sours */
	while((GET_BIT(RCC_CR,1)==0) && Local_u32TimeOut<10000){  	/*wait for HSI be ready			*/
		Local_u32TimeOut++;
	}
#elif 	CLOCK_TYPE == RCC_HSE
	#if	  RCC_HSE_SOURCE == RCC_CRYSTAL
		RCC_CR   = 0x00000000;						/*set input of HSE as Crystal ( no bypass )	*/
	#elif RCC_HSE_SOURCE == RCC_RC
		RCC_CR   = 0x00040000;						/*set input of HSE as RC ( with bypass )		*/
	#endif
	SET_BIT(RCC_CR,16);											/*HSE Enable				    */
	RCC_CFGR = 0x00000001;	    								/*Set System clock as HSE		*/
	while((GET_BIT(RCC_CR,17)==0) && Local_u32TimeOut < 10000){ /*wait for HSE be ready			*/
		Local_u32TimeOut++;
	}
	Local_u32TimeOut = 0;
	while((GET_BIT(RCC_CFGR,3)==1) && (GET_BIT(RCC_CFGR,2)==0) && Local_u32TimeOut < 10000){
		Local_u32TimeOut++;										/*wait for HSE selected as SYS CLK*/
	}
	///////////////////////////////////clock security will be added

#elif	CLOCK_TYPE == RCC_PLL
	#if 	PLL_INPUT  == RCC_HSIDIV2
		RCC_CR   = 0x00000081;		/*Enable HSI  + Trimming =0  	*/
		RCC_CFGR = 0x00000000;		/*Set input of PLL as HSI/2		*/
		while((GET_BIT(RCC_CR,1)==0) && Local_u32TimeOut<10000){  	/*wait for HSI be ready			*/
			Local_u32TimeOut++;
		}
	#elif	PLL_INPUT  == RCC_HSE
		#if	  RCC_HSE_SOURCE == RCC_CRYSTAL
		RCC_CR   = 0x00010000;						/*set input of HSE as Crystal + Enable HSE	*/
		#elif RCC_HSE_SOURCE == RCC_RC
		RCC_CR   = 0x00050000;						/*set input of HSE as RC + Enable HSE		*/
		#endif
		RCC_CFGR = 0x00010000;		/*Set input of PLL as HSE	*/
		while((GET_BIT(RCC_CR,17)==0) && Local_u32TimeOut < 10000){ /*wait for HSE be ready			*/
				Local_u32TimeOut++;
		}
	///////////////////////////////////clock security will be added

	#elif	PLL_INPUT  == RCC_HSE/2
		#if	  RCC_HSE_SOURCE == RCC_CRYSTAL
		RCC_CR   = 0x00010000;						/*set input of HSE as Crystal + Enable HSE	*/
		#elif RCC_HSE_SOURCE == RCC_RC
		RCC_CR   = 0x00050000;						/*set input of HSE as RC 	  + Enable HSE*/
		#endif
		RCC_CFGR = 0x00030000;		/*Set input of PLL as HSE/2	*/
		while((GET_BIT(RCC_CR,17)==0) && Local_u32TimeOut < 10000){ /*wait for HSE be ready			*/
				Local_u32TimeOut++;
		}
		///////////////////////////////////clock security will be added
	#endif

	/* Choose multiplication  factor */
	#if		PLL_MUL_FACTOR == 2		RCC_CFGR |=(0x0<<18);  	/*set bits 18,19,20,21 with value 0b0000 */
	#elif	PLL_MUL_FACTOR == 3		RCC_CFGR |=(0x1<<18);	/*set bits 18,19,20,21 with value 0b0001 */
	#elif	PLL_MUL_FACTOR == 4		RCC_CFGR |=(0x2<<18);	/*set bits 18,19,20,21 with value 0b0010 */
	#elif	PLL_MUL_FACTOR == 5		RCC_CFGR |=(0x3<<18);	/*set bits 18,19,20,21 with value 0b0011 */
	#elif	PLL_MUL_FACTOR == 6		RCC_CFGR |=(0x4<<18);
	#elif	PLL_MUL_FACTOR == 7		RCC_CFGR |=(0x5<<18);
	#elif	PLL_MUL_FACTOR == 8		RCC_CFGR |=(0x6<<18);
	#elif	PLL_MUL_FACTOR == 9		RCC_CFGR |=(0x7<<18);
	#elif	PLL_MUL_FACTOR == 10	RCC_CFGR |=(0x8<<18);
	#elif	PLL_MUL_FACTOR == 11	RCC_CFGR |=(0x9<<18);
	#elif	PLL_MUL_FACTOR == 12	RCC_CFGR |=(0xA<<18);
	#elif	PLL_MUL_FACTOR == 13	RCC_CFGR |=(0xB<<18);
	#elif	PLL_MUL_FACTOR == 14	RCC_CFGR |=(0xC<<18);
	#elif	PLL_MUL_FACTOR == 15	RCC_CFGR |=(0xD<<18);
	#elif	PLL_MUL_FACTOR == 16	RCC_CFGR |=(0xE<<18);
		#else 	#error ("Value PLL_MUL_FACTOR is not exist ")
	#endif


	SET_BIT(RCC_CR,24);											/*PLL Enable				    */
	Local_u32TimeOut = 0;
	while((GET_BIT(RCC_CR,25)==0) && Local_u32TimeOut < 10000){ /*wait for PLL be ready			*/
		Local_u32TimeOut++;
	}

	CLR_BIT(RCC_CFGR,0);										/*Set System clock as PLL		*/
	SET_BIT(RCC_CFGR,1);
	Local_u32TimeOut = 0;
	while((GET_BIT(RCC_CFGR,3)==0) && (GET_BIT(RCC_CFGR,2)==1) && Local_u32TimeOut < 10000){
		Local_u32TimeOut++;										/*wait for PLL selected as SYS CLK*/
	}

#endif


}
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8Peripheral){
	/*Rang check*/
	if(Copy_u8Peripheral < 31){
		switch (Copy_u8BusID){
		case RCC_AHB :	SET_BIT(RCC_AHPENR , Copy_u8Peripheral);	break;
		case RCC_APB1:	SET_BIT(RCC_APB1ENR, Copy_u8Peripheral);	break;
		case RCC_APB2:	SET_BIT(RCC_APB2ENR, Copy_u8Peripheral);	break;
		//default		 :#error "Copy_u8BusID is not found  "		break;
		}
	}
	else{
		//#error "Copy_u8Peripheral is too large "
		/*Return Error*/
	}


}
void RCC_voidDisablePeripheralClock(u8 Copy_u8BusID,u8 Copy_u8Peripheral){

	if(Copy_u8Peripheral < 31){
		switch (Copy_u8BusID){
		case RCC_AHB :	CLR_BIT(RCC_AHPENR , Copy_u8Peripheral);	break;
		case RCC_APB1:	CLR_BIT(RCC_APB1ENR, Copy_u8Peripheral);	break;
		case RCC_APB2:	CLR_BIT(RCC_APB2ENR, Copy_u8Peripheral);	break;
		//default		 :#error "Copy_u8BusID is not found  "		break;

		}
	}
	else{
		//default		 :#error "Copy_u8Peripheral is too large "		break;
		/*Return Error*/
	}

}
