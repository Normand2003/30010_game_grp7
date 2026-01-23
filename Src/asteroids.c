/*
 * objects.c
 *
 *  Created on: 13. jan. 2026
 *      Author: chris & Jeppe
 */

#include "spaceship.h"
#include "joystick.h"
#include "structures.h"
#include "draw.h"
#include "stopwatch.h"
#define ESC 0x1B
#define block 0xDB



//function not used? i think
void deprint_astroid(astroid_t *astroid){
	if (astroid->type == 3){
		gotoxy(astroid->pos_x-astroid->vel_x,astroid->pos_y); //this prints the removal astroid type 3 (large)
		printf("          ");
		gotoxy(astroid->pos_x-astroid->vel_x,astroid->pos_y+1);
		printf("           ");
		gotoxy(astroid->pos_x-astroid->vel_x,astroid->pos_y+2);
		printf("           ");
		gotoxy(astroid->pos_x-astroid->vel_x,astroid->pos_y+3);
		printf("          ");
		gotoxy(astroid->pos_x-astroid->vel_x,astroid->pos_y+4);
		printf("          ");
	}

	if (astroid->type == 2){
		gotoxy(astroid->pos_x-astroid->vel_x,astroid->pos_y); //this prints the removal astroid type 2 (medium)
		printf("       ");
		gotoxy(astroid->pos_x-astroid->vel_x,astroid->pos_y+1);
		printf("       ");
		gotoxy(astroid->pos_x-astroid->vel_x,astroid->pos_y+2);
		printf("       ");
		gotoxy(astroid->pos_x-astroid->vel_x,astroid->pos_y+3);
		printf("       ");
	}

	if (astroid->type == 1){
	gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 1 (small)
	printf("    ");
	gotoxy(astroid->pos_x,astroid->pos_y+1);
	printf("    ");
	gotoxy(astroid->pos_x,astroid->pos_y+2);
	printf("    ");
	}
}

