/*
 * fsm_automatic.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_automatic.h"

//void show_time(int lane){
//	if (timer_counter[lane] % 100 == 0){
//		int remaining_time = timer_counter[lane] / 100;
//		display7SEG(lane*2, remaining_time % 10);
//		display7SEG(lane*2+1, (int) (remaining_time / 10));
//	}
//}

void fsm_automatic_run(int lane){
	switch(LED_STATE[lane]){
		case INIT_STATE:
			setTrafficLightDefault(lane);
			if (lane == 0){
				LED_STATE[lane] = RED_STATE;
				setTimer(lane, RED_DURATION*100);
			}
			else{
				LED_STATE[lane] = GREEN_STATE;
				setTimer(lane, GREEN_DURATION*100);
			}
			break;
		case RED_STATE:
//			show_time(lane);
			setTrafficLightRed(lane);
			if(timer_flag[lane]){
				LED_STATE[lane] = GREEN_STATE;
				setTimer(lane, GREEN_DURATION*100);
			}
			break;
		case GREEN_STATE:
//			show_time(lane);
			setTrafficLightGreen(lane);
			if(timer_flag[lane]){
				LED_STATE[lane] = YELLOW_STATE;
				setTimer(lane, YELLOW_DURATION*100);
			}
			break;
		case YELLOW_STATE:
//			show_time(lane);
			setTrafficLightAmber(lane);
			if(timer_flag[lane]){
				LED_STATE[lane] = RED_STATE;
				setTimer(lane, RED_DURATION*100);
			}
			break;
		case EDIT_STATE:
			break;
		default:
			break;
	}
}
