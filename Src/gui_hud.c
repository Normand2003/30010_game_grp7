/*
 * gui_hud.c
 *
 *  Created on: 19. jan. 2026
 *      Author: chris
 */
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" // Input/output library for this course
#include "draw.h"
#include "aliens.h"
#define ESC 0x1B
#define block 0xDB


void start_screen() {

	blink(0);
    clrscr();

    //printer titel 'Asstroids'
    fgcolor(2);
    gotoxy(80, 1);
    printf(" _______  _______  _______ _________ _______  _______ _________ ______   _______ ");
    gotoxy(80, 2);
    printf("(  ___  )(  ____ \\(  ____ \\\\__   __/(  ____ )(  ___  )\\__   __/(  __  \\ (  ____ \\");
    gotoxy(80, 3);
    printf("| (   ) || (    \\/| (    \\/   ) (   | (    )|| (   ) |   ) (   | (  \\  )| (    \\/");
    gotoxy(80, 4);
    printf("| (___) || (_____ | (_____    | |   | (____)|| |   | |   | |   | |   ) || (_____ ");
    gotoxy(80, 5);
    printf("|  ___  |(_____  )(_____  )   | |   |     __)| |   | |   | |   | |   | |(_____  )");
    gotoxy(80, 6);
    printf("| (   ) |      ) |      ) |   | |   | (\\ (   | |   | |   | |   | |   ) |      ) |");
    gotoxy(80, 7);
    printf("| )   ( |/\\____) |/\\____) |   | |   | ) \\ \\__| (___) |___) (___| (__/  )/\\____) |");
    gotoxy(80, 8);
    printf("|/     \\|\\_______)\\_______)   )_(   |/   \\__/(_______)\\_______/(______/ \\_______)");

    //printer play
    gotoxy(110, 16);
    printf(" ____  _            ");
    gotoxy(110, 17);
    printf("|  _ \\| | __ _ _   _ ");
    gotoxy(110, 18);
    printf("| |_) | |/ _` | | | |");
    gotoxy(110, 19);
    printf("|  __/| | (_| | |_| |");
    gotoxy(110, 20);
    printf("|_|   |_|\\__,_|\\__, |");
    gotoxy(110, 21);
    printf("               |___/ ");

    //printer help
    gotoxy(110, 31);
    printf(" _   _      _       ");
    gotoxy(110, 32);
    printf("| | | | ___| |_ __  ");
    gotoxy(110, 33);
    printf("| |_| |/ _ \\ | '_ \\ ");
    gotoxy(110, 34);
    printf("|  _  |  __/ | |_) |");
    gotoxy(110, 35);
    printf("|_| |_|\\___|_| .__/ ");
    gotoxy(110, 36);
    printf("             |_|    ");


    fgcolor(2);
    window(70, 14, 170, 25); // x1, y1, x2, y2
    fgcolor(2);
    window(70, 29, 170, 40);



    alien_t alien1;
    alien1.pos_x = 50;
    alien1.pos_y = 20;
    alien1.health = 1;
    draw_alien(&alien1);


    alien_t alien2;
    alien2.pos_x = 20;
    alien2.pos_y = 40;
    alien2.health = 1;
    draw_alien(&alien2);

    alien_t alien3;
    alien3.pos_x = 180;
    alien3.pos_y = 15;
    alien3.health = 1;
    draw_alien(&alien3);

}

int start_select(int joystick){
	int static selector;

	if(joystick == 1){
		selector = 1;
	}
	else if(joystick == 3){
		selector = 2;
	}

	if ((joystick == 5) && (selector == 1)){
		gotoxy(1,1);
		printf("play selected");
		return 1;
	}
	if ((joystick == 5) && (selector == 2)){
		gotoxy(1,1);
		printf("help selected");
		return 2;
	}

	if (joystick == 1){
		blink(1);
	    gotoxy(110, 16);
	    printf(" ____  _            ");
	    gotoxy(110, 17);
	    printf("|  _ \\| | __ _ _   _ ");
	    gotoxy(110, 18);
	    printf("| |_) | |/ _` | | | |");
	    gotoxy(110, 19);
	    printf("|  __/| | (_| | |_| |");
	    gotoxy(110, 20);
	    printf("|_|   |_|\\__,_|\\__, |");
	    gotoxy(110, 21);
	    printf("               |___/ ");

	    blink(0);
	    gotoxy(110, 31);
	    printf(" _   _      _       ");
	    gotoxy(110, 32);
	    printf("| | | | ___| |_ __  ");
	    gotoxy(110, 33);
	    printf("| |_| |/ _ \\ | '_ \\ ");
	    gotoxy(110, 34);
	    printf("|  _  |  __/ | |_) |");
	    gotoxy(110, 35);
	    printf("|_| |_|\\___|_| .__/ ");
	    gotoxy(110, 36);
	    printf("             |_|    ");
	}

	if (joystick == 3){
		blink(1);
	    gotoxy(110, 31);
	    printf(" _   _      _       ");
	    gotoxy(110, 32);
	    printf("| | | | ___| |_ __  ");
	    gotoxy(110, 33);
	    printf("| |_| |/ _ \\ | '_ \\ ");
	    gotoxy(110, 34);
	    printf("|  _  |  __/ | |_) |");
	    gotoxy(110, 35);
	    printf("|_| |_|\\___|_| .__/ ");
	    gotoxy(110, 36);
	    printf("             |_|    ");

		blink(0);
	    gotoxy(110, 16);
	    printf(" ____  _            ");
	    gotoxy(110, 17);
	    printf("|  _ \\| | __ _ _   _ ");
	    gotoxy(110, 18);
	    printf("| |_) | |/ _` | | | |");
	    gotoxy(110, 19);
	    printf("|  __/| | (_| | |_| |");
	    gotoxy(110, 20);
	    printf("|_|   |_|\\__,_|\\__, |");
	    gotoxy(110, 21);
	    printf("               |___/ ");
	}
	return 0;


}

