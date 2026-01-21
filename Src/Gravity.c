#include "Gravity.h"
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "Stopwatch.h"
#include "structures.h"
/*
int clockvalue=5;

int tick=0;
int updated=0; // holder styr på hvilke objekter der allerede er opdateret i given clockperiode


void clock(){


	  if((g_time.hs%clockvalue)==0)
		tick=1;
	  	else{
			tick=0;
			updated=0; //resetter update så den kan opdatere igen i næste clockperiode
	}
}
*/




objects_t object[12]={{130,10,-1,0,1},
					{200,40,-1,0,2},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{0,0,0,0,0},
					{20,20,0,0,4}
};


void update_positions(){
	int i;
	for(i=0;i<12;i++){
		object[i].x += object[i].velx;
		object[i].y += object[i].vely;

		if (object[i].x < 2)
			removing(i);
	}
}

void removing(uint8_t p){  // this ensures that the object is removed once it hits the limit
	int r = rand();

		gotoxy(object[p].x,object[p].y);
		printf("  ");
		object[p].x=208;
		object[p].y= (r % 58)+1;
		object[p].type = r % 2+1;
	}

void print(){

	int i;
	for(i=0;i<12;i++){
		if(object[i].type==1){
			gotoxy(object[i].x,object[i].y);
			printf("o ");}
		else if(object[i].type==2){
			gotoxy(object[i].x,object[i].y);
			printf("x ");}
		else if(object[i].type==4){

			    gotoxy(object[i].x, object[i].y-1); printf(" ");
			    gotoxy(object[i].x, object[i].y  ); printf("=");
			    gotoxy(object[i].x, object[i].y+1); printf(" ");
			}

	}

}
/*
void run_functions(){
	if((tick==1)&&(updated==0)){
	player();
	update_positions();
	print();
	updated=1;
	}
}
*/

/*
void player(){

{
			uint16_t up     = GPIOA->IDR  & (0x0001 << 4);
			uint16_t down   = GPIOB->IDR  & (0x0001 << 0);
			uint16_t center = GPIOB->IDR  & (0x0001 << 5);

			object[11].vely = 0;

			if((down!=0)&&(object[11].y<65))
				object[11].vely = 1;


			else if((up!=0)&&(object[11].y>1))
				object[11].vely = -1;






}}


*/





















