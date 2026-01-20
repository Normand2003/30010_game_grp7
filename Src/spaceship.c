/*
 * spaceship.c
 *
 *  Created on: 13. jan. 2026
 *      Author: chris
 */

#include "spaceship.h"
#include "joystick.h"
#include "structures.h"
#include "draw.h"

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
		if (ship->pos_x < 230) {
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

if (ship->powerup == 0){

//logic for spawning bullets
//bullet1 logic
if (bullet1->vel_x == 0){

	if (center == 5) {
		bullet1->pos_x = ship->pos_x+12;
		bullet1->pos_y = ship->pos_y+4;
		bullet1->vel_x = 2;
	}
}
//bullet2 logic
else if (bullet2->vel_x == 0){

	if (center == 5) {
		bullet2->pos_x = ship->pos_x+12;
		bullet2->pos_y = ship->pos_y+4;
		bullet2->vel_x = 2;
	}
}
//bullet3 logic
else if (bullet3->vel_x == 0){

	if (center == 5) {
		bullet3->pos_x = ship->pos_x+12;
		bullet3->pos_y = ship->pos_y+4;
		bullet3->vel_x = 2;
	}
}
//bullet4 logic
else if (bullet4->vel_x == 0){

	if (center == 5) {
		bullet4->pos_x = ship->pos_x+12;
		bullet4->pos_y = ship->pos_y+4;
		bullet4->vel_x = 2;
	}
}
//bullet5 logic
else if (bullet5->vel_x == 0){

	if (center == 5) {
		bullet5->pos_x = ship->pos_x+12;
		bullet5->pos_y = ship->pos_y+4;
		bullet5->vel_x = 2;
	}
}



//logic for moving bullet1
	if (bullet1->pos_x < 235 && bullet1->vel_x != 0){
		gotoxy(bullet1->pos_x,bullet1->pos_y);
		printf("0");

		gotoxy(bullet1->pos_x-bullet1->vel_x,bullet1->pos_y-bullet1->vel_y);
		printf(" ");
		bullet1->pos_x = bullet1->pos_x + bullet1->vel_x;

	}
	if (bullet1->pos_x >= 235) {
		gotoxy(bullet1->pos_x,bullet1->pos_y);
		gotoxy(bullet1->pos_x-bullet1->vel_x,bullet1->pos_y-bullet1->vel_y);
		printf(" ");

		bullet1->vel_x = 0;
		bullet1->pos_x = 1;
	}

//logic for moving bullet2
	if (bullet2->pos_x < 235 && bullet2->vel_x != 0){
		gotoxy(bullet2->pos_x,bullet2->pos_y);
		printf("0");

		gotoxy(bullet2->pos_x-bullet2->vel_x,bullet2->pos_y-bullet2->vel_y);
		printf(" ");
		bullet2->pos_x = bullet2->pos_x + bullet2->vel_x;

	}
	if (bullet2->pos_x >= 235) {
		gotoxy(bullet2->pos_x,bullet2->pos_y);
		gotoxy(bullet2->pos_x-bullet2->vel_x,bullet2->pos_y-bullet2->vel_y);
		printf(" ");

		bullet2->vel_x = 0;
		bullet2->pos_x = 1;
	}
//logic for moving bullet3
	if (bullet3->pos_x < 235 && bullet3->vel_x != 0){
		gotoxy(bullet3->pos_x,bullet3->pos_y);
		printf("0");

		gotoxy(bullet3->pos_x-bullet3->vel_x,bullet3->pos_y-bullet3->vel_y);
		printf(" ");
		bullet3->pos_x = bullet3->pos_x + bullet3->vel_x;

	}
	if (bullet3->pos_x >= 235) {
		gotoxy(bullet3->pos_x,bullet3->pos_y);
		gotoxy(bullet3->pos_x-bullet3->vel_x,bullet3->pos_y-bullet3->vel_y);
		printf(" ");

		bullet3->vel_x = 0;
		bullet3->pos_x = 1;
	}

//logic for moving bullet4
	if (bullet4->pos_x < 235 && bullet4->vel_x != 0){
		gotoxy(bullet4->pos_x,bullet4->pos_y);
		printf("0");

		gotoxy(bullet4->pos_x-bullet4->vel_x,bullet4->pos_y-bullet4->vel_y);
		printf(" ");
		bullet4->pos_x = bullet4->pos_x + bullet4->vel_x;

	}
	if (bullet4->pos_x >= 235) {
		gotoxy(bullet4->pos_x,bullet4->pos_y);
		gotoxy(bullet4->pos_x-bullet4->vel_x,bullet4->pos_y-bullet4->vel_y);
		printf(" ");

		bullet4->vel_x = 0;
		bullet4->pos_x = 1;
	}

//logic for moving bullet5
	if (bullet5->pos_x < 235 && bullet5->vel_x != 0){
		gotoxy(bullet5->pos_x,bullet5->pos_y);
		printf("0");

		gotoxy(bullet5->pos_x-bullet5->vel_x,bullet5->pos_y-bullet5->vel_y);
		printf(" ");
		bullet5->pos_x = bullet5->pos_x + bullet5->vel_x;

	}
	if (bullet5->pos_x >= 235) {
		gotoxy(bullet5->pos_x,bullet5->pos_y);
		gotoxy(bullet5->pos_x-bullet5->vel_x,bullet5->pos_y-bullet5->vel_y);
		printf(" ");

		bullet5->vel_x = 0;
		bullet5->pos_x = 1;
	}
}
}

