#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "lcd.h"
#include "stopwatch.h"

/*

/** lcd.c
 *
 *  Created on: 12. jan. 2026
 *      Author: jeppe
 */


void lcd_write_string(int y, int x, char *p) {

	y = y * 128;
    int counter = 0;
    while (*p != '\0') {
    	for (int i = 0; i < 5; i++) {
			lcd_buffer[i+counter+y+x] = character_data[(*p)-32][i];
    	}
    	counter += 5;
    	p++;
    }

    lcd_push_buffer(lcd_buffer);
}


void lcd_update(char *p, char *q) {
	int old_len = strlen(p);
	int new_len = strlen(q);

	for (int i = old_len; ((i-old_len < new_len) && (i < 25)); i++) {
		p[i]=q[i-old_len];
	}

}

void number_to_string(int number, char* str, size_t str_len) {

	snprintf(str, str_len, "%d", number);

}



void lcd_scroll(char *p) {
	int i = 0;
	while (1) {
		printf("Time since start: %u:%02u:%02u.--\n", g_time.h, g_time.m, g_time.s);
		if (g_second_changed) {
			memset(lcd_buffer,0x00,512);
			lcd_write_string(0, 1+i, p);
			i += 1;
			g_second_changed = 0;
		}

	}

}


