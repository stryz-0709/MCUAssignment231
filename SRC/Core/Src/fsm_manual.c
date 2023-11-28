/*
 * fsm_manual.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_manual.h"

int tempDuration = 0;

void changeMode(int mode, int state){
	LED_STATE[0] = state;
	LED_STATE[1] = state;
	setTrafficLightDefault(0);
	setTrafficLightDefault(1);
	MODE = mode;
	setTimer(2, 25);
}

//void displayDuration(int mode, int duration){
//	display7SEG(0, mode);
//	display7SEG(1, 0);
//	display7SEG(2, duration % 10);
//	display7SEG(3, (int) (duration / 10));
//}

void fsm_manual_run(){
	switch(MODE){
		case AUTO_MODE:
			if (isButtonPressed(0)){
				tempDuration = RED_DURATION;
				changeMode(RED_MODE, EDIT_STATE);
			}
			break;
		case RED_MODE:
//			displayDuration(2, tempDuration);
			if (isButtonPressed(0)){
				tempDuration = YELLOW_DURATION;
				changeMode(AMBER_MODE, EDIT_STATE);
			}
			if (isButtonPressed(1)){
				tempDuration++;
				if (tempDuration == 100) tempDuration = 1;
			}
			if (isButtonPressed(2)){
				RED_DURATION = tempDuration;
			}
			if (timer_flag[2]){
//				HAL_GPIO_TogglePin(GPIOA, RED1_Pin);
//				HAL_GPIO_TogglePin(GPIOA, RED2_Pin);
				setTimer(2, 25);
			}
			break;
		case AMBER_MODE:
//			displayDuration(3, tempDuration);
			if (isButtonPressed(0)){
				tempDuration = GREEN_DURATION;
				changeMode(GREEN_MODE, EDIT_STATE);
			}
			if (isButtonPressed(1)){
				tempDuration++;
				if (tempDuration == 100) tempDuration = 1;
			}
			if (isButtonPressed(2)){
				YELLOW_DURATION = tempDuration;
			}
			if (timer_flag[2]){
//				HAL_GPIO_TogglePin(GPIOA, YELLOW1_Pin);
//				HAL_GPIO_TogglePin(GPIOA, YELLOW2_Pin);
				setTimer(2, 25);
			}
			break;
		case GREEN_MODE:
//			displayDuration(4, tempDuration);
			if (isButtonPressed(0)){
				changeMode(AUTO_MODE, INIT_STATE);
			}
			if (isButtonPressed(1)){
				tempDuration++;
				if (tempDuration == 100) tempDuration = 1;
			}
			if (isButtonPressed(2)){
				GREEN_DURATION = tempDuration;
			}
			if (timer_flag[2]){
//				HAL_GPIO_TogglePin(GPIOA, GREEN1_Pin);
//				HAL_GPIO_TogglePin(GPIOA, GREEN2_Pin);
				setTimer(2, 25);
			}
			break;
		case PED_MODE:
			if (isButtonPressed(0));
			if (isButtonPressed(1));
			if (isButtonPressed(2));
			break;
		default:
			 break;
	}
}
