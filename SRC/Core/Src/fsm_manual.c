/*
 * fsm_manual.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_manual.h"

int tempDuration = 0;

void changeMode(int mode){
	setTrafficLightDefault(0);
	setTrafficLightDefault(1);
	MODE = mode;
	setTimer(2, 25);
}

void displayDuration(int mode, int duration){
	display7SEG(0, mode);
	display7SEG(1, 0);
	display7SEG(2, duration % 10);
	display7SEG(3, (int) (duration / 10));
}

void fsm_manual_run(){
	switch(MODE){
		case MODE_1:
			fsm_automatic_run(0);
		    fsm_automatic_run(1);
			if (isButtonPressed(0) == 1){
				tempDuration = RED_DURATION;
				changeMode(MODE_2);
			}
			break;
		case MODE_2:
			displayDuration(2, tempDuration);
			if (isButtonPressed(0) == 1){
				tempDuration = YELLOW_DURATION;
				changeMode(MODE_3);
			}
			if (isButtonPressed(1) == 1){
				tempDuration++;
				if (tempDuration == 100) tempDuration = 1;
			}
			if (isButtonPressed(2) == 1){
				RED_DURATION = tempDuration;
			}
			if (timer_flag[2] == 1){
				HAL_GPIO_TogglePin(GPIOA, RED1_Pin);
				HAL_GPIO_TogglePin(GPIOA, RED2_Pin);
				setTimer(2, 25);
			}
			break;
		case MODE_3:
			displayDuration(3, tempDuration);
			if (isButtonPressed(0) == 1){
				tempDuration = GREEN_DURATION;
				changeMode(MODE_4);
			}
			if (isButtonPressed(1) == 1){
				tempDuration++;
				if (tempDuration == 100) tempDuration = 1;
			}
			if (isButtonPressed(2) == 1){
				YELLOW_DURATION = tempDuration;
			}
			if (timer_flag[2] == 1){
				HAL_GPIO_TogglePin(GPIOA, YELLOW1_Pin);
				HAL_GPIO_TogglePin(GPIOA, YELLOW2_Pin);
				setTimer(2, 25);
			}
			break;
		case MODE_4:
			displayDuration(4, tempDuration);
			if (isButtonPressed(0) == 1){
				LED_STATE [0] = INIT_STATE;
				LED_STATE [1] = INIT_STATE;
				changeMode(MODE_1);
			}
			if (isButtonPressed(1) == 1){
				tempDuration++;
				if (tempDuration == 100) tempDuration = 1;
			}
			if (isButtonPressed(2) == 1){
				GREEN_DURATION = tempDuration;
			}
			if (timer_flag[2] == 1){
				HAL_GPIO_TogglePin(GPIOA, GREEN1_Pin);
				HAL_GPIO_TogglePin(GPIOA, GREEN2_Pin);
				setTimer(2, 25);
			}
			break;
		default:
			 break;
	}
}