void help_screen(){
	blink(0);
    clrscr();

    //printer titel 'Asstroids'
    fgcolor(2);
    gotoxy(80, 1);
    printf(" _______  _______  _______ _________ _______  _______ _________ ______   _______ ");
    gotoxy(80, 2);
    printf("(  ___  )(  ____ \\(  ____ \\\\__   __/(  ____ )(  ___  )\\__   __/(  __  \\ (  ____ \\");
    gotoxy(80, 3);
    printf("| (   ) || (    \\/| (    \\/   ) (   | (    )|| (   ) |   ) (   | (  \\  )| (    \\/");
    gotoxy(80, 4);
    printf("| (___) || (_____ | (_____    | |   | (____)|| |   | |   | |   | |   ) || (_____ ");
    gotoxy(80, 5);
    printf("|  ___  |(_____  )(_____  )   | |   |     __)| |   | |   | |   | |   | |(_____  )");
    gotoxy(80, 6);
    printf("| (   ) |      ) |      ) |   | |   | (\\ (   | |   | |   | |   | |   ) |      ) |");
    gotoxy(80, 7);
    printf("| )   ( |/\\____) |/\\____) |   | |   | ) \\ \\__| (___) |___) (___| (__/  )/\\____) |");
    gotoxy(80, 8);
    printf("|/     \\|\\_______)\\_______)   )_(   |/   \\__/(_______)\\_______/(______/ \\_______)");

    //printer "help-menu"
    gotoxy(71, 17);
    printf(" _          _                                          ");
    gotoxy(71, 18);
    printf("| |__   ___| |_ __          _ __ ___   ___ _ __  _   _ ");
    gotoxy(71, 19);
    printf("| '_ \\ / _ \\ | '_ \\  _____ | '_ ` _ \\ / _ \\ '_ \\| | | |");
    gotoxy(71, 20);
    printf("| | | |  __/ | |_) ||_____|| | | | | |  __/ | | | |_| |");
    gotoxy(71, 21);
    printf("|_| |_|\\___|_| .__/        |_| |_| |_|\\___|_| |_|\\__,_|");
    gotoxy(71, 22);
    printf("             |_|                                       ");

    window(70, 23, 170, 50);

    gotoxy(71,25);
    printf("CONTROLS:");
    gotoxy(71,26);
    	printf(" Move up: Arrowkey up");
    gotoxy(71,27);
    	printf(" Move down: Arrowkey down");
    gotoxy(71,28);
        printf(" Shoot: Space");
    gotoxy(71,29);
        printf(" Boss key: x");
    gotoxy(71,30);
        printf(" Laser shot: Arrowkey right");
    gotoxy(71,31);
        printf(" Spread shot: Arrowkey left");

    gotoxy(71,34);
    	printf("How to play:");
    gotoxy(71,35);
    	printf(" Your objective is to survive as long as possible,");
    gotoxy(71,36);
    	printf(" while astroids, aliens and other threats are approaching.");
    gotoxy(71,37);
    	printf(" Shoot enemies to gain points, and make sure none get past!");

    gotoxy(71,40);
    	printf("Powerups:");
    gotoxy(71,41);
    	printf(" Collect powerups while playing, and use your powerful abilites");
    gotoxy(71,42);
    	printf(" like the laser and spread-shot to kill all who oppose you!");
    gotoxy(71,43);
    	printf(" However! Powerups don't last forever! Use them wisely");

    //printer "back" knap

    blink(1);
    gotoxy(71, 51);
    printf(" ____             _    ");
    gotoxy(71, 52);
    printf("| __ )  __ _  ___| | __");
    gotoxy(71, 53);
    printf("|  _ \\ / _` |/ __| |/ /");
    gotoxy(71, 54);
    printf("| |_) | (_| | (__|   < ");
    gotoxy(71, 55);
    printf("|____/ \\__,_|\\___|_|\\_\\");
    blink(0);
}
