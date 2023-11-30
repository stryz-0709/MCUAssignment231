/*
 * fsm_manual.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include <fsm_manual.h>

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
	setTrafficLight(0, OFF);
	setTrafficLight(1, OFF);
	setTrafficLight(2, OFF);

	//Update mode
	TRAFFIC_MODE = mode;
	PED_MODE = ledMode;

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
	toggleLight(2, mode);
	setTimer(3, 25);
}


//Check and update duration so that RED = GREEN + AMBER
void checkDuration(int mode){
	int lane = GREEN_DURATION + AMBER_DURATION;
	switch (mode){
	case RED:
		if (lane != RED) GREEN_DURATION = RED_DURATION - AMBER_DURATION;
		break;
	case AMBER:
		if (lane != RED) RED_DURATION = GREEN_DURATION + AMBER_DURATION;
		break;
	case GREEN:
		if (lane != RED) RED_DURATION = GREEN_DURATION + AMBER_DURATION;
		break;
	}
}

void fsm_manual_run(){
	switch(TRAFFIC_MODE){
		case AUTO:
			//Change mode
			if (isButtonPressed(0)){
				changeMode(MANUAL, 0, INIT);
				displayUART(MANUAL, tempDuration);
			}
			break;

		case MANUAL:
			//Change mode
			if (isButtonPressed(0)){
				changeMode(RED, RED_DURATION, OFF);
				displayUART(TUNING, tempDuration);
			}
			break;

		case RED:
			//Change mode
			if (isButtonPressed(0)) changeMode(AMBER, AMBER_DURATION, OFF);

			//Change duration
			if (isButtonPressed(1))	changeDuration(RED);

			//Save duration
			if (isButtonPressed(2)){
				RED_DURATION = tempDuration;
				checkDuration(RED);
				displayUART(SAVED, tempDuration);
			}

			//Toggle lights
			if (timer_flag[3]) toggle(RED);
			break;

		case AMBER:
			//Change mode
			if (isButtonPressed(0)) changeMode(GREEN, GREEN_DURATION, OFF);

			//Change duration
			if (isButtonPressed(1))	changeDuration(AMBER);

			//Save duration
			if (isButtonPressed(2)){
				AMBER_DURATION = tempDuration;
				checkDuration(AMBER);
				displayUART(SAVED, tempDuration);
			}

			//Toggle lights
			if (timer_flag[3]) toggle(AMBER);
			break;

		case GREEN:
			//Change mode
			if (isButtonPressed(0)){
				changeMode(AUTO, 0, INIT);
				displayUART(AUTO, tempDuration);
			}

			//Change duration
			if (isButtonPressed(1)) changeDuration(GREEN);

			//Save duration
			if (isButtonPressed(2)){
				GREEN_DURATION = tempDuration;
				checkDuration(GREEN);
				displayUART(SAVED, tempDuration);
			}

			//Toggle lights
			if (timer_flag[3]) toggle(GREEN);
			break;

		default:
			 break;
	}
}
