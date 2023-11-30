/*
 * fsm_automatic.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_automatic.h"

int initMode[3] = {RED, GREEN, OFF};

void displayCountdown(int lane){
	if (timer_counter[lane] % 100 == 0){
		int remaining_time = timer_counter[lane] / 100;
		displayUART(COUNTDOWN, remaining_time);
	}
}

int initDuration(int lane){
	return (lane == 1)? GREEN_DURATION : RED_DURATION;
}
void fsm_automatic_run0()
{
	fsm_automatic_run(0);
}

void fsm_automatic_run1()
{
	fsm_automatic_run(1);
}

void fsm_automatic_run2()
{
	fsm_automatic_run(2);
}

void fsm_automatic_run(int lane){
	switch(LED_MODE[lane]){
		case INIT:
			//Turn off all lights
			setTrafficLight(lane, OFF);

			//Change mode and duration
			LED_MODE[lane] = initMode[lane];
			setTimer(lane, initDuration(lane)*100);
			break;
		case RED:
			//Display countdown and turn on light
			if (lane == 0) displayCountdown(lane);
			setTrafficLight(lane, RED);


			//Timer flag to change light
			if(timer_flag[lane]){
				LED_MODE[lane] = GREEN;
				setTimer(lane, GREEN_DURATION*100);
			}

			if(TRAFFIC_MODE == MANUAL){
				if (isButtonPressed(1)) LED_MODE[lane] = GREEN;
				if (isButtonPressed(2)) LED_MODE[lane] = AMBER;
			}
			break;
		case AMBER:
			//Display countdown and turn on light
			if (lane == 0) displayCountdown(lane);
			if (lane == 2) setTrafficLight(lane, GREEN);
			else setTrafficLight(lane, AMBER);


			//Timer flag to change light
			if(timer_flag[lane]){
				LED_MODE[lane] = RED;
				setTimer(lane, RED_DURATION*100);
			}

			if(TRAFFIC_MODE == MANUAL){
				if (isButtonPressed(1)) LED_MODE[lane] = RED;
				if (isButtonPressed(2)) LED_MODE[lane] = GREEN;
			}
			break;
		case GREEN:
			//Display countdown and turn on light
			if (lane == 0) displayCountdown(lane);
			setTrafficLight(lane, GREEN);

			//Timer flag to change light
			if(timer_flag[lane]){
				LED_MODE[lane] = AMBER;
				setTimer(lane, AMBER_DURATION*100);
			}

			if(TRAFFIC_MODE == MANUAL){
				if (isButtonPressed(1)) LED_MODE[lane] = AMBER;
				if (isButtonPressed(2)) LED_MODE[lane] = RED;
			}
			break;
		case OFF:
			break;
		default:
			break;
	}
}
