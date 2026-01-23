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
#define ESC 0x1B
#define block 0xDB
#define skud 0xDF

//function not used
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

void update_pos(spaceship_t *ship,int joystick, int keyboard) {


	if (joystick == 1 || keyboard == 65) {
		if (ship->pos_y>2){
			ship->pos_y = ship->pos_y-1;
		}
	} // up

	if (joystick == 3 || keyboard == 66) {
		if (ship->pos_y<55){
			ship->pos_y = ship->pos_y+1;
		}
	} // down

	//if (direction == 2) {
	//	if (ship->pos_x < 230) {
	//		ship->pos_x = ship->pos_x+2;
	//	}
	//} // right

	//if (direction == 4) {
	//	if (ship->pos_x > 0) {
	//		ship->pos_x = ship->pos_x-2;
	//	}
	//} // left
}

void shoot(spaceship_t *ship, int joystick,int space,bullet_t *bullet1,bullet_t *bullet2,bullet_t *bullet3,bullet_t *bullet4,bullet_t *bullet5) {

if (ship->powerup == 0){

//logic for spawning bullets
//bullet1 logic
if (bullet1->vel_x == 0){

	if ((joystick == 5 || space == 32)) {
		bullet1->pos_x = ship->pos_x+12;
		bullet1->pos_y = (ship->pos_y+4)<<5;
		bullet1->vel_x = 2;
		bullet1->vel_y = 0;
	}
}
//bullet2 logic
else if (bullet2->vel_x == 0){

	if (joystick == 5 || space == 32) {
		bullet2->pos_x = ship->pos_x+12;
		bullet2->pos_y = (ship->pos_y+4)<<5;
		bullet2->vel_x = 2;
		bullet2->vel_y = 0;
	}
}
//bullet3 logic
else if (bullet3->vel_x == 0){

	if (joystick == 5 || space == 32) {
		bullet3->pos_x = ship->pos_x+12;
		bullet3->pos_y = (ship->pos_y+4)<<5;
		bullet3->vel_x = 2;
		bullet3->vel_y = 0;
	}
}
//bullet4 logic
else if (bullet4->vel_x == 0){

	if (joystick == 5 || space == 32) {
		bullet4->pos_x = ship->pos_x+12;
		bullet4->pos_y = (ship->pos_y+4)<<5;
		bullet4->vel_x = 2;
		bullet4->vel_y = 0;
	}
}
//bullet5 logic
else if (bullet5->vel_x == 0){

	if (joystick == 5 || space == 32) {
		bullet5->pos_x = ship->pos_x+12;
		bullet5->pos_y = (ship->pos_y+4)<<5;
		bullet5->vel_x = 2;
		bullet5->vel_y = 0;
	}
}



//logic for moving bullet1
	if (bullet1->pos_x < 235 && bullet1->vel_x != 0){
		gotoxy(bullet1->pos_x,(bullet1->pos_y)>>5);
		fgcolor(12);
		printf("%c",skud);
		fgcolor(15);

		gotoxy(bullet1->pos_x-bullet1->vel_x,(bullet1->pos_y-bullet1->vel_y)>>5);
		printf(" ");
		bullet1->pos_x = bullet1->pos_x + bullet1->vel_x;
		bullet1->pos_y = bullet1->pos_y + bullet1->vel_y;

	}
	if (bullet1->pos_x >= 235 || bullet1->pos_y>>5 >=65 || bullet1->pos_y>>5 <= 0) {
		gotoxy(bullet1->pos_x-bullet1->vel_x,(bullet1->pos_y-bullet1->vel_y)>>5);
		printf(" ");

		bullet1->vel_y = 0;
		bullet1->vel_x = 0;
		bullet1->pos_x = 1;
		bullet1->pos_y = 1;
	}

//logic for moving bullet2
	if (bullet2->pos_x < 235 && bullet2->vel_x != 0){
		gotoxy(bullet2->pos_x,(bullet2->pos_y)>>5);
		fgcolor(12);
		printf("%c",skud);
		fgcolor(15);

		gotoxy(bullet2->pos_x-bullet2->vel_x,(bullet2->pos_y-bullet2->vel_y)>>5);
		printf(" ");
		bullet2->pos_x = bullet2->pos_x + bullet2->vel_x;
		bullet2->pos_y = bullet2->pos_y + bullet2->vel_y;

	}
	if (bullet2->pos_x >= 235 || bullet2->pos_y>>5 >=65 || bullet2->pos_y>>5 <= 0) {
		gotoxy(bullet2->pos_x-bullet2->vel_x,(bullet2->pos_y-bullet2->vel_y)>>5);
		printf(" ");

		bullet2->vel_y = 0;
		bullet2->vel_x = 0;
		bullet2->pos_x = 1;
		bullet2->pos_y = 1;
	}
//logic for moving bullet3
	if (bullet3->pos_x < 235 && bullet3->vel_x != 0){
		gotoxy(bullet3->pos_x,(bullet3->pos_y)>>5);
		fgcolor(12);
		printf("%c",skud);
		fgcolor(15);

		gotoxy(bullet3->pos_x-bullet3->vel_x,(bullet3->pos_y-bullet3->vel_y)>>5);
		printf(" ");
		bullet3->pos_x = bullet3->pos_x + bullet3->vel_x;
		bullet3->pos_y = bullet3->pos_y + bullet3->vel_y;

	}
	if (bullet3->pos_x >= 235 || bullet3->pos_y>>5 >=65 || bullet3->pos_y>>5 <= 0) {
		gotoxy(bullet3->pos_x-bullet3->vel_x,(bullet3->pos_y-bullet3->vel_y)>>5);
		printf(" ");

		bullet3->vel_y = 0;
		bullet3->vel_x = 0;
		bullet3->pos_x = 1;
		bullet3->pos_y = 1;
	}
//logic for moving bullet4
		if (bullet4->pos_x < 235 && bullet4->vel_x != 0){
			gotoxy(bullet4->pos_x,(bullet4->pos_y)>>5);
			fgcolor(12);
			printf("%c",skud);
			fgcolor(15);

			gotoxy(bullet4->pos_x-bullet4->vel_x,(bullet4->pos_y-bullet4->vel_y)>>5);
			printf(" ");
			bullet4->pos_x = bullet4->pos_x + bullet4->vel_x;
			bullet4->pos_y = bullet4->pos_y + bullet4->vel_y;

		}
		if (bullet4->pos_x >= 235 || bullet4->pos_y>>5 >=65 || bullet4->pos_y>>5 <= 0) {
			gotoxy(bullet4->pos_x-bullet4->vel_x,(bullet4->pos_y-bullet4->vel_y)>>5);
			printf(" ");

			bullet4->vel_y = 0;
			bullet4->vel_x = 0;
			bullet4->pos_x = 1;
			bullet4->pos_y = 1;

		}
//logic for moving bullet5
		if (bullet5->pos_x < 235 && bullet5->vel_x != 0){
			gotoxy(bullet5->pos_x,(bullet5->pos_y)>>5);
			fgcolor(12);
			printf("%c",skud);
			fgcolor(15);

			gotoxy(bullet5->pos_x-bullet5->vel_x,(bullet5->pos_y-bullet5->vel_y)>>5);
			printf(" ");
			bullet5->pos_x = bullet5->pos_x + bullet5->vel_x;
			bullet5->pos_y = bullet5->pos_y + bullet5->vel_y;

			}
		if (bullet5->pos_x >= 235 || bullet5->pos_y>>5 >=65 || bullet5->pos_y>>5 <= 0) {
			gotoxy(bullet5->pos_x-bullet5->vel_x,(bullet5->pos_y-bullet5->vel_y)>>5);
			printf(" ");

			bullet5->vel_y = 0;
			bullet5->vel_x = 0;
			bullet5->pos_x = 1;
			bullet5->pos_y = 1;

		}}
}

