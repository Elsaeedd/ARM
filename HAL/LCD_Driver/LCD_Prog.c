
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "GPIO_interface.h"
#include "STK_Interface.h"
#include "LCD_confg.h"
#include "LCD_Init.h"

void LCD_voidInit(void)
{
	STK_voidSetBusyWait(Copy_u32Ticks);
	GPIO_voidSetPortValue(PORTA, 0);
	GPIO_voidSetPinValue(PORTA, E, LOW);
	LCD_voidWRCMD(0X33);
	LCD_voidWRCMD(0X32);
#if (LCD_mode == 8)
	{LCD_voidWRCMD(0x30);}
#elif(LCD_mode == 4)
	{LCD_voidWRCMD(0x28);}
#endif
	LCD_voidWRCMD(0x0e);
/*	LCD_voidWRCMD(0X01);
	_delay_ms(2);*/
	LCD_voidWRCMD(0X06);
}
void LCD_setMostSegNibble(u8 data)
{
	GPIO_voidSetPinValue(PORTA, D4, GET_BIT(data,4));
	GPIO_voidSetPinValue(PORTA, D5, GET_BIT(data,5));
	GPIO_voidSetPinValue(PORTA, D6, GET_BIT(data,6));
	GPIO_voidSetPinValue(PORTA, D7, GET_BIT(data,7));

}
void LCD_setLeastSegNibble(u8 data)
{
	GPIO_voidSetPinValue(PORTA, D4, GET_BIT(data,0));
	GPIO_voidSetPinValue(PORTA, D5, GET_BIT(data,1));
	GPIO_voidSetPinValue(PORTA, D6, GET_BIT(data,2));
	GPIO_voidSetPinValue(PORTA, D7, GET_BIT(data,3));

}
void LCD_voidWRCMD(u8 data)
{
	GPIO_voidSetPinValue(PORTA, RS, LOW);
	GPIO_voidSetPinValue(PORTA, RW, LOW);


#if (LCD_mode == 8)
	{
		GPIO_voidSetPortValue(PORTA, data);
		GPIO_voidSetPinValue(PORTA, E, HIGH);
	STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(PORTA, E, LOW);
	STK_voidSetBusyWait(1);
	}
#elif (LCD_mode == 4)
	{
	    LCD_setMostSegNibble(data);
		GPIO_voidSetPinValue(PORTA, E, HIGH);
	STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(PORTA, E, LOW);
	STK_voidSetBusyWait(1);
		LCD_setLeastSegNibble(data);
		GPIO_voidSetPinValue(PORTA, E, HIGH);
	STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(PORTA, E, LOW);
	STK_voidSetBusyWait(1);
	}
#endif

}
void LCD_voidWRData(u8 data)
{
	GPIO_voidSetPinValue(PORTA, RS, HIGH);
	GPIO_voidSetPinValue(PORTA, RW, LOW);
#if (LCD_mode == 8)
	{
		GPIO_voidSetPortValue(PORTA, data);
		GPIO_voidSetPinValue(PORTA, E, HIGH);
	STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(PORTA, E, LOW);
	STK_voidSetBusyWait(1);
	}
#elif (LCD_mode == 4)
	{
	    LCD_setMostSegNibble(data);
		GPIO_voidSetPinValue(PORTA, E, HIGH);
	STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(PORTA, E, LOW);
	STK_voidSetBusyWait(1);
		LCD_setLeastSegNibble(data);
		GPIO_voidSetPinValue(PORTA, E, HIGH);
	STK_voidSetBusyWait(1);
		GPIO_voidSetPinValue(PORTA, E, LOW);
	STK_voidSetBusyWait(1);
	}
#endif
}
void LCD_voidPrint(u8 *str)
{
	u8 i = 0;
    while(str[i] != '\0')
    {
      LCD_voidWRData(str[i]);
      i++;
    }
}
void LCD_voidClrScr(void)
{ LCD_voidWRCMD(0x01); }
void LCD_voidGoToxy(u8 x, u8 y)
{
u8 fristchar[] = {0x80,0xC0};
LCD_voidWRCMD(fristchar[y - 1] + x - 1);
}
