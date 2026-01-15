#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "ansi.h"
#include "lut.h"
#include "joystick.h"
#include "LCD.h"
#include <string.h>
#include "charset.h"
#include "mid.h"
#include "Stopwatch.h"

// grænseværdier for terminal putty; x = 1..207, y = 1..65


int main() {
	uart_init (115200);
	clrscr();
	goHome();
    initTimer();
    g_running = 1;






    while (1) {

        state_reset();
        printer();
        update_position();


}

}
















