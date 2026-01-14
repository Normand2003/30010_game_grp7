#include "joystick.h"
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
void underline(uint8_t on);

void shoot(uint8_t x, uint8_t y){
	int t=0;
	int i;
	int shot1[3]={0,0,0}; // [0] i whether or not the shot has been fired
	//[1] is its x-coordinate [2] is y-coordinate

        if(shot1[0]==0){ // this code activates when the center button is pushed and the projectile is fired
        	gotoxy(y+4,x+19);
        	shot1[0]=1;
        	shot1[1]=x+19;
        	shot1[2]=y+4;
        	printf("o");
        }
    	for(i=0;i<101;i++){ // this code updates the position of the projectile
		   	if(t==0) // this code is to change the trajectiory of the bullet when entering the gravitational field of a meteorite
    		 	if(shot1[2]==34)
    		   		if(shot1[1]>152)
    		   			t=1;
		   	if(t==0)
    		   	if(shot1[2]==39)
    		   		if(shot1[1]>154)
    		   			t=-1;

    			if(shot1[0]==1){
    			gotoxy(shot1[2]+t,shot1[1]+2);
    			printf("o");
    			gotoxy(shot1[2],shot1[1]);
    			printf(" ");
    			shot1[1]=shot1[1]+2;
    			shot1[2]=shot1[2]+t;
    			if(shot1[1]>210)
    				i=100;// this ensures that the bullet does'nt reappear
    		}
        }
	}

void Cockpit(){ //this function takes inputs from the controller

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

void Planemove(uint8_t x, uint8_t y){
	int i;


	for(i=0;i<10000;i++){
        // this is information from the function Cockpit wich takes inputs from the joystick
		uint16_t right  = GPIOC->IDR & (0x0001 << 0);
		uint16_t up     = GPIOA->IDR  & (0x0001 << 4);
		uint16_t left   = GPIOC->IDR  & (0x0001 << 1);
		uint16_t down   = GPIOB->IDR  & (0x0001 << 0);

		uint16_t center = GPIOB->IDR  & (0x0001 << 5);

		// this changes the current placement of the jet depending on what direction the user moves it

		if(down!=0)
			if(y<57)
				y += 1;
		if(up!=0)
			if(y>0)
				y = y-1;
		if(left!=0)
			if(x>4)
				x = x-2;
		if(right!=0)
			if(x<193)
				x += 2;





        // this is the design for the body of the spaceship/plane
		gotoxy(y,x);
		printf("           ");
		gotoxy(y+1,x);
		printf("      |\\      ");
		gotoxy(y+2,x);
		printf("      | \\__    "); //left wing
		gotoxy(y+3,x-4);
		printf("        |\\| |  \\         ");
		gotoxy(y+4,x-4);
		printf("        |-<\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0>  "); // body
		gotoxy(y+5,x-4);
		printf("        |/| |__/           ");
		gotoxy(y+6,x);
		printf("      | /      "); // right wing
		gotoxy(y+7,x);
		printf("      |/       ");
		gotoxy(y+8,x);
		printf("          ");

		if(center!=0)
			shoot(x,y);

	}
}

void positions(){

int positionsarray[20][5];}

//These functions draw the different objects but dont contain code describing their movement etc.

void meteorite(uint8_t mx, uint8_t my){

	gotoxy(my,mx); // this prints the meteorite
	printf(" ____");
	gotoxy(my+1,mx);
	printf("/   \xA7\\");
	gotoxy(my+2,mx);
	printf("\\\xF8   \xA7\\");
	gotoxy(my+3,mx);
	printf(" \\____/");



}

void meteorite1(uint8_t mx, uint8_t my){

	gotoxy(my,mx); //this prints the meteorite
	printf(" __");
	gotoxy(my+1,mx);
	printf("/\xF8 \\");
	gotoxy(my+2,mx);
	printf("\\__/");
}

void meteorite2(uint8_t mx, uint8_t my){

	gotoxy(my,mx); // this prints the meteorite
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

void satelite(uint8_t mx, uint8_t my){

	gotoxy(my-1,mx);
	printf("       __");
	gotoxy(my,mx);
	printf("      ///");
	underline(1);
	gotoxy(my+1,mx+5);
	printf("//");
	underline(0);
	gotoxy(my+1,mx+7);
	printf("/");
	gotoxy(my+2,mx);
	printf("     /");
	gotoxy(my+3,mx);
	printf("   (O)");
	underline(1);
	gotoxy(my+4,mx+2);
	printf(" /");
	underline(0);
	gotoxy(my+5,mx);
	printf(" ///");
	underline(1);
	gotoxy(my+6,mx);
	printf("//");
	underline(0);
	gotoxy(my+6,mx+2);
	printf("/");


}

void satelite1(uint8_t mx, uint8_t my){

	gotoxy(my-1,mx);
	printf("__");
	gotoxy(my,mx);
	printf("\\\\\\");
	underline(1);
	gotoxy(my+1,mx+2);
	printf("\\\\");
	underline(0);

	gotoxy(my+1,mx+1);
	printf("\\");
	gotoxy(my+2,mx);
	printf("   \\");
	gotoxy(my+3,mx+3);
	printf("(O)");
	underline(1);
	gotoxy(my+4,mx+5);
	printf("\\ ");
	underline(0);
	gotoxy(my+5,mx+2);
	printf("   \\\\\\");
	underline(1);
	gotoxy(my+6,mx+7);
	printf("\\\\");
	underline(0);
	gotoxy(my+6,mx+6);
	printf("\\");


}

void spaceship(uint8_t mx, uint8_t my){
	gotoxy(my,mx);
	printf("           ");
	gotoxy(my+1,mx);
	printf("      |\\      ");
	gotoxy(my+2,mx);
	printf("      | \\__    "); //left wing
	gotoxy(my+3,mx-4);
	printf("        |\\| |  \\         ");
	gotoxy(my+4,mx-4);
	printf("        |-<\xB0\xB0\xB0\xB0\xB0\xB0\xB0\xB0>  "); // body
	gotoxy(my+5,mx-4);
	printf("        |/| |__/           ");
	gotoxy(my+6,mx);
	printf("      | /      "); // right wing
	gotoxy(my+7,mx);
	printf("      |/       ");
	gotoxy(my+8,mx);
	printf("          ");

}

void enemy(uint8_t mx, uint8_t my){
	gotoxy(my,mx+3);
	printf("/|");
	gotoxy(my+1,mx);
	printf("<\xB0\xB0\xB0<");
	gotoxy(my+2,mx+3);
	printf("\\|");
}

void shot(uint8_t mx, uint8_t my){
	gotoxy(my,mx);
	printf("o");
}
