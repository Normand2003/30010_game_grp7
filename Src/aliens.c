#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "aliens.h"
#include "stopwatch.h"



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

/* Følgende er brugt i main.c

     alien_t alien1;
    alien1.pos_x = 50;
    alien1.pos_y = 20;
    alien1.health = 1;



   // start_screen();


//    while (1) {
//    	draw_alien(&alien1);
//    	alien_dying(&alien1);
 //   }


 */



