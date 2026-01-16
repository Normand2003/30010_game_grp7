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
#include "stopwatch.h"

void print_astroid(astroid_t *astroid){

if (astroid->pos_x > 150){
	gotoxy(astroid->pos_x,astroid->pos_y);

	if (astroid->type == 1) {
		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the astroid type 1 (small)
		printf(" __");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("/\xF8 \\");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("\\__/");
	}

	if (astroid->type == 2) {
		gotoxy(astroid->pos_x,astroid->pos_y); // this prints the astroid type 2 (medium)
		printf(" ____");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("/   \xA7\\");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("\\\xF8   \xA7\\");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf(" \\____/");
	}

	if (astroid->type == 3) {
		gotoxy(astroid->pos_x,astroid->pos_y); // this prints the astroid type 3 (large)
		printf("    ______");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("   /   \xF8  \\");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("  /\xA7      /");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf(" /     \xF8 /");
		gotoxy(astroid->pos_x,astroid->pos_y+4);
		printf(" \\_______)");
		underline(1);
		gotoxy(astroid->pos_x+3,astroid->pos_y+4);
		printf("\xA7");
		underline(0);
	}
}
}

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

void hit_astroid(astroid_t *astroid,bullet_t *bullet) {
	if (astroid->type == 3){
	if ((bullet->pos_x-1 >= astroid->pos_x && bullet->pos_y >= astroid->pos_y) && (bullet->pos_x+2 <= astroid->pos_x+10 && bullet->pos_y <= astroid->pos_y+4)){

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
		//moves the astroids postion waaaaayyyyy off-screen
		astroid->pos_x += 100;

		//destroys the bullet
		bullet->vel_x = 0;

	}
	}

	if (astroid->type == 2){
	if ((bullet->pos_x-1 >= astroid->pos_x && bullet->pos_y >= astroid->pos_y) && (bullet->pos_x+2 <= astroid->pos_x+6 && bullet->pos_y <= astroid->pos_y+3)){

		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 2 (medium)
		printf("       ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("       ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("       ");
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		printf("       ");
		//moves the astroids postion waaaaayyyyy off-screen
		astroid->pos_x += 100;

		//destroys the bullet
		bullet->vel_x = 0;
	}
	}

	if (astroid->type == 1){
	if ((bullet->pos_x-1 >= astroid->pos_x && bullet->pos_y >= astroid->pos_y) && (bullet->pos_x+2 <= astroid->pos_x+5 && bullet->pos_y <= astroid->pos_y+2)){

		gotoxy(astroid->pos_x,astroid->pos_y); //this prints the removal astroid type 1 (small)
		printf("    ");
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		printf("    ");
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		printf("    ");
		//moves the astroids postion waaaaayyyyy off-screen
		astroid->pos_x += 100;

		//destroys the bullet
		bullet->vel_x = 0;
	}
	}
}
//Lorte funktion, brug ikke.
void update_stroid(astroid_t *astroid){
	if ((astroid->pos_x > astroid->vel_x) || (astroid->pos_x > 1)){
		astroid->pos_x += astroid->vel_x;
		deprint_astroid(astroid);
		print_astroid(astroid);
	}
	else {
		astroid->pos_x += 200;
	}
}