void laser(spaceship_t *ship, int joystick,int keyboard,laser_t *laser){
	//logic for spawning laser
	int length;
	if (ship->laser_shot > 0){
		if (joystick == 2 || keyboard ==  67) {
			ship->laser_shot -= 1;
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

void spread_shot(spaceship_t *ship, int joystick,int keyboard, bullet_t *bullet_spread1, bullet_t *bullet_spread2, bullet_t *bullet_spread3){
	if (ship->spread_shot > 0){
	//logic for spawning bullets
	//bullet_spread1&2&3 logic
	if ((bullet_spread1->vel_x == 0) && (bullet_spread2->vel_x == 0) && (bullet_spread3->vel_x == 0)){

		if (joystick == 4 || keyboard == 68) {
			ship->spread_shot -= 1;
			bullet_spread1->pos_x = ship->pos_x+12;
			bullet_spread1->pos_y = (ship->pos_y+3)<<5;
			bullet_spread1->vel_x = 3;
			bullet_spread1->vel_y = -1<<5;

			bullet_spread2->pos_x = ship->pos_x+12;
			bullet_spread2->pos_y = (ship->pos_y+4)<<5;
			bullet_spread2->vel_x = 3;
			bullet_spread2->vel_y = 0<<5;

			bullet_spread3->pos_x = ship->pos_x+12;
			bullet_spread3->pos_y = (ship->pos_y+5)<<5;
			bullet_spread3->vel_x = 3;
			bullet_spread3->vel_y = 1<<5;
		}
	}

	}

	//logic for moving bullet_spread1
		if (bullet_spread1->pos_x < 230 && bullet_spread1->vel_x != 0){
			gotoxy(bullet_spread1->pos_x,bullet_spread1->pos_y>>5);
			fgcolor(12);
			printf("%c",skud);
			fgcolor(15);

			gotoxy(bullet_spread1->pos_x-bullet_spread1->vel_x,(bullet_spread1->pos_y-bullet_spread1->vel_y)>>5);
			printf(" ");
			bullet_spread1->pos_x = bullet_spread1->pos_x + bullet_spread1->vel_x;
			bullet_spread1->pos_y = bullet_spread1->pos_y + bullet_spread1->vel_y;

		}
		if ((bullet_spread1->pos_x >= 120) || (bullet_spread1->pos_y>>5 >= 64) || (bullet_spread1->pos_y>>5 <= 0)) {
			gotoxy(bullet_spread1->pos_x,bullet_spread1->pos_y>>5);
			gotoxy(bullet_spread1->pos_x-bullet_spread1->vel_x,(bullet_spread1->pos_y-bullet_spread1->vel_y)>>5);
			printf(" ");

			bullet_spread1->vel_x = 0;
			bullet_spread1->vel_y = 0;
			bullet_spread1->pos_x = 1;
			bullet_spread1->pos_y = 1;
		}
		//logic for moving bullet_spread1
			if (bullet_spread2->pos_x < 230 && bullet_spread2->vel_x != 0){
				gotoxy(bullet_spread2->pos_x,bullet_spread2->pos_y>>5);
				fgcolor(12);
				printf("%c",skud);
				fgcolor(15);

				gotoxy(bullet_spread2->pos_x-bullet_spread2->vel_x,(bullet_spread2->pos_y-bullet_spread2->vel_y)>>5);
				printf(" ");
				bullet_spread2->pos_x = bullet_spread2->pos_x + bullet_spread2->vel_x;
				bullet_spread2->pos_y = bullet_spread2->pos_y + bullet_spread2->vel_y;

			}
			if ((bullet_spread2->pos_x >= 120) || (bullet_spread2->pos_y>>5 >= 64) || (bullet_spread2->pos_y>>5 <= 0)) {
				gotoxy(bullet_spread2->pos_x,bullet_spread2->pos_y>>5);
				gotoxy(bullet_spread2->pos_x-bullet_spread2->vel_x,(bullet_spread2->pos_y-bullet_spread2->vel_y)>>5);
				printf(" ");

				bullet_spread2->vel_x = 0;
				bullet_spread2->vel_y = 0;
				bullet_spread2->pos_x = 1;
				bullet_spread2->pos_y = 1;
			}
			//logic for moving bullet_spread1
				if (bullet_spread3->pos_x < 230 && bullet_spread3->vel_x != 0){
					gotoxy(bullet_spread3->pos_x,bullet_spread3->pos_y>>5);
					fgcolor(12);
					printf("%c",skud);
					fgcolor(15);

					gotoxy(bullet_spread3->pos_x-bullet_spread3->vel_x,(bullet_spread3->pos_y-bullet_spread3->vel_y)>>5);
					printf(" ");
					bullet_spread3->pos_x = bullet_spread3->pos_x + bullet_spread3->vel_x;
					bullet_spread3->pos_y = bullet_spread3->pos_y + bullet_spread3->vel_y;

				}
				if ((bullet_spread3->pos_x >= 120) || (bullet_spread3->pos_y>>5 >= 64) || (bullet_spread3->pos_y>>5 <= 0)) {
					gotoxy(bullet_spread3->pos_x,bullet_spread3->pos_y>>5);
					gotoxy(bullet_spread3->pos_x-bullet_spread3->vel_x,(bullet_spread3->pos_y-bullet_spread3->vel_y)>>5);
					printf(" ");

					bullet_spread3->vel_x = 0;
					bullet_spread3->vel_y = 0;
					bullet_spread3->pos_x = 1;
					bullet_spread3->pos_y = 1;
				}

}

void draw_spaceship1(spaceship_t *ship) {

	gotoxy(ship->pos_x, ship->pos_y-1);
	printf("       ");

	gotoxy(ship->pos_x, ship->pos_y);
	fgcolor(0);
	printf("%c", block);
	printf("%c", block);
	fgcolor(8);
	printf("%c", block);
	printf("%c", block);
	printf("%c", block);
	fgcolor(7);
	printf("%c", block);
	printf("%c ", block);

	gotoxy(ship->pos_x, ship->pos_y+1);
	fgcolor(0);
	printf("%c", block);
	printf("%c", block);
	printf("%c", block);
	fgcolor(7);
	printf("%c", block);
	printf("%c", block);
	fgcolor(15);
	printf("%c", block);
	printf("%c", block);
	fgcolor(7);
	printf("%c ", block);

	gotoxy(ship->pos_x, ship->pos_y+2);
	fgcolor(0);
	printf("%c", block);
	printf("%c", block);
	printf("%c", block);
	printf("%c", block);
	fgcolor(7);
	printf("%c", block);
	fgcolor(15);
	printf("%c", block);
	printf("%c", block);
	printf("%c", block);
	fgcolor(7);
	printf("%c ", block);

	//første række med ild
	gotoxy(ship->pos_x, ship->pos_y+3);
	fgcolor(0);
	printf("%c", block);
	fgcolor(9);
	printf("%c", block);
	printf("%c", block);
	fgcolor(11);
	printf("%c", block);
	fgcolor(8);
	printf("%c", block);
	fgcolor(7);
	printf("%c", block);
	fgcolor(8);
	printf("%c", block);
	fgcolor(12);
	printf("%c", block);
	fgcolor(15);
	printf("%c", block);
	printf("%c ", block);

	//anden række med ild
	gotoxy(ship->pos_x, ship->pos_y+4);
	fgcolor(9);
	printf("%c", block);
	printf("%c", block);
	fgcolor(11);
	printf("%c", block);
	printf("%c", block);
	fgcolor(8);
	printf("%c", block);
	fgcolor(7);
	printf("%c", block);
	fgcolor(8);
	printf("%c", block);
	fgcolor(12);
	printf("%c", block);
	fgcolor(15);
	printf("%c", block);
	printf("%c ", block);

	//Tredje række med ild
	gotoxy(ship->pos_x, ship->pos_y+5);
	fgcolor(9);
	printf("%c", block);
	printf("%c", block);
	fgcolor(11);
	printf("%c", block);
	printf("%c", block);
	fgcolor(8);
	printf("%c", block);
	fgcolor(7);
	printf("%c", block);
	fgcolor(8);
	printf("%c", block);
	fgcolor(12);
	printf("%c", block);
	fgcolor(15);
	printf("%c", block);
	printf("%c ", block);

	gotoxy(ship->pos_x, ship->pos_y+6);
	fgcolor(0);
	printf("%c", block);
	printf("%c", block);
	printf("%c", block);
	printf("%c", block);
	fgcolor(7);
	printf("%c", block);
	fgcolor(15);
	printf("%c", block);
	printf("%c", block);
	printf("%c", block);
	fgcolor(7);
	printf("%c ", block);

	gotoxy(ship->pos_x, ship->pos_y+7);
	fgcolor(0);
	printf("%c", block);
	printf("%c", block);
	printf("%c", block);
	fgcolor(7);
	printf("%c", block);
	printf("%c", block);
	fgcolor(15);
	printf("%c", block);
	printf("%c", block);
	fgcolor(7);
	printf("%c ", block);

	gotoxy(ship->pos_x, ship->pos_y+8);
	fgcolor(0);
	printf("%c", block);
	printf("%c", block);
	fgcolor(8);
	printf("%c", block);
	printf("%c", block);
	printf("%c", block);
	fgcolor(7);
	printf("%c", block);
	printf("%c ", block);
	gotoxy(ship->pos_x, ship->pos_y+9);
	printf("       ");

fgcolor(15);

}

void lorentzforce(bullet_t *bullets, astroid_t *stroids)
{
    for (int i = 0; i < 5; i++) {
        for (int t = 0; t < 8; t++) {

            int bx = bullets[i].pos_x;
            int by = bullets[i].pos_y >> 5;   // only if pos_y is fixed-point
            int ax = stroids[t].pos_x;
            int ay = stroids[t].pos_y;

            // X inside asteroid width [ax, ax+5]
            if ((bullets[i].vel_x !=0)&&(bx >= ax && bx <= ax + 5)) {

                // example: if bullet is in band ay..ay+8 -> push down
                if (by <= ay && by >= ay - 4) {
                    bullets[i].vel_y+=3;

                // example: if bullet is in band ay+6..ay+10 -> push up
                } else if (by >= ay + 3 && by <= ay + 12) {
                    bullets[i].vel_y-=3;
                }
            }
        }
    }
}
