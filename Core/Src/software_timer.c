/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: admin
 */
#include "software_timer.h"

#define TICK 10

int timer_counter[3];
int timer_flag[3];

void setTimer(int duration, int num){
	timer_counter[num] = duration/TICK;
	timer_flag[num] = 0;
}
void timerRun(){
	for(int i = 0; i < 3; i++){
		if(timer_counter[i] > 0){
			timer_counter[i]--;
			if(timer_counter[i] <= 0) {
				timer_flag[i] = 1;
				timer_counter[i] = 0;
			}
		}
	}
}

int CountDownTimer(int num){
	if(timer_flag[num] == 1){
		timer_flag[num] = 0;
		return 1;
	}
	return 0;
}
