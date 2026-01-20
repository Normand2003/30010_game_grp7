/*
 * joystick.h
 *
 *  Created on: 9. jan. 2026
 *      Author: chris
 */

#ifndef JOYSTICK_H_
#define JOYSTICK_H_
#include <stdint.h>
#include "structures.h"

int detect_joystick();
void init_joystick();
void init_led();
void lives_RGB(spaceship_t *ship);

#endif /* JOYSTICK_H_ */
