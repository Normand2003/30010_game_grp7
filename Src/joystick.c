/*
 * joystick.c
 *
 *  Created on: 9. jan. 2026
 *      Author: chris
 */
#include "joystick.h"
#include "stm32f30x_rcc.h"
#include "structures.h"

void init_joystick() {
	RCC->AHBENR |= RCC_AHBPeriph_GPIOA; // Enable clock for GPIO Port A
	RCC->AHBENR |= RCC_AHBPeriph_GPIOB; // Enable clock for GPIO Port B
	RCC->AHBENR |= RCC_AHBPeriph_GPIOC; // Enable clock for GPIO Port C

	//--- A4 - UP
		// Set pin PA4 to input
	GPIOA->MODER &= ~(0x00000003 << (4 * 2)); // Clear mode register
	GPIOA->MODER |= (0x00000000 << (4 * 2)); // Set mode register (0x00 –
		//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOA->PUPDR &= ~(0x00000003 << (4 * 2)); // Clear push/pull register
	GPIOA->PUPDR |= (0x00000002 << (4 * 2)); // Set push/pull register (0x00 -
		//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

	//--- C0 - RIGHT
		// Set pin PC0 to input
	GPIOC->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
	GPIOC->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 –
		//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
	GPIOC->PUPDR |= (0x00000002 << (0 * 2)); // Set push/pull register (0x00 -
		//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

	//--- C1 - LEFT
		// Set pin PC1 to input
	GPIOC->MODER &= ~(0x00000003 << (1 * 2)); // Clear mode register
	GPIOC->MODER |= (0x00000000 << (1 * 2)); // Set mode register (0x00 –
		//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOC->PUPDR &= ~(0x00000003 << (1 * 2)); // Clear push/pull register
	GPIOC->PUPDR |= (0x00000002 << (1 * 2)); // Set push/pull register (0x00 -
		//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

	//--- B0 - DOWN
		// Set pin PB0 to input
	GPIOB->MODER &= ~(0x00000003 << (0 * 2)); // Clear mode register
	GPIOB->MODER |= (0x00000000 << (0 * 2)); // Set mode register (0x00 –
		//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOB->PUPDR &= ~(0x00000003 << (0 * 2)); // Clear push/pull register
	GPIOB->PUPDR |= (0x00000002 << (0 * 2)); // Set push/pull register (0x00 -
		//No pull, 0x01 - Pull-up, 0x02 - Pull-down)

	//--- B5 - CENTER
		// Set pin PB5 to input
	GPIOB->MODER &= ~(0x00000003 << (5 * 2)); // Clear mode register
	GPIOB->MODER |= (0x00000000 << (5 * 2)); // Set mode register (0x00 –
		//Input, 0x01 - Output, 0x02 - Alternate Function, 0x03 - Analog in/out)
	GPIOB->PUPDR &= ~(0x00000003 << (5 * 2)); // Clear push/pull register
	GPIOB->PUPDR |= (0x00000002 << (5 * 2)); // Set push/pull register (0x00 -
		//No pull, 0x01 - Pull-up, 0x02 - Pull-down)
}

int detect_joystick() {
	//returns 1 for up, 2 for right, 3 for down, 4 for left, 5 for center and 0 for nothing


	//--- A4 - UP
	uint16_t val_up = GPIOA->IDR & (0x0001 << 4); //Read from pin PA4
	//--- C0 - RIGHT
	uint16_t val_right = GPIOC->IDR & (0x0001 << 0); //Read from pin PC0
	//--- C1 - LEFT
	uint16_t val_left = GPIOC->IDR & (0x0001 << 1); //Read from pin PC1
	//--- B0 - DOWN
	uint16_t val_down = GPIOB->IDR & (0x0001 << 0); //Read from pin PB0
	//--- B5 - CENTER
	uint16_t val_center = GPIOB->IDR & (0x0001 << 5); //Read from pin PB5

	if (val_right != 0) {
		return 2;
	}

	else if (val_up != 0) {
		return 1;
	}

	else if (val_down != 0) {
		return 3;
	}

	else if (val_left != 0) {
		return 4;
	}

	else if (val_center != 0) {
		return 5;
	}
	else {
		return 0;
	}
}

int keyboard2() {

	// pil op = 27 91 "65"
	// pil ned = 27 91 "66"
	// pil højre = 27 91 "67"
	// pil venstre = 27 91 "68"
    // space = 32
	// x(bosskey) = 120


	//reads keyboard input, and returns corrisponding value
	int x = 0;
	int i = 0;
	char buffer[255];
	while (uart_get_count() != 0) {
		x = uart_get_char();
		buffer[i]=x;

		if (x == 65) {
			i++;
			buffer[254] = 0x00;
			uart_clear();
			return 65;
		}
		if (x == 66) {
			i++;
			buffer[254] = 0x00;
			uart_clear();
			return 66;
		}
		if (x == 120) {
			i++;
			buffer[254] = 0x00;
			uart_clear();
			return 120;
		}
		if (x == 67) {
			i++;
			buffer[254] = 0x00;
			uart_clear();
			return 67;
		}
		if (x == 68) {
			i++;
			buffer[254] = 0x00;
			uart_clear();
			return 68;
		}
		if (x == 32) {
			i++;
			buffer[254] = 0x00;
			uart_clear();
			return 32;
		}
		i++;
	}


	buffer[254] = 0x00;
	uart_clear();
	return 0;
}
