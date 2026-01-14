#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include <stdint.h>

// Omdøb fra time_t -> sw_time_t (time_t er optaget af stdlib)
typedef struct {
    uint8_t h, m, s, hs;
} sw_time_t;

// Globale variabler (declare)
extern volatile sw_time_t g_time;
extern volatile sw_time_t g_split1;
extern volatile sw_time_t g_split2;

extern volatile uint8_t g_running;
extern volatile uint8_t g_second_changed;

// Funktioner
void initTimer(void);
void print_time(const char *label, const sw_time_t *t);
void copy_time_atomic(volatile sw_time_t *dst, volatile sw_time_t *src);
void lcd_write_string();

// IRQ handler skal have (void)
void TIM1_BRK_TIM15_IRQHandler(void);

#endif /* STOPWATCH_H_ */
