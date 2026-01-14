#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "draw.h"
#include "joystick.h"
#include "structures.h"
#include "spaceship.h"

int main(void)
{
uart_init( 9600 ); // Initialize USB serial emulation at 9600 baud
clrscr();
gotoxy(0,0);

spaceship_t my_ship;
my_ship.pos_x = 10;
my_ship.pos_y = 10;
print_ship(&my_ship);

astroid_t lille_stroid;
lille_stroid.pos_x = 100;
lille_stroid.pos_y = 25;

print_astroid(&lille_stroid);

init_joystick();


while(1){
	update_pos(&my_ship,detect_joystick());
	print_ship(&my_ship);

}
}
