/*
 * fsm_automatic.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_automatic.h"

void displayCountdown(int lane){
	if (timer_counter[lane] % 100 == 0){
		int remaining_time = timer_counter[lane] / 100;
		displayUART(AUTO_MODE, remaining_time % 10);
	}
}


int initMode[3] = {RED_MODE, GREEN_MODE, EDIT_MODE};
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
			setTrafficLight(lane, INIT);
			LED_MODE[lane] = initMode[lane];
			setTimer(lane, initDuration(lane)*100);
			break;
		case RED_MODE:
			if (lane == 0) displayCountdown(lane);

			setTrafficLight(lane, RED_MODE);

			if(timer_flag[lane]){
				LED_MODE[lane] = GREEN_MODE;
				setTimer(lane, GREEN_DURATION*100);
			}
			break;
		case GREEN_MODE:
			if (lane == 0) displayCountdown(lane);

			setTrafficLight(lane, GREEN_MODE);

			if(timer_flag[lane]){
				LED_MODE[lane] = AMBER_MODE;
				setTimer(lane, YELLOW_DURATION*100);
			}
			break;
		case AMBER_MODE:
			if (lane == 0) displayCountdown(lane);

			setTrafficLight(lane, AMBER_MODE);

			if(timer_flag[lane]){
				LED_MODE[lane] = RED_MODE;
				setTimer(lane, RED_DURATION*100);
			}
			break;
		case EDIT_MODE:
			break;
		default:
			break;
	}
}
