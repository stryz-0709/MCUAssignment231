/*
 * fsm_automatic.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "fsm_automatic.h"

int initMode[3] = {RED, GREEN, OFF};


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

//void buzzer(int val1, int val2) {
//	__HAL_TIM_SET_AUTORELOAD(&htim3, 5*val1);
//	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0.6 * (5*val2));
//}

void fsm_automatic_run(int lane){
	switch(LED_MODE[lane]){
		case INIT:
			//Turn off all lights
			setTrafficLight(lane, OFF);
			val = MAX;

			//Change mode and duration
			LED_MODE[lane] = initMode[lane];
			setTimer(lane, initDuration(lane)*100);

			break;
		case RED:
			setTrafficLight(lane, RED);
			val = MAX;
//			buzzer(val, 0);

			//Timer flag to change light
			if(timer_flag[lane] && TRAFFIC_MODE != MANUAL){
				LED_MODE[lane] = GREEN;
//				if (lane == 2) setTimer(lane, (GREEN_DURATION+AMBER_DURATION)*100);
				setTimer(lane, GREEN_DURATION*100);
//				setTimer(5,10);
			}
			break;
		case AMBER:
			if (lane == 2){
				setTrafficLight(lane, GREEN);
//				if (timer_flag[lane] % 100 == 0){
//					buzzer(val, val);
//					val = val - MAX/(GREEN_DURATION + AMBER_DURATION - 1);
//				}

			}
			else setTrafficLight(lane, AMBER);
//				buzzer(val, 0);



			//Timer flag to change light
			if(timer_flag[lane] && TRAFFIC_MODE != MANUAL){
				LED_MODE[lane] = RED;
				setTimer(lane, RED_DURATION*100);
			}


			break;
		case GREEN:

			setTrafficLight(lane, GREEN);
			if (lane == 2){
//				if (timer_flag[lane] % 100 == 0){
//					buzzer(val, val);
//					val = val - MAX/(GREEN_DURATION + AMBER_DURATION - 1);
//				}

			}
//			else buzzer(val, 0);

			//Timer flag to change light

			if(timer_flag[lane] && TRAFFIC_MODE != MANUAL){
//				if (lane == 2){
//					LED_MODE[lane] = RED;
//					setTimer(lane, RED_DURATION*100);
//				}
//				else {
					LED_MODE[lane] = AMBER;
					setTimer(lane, AMBER_DURATION*100);
//				}

			}

//			if(TRAFFIC_MODE == MANUAL){
//				if (isButtonPressed(1)) LED_MODE[lane] = AMBER;
//				if (isButtonPressed(2)) LED_MODE[lane] = RED;
//			}
			break;
		case OFF:
			stopBuzzer(RED);
			break;
		default:
			break;
	}
}
