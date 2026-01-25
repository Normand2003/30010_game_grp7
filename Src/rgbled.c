/*
 * rgbled.c
 *
 *  Created on: 23. jan. 2026
 *      Author: chris
 */
#include "rgbled.h"
#include "structures.h"
#include "stm32f30x_rcc.h"


void init_led() {

	// Set pin PA9 (blue) to output
	GPIOA->OSPEEDR &= ~(0x00000003 << (9 * 2)); // Clear speed register
	GPIOA->OSPEEDR |= (0x00000002 << (9 * 2)); // set speed register (0x01 - 10 MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
	GPIOA->OTYPER &= ~(0x0001 << (9 * 1)); // Clear output type register
	GPIOA->OTYPER |= (0x0000 << (1)); // Set output type register (0x00 - Push pull, 0x01 - Open drain)
	GPIOA->MODER &= ~(0x00000003 << (9 * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000001 << (9 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

	GPIOA->ODR |= (0x0001 << 9); //slukker for blå lys

	// Set pin PC7 (green) to output
	GPIOC->OSPEEDR &= ~(0x00000003 << (7 * 2)); // Clear speed register
	GPIOC->OSPEEDR |= (0x00000002 << (7 * 2)); // set speed register (0x01 - 10 MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
	GPIOC->OTYPER &= ~(0x0001 << (7 * 1)); // Clear output type register
	GPIOC->OTYPER |= (0x0000 << (1)); // Set output type register (0x00 - Push pull, 0x01 - Open drain)
	GPIOC->MODER &= ~(0x00000003 << (7 * 2)); // Clear mode register
	GPIOC->MODER |= (0x00000001 << (7 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

	GPIOB->ODR |= (0x0001 << 4); //slukker for rød

	// Set pin PB4 (red) to output
	GPIOB->OSPEEDR &= ~(0x00000003 << (4 * 2)); // Clear speed register
	GPIOB->OSPEEDR |= (0x00000002 << (4 * 2)); // set speed register (0x01 - 10 MHz, 0x02 - 2 MHz, 0x03 - 50 MHz)
	GPIOB->OTYPER &= ~(0x0001 << (4 * 1)); // Clear output type register
	GPIOB->OTYPER |= (0x0000 << (1)); // Set output type register (0x00 - Push pull, 0x01 - Open drain)
	GPIOB->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
	GPIOB->MODER |= (0x00000001 << (4 * 2)); // Set mode register (0x00 – Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)

	GPIOC->ODR |= (0x0001 << 7); //slukker for grøn

}

void lives_RGB(spaceship_t *ship) {

	//GRØN
	if (ship->health == 3) {
	GPIOC->ODR &= ~(0x0001 << 7); //tænder for grøn
	GPIOA->ODR |= (0x0001 << 9); //slukker for blå
	GPIOB->ODR |= (0x0001 << 4); //slukker for rød
	}

	//GUL
	else if (ship->health == 2) {
	GPIOB->ODR &= ~(0x0001 << 4); //tænder for rød
	GPIOA->ODR |= (0x0001 << 9); //slukker for blå
	GPIOC->ODR &= ~(0x0001 << 7); //tænder for grøn
	}

	//RØD
	else if (ship->health == 1) {
	GPIOB->ODR &= ~(0x0001 << 4); //tænder for rød
	GPIOA->ODR |= (0x0001 << 9); //slukker for blå
	GPIOC->ODR |= (0x0001 << 7); //slukker for grøn
	}

	//SLUKKET
	else if (ship->health == 0) {
	GPIOC->ODR |= (0x0001 << 7); //slukker for grøn
	GPIOA->ODR |= (0x0001 << 9); //slukker for blå
	GPIOB->ODR |= (0x0001 << 4); //slukker for rød
	}

}


