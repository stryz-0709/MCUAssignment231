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
		case AUTO_MODE:
			//TODO


			if (isButtonPressed(3)){
				changePedMode(PED_MODE);
			}
			break;
		case PED_MODE:
			//TODO

			if (isButtonPressed(3)){
				changePedMode(AUTO_MODE);
			}
			break;
		default:
			break;
	}
}
