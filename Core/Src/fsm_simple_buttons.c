/*
 * fsm_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: admin
 */

#include "fsm_simple_buttons.h"
#include "software_timer.h"

#define STATUS_INIT 			0
#define STATUS_RESET 			1
#define STATUS_INCREASE 		2
#define STATUS_DECREASE 		3
#define STATUS_RUN 				4
#define STATUS_AUTO_DECREASE 	5

#define AUTO_DECREASE_TIME 10000 //10s
#define COUNT_DOWN_TIME 500
int status = STATUS_INIT;
//setTimer1(1000);
void fsm_simple_buttons_run(){
	switch(status){
		case STATUS_INIT:
			status = STATUS_RUN;
			setTimer(10000, 1);
			counter_value = 0;
			break;

		case STATUS_RUN:
			display7SEG(counter_value);
//			setTimer(10000, 1);

			if(isButtonPressed(RESETbtn)==1){
				status = STATUS_RESET;
			}

			if(isButtonPressed(INCREASEbtn)){
				status = STATUS_INCREASE;
//				counter_value++;
//				setTimer1(100);
			}

			if(isButtonPressed(DECREASEbtn)){
				status = STATUS_DECREASE;
//				counter_value--;
//				setTimer1(100);
			}
			if(CountDownTimer(1) == 1){
				status = STATUS_AUTO_DECREASE;
				setTimer(COUNT_DOWN_TIME, 1);
				if(counter_value > 0) counter_value--;

			}
			break;


		case STATUS_RESET:
//			display7SEG(counter_value);
			counter_value = 0;
			setTimer(10000, 1);
			status = STATUS_RUN;

//			if(isButtonPressed(RESETbtn)){
//				status = STATUS_RESET;
//				counter_value = 0;
//
//			}
//
//			if(isButtonPressed(INCREASEbtn)){
//				status = STATUS_INCREASE;
//				counter_value++;
//			}
//
//			if(isButtonPressed(DECREASEbtn)){
//				status = STATUS_DECREASE;
//				counter_value--;
//			}

			break;

		case STATUS_INCREASE:
			counter_value++;
			if(counter_value > 9) counter_value = 0;
//			display7SEG(counter_value);
			status = STATUS_RUN;
			setTimer(10000, 1);
//			if(isButtonPressed(RESETbtn)){
//				status = STATUS_RESET;
//				counter_value = 0;
//			}
//
//			if(isButtonPressed(INCREASEbtn)){
//				status = STATUS_INCREASE;
//				counter_value++;
//			}
//
//			if(isButtonPressed(DECREASEbtn)){
//				status = STATUS_DECREASE;
//				counter_value--;
//			}
			break;

		case STATUS_DECREASE:
			counter_value--;
			if(counter_value < 0) counter_value = 9;
//			display7SEG(counter_value);
			setTimer(10000, 1);
			status = STATUS_RUN;
//			if(isButtonPressed(RESETbtn)){
//				status = STATUS_RESET;
//				counter_value = 0;
//			}
//
//			if(isButtonPressed(INCREASEbtn)){
//				status = STATUS_INCREASE;
//				counter_value++;
//			}
//
//			if(isButtonPressed(DECREASEbtn)){
//				status = STATUS_DECREASE;
//				counter_value--;
//			}

			break;

		case STATUS_AUTO_DECREASE:
			display7SEG(counter_value);
			if(CountDownTimer(1) == 1){
				status = STATUS_AUTO_DECREASE;
				setTimer(COUNT_DOWN_TIME, 1);
				if(counter_value > 0) counter_value--;
			}

			if(isButtonPressed(RESETbtn)){
				status = STATUS_RESET;
			}

			if(isButtonPressed(INCREASEbtn)){
				status = STATUS_INCREASE;
			}

			if(isButtonPressed(DECREASEbtn)){
				status = STATUS_DECREASE;
			}

			break;
	}
}

