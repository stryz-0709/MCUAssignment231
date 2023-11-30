/*
 * fsm_ped.c
 *
 *  Created on: 27 Nov 2023
 *      Author: minht
 */

#include "fsm_ped.h"

void fsm_ped_run(){
	switch(TRAFFIC_MODE){
		case INIT:
			if (PED == 1) TRAFFIC_MODE = AUTO_MODE;
			else TRAFFIC_MODE = EDIT_MODE;
			break;

		//Off mode
		case EDIT_MODE:
			//TODO
			if (isButtonPressed(3)){
				//Mimic lane 0 light
				setTimer(2, timer_counter[0]);
				LED_MODE[2] = LED_MODE[0];
				PED = 1;

				//Change mode
				if (MODE == AUTO_MODE) TRAFFIC_MODE = AUTO_MODE;
			}
			break;

		//On mode
		case AUTO_MODE:
			//TODO
			//Implement buzzer here
			if (isButtonPressed(3)){
				//Turn off ped light
				LED_MODE[2] = EDIT_MODE;
				setTrafficLight(2, INIT);
				PED = 0;

				//Change mode
				TRAFFIC_MODE = EDIT_MODE;
			}
			break;
		default:
			break;
	}
}
