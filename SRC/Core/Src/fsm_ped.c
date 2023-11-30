/*
 * fsm_ped.c
 *
 *  Created on: 27 Nov 2023
 *      Author: minht
 */

#include "fsm_ped.h"

void turnPedLed(int mode){
	if (mode == 1){
		setTimer(2, timer_counter[0]);
		LED_MODE[2] = LED_MODE[0];
	}
	else{
		LED_MODE[2] = EDIT_MODE;
		setTrafficLight(2, INIT);
	}
}

void fsm_ped_run(){
	switch(TRAFFIC_MODE){
		case INIT:
			if (PED == 1){
				turnPedLed(PED);
				TRAFFIC_MODE = AUTO_MODE;
			}
			else {
				turnPedLed(PED);
				TRAFFIC_MODE = EDIT_MODE;
			}
			break;

		//Off mode
		case EDIT_MODE:
			//TODO
			if (isButtonPressed(3)){
				//Mimic lane 0 light
				turnPedLed(1);

				//Change mode
				if (MODE == AUTO_MODE){
					PED = 1;
					TRAFFIC_MODE = AUTO_MODE;
				}
			}
			break;

		//On mode
		case AUTO_MODE:
			//TODO
			//Implement buzzer here
			if (isButtonPressed(3)){
				//Turn off ped light
				turnPedLed(0);

				//Change mode
				PED = 0;
				TRAFFIC_MODE = EDIT_MODE;
			}
			break;
		default:
			break;
	}
}
