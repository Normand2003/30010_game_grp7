#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "draw.h"
#include "joystick.h"
#include "structures.h"
#include "spaceship.h"
#include "stopwatch.h"
#include "aliens.h"
#include "gui_hud.h"

//game screen is 235 x 65 pixels

int main(void){



uart_init( 115200 ); // Initialize USB serial emulation at 115200 baud
clrscr();
init_joystick();
bgcolor(0);
fgcolor(15);
//enables timer
initTimer();
g_running = 1;
//creates "level select" variable
int lvl_select = 0;



while(1){

if(lvl_select == 0){
	start_screen();
}

while(lvl_select == 0){
	while (timer(10) == 1){
		lvl_select = start_select(detect_joystick());
	}
}

if(lvl_select == 2){
	help_screen();
}

while(lvl_select == 2){
	if(detect_joystick() == 5){
		lvl_select = 0;
	}
}



//creates and enables the spaceship
spaceship_t my_ship;
my_ship.pos_x = 20;
my_ship.pos_y = 32;
my_ship.powerup = 1; //0 standard, 1 laser, 2 spread
my_ship.laser_shot = 0;
my_ship.health = 3;


//creates and enables the astroids
//big astroid
astroid_t small_stroid;
small_stroid.pos_x = 130;
small_stroid.pos_y = 25;
small_stroid.type = 1;
small_stroid.vel_x = -1;
//big astroid
astroid_t med_stroid;
med_stroid.pos_x = 90;
med_stroid.pos_y = 25;
med_stroid.type = 2;
med_stroid.vel_x = -2;
//big astroid
astroid_t big_stroid;
big_stroid.pos_x = 70;
big_stroid.pos_y = 35;
big_stroid.type = 3;
big_stroid.vel_x = -1;


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
//prints different elements
draw_asteroid(&small_stroid);
draw_asteroid(&med_stroid);
draw_asteroid(&big_stroid);
//satelite(20,20);
}

//main gameplay loop
while(lvl_select == 1){
	while (timer(10) == 1){
	update_pos(&my_ship,detect_joystick());
	draw_spaceship1(&my_ship);

	shoot(&my_ship,detect_joystick(),&ship_bullet1,&ship_bullet2,&ship_bullet3,&ship_bullet4,&ship_bullet5);
	laser(&my_ship,detect_joystick(),&ship_laser);
	laser_hit(&big_stroid,&ship_laser);
	laser_hit(&med_stroid,&ship_laser);
	laser_hit(&small_stroid,&ship_laser);
	spread_shot(&my_ship,detect_joystick(),&bullet_spread1,&bullet_spread2,&bullet_spread3);

	hit_astroid(&small_stroid,&ship_bullet1);
	hit_astroid(&small_stroid,&ship_bullet2);
	hit_astroid(&small_stroid,&ship_bullet3);
	hit_astroid(&small_stroid,&ship_bullet4);
	hit_astroid(&small_stroid,&ship_bullet5);

	hit_astroid(&med_stroid,&ship_bullet1);
	hit_astroid(&med_stroid,&ship_bullet2);
	hit_astroid(&med_stroid,&ship_bullet3);
	hit_astroid(&med_stroid,&ship_bullet4);
	hit_astroid(&med_stroid,&ship_bullet5);

	hit_astroid(&big_stroid,&ship_bullet1);
	hit_astroid(&big_stroid,&ship_bullet2);
	hit_astroid(&big_stroid,&ship_bullet3);
	hit_astroid(&big_stroid,&ship_bullet4);
	hit_astroid(&big_stroid,&ship_bullet5);

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

	if(my_ship.health == 0){
		lvl_select = 0;
	}
	}
}
}
}