void hit_astroid(astroid_t *astroid,bullet_t *bullet, spaceship_t *ship) {
	if (astroid->type == 3){
	if ((bullet->pos_x-1 >= astroid->pos_x && bullet->pos_y>>5 >= astroid->pos_y) && (bullet->pos_x <= astroid->pos_x+10 && bullet->pos_y>>5 <= astroid->pos_y+4)){

		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 3 (large)
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+4);
		printf("          ");
		//respawns astroid
		astroid->pos_x = 230;
		astroid->pos_y = (rand() % 57)+4;
		//increases score
		ship->score += 10;

		//destroys the bullet
		gotoxy(bullet->pos_x-bullet->vel_x,(bullet->pos_y-bullet->vel_y)>>5);
		printf(" ");
		bullet->vel_x = 0;
		bullet->pos_x = 0;
		bullet->pos_y = 0;

	}
	}

	if (astroid->type == 2){
	if ((bullet->pos_x-1 >= astroid->pos_x && bullet->pos_y>>5 >= astroid->pos_y) && (bullet->pos_x <= astroid->pos_x+6 && bullet->pos_y>>5 <= astroid->pos_y+3)){

		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 2 (medium)
		printf("       ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("       ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("       ");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf("       ");
		//respawns astroid
		astroid->pos_x = 230;
		astroid->pos_y = (rand() % 57)+4;
		//increases score
		ship->score += 20;

		//destroys the bullet
		gotoxy(bullet->pos_x-bullet->vel_x,(bullet->pos_y-bullet->vel_y)>>5);
		printf(" ");
		bullet->vel_x = 0;
		bullet->pos_x = 0;
		bullet->pos_y = 0;
	}
	}

	if (astroid->type == 1){
	if ((bullet->pos_x-1 >= astroid->pos_x && bullet->pos_y>>5 >= astroid->pos_y) && (bullet->pos_x <= astroid->pos_x+5 && bullet->pos_y>>5 <= astroid->pos_y+2)){

		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 1 (small)
		printf("    ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("    ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("    ");
		//respawns astroid
		astroid->pos_x = 230;
		astroid->pos_y = (rand() % 57)+4;
		//increases score
		ship->score += 30;

		//destroys the bullet
		gotoxy(bullet->pos_x-bullet->vel_x,(bullet->pos_y-bullet->vel_y)>>5);
		printf(" ");
		bullet->vel_x = 0;
		bullet->pos_x = 0;
		bullet->pos_y = 0;
	}
	}
	if (astroid->type == 4){
	if ((bullet->pos_x-1 >= astroid->pos_x && bullet->pos_y>>5 >= astroid->pos_y) && (bullet->pos_x <= astroid->pos_x+7 && bullet->pos_y>>5 <= astroid->pos_y+8)){

		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 4 (satellite)
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+4);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+5);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+6);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+7);
		printf("          ");
		//respawns astroid
		astroid->pos_x = 230;
		astroid->pos_y = (rand() % 52)+4;
		//increases ammo
		ship->spread_shot += 1;
		ship->score += 2;

		//destroys the bullet
		gotoxy(bullet->pos_x-bullet->vel_x,(bullet->pos_y-bullet->vel_y)>>5);
		printf(" ");
		bullet->vel_x = 0;
		bullet->pos_x = 0;
		bullet->pos_y = 0;

	}
	}
	if (astroid->type == 5){
	if ((bullet->pos_x-1 >= astroid->pos_x && bullet->pos_y>>5 >= astroid->pos_y) && (bullet->pos_x <= astroid->pos_x+7 && bullet->pos_y>>5 <= astroid->pos_y+8)){

		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 5 (satellite)
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+4);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+5);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+6);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+7);
		printf("          ");
		//respawns astroid
		astroid->pos_x = 230;
		astroid->pos_y = (rand() % 52)+4;
		//increases ammo
		ship->laser_shot += 1;
		ship->score += 2;

		//destroys the bullet
		gotoxy(bullet->pos_x-bullet->vel_x,(bullet->pos_y-bullet->vel_y)>>5);
		printf(" ");
		bullet->vel_x = 0;
		bullet->pos_x = 0;
		bullet->pos_y = 0;

	}
	}
	if (astroid->type == 6){
	if ((bullet->pos_x-1 >= astroid->pos_x && bullet->pos_y>>5 >= astroid->pos_y) && (bullet->pos_x <= astroid->pos_x+11 && bullet->pos_y>>5 <= astroid->pos_y+5)){

		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 6 (alien)
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+4);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+5);
		printf("           ");
		//respawns alien
		astroid->pos_x = 230;
		astroid->pos_y = (rand() % 54)+4;
		//increases score
		ship->score += 100;

		//destroys the bullet
		gotoxy(bullet->pos_x-bullet->vel_x,(bullet->pos_y-bullet->vel_y)>>5);
		printf(" ");
		bullet->vel_x = 0;
		bullet->pos_x = 0;
		bullet->pos_y = 0;

	}
	}
}

