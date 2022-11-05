/*
 * led_blinky.c
 *
 *  Created on: Nov 5, 2022
 *      Author: admin
 */


#include "led_blinky.h"
#include "software_timer.h"

void led_blinky(void) {
	if(timer3_flag){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer3(200);
	}
}
