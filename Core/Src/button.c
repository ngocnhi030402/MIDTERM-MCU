/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: admin
 */

#include "button.h"
//
#define PRESSED_STATE 	0
#define NORMAL_STATE 	1


uint16_t BUTTON[3] = {GPIO_PIN_10, GPIO_PIN_11, GPIO_PIN_12};

int button_flag[3];
int button_flag_3s[3];


int KeyReg0[3] = {NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE};
int KeyReg3[3] = {NORMAL_STATE};

int TimeOutForKeyPress[3];

void getKeyInput() {
  for(int i = 0; i < 3; i++) {
    KeyReg2[i] = KeyReg1[i];
    KeyReg1[i] = KeyReg0[i];
    KeyReg0[i] = HAL_GPIO_ReadPin(GPIOA, BUTTON[i]);
    if((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])) {
      if(KeyReg3[i] != KeyReg2[i]) {
    	KeyReg3[i] = KeyReg2[i];
    	if(KeyReg3[i] == PRESSED_STATE) {
    	  TimeOutForKeyPress[i] = 300;
    	  button_flag[i] = 1;
    	}
      }
      else {
        TimeOutForKeyPress[i]--;
        if(TimeOutForKeyPress[i] == 0) {
          if(KeyReg3[i] == PRESSED_STATE){
                TimeOutForKeyPress[i] = 100;
                button_flag[i] = 1;
          }
        }
      }
    }
  }
}

int isButtonPressed(int index) {
    if(button_flag[index] == 1) {
      button_flag[index] = 0;
      return 1;
    }
  return 0;
}
