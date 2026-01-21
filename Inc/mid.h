#ifndef MID_H_
#define MID_H_
#include <stdint.h>
#include <stdio.h>


typedef struct{
	uint16_t x;
	uint16_t y;
	uint8_t velx;
	int16_t vely;
	uint8_t type; // 0=bullet, 1 = small assteroid, 2 = medium assteroid, 3 large assteroid, 4 = satelite, 5 = satelite
}object_t;

typedef struct{
	uint8_t x;
	uint8_t y;

}coordinate_t;



#endif

