
#include "mid.h"
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "Stopwatch.h"



void pins(){
	//klokken for GPIO(A,B og C)
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA;
	RCC->AHBENR |= RCC_AHBPeriph_GPIOB;
	RCC->AHBENR |= RCC_AHBPeriph_GPIOC;

	// PC0 -> right
	// PA4 -> up
	// PB5 -> center
	// PC1 -> left
	// PB0 -> down

	//PC0:

	GPIOC->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
	GPIOC->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 –
	GPIOC->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
	GPIOC->PUPDR |= (0x00000002 << (0 * 2)); // Set push/pull register (0x00 -

	// PA4:

	GPIOA->MODER &= ~(0x00000003 << (4 * 2));
	GPIOA->MODER |= (0x00000000 << (4 * 2));
	GPIOA->PUPDR &= ~(0x00000003 << (4 * 2));
	GPIOA->PUPDR |= (0x00000002 << (4 * 2));

	// PB5

	GPIOB->MODER &= ~(0x00000003 << (5 * 2));
	GPIOB->MODER |= (0x00000000 << (5 * 2));
	GPIOB->PUPDR &= ~(0x00000003 << (5 * 2));
	GPIOB->PUPDR |= (0x00000002 << (5 * 2));

	// PC1:

	GPIOC->MODER &= ~(0x00000003 << (1 * 2));
	GPIOC->MODER |= (0x00000000 << (1 * 2));
	GPIOC->PUPDR &= ~(0x00000003 << (1 * 2));
	GPIOC->PUPDR |= (0x00000002 << (1 * 2));

	// PB0:

	GPIOB->MODER &= ~(0x00000003 << (0 * 2));
	GPIOB->MODER |= (0x00000000 << (0 * 2));
	GPIOB->PUPDR &= ~(0x00000003 << (0 * 2));
	GPIOB->PUPDR |= (0x00000002 << (0 * 2));
}

object_t thing[7] ={{40,20,0,0,3},
					{72,18,0,0,3},
					{82,18,0,0,3},
					{114,16,0,0,3},
					{145,1,0,0,2},
					{10,35,0,0,0},
					{0,0,0,0,0}
};




int x_updated_this_hs[8]={0,0,0,0,0,0,0,0}; // this global says whether or not an objects position has already been updated in given clockperiod

int spou=10; //spou = speed of update. this decides how fast the clock period is to 60/spou per second

int gravitational_pull=0;



void lorentz(){
	int i;
	for(i=0;i<6;i++){
	if(((((thing[6].y>>5)>(thing[i].y+4))&&((thing[6].y>>5)<(thing[i].y+9)))&&((thing[6].x>thing[i].x-2)&&(thing[6].x<thing[i].x+7)))&&x_updated_this_hs[7]==0){
		thing[6].vely--;
		x_updated_this_hs[7]=-1;}
	if(((((thing[6].y>>5)<(thing[i].y))&&((thing[6].y>>5)>(thing[i].y-5)))&&((thing[6].x>thing[i].x-2)&&(thing[6].x<thing[i].x+7)))&&(x_updated_this_hs[7]==0)){
			thing[6].vely++;
			x_updated_this_hs[7]=1;}
}}


void state_reset(){
	int i;
		for(i=0;i<8;i++){
		x_updated_this_hs[i]=0;}}


void destroy(){  // this ensures that the object is removed once it hits the limit
int i;
for(i=0;i<5;i++){
	if(thing[i].type==67){
		thing[i].type=69;
		thing[i].y -= 1;
		gotoxy(thing[i].x,thing[i].y);
		printf("            ");
		gotoxy(thing[i].x,thing[i].y+1);
		printf("            ");
		gotoxy(thing[i].x,thing[i].y+2);
		printf("            ");
		gotoxy(thing[i].x,thing[i].y+3);
		printf("            ");
		gotoxy(thing[i].x,thing[i].y+4);
		printf("           ");
		gotoxy(thing[i].x,thing[i].y+5);
		printf("           ");
		gotoxy(thing[i].x,thing[i].y+6);
		printf("           ");
		gotoxy(thing[i].x,thing[i].y+7);
		printf("           ");}
	if(thing[i].type==69){
		int r = rand();
		thing[i].x=208;
		thing[i].y= (r % 58)+1;
		thing[i].type = r % 3+1;
	}

}}

