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
		gotoxy(my,mx); // this prints the astroid type 3 (large)
		printf("    ______");
		gotoxy(my+1,mx);
		printf("   /   \xF8  \\");
		gotoxy(my+2,mx);
		printf("  /\xA7      /");
		gotoxy(my+3,mx);
		printf(" /     \xF8 /");
		gotoxy(my+4,mx);
		printf(" \\_______)");
		underline(1);
		gotoxy(my+4,mx+3);
		printf("\xA7");
		underline(0);
	}
}

//void hit_astroid(astroid_t *astroid,spaceship_t *ship) {
//	if ((ship->pos_x >= astroid->pos_x && )&&(2)) {
//		printf("lort")
//	}
//}

