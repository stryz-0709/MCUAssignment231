/*
 * fsm_ped.c
 *
 *  Created on: 27 Nov 2023
 *      Author: minht
 */

#include "fsm_ped.h"

void changePedMode(int mode){
	TRAFFIC_MODE = mode;
}

void fsm_ped_run(){
	switch(TRAFFIC_MODE){
		case EDIT_MODE:
			//TODO


			if (isButtonPressed(3)){
				setTimer(2, timer_counter[0]);
				LED_MODE[2] = LED_MODE[0];
				changePedMode(AUTO_MODE);
			}
			break;
		case AUTO_MODE:
			//TODO

			if (isButtonPressed(3)){
				LED_MODE[2] = EDIT_MODE;
				setTrafficLight(2, INIT);
				changePedMode(EDIT_MODE);
			}
			break;
		default:
			break;
	}
}
