#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "aliens.h"
#include "stopwatch.h"
#include "structures.h"
#include "draw.h"
#define ESC 0x1B
#define block 0xDB



void draw_alien(alien_t *alien) {
	//printer linje 1

	int i = 1;
	static int start = 0;

	if (alien->health == 1) {
		//printer linje 3
		enable_alien(alien);
		start = 1;
	}


		// sletter alienen hvis den dør
		if (alien->health == 0) {
			if (start == 1) {
			delete_alien(alien);
			start = 0;
			}
		}





}

void alien_dying(alien_t *alien) {

	int bullet_pos_x = 3;
	int bullet_pos_y = 3;

	int death = 0; // ret til 0 for at trigger death animation
	int tid = 0;
	int start = 0;



	if ((bullet_pos_x >= alien->pos_x) && (bullet_pos_x <= alien->pos_x+5) && (bullet_pos_y >= alien->pos_y) && (bullet_pos_y <= alien->pos_y+10)) {
		death = 1;
	}

	if (death == 1){

		if (start == 0) {
			int tid = g_time.s;

		}
			if (g_time.s == tid + 1) {
				alien->health = 0;
				start = 1;
				}
			if ((g_time.s - tid < 1)) {
				enable_alien(alien);
				delete_alien(alien);
			}
	}
}

void delete_alien(alien_t *alien) {

		gotoxy(alien->pos_x, alien->pos_y);
		bgcolor(0);
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		gotoxy(alien->pos_x, alien->pos_y+1);
		bgcolor(0);
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		gotoxy(alien->pos_x, alien->pos_y+2);
		bgcolor(0);
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		gotoxy(alien->pos_x, alien->pos_y+3);
		bgcolor(0);
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		gotoxy(alien->pos_x, alien->pos_y+4);
		bgcolor(0);
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		gotoxy(alien->pos_x, alien->pos_y+5);
		bgcolor(0);
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		printf(" ");
		bgcolor(0);
}

void enable_alien(alien_t *alien) {
	int i = 1;
	//printer linje 3
	gotoxy(alien->pos_x, alien->pos_y);
	bgcolor(0);
	printf(" ");
	printf(" ");
	bgcolor(i);
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	bgcolor(0);
	printf(" ");
	printf(" ");

	//printer linje 4
	gotoxy(alien->pos_x,alien->pos_y+1);
	bgcolor(0);
	printf(" ");
	bgcolor(i);
	printf(" ");
	printf(" ");
	bgcolor(0);
	printf(" ");
	bgcolor(i);
	printf(" ");
	printf(" ");
	printf(" ");
	bgcolor(0);
	printf(" ");
	bgcolor(i);
	printf(" ");
	printf(" ");
	bgcolor(0);
	printf(" ");

	//printer linje 5
	gotoxy(alien->pos_x,alien->pos_y+2);
	bgcolor(i);
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");

	//printer linje 6
	gotoxy(alien->pos_x,alien->pos_y+3);
	bgcolor(i);
	printf(" ");
	bgcolor(0);
	printf(" ");
	bgcolor(i);
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	bgcolor(0);
	printf(" ");
	bgcolor(i);
	printf(" ");

	//printer linje 7
	gotoxy(alien->pos_x,alien->pos_y+4);
	bgcolor(i);
	printf(" ");
	bgcolor(0);
	printf(" ");
	bgcolor(i);
	printf(" ");
	bgcolor(0);
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	printf(" ");
	bgcolor(i);
	printf(" ");
	bgcolor(0);
	printf(" ");
	bgcolor(i);
	printf(" ");

	//printer linje 8
	gotoxy(alien->pos_x,alien->pos_y+5);
	bgcolor(0);
	printf(" ");
	printf(" ");
	printf(" ");
	bgcolor(i);
	printf(" ");
	printf(" ");
	bgcolor(0);
	printf(" ");
	bgcolor(i);
	printf(" ");
	printf(" ");
	bgcolor(0);
	printf(" ");
	printf(" ");
	printf(" ");
	bgcolor(0);
}


void draw_spaceship1(spaceship_t *ship) {


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
	printf("%c", block);

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
	printf("%c", block);

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
	printf("%c", block);

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
	printf("%c", block);

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
	printf("%c", block);

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
	printf("%c", block);

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
	printf("%c", block);

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
	printf("%c", block);

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
	printf("%c", block);

fgcolor(15);

}

void undraw_spaceship1(spaceship_t *ship){
	gotoxy(ship->pos_x, ship->pos_y);
	printf("       ");

	gotoxy(ship->pos_x, ship->pos_y+1);
	printf("        ");

	gotoxy(ship->pos_x, ship->pos_y+2);
	fgcolor(0);
	printf("         ");

	//første række med ild
	gotoxy(ship->pos_x, ship->pos_y+3);
	printf("          ");

	//anden række med ild
	gotoxy(ship->pos_x, ship->pos_y+4);
	printf("          ");

	//tredje række med ild
	gotoxy(ship->pos_x, ship->pos_y+5);
	printf("          ");

	gotoxy(ship->pos_x, ship->pos_y+6);
	printf("         ");

	gotoxy(ship->pos_x, ship->pos_y+7);
	printf("        ");

	gotoxy(ship->pos_x, ship->pos_y+8);
	printf("       ");

}