void laser_hit(astroid_t *astroid, laser_t *laser,spaceship_t *ship){
	if (astroid->type == 3){
	if (laser->pos_y >= astroid->pos_y && laser->pos_y <= astroid->pos_y+4){
		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 3 (large)
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+4);
		printf("          ");
		//respawns the asteroid
		astroid->pos_y = (rand() % 57)+4;
		astroid->pos_x = 234;
		laser->pos_y = 70;
		ship->score += 10;
	}
	}
	if (astroid->type == 2){
	if (laser->pos_y >= astroid->pos_y && laser->pos_y <= astroid->pos_y+3){
		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 2 (med)
		printf("        ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("         ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("         ");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf("        ");
		//respawns the asteroid
		astroid->pos_y = (rand() % 57)+4;
		astroid->pos_x = 234;
		laser->pos_y = 70;
		ship->score += 20;
	}
	}
	if (astroid->type == 1){
	if (laser->pos_y >= astroid->pos_y && laser->pos_y <= astroid->pos_y+2){
		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 2 (med)
		printf("       ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("        ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("        ");
		//respawns the asteroid
		astroid->pos_y = (rand() % 57)+4;
		astroid->pos_x = 234;
		laser->pos_y = 70;
		ship->score += 30;
	}
	}
	if (astroid->type == 4){
	if (laser->pos_y >= astroid->pos_y && laser->pos_y <= astroid->pos_y+8){
		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 4 (satellite)
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+4);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+5);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+6);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+7);
		printf("          ");
		//respawns the asteroid
		astroid->pos_y = (rand() % 54)+4;
		astroid->pos_x = 234;
		laser->pos_y = 70;
		ship->spread_shot += 1;
		ship->score += 2;
	}
	}
	if (astroid->type == 5){
	if (laser->pos_y >= astroid->pos_y && laser->pos_y <= astroid->pos_y+8){
		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 5 (satellite)
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+4);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+5);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+6);
		printf("          ");
		gotoxy(astroid->pos_x,astroid->pos_y+7);
		printf("          ");
		//respawns the asteroid
		astroid->pos_y = (rand() % 54)+4;
		astroid->pos_x = 234;
		laser->pos_y = 70;
		ship->laser_shot += 1;
		ship->score += 2;
	}
	}
	if (astroid->type == 6){
	if (laser->pos_y >= astroid->pos_y && laser->pos_y <= astroid->pos_y+5){
		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 6 (alien)
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+4);
		printf("           ");
		gotoxy(astroid->pos_x,astroid->pos_y+5);
		printf("           ");
		//respawns the asteroid
		astroid->pos_y = (rand() % 54)+4;
		astroid->pos_x = 234;
		laser->pos_y = 70;
		ship->score += 100;
	}
	}
}

void spaceship_hit(astroid_t *astroid,spaceship_t *ship){
if (astroid->type == 3){
	if((ship->pos_x+9 >= astroid->pos_x) && (ship->pos_x <= astroid->pos_x+6 )){
		if((ship->pos_y+8 >= astroid->pos_y) && (ship->pos_y <= astroid->pos_y+4)){
			ship->health = ship->health - 1;

			gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 3 (large)
			printf("          ");
			gotoxy(astroid->pos_x,astroid->pos_y+1);
			printf("           ");
			gotoxy(astroid->pos_x,astroid->pos_y+2);
			printf("           ");
			gotoxy(astroid->pos_x,astroid->pos_y+3);
			printf("          ");
			gotoxy(astroid->pos_x,astroid->pos_y+4);
			printf("          ");
			//respawns astroid
			astroid->pos_x = 230;
			astroid->pos_y = (rand() % 57)+4;
		}
	}
}
if (astroid->type == 2){
	if((ship->pos_x+9 >= astroid->pos_x) && (ship->pos_x <= astroid->pos_x+5 )){
		if((ship->pos_y+8 >= astroid->pos_y) && (ship->pos_y <= astroid->pos_y+3)){

			ship->health = ship->health - 1;

			gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 2 (medium)
			printf("       ");
			gotoxy(astroid->pos_x,astroid->pos_y+1);
			printf("       ");
			gotoxy(astroid->pos_x,astroid->pos_y+2);
			printf("       ");
			gotoxy(astroid->pos_x,astroid->pos_y+3);
			printf("       ");
			//respawns astroid
			astroid->pos_x = 230;
			astroid->pos_y = (rand() % 57)+4;
		}
	}
}
if (astroid->type == 1){
	if((ship->pos_x+9 >= astroid->pos_x) && (ship->pos_x <= astroid->pos_x+4 )){
		if((ship->pos_y+8 >= astroid->pos_y) && (ship->pos_y <= astroid->pos_y+2)){

			ship->health = ship->health - 1;

			gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 1 (small)
			printf("    ");
			gotoxy(astroid->pos_x,astroid->pos_y+1);
			printf("    ");
			gotoxy(astroid->pos_x,astroid->pos_y+2);
			printf("    ");
			//respawns astroid
			astroid->pos_x = 230;
			astroid->pos_y = (rand() % 57)+4;
		}
	}
}
if (astroid->type == 4 || astroid->type == 5){
	if((ship->pos_x+9 >= astroid->pos_x) && (ship->pos_x <= astroid->pos_x+7 )){
		if((ship->pos_y+8 >= astroid->pos_y) && (ship->pos_y <= astroid->pos_y+8)){

			ship->health = ship->health - 1;

			gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 5 (satellite)
			printf("          ");
			gotoxy(astroid->pos_x,astroid->pos_y+1);
			printf("           ");
			gotoxy(astroid->pos_x,astroid->pos_y+2);
			printf("           ");
			gotoxy(astroid->pos_x,astroid->pos_y+3);
			printf("          ");
			gotoxy(astroid->pos_x,astroid->pos_y+4);
			printf("          ");
			gotoxy(astroid->pos_x,astroid->pos_y+5);
			printf("          ");
			gotoxy(astroid->pos_x,astroid->pos_y+6);
			printf("          ");
			gotoxy(astroid->pos_x,astroid->pos_y+7);
			printf("          ");
			//respawns astroid
			astroid->pos_x = 230;
			astroid->pos_y = (rand() % 54)+4;
		}
	}
}
if (astroid->type == 6){
	if((ship->pos_x+9 >= astroid->pos_x) && (ship->pos_x <= astroid->pos_x+11 )){
		if((ship->pos_y+8 >= astroid->pos_y) && (ship->pos_y <= astroid->pos_y+5)){

			//skib dør ved kontakt med alien
			ship->health = 0;

			gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 6 (alien)
			printf("           ");
			gotoxy(astroid->pos_x,astroid->pos_y+1);
			printf("           ");
			gotoxy(astroid->pos_x,astroid->pos_y+2);
			printf("           ");
			gotoxy(astroid->pos_x,astroid->pos_y+3);
			printf("           ");
			gotoxy(astroid->pos_x,astroid->pos_y+4);
			printf("           ");
			gotoxy(astroid->pos_x,astroid->pos_y+5);
			printf("           ");
			//respawns astroid
			astroid->pos_x = 230;
			astroid->pos_y = (rand() % 54)+4;
		}
	}
}
}

