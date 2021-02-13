
#ifndef LCD_int
#define LCD_int

/*typedef unsigned char u8;*/
void LCD_voidGoToxy(u8 x, u8 y);
void LCD_voidClrScr(void);
void LCD_voidInit(void);
void LCD_setMostSegNibble(u8 data);
void LCD_setLeastSegNibble(u8 data);
void LCD_voidWRCMD(u8);
void LCD_voidWRData(u8 data);
void LCD_voidPrint(u8 *str);
 /* LCD_INIT_H_ */

#endif
