/*
 * ansi.c
 *
 *  Created on: 13. jan. 2026
 *      Author: chris
 */

//includes
#include "draw.h"

//defines
#define ESC 0x1B
#define vline 0xBA
#define rtcor 0xBB
#define rbcor 0xBC
#define lbcor 0xC8
#define ltcor 0xC9
#define hline 0xCD
#define txtstart 0xB9
#define txtend 0xCC
#define empty 0x10


//Text commands/functions
void fgcolor(uint8_t foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(uint8_t background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(uint8_t foreground, uint8_t background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  uint8_t type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);
}

void clrscr() {
// clear screen and cursor
	printf("%c[2J",ESC);
}

void clreol() {
// clear rest of current line
	printf("%c[K",ESC);
}

void gotoxy(uint8_t x, uint8_t y) {
// puts cursor on specific x and y coordinates

	printf("%c[%d;%dH",ESC, y, x);

}

void underline(uint8_t on) {
// turns underline on/off

	if (on == 1) {
		printf("%c[4m",ESC);
	} else {
		printf("%c[24m",ESC);
	}

}

void blink(uint8_t on) {
// turns underline on/off

	if (on == 1) {
		printf("%c[5m",ESC);
	} else {
		printf("%c[25m",ESC);
	}

}

void inverse(uint8_t on) {
// turns underline on/off

	if (on == 1) {
		printf("%c[7m",ESC);
	} else {
		printf("%c[27m",ESC);
	}

}



// window functions
void window(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {

//goes to position x1,y1 and writes top line+text

	printf("%c[%d;%dH",ESC,y1,x1);
	printf("%c%cWindow title%c",ltcor,txtstart,txtend);

	int16_t windowlen = x2 - x1;
	int16_t i = 15;
	while (i < windowlen) {
		i++;
		printf("%c",hline);
	}
	printf("%c",rtcor);

//writes vertical lines
	int16_t windowheight = y2 - y1;
	int16_t j = 0;
	while (j < windowheight-1){
		++j;
		printf("%c[%d;%dH",ESC,y1+j,x1);
		printf("%c",vline);
		printf("%c[%d;%dH",ESC,y1+j,x2);
		printf("%c",vline);

	}
	printf("%c[%d;%dH",ESC,y2,x1);
	printf("%c",lbcor);
	printf("%c[%d;%dH",ESC,y2,x2);
	printf("%c",rbcor);

	//writes bottom horizontal line
	printf("%c[%d;%dH",ESC,y2,x1+1);
		int16_t l = 0;
		while (l < windowlen-1) {
			l++;
			printf("%c",hline);
		}
}

