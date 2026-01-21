#ifndef GRAVITY_H_
#define GRAVITY_H_
#include <stdint.h>
#include <stdio.h>
void clock(void);
void run_functions(void);
void removing(uint8_t p);
void player(void);

typedef struct{
	uint8_t x;
	uint16_t y;
	uint8_t velx;
	int16_t vely;
	uint8_t type; // 0=bullet, 1 = small assteroid, 2 = medium assteroid, 3 large assteroid, 4 = satelite, 5 = satelite
}objects_t;


//1==0||g_time.hs>>1==5 || // bestemmer hvornår objecter kan bevæge sig. dette sker 10 gange i sekundet
//		g_time.hs>>1==10||g_time.hs>>1==15||
//		g_time.hs>>1==20||g_time.hs>>1==25||
//		g_time.hs>>1==30||g_time.hs>>1==35||
//		g_time.hs>>1==40||g_time.hs>>1==45


#endif
