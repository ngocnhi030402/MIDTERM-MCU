/*
 * led_blinky.c
 *
 *  Created on: Nov 5, 2022
 *      Author: admin
 */


#include "led_blinky.h"
#include "software_timer.h"

#define LEDINIT 6
#define LEDON 7
#define LEDOFF 8
int state = LEDINIT;
void led_blinky(void) {
	switch(state){
		case LEDINIT:
			state = LEDON;
			setTimer(500, 2);
			break;

		case LEDON:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 0);
			state = LEDOFF;
			setTimer(500, 2);
			break;

		case LEDOFF:
			state = LEDON;
			setTimer(500, 2);
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 1);
			break;
	}

}
