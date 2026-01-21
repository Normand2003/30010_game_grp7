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

//creates "level select" variable
int lvl_select = 0;

//keeps start screen running
while(1){

if(lvl_select == 0){
	start_screen();
}

while(lvl_select == 0){
	while (timer(10) == 1){
		lvl_select = start_select(detect_joystick(), keyboard2());
		}
	}

//
//Keeps help screen running
if(lvl_select == 2){
	help_screen();
}

while(lvl_select == 2){
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
my_ship.health = 3;
my_ship.score = 100;

//creates strings on lcd
char health_string[25] = "Health: ";
char health[2] = "";

char score_string[10] = "Score: ";
char score[6] = "";
//clears and fixes lcd screen
memset(lcd_buffer,0x00,512);
lcd_write_string(0,1,health_string);
lcd_write_string(1,1,score_string);


//creates and enables the astroids
//big astroid
astroid_t small_stroid;
small_stroid.pos_x = 130;
small_stroid.pos_y = 20;
small_stroid.type = 1;
small_stroid.vel_x = -2;
//big astroid
astroid_t med_stroid;
med_stroid.pos_x = 90;
med_stroid.pos_y = 25;
med_stroid.type = 2;
med_stroid.vel_x = -1;
//big astroid
astroid_t big_stroid;
big_stroid.pos_x = 70;
big_stroid.pos_y = 35;
big_stroid.type = 3;
big_stroid.vel_x = -1;

//creates array of astroids:
astroid_t all_stroids[8]={
		{70,10,-1,0,1},
		{85,30,-1,0,2},
		{100,40,-2,0,3},
		{115,8,-1,0,1},
		{130,50,-1,0,1},
		{145,20,-1,0,2},
		{160,5,-1,0,3},
		{175,50,-2,0,1},
};
//creates array of bullets
bullet_t all_bullets[5]={
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
};

//Ship Bullets
bullet_t ship_bullet1;
ship_bullet1.vel_x = 0;
ship_bullet1.vel_y = 0;
ship_bullet1.pos_x = 0;
bullet_t ship_bullet2;
ship_bullet2.vel_x = 0;
ship_bullet2.vel_y = 0;
ship_bullet2.pos_x = 0;
bullet_t ship_bullet3;
ship_bullet3.vel_x = 0;
ship_bullet3.vel_y = 0;
ship_bullet3.pos_x = 0;
bullet_t ship_bullet4;
ship_bullet4.vel_x = 0;
ship_bullet4.vel_y = 0;
ship_bullet4.pos_x = 0;
bullet_t ship_bullet5;
ship_bullet5.vel_x = 0;
ship_bullet5.vel_y = 0;
ship_bullet5.pos_x = 0;

//Ship Laser
laser_t ship_laser;
ship_laser.pos_x = 0;
ship_laser.pos_y = 0;

//Ship Spread Gun
bullet_t bullet_spread1;
bullet_spread1.vel_x = 0;
bullet_spread1.vel_y = 0;
bullet_spread1.pos_x = 0;
bullet_spread1.pos_y = 0;
bullet_t bullet_spread2;
bullet_spread2.vel_x = 0;
bullet_spread2.vel_y = 0;
bullet_spread2.pos_x = 0;
bullet_spread2.pos_y = 0;
bullet_t bullet_spread3;
bullet_spread3.vel_x = 0;
bullet_spread3.vel_y = 0;
bullet_spread3.pos_x = 0;
bullet_spread3.pos_y = 0;

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
	for (int i = 0; i < 9; ++i){
		update_pos_asteroid(&all_stroids[i]);
		draw_asteroid(&all_stroids[i]);
	}
	//updates spaceship position and draws
	update_pos(&my_ship,detect_joystick(),key);
	draw_spaceship1(&my_ship);
	//tracks if spaceship is hit
	for (int i = 0; i < 9; ++i){
	spaceship_hit(&all_stroids[i],&my_ship);
	}
	//shoot function and detect if asteroid is hit function
	shoot(&my_ship,detect_joystick(),key,&all_bullets[0],&all_bullets[1],&all_bullets[2],&all_bullets[3],&all_bullets[4]);
	for (int k = 0; k < 6; ++k){
		for (int j = 0; j < 9; ++j){
		hit_astroid(&all_stroids[j],&all_bullets[k],&my_ship);
	}
	}

	//health system - displays current health and goes to main menu if health = 0
	gotoxy(1,1);
	printf("Ship Health: %d",my_ship.health);
	number_to_string(my_ship.health, health,2);
	lcd_write_string(0,40,health);
	if(my_ship.health == 0){
		lvl_select = 0;
	}
	//rgb lives
	lives_RGB(&my_ship);


	/*
	update_pos_asteroid(&big_stroid);
	update_pos_asteroid(&med_stroid);
	update_pos_asteroid(&small_stroid);
	draw_asteroid(&big_stroid);
	draw_asteroid(&med_stroid);
	draw_asteroid(&small_stroid);

	//tracks normal shots and updates if it hits asteroid
	shoot(&my_ship,detect_joystick(),key,&ship_bullet1,&ship_bullet2,&ship_bullet3,&ship_bullet4,&ship_bullet5);
	hit_astroid(&small_stroid,&ship_bullet1,&my_ship);
	hit_astroid(&small_stroid,&ship_bullet2,&my_ship);
	hit_astroid(&small_stroid,&ship_bullet3,&my_ship);
	hit_astroid(&small_stroid,&ship_bullet4,&my_ship);
	hit_astroid(&small_stroid,&ship_bullet5,&my_ship);

	hit_astroid(&med_stroid,&ship_bullet1,&my_ship);
	hit_astroid(&med_stroid,&ship_bullet2,&my_ship);
	hit_astroid(&med_stroid,&ship_bullet3,&my_ship);
	hit_astroid(&med_stroid,&ship_bullet4,&my_ship);
	hit_astroid(&med_stroid,&ship_bullet5,&my_ship);

	hit_astroid(&big_stroid,&ship_bullet1,&my_ship);
	hit_astroid(&big_stroid,&ship_bullet2,&my_ship);
	hit_astroid(&big_stroid,&ship_bullet3,&my_ship);
	hit_astroid(&big_stroid,&ship_bullet4,&my_ship);
	hit_astroid(&big_stroid,&ship_bullet5,&my_ship);

	//laser shot
	laser(&my_ship,detect_joystick(),key,&ship_laser);

	laser_hit(&big_stroid,&ship_laser);
	laser_hit(&med_stroid,&ship_laser);
	laser_hit(&small_stroid,&ship_laser);


	//spread shot
	spread_shot(&my_ship,detect_joystick(),key,&bullet_spread1,&bullet_spread2,&bullet_spread3);
	hit_astroid(&small_stroid,&bullet_spread1);
	hit_astroid(&med_stroid,&bullet_spread1);
	hit_astroid(&big_stroid,&bullet_spread1);

	hit_astroid(&small_stroid,&bullet_spread2);
	hit_astroid(&med_stroid,&bullet_spread2);
	hit_astroid(&big_stroid,&bullet_spread2);

	hit_astroid(&small_stroid,&bullet_spread3);
	hit_astroid(&med_stroid,&bullet_spread3);
	hit_astroid(&big_stroid,&bullet_spread3);


	//updates spaceship position and draws
	update_pos(&my_ship,detect_joystick(),key);
	draw_spaceship1(&my_ship);

	//tracks if spaceship is hit
	spaceship_hit(&big_stroid,&my_ship);
	spaceship_hit(&med_stroid,&my_ship);
	spaceship_hit(&small_stroid,&my_ship);


	//health system - displays current health and goes to main menu if health = 0
	gotoxy(1,1);
	printf("Ship Health: %d",my_ship.health);
	number_to_string(my_ship.health, health,2);
	lcd_write_string(0,40,health);
	if(my_ship.health == 0){
		lvl_select = 0;
	}

	//rgb lives
	lives_RGB(&my_ship);
	*/
	global_timer.updated=1;
	}

	/*
	while (timer(10) == 1){
	key = keyboard2();

	update_pos(&my_ship,detect_joystick(),key);
	draw_spaceship1(&my_ship);

	shoot(&my_ship,detect_joystick(),key,&ship_bullet1,&ship_bullet2,&ship_bullet3,&ship_bullet4,&ship_bullet5);

	laser(&my_ship,detect_joystick(),key,&ship_laser);




	laser_hit(&big_stroid,&ship_laser);
	laser_hit(&med_stroid,&ship_laser);
	laser_hit(&small_stroid,&ship_laser);

	spread_shot(&my_ship,detect_joystick(),key,&bullet_spread1,&bullet_spread2,&bullet_spread3);

	hit_astroid(&small_stroid,&ship_bullet1,&my_ship);
	hit_astroid(&small_stroid,&ship_bullet2,&my_ship);
	hit_astroid(&small_stroid,&ship_bullet3,&my_ship);
	hit_astroid(&small_stroid,&ship_bullet4,&my_ship);
	hit_astroid(&small_stroid,&ship_bullet5,&my_ship);

	hit_astroid(&med_stroid,&ship_bullet1,&my_ship);
	hit_astroid(&med_stroid,&ship_bullet2,&my_ship);
	hit_astroid(&med_stroid,&ship_bullet3,&my_ship);
	hit_astroid(&med_stroid,&ship_bullet4,&my_ship);
	hit_astroid(&med_stroid,&ship_bullet5,&my_ship);

	hit_astroid(&big_stroid,&ship_bullet1,&my_ship);
	hit_astroid(&big_stroid,&ship_bullet2,&my_ship);
	hit_astroid(&big_stroid,&ship_bullet3,&my_ship);
	hit_astroid(&big_stroid,&ship_bullet4,&my_ship);
	hit_astroid(&big_stroid,&ship_bullet5,&my_ship);

	hit_astroid(&small_stroid,&bullet_spread1);
	hit_astroid(&med_stroid,&bullet_spread1);
	hit_astroid(&big_stroid,&bullet_spread1);

	hit_astroid(&small_stroid,&bullet_spread2);
	hit_astroid(&med_stroid,&bullet_spread2);
	hit_astroid(&big_stroid,&bullet_spread2);

	hit_astroid(&small_stroid,&bullet_spread3);
	hit_astroid(&med_stroid,&bullet_spread3);
	hit_astroid(&big_stroid,&bullet_spread3);

	spaceship_hit(&big_stroid,&my_ship);
	spaceship_hit(&med_stroid,&my_ship);
	spaceship_hit(&small_stroid,&my_ship);

	gotoxy(1,1);
	printf("Ship Health: %d",my_ship.health);

	number_to_string(my_ship.health, health,2);
	lcd_write_string(0,40,health);

	number_to_string(my_ship.score, score ,6);
	lcd_write_string(1,35,score);

	lives_RGB(&my_ship);

	if(my_ship.health == 0){
		lvl_select = 0;
	}
	}
}
*/
}
}
}
