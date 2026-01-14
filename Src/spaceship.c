/*
 * spaceship.c
 *
 *  Created on: 13. jan. 2026
 *      Author: chris
 */

#include "spaceship.h"
#include "joystick.h"
#include "structures.h"

void print_ship(spaceship_t *ship) {

	//prints ship and "air" around it
	gotoxy(ship->pos_x,ship->pos_y);
		gotoxy(ship->pos_y,ship->pos_x);
		printf("           ");
		gotoxy(ship->pos_y+1,ship->pos_x);
		printf("      |\\      ");
		gotoxy(ship->pos_y+2,ship->pos_x);
		printf("      | \\__    "); //left wing
		gotoxy(ship->pos_y+3,ship->pos_x-4);
		printf("        |\\| |  \\         ");
		gotoxy(ship->pos_y+4,ship->pos_x-4);
		printf("        |-<\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0>  "); // body
		gotoxy(ship->pos_y+5,ship->pos_x-4);
		printf("        |/| |__/           ");
		gotoxy(ship->pos_y+6,ship->pos_x);
		printf("      | /      "); // right wing
		gotoxy(ship->pos_y+7,ship->pos_x);
		printf("      |/       ");
		gotoxy(ship->pos_y+8,ship->pos_x);
		printf("          ");
}

void update_pos(spaceship_t *ship,int direction) {
	if (direction == 1) {
		ship->pos_y = ship->pos_y-1;
	}
	if (direction == 3) {
		ship->pos_y = ship->pos_y+1;
	}
	if (direction == 2) {
		ship->pos_x = ship->pos_x+2;
	}
	if (direction == 4) {
		ship->pos_x = ship->pos_x-2;
	}
}
