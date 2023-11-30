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
		LED_MODE[2] = OFF;
		setTrafficLight(2, OFF);
	}
}

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
			break;

		//Off mode
		case OFF:
			//TODO
			if (isButtonPressed(3)){
				//Mimic lane 0 light
				turnPedLed(1);

				//Change mode
				if (TRAFFIC_MODE == AUTO){
					PED = 1;
					PED_MODE = AUTO;
				}
			}
			break;

		//On mode
		case AUTO:
			//TODO
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
