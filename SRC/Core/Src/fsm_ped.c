/*
 * fsm_ped.c
 *
 *  Created on: 27 Nov 2023
 *      Author: minht
 */

#include "fsm_ped.h"

void changePedMode(int mode, int state){
	LED_STATE[0] = state;
	LED_STATE[1] = state;
	setTrafficLightDefault(0);
	setTrafficLightDefault(1);
	TRAFFIC_MODE = mode;
	MODE = mode;
}

void fsm_ped_run(){
	switch(TRAFFIC_MODE){
		case AUTO_MODE:
			//TODO


			if (isButtonPressed(3)){
				changePedMode(PED_MODE, EDIT_STATE);
			}
			break;
		case PED_MODE:
			//TODO


			if (isButtonPressed(3)){
				changePedMode(AUTO_MODE, INIT_STATE);
			}
			break;
		default:
			break;
	}
}
