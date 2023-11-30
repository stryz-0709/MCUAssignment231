/*
 * fsm_automatic.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_automatic.h"

int initMode[3] = {RED_MODE, GREEN_MODE, EDIT_MODE};

void displayCountdown(int lane){
	if (timer_counter[lane] % 100 == 0){
		int remaining_time = timer_counter[lane] / 100;
		displayUART(AUTO_MODE, remaining_time);
	}
}

int initDuration(int lane){
	return (lane == 1)? GREEN_DURATION : RED_DURATION;
}

void fsm_automatic_run(int lane){
	switch(LED_MODE[lane]){
		case INIT:
			//Turn off all lights
			setTrafficLight(lane, EDIT_MODE);

			//Change mode and duration
			LED_MODE[lane] = initMode[lane];
			setTimer(lane, initDuration(lane)*100);
			break;
		case RED_MODE:
			//Display countdown and turn on light
			if (lane == 0) displayCountdown(lane);
			setTrafficLight(lane, RED_MODE);


			//Timer flag to change light
			if(timer_flag[lane]){
				LED_MODE[lane] = GREEN_MODE;
				setTimer(lane, GREEN_DURATION*100);
			}
			break;
		case AMBER_MODE:
			//Display countdown and turn on light
			if (lane == 0) displayCountdown(lane);
			if (lane == 2) setTrafficLight(lane, GREEN_MODE);
			else setTrafficLight(lane, AMBER_MODE);


			//Timer flag to change light
			if(timer_flag[lane]){
				LED_MODE[lane] = RED_MODE;
				setTimer(lane, RED_DURATION*100);
			}
			break;
		case GREEN_MODE:
			//Display countdown and turn on light
			if (lane == 0) displayCountdown(lane);
			setTrafficLight(lane, GREEN_MODE);

			//Timer flag to change light
			if(timer_flag[lane]){
				LED_MODE[lane] = AMBER_MODE;
				setTimer(lane, AMBER_DURATION*100);
			}
			break;
		default:
			break;
	}
}