void draw_asteroid(astroid_t *astroid) {

	// 1 = lille, 2 = mellem, 3 = stor, 4 = satellite, 5 = red satellite, 6 = alien


	// lille
	if (astroid->type == 1) {
		//Første linje
		gotoxy(astroid->pos_x,astroid->pos_y);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);
		fgcolor(15);
		printf("%c", block);
		fgcolor(8);
		printf("%c     ", block);

		//Anden linje
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		fgcolor(8);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c     ", block);


		//Tredje linje
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		fgcolor(8);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);
		fgcolor(7);
		printf("%c     ", block);

		//resetter farven
		fgcolor(15);

	}


	// mellem
	else if  (astroid->type == 2) {
		//Første linje
		gotoxy(astroid->pos_x,astroid->pos_y);
		fgcolor(8);
		printf("%c%c", block,block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c%c", block,block);
		fgcolor(15);
		printf("%c     ", block);

		//Anden linje
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		fgcolor(8);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c%c", block,block);
		fgcolor(7);
		printf("%c%c", block,block);
		fgcolor(8);
		printf("%c     ", block);

		//Tredje linje
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c%c%c%c%c%c     ", block,block,block,block,block,block);


		//Fjerde linje
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		fgcolor(0);
		printf("%c", block);
		fgcolor(8);
		printf("%c%c", block,block);
		fgcolor(7);
		printf("%c%c     ", block,block);


		//resetter farven
		fgcolor(15);

	}
	// stor
	else if (astroid->type == 3) {
		//Første linje
		gotoxy(astroid->pos_x,astroid->pos_y);
		fgcolor(0);
		printf("%c", block);
		fgcolor(7);
		printf("%c%c", block,block);
		fgcolor(8);
		printf("%c%c%c     ", block,block,block);

		//Anden linje
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		fgcolor(7);
		printf("%c%c%c%c%c%c", block,block,block,block,block,block);
		fgcolor(15);
		printf("%c", block);
		fgcolor(8);
		printf("%c     ", block);


		//Tredje linje
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		fgcolor(8);
		printf("%c", block);
		fgcolor(7);
		printf("%c%c%c%c%c%c%c%c", block,block,block,block,block,block,block,block);
		fgcolor(8);
		printf("%c     ", block);

		//Fjerde linje
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		fgcolor(8);
		printf("%c%c", block,block);
		fgcolor(7);
		printf("%c%c", block,block);
		fgcolor(8);
		printf("%c", block);
		fgcolor(7);
		printf("%c%c%c", block,block,block);
		fgcolor(8);
		printf("%c     ", block);

		//Femte linje
		gotoxy(astroid->pos_x+1,astroid->pos_y+4);
		fgcolor(8);
		printf("%c%c%c", block,block,block);
		fgcolor(7);
		printf("%c%c%c", block,block,block);
		fgcolor(8);
		printf("%c     ", block);


		//resetter farven
		fgcolor(15);

	}


	else if (astroid->type == 4) {
		gotoxy(astroid->pos_x,astroid->pos_y);
		fgcolor(12);
		printf("%c        ", block);
		gotoxy(astroid->pos_x+8,astroid->pos_y);
		fgcolor(4);
		printf("%c  ", block);

		gotoxy(astroid->pos_x,astroid->pos_y+1);
		fgcolor(12);
		printf("%c%c        ", block,block);
		gotoxy(astroid->pos_x+7,astroid->pos_y+1);
		fgcolor(4);
		printf("%c%c  ", block,block);

		gotoxy(astroid->pos_x,astroid->pos_y+2);
		fgcolor(12);
		printf("%c%c       ", block,block);
		gotoxy(astroid->pos_x+7,astroid->pos_y+2);
		fgcolor(4);
		printf("%c", block);
		fgcolor(12);
		printf("%c  ", block);

		gotoxy(astroid->pos_x,astroid->pos_y+3);
		fgcolor(4);
		printf("%c", block);
		fgcolor(12);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c%c%c", block,block,block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(12);
		printf("%c", block);
		fgcolor(4);
		printf("%c  ", block);


		gotoxy(astroid->pos_x,astroid->pos_y+4);
		fgcolor(4);
		printf("%c", block);
		fgcolor(12);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c%c%c", block,block,block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(12);
		printf("%c%c  ", block,block);

		gotoxy(astroid->pos_x,astroid->pos_y+5);
		fgcolor(4);
		printf("%c%c       ", block,block);
		gotoxy(astroid->pos_x+7,astroid->pos_y+5);
		fgcolor(12);
		printf("%c%c  ", block,block);

		gotoxy(astroid->pos_x,astroid->pos_y+6);
		fgcolor(4);
		printf("%c%c       ", block,block);
		gotoxy(astroid->pos_x+7,astroid->pos_y+6);
		fgcolor(12);
		printf("%c%c  ", block,block);

		gotoxy(astroid->pos_x,astroid->pos_y+7);
		fgcolor(4);
		printf("%c        ", block);
		gotoxy(astroid->pos_x+8,astroid->pos_y+7);
		fgcolor(12);
		printf("%c  ", block);

		//resetter farven
		fgcolor(15);
	}
	else if (astroid->type == 5) {
		gotoxy(astroid->pos_x,astroid->pos_y);
		fgcolor(9);
		printf("%c        ", block);
		gotoxy(astroid->pos_x+8,astroid->pos_y);
		fgcolor(1);
		printf("%c  ", block);

		gotoxy(astroid->pos_x,astroid->pos_y+1);
		fgcolor(9);
		printf("%c%c       ", block,block);
		gotoxy(astroid->pos_x+7,astroid->pos_y+1);
		fgcolor(1);
		printf("%c%c  ", block,block);

		gotoxy(astroid->pos_x,astroid->pos_y+2);
		fgcolor(9);
		printf("%c%c       ", block,block);
		gotoxy(astroid->pos_x+7,astroid->pos_y+2);
		fgcolor(1);
		printf("%c", block);
		fgcolor(9);
		printf("%c  ", block);

		gotoxy(astroid->pos_x,astroid->pos_y+3);
		fgcolor(1);
		printf("%c", block);
		fgcolor(9);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c%c%c", block,block,block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(9);
		printf("%c", block);
		fgcolor(1);
		printf("%c  ", block);


		gotoxy(astroid->pos_x,astroid->pos_y+4);
		fgcolor(1);
		printf("%c", block);
		fgcolor(9);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c%c%c", block,block,block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(9);
		printf("%c%c  ", block,block);

		gotoxy(astroid->pos_x,astroid->pos_y+5);
		fgcolor(1);
		printf("%c%c       ", block,block);
		gotoxy(astroid->pos_x+7,astroid->pos_y+5);
		fgcolor(9);
		printf("%c%c  ", block,block);

		gotoxy(astroid->pos_x,astroid->pos_y+6);
		fgcolor(1);
		printf("%c%c       ", block,block);
		gotoxy(astroid->pos_x+7,astroid->pos_y+6);
		fgcolor(9);
		printf("%c%c  ", block,block);

		gotoxy(astroid->pos_x,astroid->pos_y+7);
		fgcolor(1);
		printf("%c        ", block);
		gotoxy(astroid->pos_x+8,astroid->pos_y+7);
		fgcolor(9);
		printf("%c  ", block);

		//resetter farven
		fgcolor(15);
	}
	else if (astroid->type == 6) {
		//printer linje 3
			gotoxy(astroid->pos_x, astroid->pos_y);
			printf("  ");
			fgcolor(1);
			printf("%c%c%c%c%c%c%c        ",block,block,block,block,block,block,block);

		//printer linje 4
			gotoxy(astroid->pos_x,astroid->pos_y+1);
			printf(" %c%c %c%c%c %c%c       ",block,block,block,block,block,block,block);

		//printer linje 5
			gotoxy(astroid->pos_x,astroid->pos_y+2);
			printf("%c%c%c%c%c%c%c%c%c%c%c      ",block,block,block,block,block,block,block,block,block,block,block);

		//printer linje 6
			gotoxy(astroid->pos_x,astroid->pos_y+3);
			printf("%c %c%c%c%c%c%c%c %c      ",block,block,block,block,block,block,block,block,block);

		//printer linje 7
			gotoxy(astroid->pos_x,astroid->pos_y+4);
			printf("%c %c     %c %c      ",block,block,block,block);

		//printer linje 8
			gotoxy(astroid->pos_x,astroid->pos_y+5);
			printf("   %c%c %c%c         ",block,block,block,block);

		//resetter farven
			fgcolor(15);
		}
}

void update_pos_asteroid(astroid_t *astroid){
	if (astroid->pos_x > 3){
	astroid->pos_x = astroid->pos_x + astroid->vel_x;
	}
	else{
		gotoxy(astroid->pos_x,astroid->pos_y);
		printf("              ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("              ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("              ");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf("              ");
		gotoxy(astroid->pos_x,astroid->pos_y+4);
		printf("              ");
		gotoxy(astroid->pos_x,astroid->pos_y+5);
		printf("              ");
		gotoxy(astroid->pos_x,astroid->pos_y+6);
		printf("              ");
		gotoxy(astroid->pos_x,astroid->pos_y+7);
		printf("              ");
		astroid->pos_x = 235;
		astroid->pos_y = (rand() % 54)+4;
	}
}

void update_difficulty(int timer, int *difficulty){
	if (timer > 30 && *difficulty == 0){
		*difficulty = 1;
	}
	else if (timer > 60 && *difficulty == 1){
		*difficulty = 2;
	}
	else if (timer > 90 && *difficulty == 2){
		*difficulty = 3;
	}
}
