/*
 * lcd.h
 *
 *  Created on: 12. jan. 2026
 *      Author: jeppe
 */

#ifndef LCD_H_
#define LCD_H_

#include "charset.h"
#include <string.h>

typedef struct {
	int score;
} score_t;

uint8_t lcd_buffer [512];

void lcd_write_string(int y, int x, char *p);
void lcd_update(char *p, char *q);
void lcd_scroll(char *p);

void number_to_string(int number, char* str, size_t str_len);

#endif /* LCD_H_ */
