/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void timerRun();
int CountDownTimer(int second);

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

#endif /* INC_SOFTWARE_TIMER_H_ */
