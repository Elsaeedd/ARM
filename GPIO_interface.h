/*
 * GPIO_interface.h
 *
 *  Created on: Feb 3, 2021
 *      Author: Elsaeed
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

void GPIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Mode);
void GPIO_voidSetPinValue	 (u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Value);
u8 	 GPIO_u8GetPinValue		 (u8 Copy_u8PortID,u8 Copy_u8PinID);
/* Optional functions */
#if  SET_PORT_DIRICTION == 1
void GPIO_voidSetPortDirection(u8 Copy_u8PortID,u8 Copy_u8Mode  );
#endif
#if  SET_PORT_VALUE	    == 1
void GPIO_voidSetPortValue	  (u8 Copy_u8PortID,u16 Copy_u8Value);
#endif
#if  SET_PIN_VALUE_FAST == 1
void GPIO_voidSetPinValueFast (u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Value);
#endif



/* set port Direction  assiment function */
/* set port value	  */


#define GPIO_U8_PORTA	0
#define GPIO_U8_PORTB	1
#define GPIO_U8_PORTC	2

#define GPIO_U8_PIN0	0
#define GPIO_U8_PIN1	1
#define GPIO_U8_PIN2	2
#define GPIO_U8_PIN3	3
#define GPIO_U8_PIN4	4
#define GPIO_U8_PIN5	5
#define GPIO_U8_PIN6	6
#define GPIO_U8_PIN7	7
#define GPIO_U8_PIN8	8
#define GPIO_U8_PIN9	9
#define GPIO_U8_PIN10	10
#define GPIO_U8_PIN11	11
#define GPIO_U8_PIN12	12
#define GPIO_U8_PIN13	13
#define GPIO_U8_PIN14	14
#define GPIO_U8_PIN15	15


/*				INPUT Options					*/
#define			GPIO_INPUT_ANALOG		0b0000
#define			GPIO_INPUT_FLOATING		0b0100
#define			GPIO_INPUT_PULL_UP_DOWN	0b1000

/*				OUTPUT 2 MHz Options			*/
#define			GPIO_OUTPUT_2MHZ_PP		0b0010
#define			GPIO_OUTPUT_2MHZ_OD		0b0110
#define			GPIO_OUTPUT_2MHZ_AF_PP	0b1010
#define			GPIO_OUTPUT_2MHZ_AF_OD	0b1110
/*				OUTPUT 10 MHz Options			*/
#define			GPIO_OUTPUT_10MHZ_PP	0b0001
#define			GPIO_OUTPUT_10MHZ_OD	0b0101
#define			GPIO_OUTPUT_10MHZ_AF_PP	0b1001
#define			GPIO_OUTPUT_10MHZ_AF_OD	0b1101

/*				OUTPUT 50 MHz Options			*/
#define			GPIO_OUTPUT_50MHZ_PP	0b0011
#define			GPIO_OUTPUT_50MHZ_OD	0b0111
#define			GPIO_OUTPUT_50MHZ_AF_PP	0b1011
#define			GPIO_OUTPUT_50MHZ_AF_OD	0b1111

#define HIGH	1
#define LOW		0


#endif /* GPIO_INTERFACE_H_ */
