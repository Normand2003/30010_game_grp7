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

//functions
void update_pos(spaceship_t *ship,int direction);
void print_ship(spaceship_t *ship);


#endif /* SPACESHIP_H_ */
