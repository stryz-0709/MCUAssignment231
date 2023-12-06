/*
 * fsm_manual.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include <fsm_manual.h>

int tempDuration = 0;

int LIGHT[8] = {RED, RED, GREEN, AMBER, GREEN, AMBER, RED, RED};
int manualMode[2] = {0, 4};

void manualPlus(int lane){
	manualMode[lane] += 1;
	if (manualMode[lane] > (lane+1)*4-1) manualMode[lane] = lane*4;
	LED_MODE[lane] = LIGHT[manualMode[lane]];
}

void manualMinus(int lane){
	manualMode[lane] -= 1;
	if (manualMode[lane] < lane*4) manualMode[lane] = (lane+1)*4-1;
	LED_MODE[lane] = LIGHT[manualMode[lane]];
}


void display(int mode, int duration){
	displayUART(mode, duration, 0, 0, 0, 0, 0);
}

//Change mode
void changeMode(int mode, int duration, int ledMode){
	//Display duration
	display(mode, duration);
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
	display(mode, tempDuration);
}


//Toggle Lights
void toggle(int mode){
	toggleLight(0, mode);
	toggleLight(1, mode);
	toggleLight(2, mode);
	setTimer(3, 25);
}


void displayCountdown(){
	if (timer_counter[0] % 100 == 0 && timer_counter[1] % 100 == 0){
		displayUART(COUNTDOWN, timer_counter[0] / 100, timer_counter[1] / 100, LED_MODE[0], LED_MODE[1], LED_MODE[2], PED_MODE);
	}
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
			displayCountdown();
			if (isButtonPressed(0)){
				changeMode(MANUAL, 0, INIT);
				displayUART(MANUAL, 0, 0, LIGHT[manualMode[0]], LIGHT[manualMode[1]], 0, 0);
			}
			break;

		case MANUAL:
			//Change mode
			if (isButtonPressed(0)){
				changeMode(RED, RED_DURATION, OFF);
			}

			if (isButtonPressed(1)){
				manualPlus(0);
				manualPlus(1);
				displayUART(MANUAL, 0, 0, LIGHT[manualMode[0]], LIGHT[manualMode[1]], 0, 0);
			}
			if (isButtonPressed(2)){
				manualMinus(0);
				manualMinus(1);
				displayUART(MANUAL, 0, 0, LIGHT[manualMode[0]], LIGHT[manualMode[1]], 0, 0);
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
				display(SAVED, tempDuration);
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
				display(SAVED, tempDuration);
			}

			//Toggle lights
			if (timer_flag[3]) toggle(AMBER);
			break;

		case GREEN:
			//Change mode
			if (isButtonPressed(0))	changeMode(AUTO, 0, INIT);

			//Change duration
			if (isButtonPressed(1)) changeDuration(GREEN);

			//Save duration
			if (isButtonPressed(2)){
				GREEN_DURATION = tempDuration;
				checkDuration(GREEN);
				display(SAVED, tempDuration);
			}

			//Toggle lights
			if (timer_flag[3]) toggle(GREEN);
			break;

		default:
			 break;
	}
}