void laser(spaceship_t *ship, int center,laser_t *laser, int *laser_shot){
	//logic for spawning laser
	int length;
	if (ship->powerup == 1){
		if (center == 5){
			ship->laser_shot = 1;
			laser->pos_y = ship->pos_y+4;
			laser->pos_x = ship->pos_x+11;
			while (length < (228-laser->pos_x)){
				gotoxy(laser->pos_x+length,laser->pos_y);
				bgcolor(1);
				printf("          ");
				length = length + 5;
			}
			length = 0;
			while (length < (228-laser->pos_x)){
				gotoxy(laser->pos_x+length,laser->pos_y);
				bgcolor(0);
				printf("          ");
				length = length + 5;
			}
			length = 0;
			bgcolor(0);
		}
	}
}

void spread_shot(spaceship_t *ship, int center, bullet_t *bullet_spread1, bullet_t *bullet_spread2, bullet_t *bullet_spread3){
	if (ship->powerup == 2){

	//logic for spawning bullets
	//bullet_spread1&2&3 logic
	if ((bullet_spread1->vel_x == 0) && (bullet_spread2->vel_x == 0) && (bullet_spread3->vel_x == 0)){

		if (center == 5) {
			bullet_spread1->pos_x = ship->pos_x+12;
			bullet_spread1->pos_y = ship->pos_y+3;
			bullet_spread1->vel_x = 2;
			bullet_spread1->vel_y = -1;

			bullet_spread2->pos_x = ship->pos_x+12;
			bullet_spread2->pos_y = ship->pos_y+4;
			bullet_spread2->vel_x = 2;
			bullet_spread2->vel_y = 0;

			bullet_spread3->pos_x = ship->pos_x+12;
			bullet_spread3->pos_y = ship->pos_y+5;
			bullet_spread3->vel_x = 2;
			bullet_spread3->vel_y = 1;
		}
	}

	}

	//logic for moving bullet_spread1
		if (bullet_spread1->pos_x < 158 && bullet_spread1->vel_x != 0){
			gotoxy(bullet_spread1->pos_x,bullet_spread1->pos_y);
			printf("o");

			gotoxy(bullet_spread1->pos_x-bullet_spread1->vel_x,bullet_spread1->pos_y-bullet_spread1->vel_y);
			printf(" ");
			bullet_spread1->pos_x = bullet_spread1->pos_x + bullet_spread1->vel_x;
			bullet_spread1->pos_y = bullet_spread1->pos_y + bullet_spread1->vel_y;

		}
		if ((bullet_spread1->pos_x >= 158) || (bullet_spread1->pos_y >= 50) || (bullet_spread1->pos_y <= 0)) {
			gotoxy(bullet_spread1->pos_x,bullet_spread1->pos_y);
			gotoxy(bullet_spread1->pos_x-bullet_spread1->vel_x,bullet_spread1->pos_y-bullet_spread1->vel_y);
			printf(" ");

			bullet_spread1->vel_x = 0;
			bullet_spread1->vel_y = 0;
			bullet_spread1->pos_x = 1;
			bullet_spread1->pos_y = 1;
		}
	//logic for moving bullet_spread2
		if (bullet_spread2->pos_x < 158 && bullet_spread2->vel_x != 0){
			gotoxy(bullet_spread2->pos_x,bullet_spread2->pos_y);
			printf("o");

			gotoxy(bullet_spread2->pos_x-bullet_spread2->vel_x,bullet_spread2->pos_y-bullet_spread2->vel_y);
			printf(" ");
			bullet_spread2->pos_x = bullet_spread2->pos_x + bullet_spread2->vel_x;
			bullet_spread2->pos_y = bullet_spread2->pos_y + bullet_spread2->vel_y;

		}
		if ((bullet_spread2->pos_x >= 158) || (bullet_spread2->pos_y >= 50) || (bullet_spread2->pos_y <= 0)) {
			gotoxy(bullet_spread2->pos_x,bullet_spread2->pos_y);
			gotoxy(bullet_spread2->pos_x-bullet_spread2->vel_x,bullet_spread2->pos_y-bullet_spread2->vel_y);
			printf(" ");

			bullet_spread2->vel_x = 0;
			bullet_spread2->vel_y = 0;
			bullet_spread2->pos_x = 1;
			bullet_spread2->pos_y = 1;
		}
	//logic for moving bullet_spread3
		if (bullet_spread3->pos_x < 158 && bullet_spread3->vel_x != 0){
			gotoxy(bullet_spread3->pos_x,bullet_spread3->pos_y);
			printf("o");

			gotoxy(bullet_spread3->pos_x-bullet_spread3->vel_x,bullet_spread3->pos_y-bullet_spread3->vel_y);
			printf(" ");
			bullet_spread3->pos_x = bullet_spread3->pos_x + bullet_spread3->vel_x;
			bullet_spread3->pos_y = bullet_spread3->pos_y + bullet_spread3->vel_y;

		}
		if ((bullet_spread3->pos_x >= 158) || (bullet_spread3->pos_y >= 50) || (bullet_spread3->pos_y <= 0)) {
			gotoxy(bullet_spread3->pos_x,bullet_spread3->pos_y);
			gotoxy(bullet_spread3->pos_x-bullet_spread3->vel_x,bullet_spread3->pos_y-bullet_spread3->vel_y);
			printf(" ");

			bullet_spread3->vel_x = 0;
			bullet_spread3->vel_y = 0;
			bullet_spread3->pos_x = 1;
			bullet_spread3->pos_y = 1;
		}

}
