/*
 * objects.c
 *
 *  Created on: 13. jan. 2026
 *      Author: chris
 */

#include "spaceship.h"
#include "joystick.h"
#include "structures.h"
#include "draw.h"

void print_astroid(astroid_t *astroid){
	gotoxy(astroid->pos_x,astroid->pos_y);
	printf("#");
}

