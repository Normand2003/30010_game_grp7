
#include "mid.h"
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "Stopwatch.h"

void pins(){
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

object_t thing = {200,20,-1,0,0};

int x_updated_this_hs=0;

int spou=4;


void state_reset(){

	if((g_time.hs%spou) !=0)
		x_updated_this_hs=0;
}

void update_position(void)
{
    if (g_time.hs % spou == 0) {
        if (x_updated_this_hs == 0) {

            if (thing.x > 1) {
                thing.x += thing.velx;
                thing.y += thing.vely;
            }

            x_updated_this_hs = 1;
        }
    }
}


void printer(){
static int lastx;
static int lasty;

	if((g_time.hs%spou) == 0){
		gotoxy(lasty,lastx);
		printf(" ");
		gotoxy(thing.y,thing.x);
		printf("o");}
		lastx=thing.x;
		lasty=thing.y;


}






















