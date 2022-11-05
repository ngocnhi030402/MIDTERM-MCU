/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define RESETbtn 0
#define INCREASEbtn 1
#define DECREASEbtn 2

void getKeyInput();
int isButtonPressed(int button);
int isButtonPressed3s(int button);

#endif /* INC_BUTTON_H_ */
