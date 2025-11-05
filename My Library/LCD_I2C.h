#ifndef _LCD_I2C_H_
#define _LCD_I2C_H_

#include "stm32f1xx_hal.h"

/* LCD's I2C Default address */
#define LCD_ADDR 0x27

/* Command LCD */
#define LCD_CLEAR_DISPLAY 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_ENTRY_MODE_SET 0x04
#define LCD_DISPLAY_CONTROL 0x08
#define LCD_CURSOR_SHIFT 0x10
#define LCD_FUNCTION_SET 0x20
#define LCD_SET_CGRAM_ADDR 0x40
#define LCD_SET_DDRAM_ADDR 0x80

/* Flags for display entry mode */
#define LCD_ENTRY_RIGHT 0x00
#define LCD_ENTRY_LEFT 0x02
#define LCD_ENTRY_SHIFT_INCREMENT 0x01
#define LCD_ENTRY_SHIFT_DECREMENT 0x00

/* Flags for display on/off control */
#define LCD_DISPLAY_ON 0x04
#define LCD_DISPLAY_OFF 0x00
#define LCD_CURSOR_ON 0x02
#define LCD_CURSOR_OFF 0x00
#define LCD_BLINK_ON 0x01
#define LCD_BLINK_OFF 0x00

/* Flags for display/cursor shift */
#define LCD_DISPLAY_MOVE 0x08
#define LCD_CURSOR_MOVE 0x00
#define LCD_MOVE_RIGHT 0x04
#define LCD_MOVE_LEFT 0x00

/* Flags for function set */
#define LCD_8BIT_MODE 0x10
#define LCD_4BIT_MODE 0x00
#define LCD_2LINE 0x08
#define LCD_5x8_DOTS 0x00

/* Backlight control */
#define LCD_BACKLIGHT 0x08
#define LCD_NOBACKLIGHT 0x00

/* Enable bit */
#define LCD_EN_SET 0x04
#define LCD_EN_CLEAR 0x00

#define DISABLE 0x00
#define RS_COMMAND 0x00
#define RS_DATA 0x01

typedef struct
{
	I2C_HandleTypeDef *lcd_hi2c;
	uint8_t lcd_addr;
	uint8_t backlight;
	uint8_t displaycontrol;
	uint8_t displaymode;
} LCD_HandleTypeDef;

void LCD_Init(LCD_HandleTypeDef *LCDx, I2C_HandleTypeDef *hi2c, uint8_t addr);
void LCD_Clear_Display(LCD_HandleTypeDef *LCDx);
void LCD_Home(LCD_HandleTypeDef *LCDx);
void LCD_SetCursor(LCD_HandleTypeDef *LCDx, uint8_t col, uint8_t row);
void LCD_NoDisplay(LCD_HandleTypeDef *LCDx);
void LCD_Display(LCD_HandleTypeDef *LCDx);

// Turns the underline cursor on/off
void LCD_NoCursor(LCD_HandleTypeDef *LCDx);
void LCD_Cursor(LCD_HandleTypeDef *LCDx);

// Turn on and off the blinking cursor
void LCD_NoBlink(LCD_HandleTypeDef *LCDx);
void LCD_Blink(LCD_HandleTypeDef *LCDx);

// ....
void LCD_Backlight(LCD_HandleTypeDef *LCDx);
void LCD_NoBacklight(LCD_HandleTypeDef *LCDx);
void LCD_Print(LCD_HandleTypeDef *LCDx, char *str);
void LCD_PrintChar(LCD_HandleTypeDef *LCDx, char ch);
void LCD_CreateChar(LCD_HandleTypeDef *LCDx, uint8_t location, uint8_t charmap[]);
void LCD_ScrollText(LCD_HandleTypeDef *LCDx, uint8_t row, char *message, uint16_t delay_ms);
#endif /* _LCD_I2C_H_ */