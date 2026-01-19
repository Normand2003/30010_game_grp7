/*
 * aliens.h
 *
 *  Created on: 15. jan. 2026
 *      Author: jeppe
 */

#ifndef ALIENS_H_
#define ALIENS_H_
#include <stdint.h>
#include <stdio.h>
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "lcd.h"
#include "stopwatch.h"
#include "joystick.h"
#include "ansi.h"


typedef struct {
	int pos_x;
	int pos_y;
	int health;
} alien_t;


void draw_alien(alien_t *alien);
void alien_dying(alien_t *alien);
void delete_alien(alien_t *alien);
void enable_alien(alien_t *alien);
void draw_asteroid(int x, int y, int size);
void draw_spaceship1(int x, int y);
void draw_spaceship2(int x, int y);


#endif /* ALIENS_H_ */
