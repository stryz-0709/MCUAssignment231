/*
 * fsm_manual.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_manual.h"

int tempDuration = 0;

void changeMode(int mode, int duration, int ledMode){
	displayUART(mode, duration);
	tempDuration = duration;
	LED_MODE[0] = ledMode;
	LED_MODE[1] = ledMode;
	setTrafficLight(0, INIT);
	setTrafficLight(1, INIT);
	MODE = mode;
	setTimer(3, 25);
}

void changeDuration(int mode){
	tempDuration++;
	if (tempDuration == 100) tempDuration = 1;
	displayUART(mode, tempDuration);
}

void toggle(int mode){
	toggleLight(0, mode);
	toggleLight(1, mode);
	setTimer(3, 25);
}

void fsm_manual_run(){
	switch(MODE){
		case AUTO_MODE:
			if (isButtonPressed(0)) changeMode(RED_MODE, RED_DURATION, EDIT_MODE);
			break;
		case RED_MODE:
			if (isButtonPressed(0)) changeMode(AMBER_MODE, AMBER_DURATION, EDIT_MODE);
			if (isButtonPressed(1))	changeDuration(RED_MODE);
			if (isButtonPressed(2)){
				RED_DURATION = tempDuration;
				displayUART(SAVED, tempDuration);
			}
			if (timer_flag[3]) toggle(RED_MODE);
			break;
		case AMBER_MODE:
			if (isButtonPressed(0)) changeMode(GREEN_MODE, GREEN_DURATION, EDIT_MODE);
			if (isButtonPressed(1))	changeDuration(AMBER_MODE);
			if (isButtonPressed(2)){
				AMBER_DURATION = tempDuration;
				displayUART(SAVED, tempDuration);
			}
			if (timer_flag[3]) toggle(AMBER_MODE);
			break;
		case GREEN_MODE:
			if (isButtonPressed(0)) changeMode(AUTO_MODE, 0, INIT);
			if (isButtonPressed(1)) changeDuration(GREEN_MODE);
			if (isButtonPressed(2)){
				GREEN_DURATION = tempDuration;
				displayUART(SAVED, tempDuration);
			}
			if (timer_flag[3]) toggle(GREEN_MODE);
			break;
		default:
			 break;
	}
}
