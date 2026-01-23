#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "draw.h"
#include "joystick.h"
#include "structures.h"
#include "spaceship.h"
#include "stopwatch.h"
#include "aliens.h"
#include "gui_hud.h"
#include "lcd.h"
#include <string.h>

//game screen is 235 x 65 pixels

int main(void){



uart_init( 115200 ); // Initialize USB serial emulation at 115200 baud
//uart_init( 230400 ); // Initialize USB serial emulation at 230400 baud

clrscr();
init_joystick();
bgcolor(0);
fgcolor(15);
//enables timer and timer structure
initTimer();
g_running = 1;
gtimer_t global_timer;


//enables lcd
lcd_init();
lcd_reset();

//resets lcd
memset(lcd_buffer,0x00,512);
//enables LED
init_led();

//creates "level select" variable and bosskey
int lvl_select = 0;
int bosskey = 0;

//keeps game running & functions as a "main outside loop"
while(1){
	int time_since_start = 0;
	int difficulty = 0;

if(lvl_select == 0){
	start_screen();
}

while(lvl_select == 0){
	clock(&global_timer);
	if((global_timer.tick==1)&&(global_timer.updated==0)){

		lvl_select = start_select(detect_joystick(), keyboard2());
	global_timer.updated=1;
		}
	}

//
//Keeps help screen running
if(lvl_select == 10){
	help_screen();
}

while(lvl_select == 10){
	if(detect_joystick() == 5 || keyboard2() == 32){
		lvl_select = 0;
		}
	}




//creates and enables the spaceship
spaceship_t my_ship;
my_ship.pos_x = 20;
my_ship.pos_y = 32;
my_ship.powerup = 0; //0 standard, 1 laser, 2 spread
my_ship.laser_shot = 3;
my_ship.spread_shot = 3;
my_ship.health = 3;
my_ship.score = 0;

//creates strings on lcd
char health_string[25] = "Health: ";
char health[2] = "";

char score_string[10] = "Score: ";
char score[6] = "";

char laser_string[20] = "Laser Ammo: ";
char laserammo[6] = "";

char spread_string[20] = "Spread Ammo: ";
char spreadammo[6] = "";

//clears and fixes lcd screen
memset(lcd_buffer,0x00,512);
lcd_write_string(0,1,health_string);
lcd_write_string(1,1,score_string);
lcd_write_string(2,1,laser_string);
lcd_write_string(3,1,spread_string);

//creates array of astroids:
astroid_t all_stroids[8]={
		{70,10,-1,0,1},
		{85,30,-1,0,2},
		{100,40,-2,0,3},
		{115,8,-1,0,4},
		{130,50,-1,0,5},
		{145,20,-1,0,2},
		{160,5,-3,0,6},
		{175,50,-2,0,1},
};
//creates array of bullets
bullet_t all_bullets[5]={
		{0,0,0,15,0},
		{0,0,0,10,0},
		{0,0,0,5,0},
		{0,0,0,-3,0},
		{0,0,0,-31,0},
};
//creates array of spread bullets
bullet_t spread_bullets[3]={
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
};

//Ship Laser
laser_t ship_laser;
ship_laser.pos_x = 0;
ship_laser.pos_y = 0;

if (lvl_select == 1){
clrscr();
}

int key;
//main gameplay loop
while(lvl_select == 1){

	clock(&global_timer);
	if((global_timer.tick==1)&&(global_timer.updated==0)){

	//makes keyboard work
	key = keyboard2();

	//updates astroid positions and draws
	for (int i = 0; i < 8; ++i){
		update_pos_asteroid(&all_stroids[i]);
		draw_asteroid(&all_stroids[i]);
	}
	//updates spaceship position and draws
	update_pos(&my_ship,detect_joystick(),key);
	draw_spaceship1(&my_ship);
	//tracks if spaceship is hit
	for (int i = 0; i < 8; ++i){
	spaceship_hit(&all_stroids[i],&my_ship);
	}
	//shoot function and detect if asteroid is hit function
	shoot(&my_ship,detect_joystick(),key,&all_bullets[0],&all_bullets[1],&all_bullets[2],&all_bullets[3],&all_bullets[4]);
	for (int k = 0; k < 5; ++k){
		for (int j = 0; j < 8; ++j){
		hit_astroid(&all_stroids[j],&all_bullets[k],&my_ship);
	}
	}
	//laser system
	laser(&my_ship,detect_joystick(),key,&ship_laser);
	for (int l = 0; l < 8; ++l){
		laser_hit(&all_stroids[l],&ship_laser,&my_ship);
	}
	//spread shot
	spread_shot(&my_ship,detect_joystick(),key,&spread_bullets[0],&spread_bullets[1],&spread_bullets[2]);
	for (int f = 0; f < 3; ++f){
		for (int g = 0; g < 8; ++g){
		hit_astroid(&all_stroids[g],&spread_bullets[f],&my_ship);
		}
	}

	//forces gravity on bullets by asteroids
	//lorentzforce(&all_bullets, &all_stroids);

	//health system - displays current health, ammo and time - and goes to main menu if health = 0
	gotoxy(1,1);
	fgcolor(15);
	printf("Ship Health: %d",my_ship.health);
	printf("\nLaser Shot: %d",my_ship.laser_shot);
	printf("\nSpread Shot: %d",my_ship.spread_shot);
	printf("\nTime: %d",(time_since_start++)>>2);
	printf("\nDifficulty Level: %d",difficulty+1);

	number_to_string(my_ship.health, health,2);
	lcd_write_string(0,40,health);
	if(my_ship.health == 0){
		lvl_select = 0;
	}
	//rgb lives
	lives_RGB(&my_ship);

	//score on lcd
	number_to_string(my_ship.score, score ,6);
	lcd_write_string(1,35,score);

	//ammunition on lcd
	number_to_string(my_ship.laser_shot,laserammo,6);
	lcd_write_string(2,60,laserammo);
	number_to_string(my_ship.spread_shot,spreadammo,6);
	lcd_write_string(3,65,spreadammo);

	//boss key
	if (key == 120){
		clrscr();
		bosskey = 1;
		bosskey_gfx();
		while (bosskey == 1){
			clock(&global_timer);
			key = keyboard2();
			if (key == 120){
				bosskey = 0;
			}
			global_timer.updated=1;
		}
		clrscr();
	}
	//updates difficulty for the game, and increases speed of astroid each time it increases
		update_difficulty((time_since_start)>>2,&difficulty);
		if (difficulty == 1){
			all_stroids[0].vel_x = -2;
			all_stroids[1].vel_x = -2;
			all_stroids[2].vel_x = -3;
			all_stroids[3].vel_x = -1;
			all_stroids[4].vel_x = -1;
			all_stroids[5].vel_x = -2;
			all_stroids[6].vel_x = -4;
			all_stroids[7].vel_x = -3;
		}
		if (difficulty == 2){
			all_stroids[0].vel_x = -3;
			all_stroids[1].vel_x = -3;
			all_stroids[2].vel_x = -4;
			all_stroids[3].vel_x = -1;
			all_stroids[4].vel_x = -1;
			all_stroids[5].vel_x = -3;
			all_stroids[6].vel_x = -5;
			all_stroids[7].vel_x = -4;
		}
		if (difficulty == 3){
			all_stroids[0].vel_x = -3;
			all_stroids[1].vel_x = -3;
			all_stroids[2].vel_x = -4;
			all_stroids[3].vel_x = -1;
			all_stroids[4].vel_x = -1;
			all_stroids[5].vel_x = -3;
			all_stroids[6].vel_x = -5;
			all_stroids[7].vel_x = -4;
		}



	global_timer.updated=1;
	}
}
}
}