void update_position(void){ // updates given things position
	int i;
	for(i=0;i<7;i++){
		if(thing[i].type !=0){
    	if (g_time.hs % spou < spou-3) {
        if (x_updated_this_hs[i] == 0) {
        	x_updated_this_hs[i] = 1;
            if (thing[i].x > 0) {
                thing[i].x += thing[i].velx;
            	thing[i].y += thing[i].vely;}
			if (thing[i].x < 1) {
				thing[i].type=67;
			}}}}}}




void printer(){ // prints the given object
int i;

for(i=0;i<7;i++){

	if((g_time.hs%spou)  < spou-6){


		if(thing[i].type==1){
			underline(0);
			gotoxy(thing[i].x,thing[i].y); //this prints the meteorite
			printf(" __   ");
			gotoxy(thing[i].x,thing[i].y+1);
			printf("/\xF8 \\  ");
			gotoxy(thing[i].x,thing[i].y+2);
			printf("\\__/   ");
		}

		if(thing[i].type==2){
			gotoxy(thing[i].x+1,thing[i].y); // this prints the meteorite
			printf("____   ");
			gotoxy(thing[i].x,thing[i].y+1);
			printf("/   \xA7\\   ");
			gotoxy(thing[i].x,thing[i].y+2);
			printf("\\\xF8   \xA7\\   ");
			gotoxy(thing[i].x,thing[i].y+3);
			printf(" \\____/   ");



		}

		}

		if(thing[i].type==3){

			gotoxy(thing[i].x+3,thing[i].y); // this prints the meteorite
			printf("______   ");
			gotoxy(thing[i].x+2,thing[i].y+1);
			printf("/   \xF8  \\   ");
			gotoxy(thing[i].x+1,thing[i].y+2);
			printf("/\xA7      /   ");
			gotoxy(thing[i].x,thing[i].y+3);
			printf("/     \xF8 /   ");
			gotoxy(thing[i].x,thing[i].y+4);
			printf("\\_______)   ");
			underline(1);
			gotoxy(thing[i].x+3,thing[i].y+4);
			printf("\xA7");
			underline(0);
		}

		if(thing[i].type==4){

					gotoxy(thing[i].x,(thing[i].y >> 5));
					printf("o");

		}}}








void ship(){
	if (g_time.hs % spou < spou-3)
	        if (x_updated_this_hs[5] == 0) {
	        	x_updated_this_hs[5] = 1;
{
			uint16_t up     = GPIOA->IDR  & (0x0001 << 4);
			uint16_t down   = GPIOB->IDR  & (0x0001 << 0);
			uint16_t center = GPIOB->IDR  & (0x0001 << 5);

			// this changes the current placement of the jet depending on what direction the user moves it
			thing[5].velx=thing[5].x;
			thing[5].vely=thing[5].y;

			if(down!=0)
				if(thing[5].y<65){
					thing[5].y += 1;
					gotoxy(thing[5].velx,thing[5].vely);
					printf(" ");}
			if(up!=0)
				if(thing[5].y>0){
					thing[5].y -=1;
					gotoxy(thing[5].velx,thing[5].vely);
					printf(" ");}


			gotoxy(thing[5].x,thing[5].y);
			printf("=");

			if(center!=0){
				thing[6].x=thing[5].x+1;
				thing[6].y=thing[5].y<<5;
				thing[6].velx=1;
				thing[6].type=4;
				thing[6].vely=0;}


}}}

























