/*
 * structures.h
 *
 *  Created on: 13. jan. 2026
 *      Author: chris
 */

#ifndef STRUCTURES_H_
#define STRUCTURES_H_


//Structures
typedef struct {
	int16_t pos_x, pos_y;
	int16_t vel_x, vel_y;
	int16_t type;
} astroid_t;

typedef struct {
	int16_t pos_x, pos_y;
	int16_t vel_x, vel_y;
} satellite_t;

typedef struct {
	int16_t pos_x, pos_y;
	int16_t vel_x, vel_y;
	int16_t health;
	int16_t powerup;
	int16_t laser_shot;
	int16_t spread_shot;
	int16_t score;
} spaceship_t;

typedef struct {
	int16_t pos_x, pos_y;
	int16_t vel_x, vel_y;
	int16_t health;
	int16_t type;
} enemy_t;

typedef struct {
	int16_t pos_x, pos_y;
	int16_t vel_x, vel_y;
	int16_t enemy;
}bullet_t;

typedef struct {
	int16_t pos_x, pos_y;
	int16_t active;
	int16_t enemy;
}laser_t;

typedef struct {
	int tick;
	int updated;
}gtimer_t;



#endif /* STRUCTURES_H_ */
