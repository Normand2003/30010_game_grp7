/*
 * ansi.h
 *
 *  Created on: 13. jan. 2026
 *      Author: chris
 */

#ifndef DRAW_H_
#define DRAW_H_


/* Includes -------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>

/* Exported functions -------------------------------------------------- */
void fgcolor(uint8_t foreground);
void bgcolor(uint8_t background);
void color(uint8_t foreground, uint8_t background);
void clrscr();
void clreol();
void gotoxy(uint8_t y, uint8_t x);
void underline(uint8_t on);
void blink(uint8_t on);
void inverse(uint8_t on);
void window(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

#endif /* DRAW_H_ */
