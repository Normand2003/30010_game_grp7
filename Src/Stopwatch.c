#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "Stopwatch.h"
#include "stm32f30x_rcc.h"
#include <stdio.h>
#include "structures.h"

// ===== Globale variabler (definitions - kun her!) =====
volatile sw_time_t g_time = {0};
volatile sw_time_t g_split1 = {0};
volatile sw_time_t g_split2 = {0};

volatile uint8_t g_running = 0;
volatile uint8_t g_second_changed = 0;

// ===== Hjælpefunktioner =====
void copy_time_atomic(volatile sw_time_t *dst, volatile sw_time_t *src)
{
    __disable_irq();
    *dst = *src;
    __enable_irq();
}

void print_time(const char *label, const sw_time_t *t)
{
    printf("%s %02u:%02u:%02u.%02u\r\n", label, t->h, t->m, t->s, t->hs);
}

// ===== Timer init =====
void initTimer(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_TIM15EN;

    TIM15->CR1 = 0x0000;
    TIM15->PSC = 6399;
    TIM15->ARR = 99;
    TIM15->EGR = TIM_EGR_UG;

    TIM15->DIER |= 0x0001;
    TIM15->SR &= ~0x0001;

    NVIC_SetPriority(TIM1_BRK_TIM15_IRQn, 0);
    NVIC_EnableIRQ(TIM1_BRK_TIM15_IRQn);

    TIM15->CR1 |= 0x0001;
}

// ===== IRQ handler =====
void TIM1_BRK_TIM15_IRQHandler() {

	if (g_running) {
		g_time.hs++;

		if (g_time.hs >= 100) {
			g_time.hs = 0;
			g_time.s++;
			g_second_changed = 1;
		}

		if (g_time.s >= 60) {
			g_time.s = 0;
			g_time.m++;
		}

		if (g_time.m >= 60) {
			g_time.m = 0;
			g_time.h++;
		}

	}

    TIM15->SR &= ~0x0001;

}

int timer(int spou){
	if ((g_time.hs % spou) == 0){
		return 1;
	}
	else {
		return 0;
	}
}




//silas clock

int clockvalue=5;

int tick=0;
int updated=0; // holder styr på hvilke objekter der allerede er opdateret i given clockperiode

void clock(gtimer_t *gtimer){


	  //if((g_time.hs%clockvalue)==0)
	  if((g_time.hs & 0b1) == 1)
		gtimer->tick=1;
	  	else{
			gtimer->tick=0;
			gtimer->updated=0; //resetter update så den kan opdatere igen i næste clockperiode
	}
}

void run_functions(){
	if((tick==1)&&(updated==0)){
	player();
	update_positions();
	print();
	updated=1;
	}
}
