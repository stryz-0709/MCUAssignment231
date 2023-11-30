/*
 * fsm_manual.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_manual.h"

int tempDuration = 0;


//Change mode
void changeMode(int mode, int duration, int ledMode){
	//Display duration
	displayUART(mode, duration);
	tempDuration = duration;

	//Change traffic lights to toggle the right color
	LED_MODE[0] = ledMode;
	LED_MODE[1] = ledMode;

	//Change ped light mode
	LED_MODE[2] = ledMode;

	//Turn off all lights
	setTrafficLight(0, INIT);
	setTrafficLight(1, INIT);
	setTrafficLight(2, INIT);

	//Update mode
	MODE = mode;
	TRAFFIC_MODE = ledMode;

	//Set timer to toggle lights
	setTimer(3, 25);
}


//Increment duration
void changeDuration(int mode){
	tempDuration++;
	if (tempDuration == 100) tempDuration = 1;

	//Display duration
	displayUART(mode, tempDuration);
}


//Toggle Lights
void toggle(int mode){
	toggleLight(0, mode);
	toggleLight(1, mode);
	setTimer(3, 25);
}


//Check and update duration so that RED = GREEN + AMBER
void checkDuration(int mode){
	int lane = GREEN_DURATION + AMBER_DURATION;
	switch (mode){
	case RED_MODE:
		if (lane != RED_MODE) GREEN_DURATION = RED_DURATION - AMBER_DURATION;
		break;
	case AMBER_MODE:
		if (lane != RED_MODE) RED_DURATION = GREEN_DURATION + AMBER_DURATION;
		break;
	case GREEN_MODE:
		if (lane != RED_MODE) RED_DURATION = GREEN_DURATION + AMBER_DURATION;
		break;
	}
}

void fsm_manual_run(){
	switch(MODE){
		case AUTO_MODE:
			//Change mode
			if (isButtonPressed(0)) changeMode(RED_MODE, RED_DURATION, EDIT_MODE);
			break;

		case RED_MODE:
			//Change mode
			if (isButtonPressed(0)) changeMode(AMBER_MODE, AMBER_DURATION, EDIT_MODE);

			//Change duration
			if (isButtonPressed(1))	changeDuration(RED_MODE);

			//Save duration
			if (isButtonPressed(2)){
				RED_DURATION = tempDuration;
				checkDuration(RED_MODE);
				displayUART(SAVED, tempDuration);
			}

			//Toggle lights
			if (timer_flag[3]) toggle(RED_MODE);
			break;

		case AMBER_MODE:
			//Change mode
			if (isButtonPressed(0)) changeMode(GREEN_MODE, GREEN_DURATION, EDIT_MODE);

			//Change duration
			if (isButtonPressed(1))	changeDuration(AMBER_MODE);

			//Save duration
			if (isButtonPressed(2)){
				AMBER_DURATION = tempDuration;
				checkDuration(AMBER_MODE);
				displayUART(SAVED, tempDuration);
			}

			//Toggle lights
			if (timer_flag[3]) toggle(AMBER_MODE);
			break;

		case GREEN_MODE:
			//Change mode
			if (isButtonPressed(0)) changeMode(AUTO_MODE, 0, INIT);

			//Change duration
			if (isButtonPressed(1)) changeDuration(GREEN_MODE);

			//Save duration
			if (isButtonPressed(2)){
				GREEN_DURATION = tempDuration;
				checkDuration(GREEN_MODE);
				displayUART(SAVED, tempDuration);
			}

			//Toggle lights
			if (timer_flag[3]) toggle(GREEN_MODE);
			break;

		default:
			 break;
	}
}
