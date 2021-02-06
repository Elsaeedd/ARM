/*
 * RCC_Privet.h
 *
 *  Created on: Feb 2, 2021
 *      Author: Elsaeed
 */

#ifndef RCC_PRIVET_H_
#define RCC_PRIVET_H_

#define RCC_BASE_ADD 	0x40021000

#define RCC_CR 		 	*((u32 *)(RCC_BASE_ADD + 0x00))
#define RCC_CFGR 		*((u32 *)(RCC_BASE_ADD + 0x04))
#define RCC_CIR 		*((u32 *)(RCC_BASE_ADD + 0x08))
#define RCC_APB2RSTR 	*((u32 *)(RCC_BASE_ADD + 0x0C))
#define RCC_APB1RSTR 	*((u32 *)(RCC_BASE_ADD + 0x10))
#define RCC_AHPENR 		*((u32 *)(RCC_BASE_ADD + 0x14))
#define RCC_APB2ENR    	*((u32 *)(RCC_BASE_ADD + 0x18))
#define RCC_APB1ENR 	*((u32 *)(RCC_BASE_ADD + 0x1C))
#define RCC_BDCR 		*((u32 *)(RCC_BASE_ADD + 0x20))
#define RCC_CSR 		*((u32 *)(RCC_BASE_ADD + 0x24))

/* Clock types */
#define RCC_HSI  	0
#define RCC_HSE  	1
#define RCC_PLL  	2
/* HSE types */
#define RCC_CRYSTAL 0
#define RCC_RC 		1
/* PLL Options */
#define RCC_HSIDIV2	0
#define RCC_HSE		1
#define RCC_HSEDIV2	2



#endif /* RCC_PRIVET_H_ */
