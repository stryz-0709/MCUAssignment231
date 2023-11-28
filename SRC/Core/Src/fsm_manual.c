/*
 * fsm_manual.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_manual.h"

int tempDuration = 0;

void changeMode(int mode, int ledMode){
	LED_MODE[0] = ledMode;
	LED_MODE[1] = ledMode;
	setTrafficLight(0, INIT);
	setTrafficLight(1, INIT);
	MODE = mode;
	setTimer(2, 25);
}

void displayMode(int mode, int duration){
	displayUART(mode, duration);
}

void fsm_manual_run(){
	switch(MODE){
		case AUTO_MODE:
			if (isButtonPressed(0)){
				tempDuration = RED_DURATION;
				changeMode(RED_MODE, EDIT_MODE);
			}
			break;
		case RED_MODE:
			displayMode(RED_MODE, tempDuration);
			if (isButtonPressed(0)){
				tempDuration = YELLOW_DURATION;
				changeMode(AMBER_MODE, EDIT_MODE);
			}
			if (isButtonPressed(1)){
				tempDuration++;
				if (tempDuration == 100) tempDuration = 1;
			}
			if (isButtonPressed(2)){
				RED_DURATION = tempDuration;
			}
			if (timer_flag[2]){
				toggleLight(0, RED_MODE);
				toggleLight(1, RED_MODE);
				setTimer(2, 25);
			}
			break;
		case AMBER_MODE:
			displayMode(AMBER_MODE, tempDuration);
			if (isButtonPressed(0)){
				tempDuration = GREEN_DURATION;
				changeMode(GREEN_MODE, EDIT_MODE);
			}
			if (isButtonPressed(1)){
				tempDuration++;
				if (tempDuration == 100) tempDuration = 1;
			}
			if (isButtonPressed(2)){
				YELLOW_DURATION = tempDuration;
			}
			if (timer_flag[2]){
				toggleLight(0, AMBER_MODE);
				toggleLight(1, AMBER_MODE);
				setTimer(2, 25);
			}
			break;
		case GREEN_MODE:
			displayMode(GREEN_MODE, tempDuration);
			if (isButtonPressed(0)){
				changeMode(AUTO_MODE, INIT);
			}
			if (isButtonPressed(1)){
				tempDuration++;
				if (tempDuration == 100) tempDuration = 1;
			}
			if (isButtonPressed(2)){
				GREEN_DURATION = tempDuration;
			}
			if (timer_flag[2]){
				toggleLight(0, GREEN_MODE);
				toggleLight(1, GREEN_MODE);
				setTimer(2, 25);
			}
			break;
		default:
			 break;
	}
}
