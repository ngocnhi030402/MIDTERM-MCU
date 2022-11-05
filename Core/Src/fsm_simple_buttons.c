/*
 * fsm_simple_buttons.c
 *
 *  Created on: Nov 5, 2022
 *      Author: admin
 */

#include "fsm_simple_buttons.h"

#define STATUS_INIT 0
#define STATUS_RESET 1
#define STATUS_INCREASE 2
#define STATUS_DECREASE 3

int status = STATUS_INIT;

void fsm_simple_buttons_run(){
	switch(status){
		case STATUS_INIT:
			counter_value = 0;
			display7SEG(counter_value);
			if(isButtonPressed(RESETbtn)){
				status = STATUS_RESET;
				counter_value = 0;
			}

			if(isButtonPressed(INCREASEbtn)){
				status = STATUS_INCREASE;
				counter_value++;
			}

			if(isButtonPressed(DECREASEbtn)){
				status = STATUS_DECREASE;
				counter_value--;
			}
			break;


		case STATUS_RESET:
			display7SEG(counter_value);

			if(isButtonPressed(RESETbtn)){
				status = STATUS_RESET;
				counter_value = 0;
			}

			if(isButtonPressed(INCREASEbtn)){
				status = STATUS_INCREASE;
				counter_value++;
			}

			if(isButtonPressed(DECREASEbtn)){
				status = STATUS_DECREASE;
				counter_value--;
			}

			break;

		case STATUS_INCREASE:
			if(counter_value > 9) counter_value = 0;
			display7SEG(counter_value);

			if(isButtonPressed(RESETbtn)){
				status = STATUS_RESET;
				counter_value = 0;
			}

			if(isButtonPressed(INCREASEbtn)){
				status = STATUS_INCREASE;
				counter_value++;
			}

			if(isButtonPressed(DECREASEbtn)){
				status = STATUS_DECREASE;
				counter_value--;
			}
			break;

		case STATUS_DECREASE:
			if(counter_value < 0) counter_value = 9;
			display7SEG(counter_value);

			if(isButtonPressed(RESETbtn)){
				status = STATUS_RESET;
				counter_value = 0;
			}

			if(isButtonPressed(INCREASEbtn)){
				status = STATUS_INCREASE;
				counter_value++;
			}

			if(isButtonPressed(DECREASEbtn)){
				status = STATUS_DECREASE;
				counter_value--;
			}

			break;
	}
}
