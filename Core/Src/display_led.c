/*
 * display_led.c
 *
 *  Created on: Nov 5, 2022
 *      Author: admin
 */

#include "display_led.h"

//HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 0);
//uint16_t LED[1] = {LED_RED_Pin};

GPIO_TypeDef * Led7SegPort[7] = {SEG0_GPIO_Port, SEG1_GPIO_Port, SEG2_GPIO_Port, SEG3_GPIO_Port, SEG4_GPIO_Port, SEG5_GPIO_Port, SEG6_GPIO_Port};

uint16_t Led7SegPin[7] = {SEG0_Pin, SEG1_Pin, SEG2_Pin, SEG3_Pin, SEG4_Pin, SEG5_Pin, SEG6_Pin};

const uint8_t Led7Seg[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

void display7SEG(int num) {
	for(int i = 0; i < 7; i++) {
		HAL_GPIO_WritePin(Led7SegPort[i], Led7SegPin[i], (Led7Seg[num] >> i) & 0x01);
	}
}