void draw_spaceship2(int x, int y) {
	gotoxy(x, y);
	fgcolor(0);
	printf("%c", block);
	printf("%c", block);
	fgcolor(8);
	printf("%c", block);
	printf("%c", block);
	printf("%c", block);
	fgcolor(7);
	printf("%c", block);
	printf("%c", block);

	gotoxy(x, y+1);
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
	printf("%c", block);

	gotoxy(x, y+2);
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
	printf("%c", block);

	//første  række med ild
	gotoxy(x, y+3);
	fgcolor(1);
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
	printf("%c", block);

	//anden  række med ild
	gotoxy(x, y+4);
	fgcolor(0);
	printf("%c", block);
	fgcolor(9);
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
	printf("%c", block);

	gotoxy(x, y+5);
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
	printf("%c", block);

	gotoxy(x, y+6);
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
	printf("%c", block);

	gotoxy(x, y+7);
	fgcolor(0);
	printf("%c", block);
	printf("%c", block);
	fgcolor(8);
	printf("%c", block);
	printf("%c", block);
	printf("%c", block);
	fgcolor(7);
	printf("%c", block);
	printf("%c", block);
}





void draw_asteroid(astroid_t *astroid) {

	// 1 = lille, 2 = mellem, 3 = stor, 4 = satellite


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
		printf("%c", block);

		//Anden linje
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		fgcolor(8);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);


		//Tredje linje
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		fgcolor(8);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);

		//resetter farven
		fgcolor(15);

	}


	// mellem
	else if  (astroid->type == 2) {
		//Første linje
		gotoxy(astroid->pos_x,astroid->pos_y);
		fgcolor(8);
		printf("%c", block);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);
		printf("%c", block);
		fgcolor(15);
		printf("%c", block);

		//Anden linje
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		fgcolor(8);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);

		//Tredje linje
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);


		//Fjerde linje
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		fgcolor(0);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		printf("%c", block);


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
		printf("%c", block);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);

		//Anden linje
		gotoxy(astroid->pos_x,astroid->pos_y+1);
		fgcolor(7);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		fgcolor(15);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);


		//Tredje linje
		gotoxy(astroid->pos_x,astroid->pos_y+2);
		fgcolor(8);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);

		//Fjerde linje
		gotoxy(astroid->pos_x,astroid->pos_y+3);
		fgcolor(8);
		printf("%c", block);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);

		//Femte linje
		gotoxy(astroid->pos_x+1,astroid->pos_y+4);
		fgcolor(8);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);


		//resetter farven
		fgcolor(15);

	}


	else if (astroid->type == 4) {
		gotoxy(astroid->pos_x,astroid->pos_y);
		fgcolor(12);
		printf("%c", block);
		gotoxy(astroid->pos_x+8,astroid->pos_y);
		fgcolor(4);
		printf("%c", block);

		gotoxy(astroid->pos_x,astroid->pos_y+1);
		fgcolor(12);
		printf("%c", block);
		printf("%c", block);
		gotoxy(astroid->pos_x+7,astroid->pos_y+1);
		fgcolor(4);
		printf("%c", block);
		printf("%c", block);

		gotoxy(astroid->pos_x,astroid->pos_y+2);
		fgcolor(12);
		printf("%c", block);
		printf("%c", block);
		gotoxy(astroid->pos_x+7,astroid->pos_y+2);
		fgcolor(4);
		printf("%c", block);
		fgcolor(12);
		printf("%c", block);

		gotoxy(astroid->pos_x,astroid->pos_y+3);
		fgcolor(4);
		printf("%c", block);
		fgcolor(12);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(12);
		printf("%c", block);
		fgcolor(4);
		printf("%c", block);


		gotoxy(astroid->pos_x,astroid->pos_y+4);
		fgcolor(4);
		printf("%c", block);
		fgcolor(12);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(8);
		printf("%c", block);
		printf("%c", block);
		printf("%c", block);
		fgcolor(7);
		printf("%c", block);
		fgcolor(12);
		printf("%c", block);
		printf("%c", block);

		gotoxy(astroid->pos_x,astroid->pos_y+5);
		fgcolor(4);
		printf("%c", block);
		printf("%c", block);
		gotoxy(astroid->pos_x+7,astroid->pos_y+5);
		fgcolor(12);
		printf("%c", block);
		printf("%c", block);

		gotoxy(astroid->pos_x,astroid->pos_y+6);
		fgcolor(4);
		printf("%c", block);
		printf("%c", block);
		gotoxy(astroid->pos_x+7,astroid->pos_y+6);
		fgcolor(12);
		printf("%c", block);
		printf("%c", block);

		gotoxy(astroid->pos_x,astroid->pos_y+7);
		fgcolor(4);
		printf("%c", block);
		gotoxy(astroid->pos_x+8,astroid->pos_y+7);
		fgcolor(12);
		printf("%c", block);

		//resetter farven
		fgcolor(15);
	}


}

