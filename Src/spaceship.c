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
	gotoxy(ship->pos_x+4,ship->pos_y);
	printf("      ");
	gotoxy(ship->pos_x+4,ship->pos_y+1);
	printf("  |\\    ");
	gotoxy(ship->pos_x+4,ship->pos_y+2);
	printf("  | \\__  "); //left wing
	gotoxy(ship->pos_x,ship->pos_y+3);
	printf("    |\\| |  \\    ");
	gotoxy(ship->pos_x,ship->pos_y+4);
	printf("    |-<\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0>  "); // body
	gotoxy(ship->pos_x,ship->pos_y+5);
	printf("    |/| |__/    ");
	gotoxy(ship->pos_x+4,ship->pos_y+6);
	printf("  | /    "); // right wing
	gotoxy(ship->pos_x+4,ship->pos_y+7);
	printf("  |/    ");
	gotoxy(ship->pos_x+4,ship->pos_y+8);
	printf("      ");
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
		if (ship->pos_x < 140) {
			ship->pos_x = ship->pos_x+2;
		}
	} // right

	if (direction == 4) {
		if (ship->pos_x > 0) {
			ship->pos_x = ship->pos_x-2;
		}
	} // left
}


void shoot(spaceship_t *ship, int center,bullet_t *bullet1,bullet_t *bullet2,bullet_t *bullet3,bullet_t *bullet4,bullet_t *bullet5) {

//logic for spawning bullets
//bullet1 logic
if (bullet1->vel_x == 0){

	if (center == 5) {
		bullet1->pos_x = ship->pos_x+16;
		bullet1->pos_y = ship->pos_y+4;
		bullet1->vel_x = 2;
	}
}
//bullet2 logic
else if (bullet2->vel_x == 0){

	if (center == 5) {
		bullet2->pos_x = ship->pos_x+16;
		bullet2->pos_y = ship->pos_y+4;
		bullet2->vel_x = 2;
	}
}
//bullet3 logic
else if (bullet3->vel_x == 0){

	if (center == 5) {
		bullet3->pos_x = ship->pos_x+16;
		bullet3->pos_y = ship->pos_y+4;
		bullet3->vel_x = 2;
	}
}
//bullet4 logic
else if (bullet4->vel_x == 0){

	if (center == 5) {
		bullet4->pos_x = ship->pos_x+16;
		bullet4->pos_y = ship->pos_y+4;
		bullet4->vel_x = 2;
	}
}
//bullet5 logic
else if (bullet5->vel_x == 0){

	if (center == 5) {
		bullet5->pos_x = ship->pos_x+16;
		bullet5->pos_y = ship->pos_y+4;
		bullet5->vel_x = 2;
	}
}



//logic for moving bullet1
	if (bullet1->pos_x < 158 && bullet1->vel_x != 0){
		gotoxy(bullet1->pos_x,bullet1->pos_y);
		printf("o");

		gotoxy(bullet1->pos_x-bullet1->vel_x,bullet1->pos_y-bullet1->vel_y);
		printf(" ");
		bullet1->pos_x = bullet1->pos_x + bullet1->vel_x;

	}
	if (bullet1->pos_x >= 158) {
		gotoxy(bullet1->pos_x,bullet1->pos_y);
		gotoxy(bullet1->pos_x-bullet1->vel_x,bullet1->pos_y-bullet1->vel_y);
		printf(" ");

		bullet1->vel_x = 0;
		bullet1->pos_x = 1;
	}

//logic for moving bullet2
	if (bullet2->pos_x < 158 && bullet2->vel_x != 0){
		gotoxy(bullet2->pos_x,bullet2->pos_y);
		printf("o");

		gotoxy(bullet2->pos_x-bullet2->vel_x,bullet2->pos_y-bullet2->vel_y);
		printf(" ");
		bullet2->pos_x = bullet2->pos_x + bullet2->vel_x;

	}
	if (bullet2->pos_x >= 158) {
		gotoxy(bullet2->pos_x,bullet2->pos_y);
		gotoxy(bullet2->pos_x-bullet2->vel_x,bullet2->pos_y-bullet2->vel_y);
		printf(" ");

		bullet2->vel_x = 0;
		bullet2->pos_x = 1;
	}
//logic for moving bullet3
	if (bullet3->pos_x < 158 && bullet3->vel_x != 0){
		gotoxy(bullet3->pos_x,bullet3->pos_y);
		printf("o");

		gotoxy(bullet3->pos_x-bullet3->vel_x,bullet3->pos_y-bullet3->vel_y);
		printf(" ");
		bullet3->pos_x = bullet3->pos_x + bullet3->vel_x;

	}
	if (bullet3->pos_x >= 158) {
		gotoxy(bullet3->pos_x,bullet3->pos_y);
		gotoxy(bullet3->pos_x-bullet3->vel_x,bullet3->pos_y-bullet3->vel_y);
		printf(" ");

		bullet3->vel_x = 0;
		bullet3->pos_x = 1;
	}

//logic for moving bullet4
	if (bullet4->pos_x < 158 && bullet4->vel_x != 0){
		gotoxy(bullet4->pos_x,bullet4->pos_y);
		printf("o");

		gotoxy(bullet4->pos_x-bullet4->vel_x,bullet4->pos_y-bullet4->vel_y);
		printf(" ");
		bullet4->pos_x = bullet4->pos_x + bullet4->vel_x;

	}
	if (bullet4->pos_x >= 158) {
		gotoxy(bullet4->pos_x,bullet4->pos_y);
		gotoxy(bullet4->pos_x-bullet4->vel_x,bullet4->pos_y-bullet4->vel_y);
		printf(" ");

		bullet4->vel_x = 0;
		bullet4->pos_x = 1;
	}

//logic for moving bullet5
	if (bullet5->pos_x < 158 && bullet5->vel_x != 0){
		gotoxy(bullet5->pos_x,bullet5->pos_y);
		printf("o");

		gotoxy(bullet5->pos_x-bullet5->vel_x,bullet5->pos_y-bullet5->vel_y);
		printf(" ");
		bullet5->pos_x = bullet5->pos_x + bullet5->vel_x;

	}
	if (bullet5->pos_x >= 158) {
		gotoxy(bullet5->pos_x,bullet5->pos_y);
		gotoxy(bullet5->pos_x-bullet5->vel_x,bullet5->pos_y-bullet5->vel_y);
		printf(" ");

		bullet5->vel_x = 0;
		bullet5->pos_x = 1;
	}
}
