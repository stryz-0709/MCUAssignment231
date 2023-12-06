/*
 * fsm_ped.c
 *
 *  Created on: 27 Nov 2023
 *      Author: minht
 */

#include "fsm_ped.h"
#include <math.h>

void turnPedLed(int mode){
	if (mode == 1){
		setTimer(2, timer_counter[0]);
		LED_MODE[2] = LED_MODE[0];
	}
	else{
		LED_MODE[2] = OFF;
		setTrafficLight(2, OFF);
	}
}

void buzzer(int val1, int val2) {
	__HAL_TIM_SET_AUTORELOAD(&htim3, 5*val1);
	__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0.6 * (5*val2));
}

int localVal = MAX;

void fsm_ped_run(){
	switch(PED_MODE){
		case INIT:
			if (PED == 1){
				turnPedLed(PED);
				PED_MODE = AUTO;
			}
			else {
				turnPedLed(PED);
				PED_MODE = OFF;
			}
			setTimer(5,100);
			break;

		//Off mode
		case OFF:
			//TODO
			__HAL_TIM_SET_AUTORELOAD(&htim3, 5*localVal);
			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0.6 * (5*0));
			localVal = MAX;
			if (isButtonPressed(3)){
				//Change mode
				if (TRAFFIC_MODE == AUTO){
					//Mimic lane 0 light
					turnPedLed(1);
					setTimer(4,(int)(ceil((GREEN_DURATION + AMBER_DURATION)*100/3)));
					PED = 1;
					PED_MODE = AUTO;
				}
			}
			break;

		//On mode
		case AUTO:
			//TODO
				if (timer_flag[4]){
					if (LED_MODE[2] != RED){
						__HAL_TIM_SET_AUTORELOAD(&htim3, 5*localVal);
						__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0.6 * (5*localVal));
						localVal = localVal - MAX/3;
						if (localVal < 0 ){
							localVal = MAX;
						}
					}
				}
				if (timer_flag[4]) setTimer(4,(int)(ceil((GREEN_DURATION + AMBER_DURATION)*100/3)));
				if (LED_MODE[2] == RED){
					localVal = MAX;
					__HAL_TIM_SET_AUTORELOAD(&htim3, 5*localVal);
					__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0.6 * (5*0));
				}

//			}
//			else{
//				__HAL_TIM_SET_AUTORELOAD(&htim3, 5*localVal);
//				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1, 0.6 * (5*0));
//				localVal = MAX;
//				setTimer(5,100);
//			}


			//Implement buzzer here
			if (isButtonPressed(3)){
				//Turn off ped light
				turnPedLed(0);

				//Change mode
				PED = 0;
				PED_MODE = OFF;
			}
			break;
		default:
			break;
	}
}
