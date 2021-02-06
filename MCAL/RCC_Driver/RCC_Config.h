/*
 * RCC_Config.h
 *
 *  Created on: Feb 2, 2021
 *      Author: Elsaeed
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*Choose clock type
 * RCC_HSI
 * RCC_HSE
 * RCC_PLL
 * */
#define CLOCK_TYPE RCC_HSI

/* if Clock type is chosen as HSE
 *RCC_CRYSTAL
 *RCC_RC
 */
#define RCC_HSE_SOURCE	RCC_CRYSTAL

/* if Clock type is chosen as PLL then Chose input of PLL
 * RCC_HSIDIV2      -> HSI/2
 * RCC_HSE
 * RCC_HSEDIV2      -> HSE/2
 */
#define PLL_INPUT RCC_HSIDIV2

/*Chose Multiplication factor for PLL
 *  from 2 to 16
 */
#define PLL_MUL_FACTOR  2

#endif /* RCC_CONFIG_H_ */
