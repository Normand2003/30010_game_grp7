/*
 * spaceship.h
 *
 *  Created on: 13. jan. 2026
 *      Author: chris
 */

#ifndef SPACESHIP_H_
#define SPACESHIP_H_

//includes
#include <stdint.h>
#include <stdio.h>
#include "structures.h"
#include "joystick.h"

//functions
void update_pos(spaceship_t *ship,int direction, int direction2);
void print_ship(spaceship_t *ship);
void laser(spaceship_t *ship, int joystick, int space, laser_t *laser);



#endif /* SPACESHIP_H_ */
