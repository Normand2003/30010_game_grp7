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

	gotoxy(ship->pos_x,ship->pos_y);
	printf("           ");
	gotoxy(ship->pos_x,ship->pos_y+1);
	printf("      |\\      ");
	gotoxy(ship->pos_x,ship->pos_y+2);
	printf("      | \\__    "); //left wing
	gotoxy(ship->pos_x-4,ship->pos_y+3);
	printf("        |\\| |  \\         ");
	gotoxy(ship->pos_x-4,ship->pos_y+4);
	printf("        |-<\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0>  "); // body
	gotoxy(ship->pos_x-4,ship->pos_y+5);
	printf("        |/| |__/           ");
	gotoxy(ship->pos_x,ship->pos_y+6);
	printf("      | /      "); // right wing
	gotoxy(ship->pos_x,ship->pos_y+7);
	printf("      |/       ");
	gotoxy(ship->pos_x,ship->pos_y+8);
	printf("          ");
}

void update_pos(spaceship_t *ship,int direction) {

	if (direction == 1) {
		if (ship->pos_y>0){
			ship->pos_y = ship->pos_y-1;
		}
	} // up

	if (direction == 3) {
		if (ship->pos_y<41){
			ship->pos_y = ship->pos_y+1;
		}
	} // down

	if (direction == 2) {
		if (ship->pos_x < 193) {
			ship->pos_x = ship->pos_x+2;
		}
	} // right

	if (direction == 4) {
		if (ship->pos_x > 4) {
			ship->pos_x = ship->pos_x-2;
		}
	} // left
}
