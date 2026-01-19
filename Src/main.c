#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "draw.h"
#include "joystick.h"
#include "structures.h"
#include "spaceship.h"
#include "stopwatch.h"

int main(void)
{
uart_init( 115200 ); // Initialize USB serial emulation at 115200 baud
//uart_init( 9600 ); // Initialize USB serial emulation at 9600 baud
clrscr();
init_joystick();

//enables timer
initTimer();
g_running = 1;

//creates and enables the spaceship
spaceship_t my_ship;
my_ship.pos_x = 50;
my_ship.pos_y = 20;
my_ship.powerup = 2;
my_ship.laser_shot = 0;
print_ship(&my_ship);


//creates and enables the astroids
//big astroid
astroid_t small_stroid;
small_stroid.pos_x = 130;
small_stroid.pos_y = 25;
small_stroid.type = 3;
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

//prints different elements
print_astroid(&small_stroid);
print_astroid(&med_stroid);
print_astroid(&big_stroid);
//satelite(20,20);


//creates "level select" variable
int lvl_select = 0;

while(lvl_select == 1){

}

//main gameplay loop
while(lvl_select == 0){
	while (timer(10) == 1){
	update_pos(&my_ship,detect_joystick());
	print_ship(&my_ship);

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
	}
}
}
