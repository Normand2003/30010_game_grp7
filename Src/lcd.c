#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "lcd.h"
#include "stopwatch.h"
#include "structures.h"

/*

/** lcd.c
 *
 *  Created on: 12. jan. 2026
 *      Author: jeppe
 */


void lcd_write_string(int y, int x, char *p) {

	//y is increased by 128 times, to make sure it goes to next line
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
	//uses built-in function to convert number to string
	snprintf(str, str_len, "%d", number);

}

void lcd_danger(astroid_t *alien_object){

	//creates string called tom and alien, which is empty and has "Alien" flashing on it
	char tom[15] = "       ";
	char alien[7] = "Alien!";

	//checks to see if the alien is close to the player, and then starts flashing!
	if (alien_object->pos_x < 140){


    	  if (g_time.hs >= 0 && g_time.hs <= 20) {
    		lcd_write_string(0,90, alien);
    	  }
    	  else if (g_time.hs >= 21 && g_time.hs <= 100) {
    		lcd_write_string(0, 90, tom);
    	  }
	}
	else{
		lcd_write_string(0, 90, tom);
	}
}
