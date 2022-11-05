/*
 * fsm_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: admin
 */

#include "fsm_simple_buttons.h"
#include "software_timer.h"

#define STATUS_INIT 0
#define STATUS_RESET 1
#define STATUS_INCREASE 2
#define STATUS_DECREASE 3
#define STATUS_AUTO_DECREASE 4

#define AUTO_DECREASE_TIME 10000 //10s
int status = STATUS_INIT;
//setTimer1(1000);
void fsm_simple_buttons_run(){
	switch(status){
		case STATUS_INIT:
			counter_value = 0;
			display7SEG(counter_value);
//			setTimer1(100);

			if((timer1_flag == 1) && isButtonPressed(RESETbtn)==1){
				status = STATUS_RESET;
				counter_value = 0;
				setTimer1(100);
			}

			if(isButtonPressed(INCREASEbtn)){
				status = STATUS_INCREASE;
				counter_value++;
				setTimer1(100);
			}

			if(isButtonPressed(DECREASEbtn)){
				status = STATUS_DECREASE;
				counter_value--;
				setTimer1(100);
			}
			if(CountDownTimer(1) == 1){
				status = STATUS_AUTO_DECREASE;
				setTimer1(100);
				counter_value--;
				if(counter_value == 0) counter_value = 9;

			}
			break;


		case STATUS_RESET:
			display7SEG(counter_value);

			if(isButtonPressed(RESETbtn)){
				status = STATUS_RESET;
				counter_value = 0;
				setTimer1(100);

			}

			if(isButtonPressed(INCREASEbtn)){
				status = STATUS_INCREASE;
				counter_value++;
				setTimer1(100);
			}

			if(isButtonPressed(DECREASEbtn)){
				status = STATUS_DECREASE;
				counter_value--;
				setTimer1(100);
			}

			break;

		case STATUS_INCREASE:
			if(counter_value > 9) counter_value = 0;
			display7SEG(counter_value);

			if(isButtonPressed(RESETbtn)){
				status = STATUS_RESET;
				counter_value = 0;
				setTimer1(100);
			}

			if(isButtonPressed(INCREASEbtn)){
				status = STATUS_INCREASE;
				counter_value++;
				setTimer1(100);
			}

			if(isButtonPressed(DECREASEbtn)){
				status = STATUS_DECREASE;
				counter_value--;
				setTimer1(100);
			}
			break;

		case STATUS_DECREASE:
			if(counter_value < 0) counter_value = 9;
			display7SEG(counter_value);

			if(isButtonPressed(RESETbtn)){
				status = STATUS_RESET;
				counter_value = 0;
				setTimer1(100);
			}

			if(isButtonPressed(INCREASEbtn)){
				status = STATUS_INCREASE;
				counter_value++;
				setTimer1(100);
			}

			if(isButtonPressed(DECREASEbtn)){
				status = STATUS_DECREASE;
				counter_value--;
				setTimer1(100);
			}

			break;

		case STATUS_AUTO_DECREASE:
			display7SEG(counter_value);
			if(CountDownTimer(1) == 1){
				status = STATUS_AUTO_DECREASE;
				setTimer1(100);
				counter_value--;
				if(counter_value == 0) counter_value = 9;


			}

			if(isButtonPressed(RESETbtn)){
				status = STATUS_RESET;
				counter_value = 0;
				setTimer1(100);
			}

			if(isButtonPressed(INCREASEbtn)){
				status = STATUS_INCREASE;
				counter_value++;
				setTimer1(100);
			}

			if(isButtonPressed(DECREASEbtn)){
				status = STATUS_DECREASE;
				counter_value--;
				setTimer1(100);
			}

			break;
	}
}

