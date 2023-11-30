/*
 * traffic_light.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "traffic_light.h"

uint16_t D_Pin[6] = {D2_Pin, D3_Pin, D4_Pin, D5_Pin, Ped_LIGHT1_Pin, Ped_LIGHT2_Pin};
GPIO_TypeDef *D_Port[6] = {D2_GPIO_Port, D3_GPIO_Port, D4_GPIO_Port, D5_GPIO_Port, Ped_LIGHT1_GPIO_Port, Ped_LIGHT2_GPIO_Port};


void setTrafficLight(int lane, int light){
	switch (light){
		case RED:
			HAL_GPIO_WritePin(D_Port[lane*2], D_Pin[lane*2], SET);
			HAL_GPIO_WritePin(D_Port[lane*2+1], D_Pin[lane*2+1], RESET);
			break;
		case AMBER:
			HAL_GPIO_WritePin(D_Port[lane*2], D_Pin[lane*2], SET);
			HAL_GPIO_WritePin(D_Port[lane*2+1], D_Pin[lane*2+1], SET);
			break;
		case GREEN:
			HAL_GPIO_WritePin(D_Port[lane*2], D_Pin[lane*2], RESET);
			HAL_GPIO_WritePin(D_Port[lane*2+1], D_Pin[lane*2+1], SET);
			break;
		case OFF:
			HAL_GPIO_WritePin(D_Port[lane*2], D_Pin[lane*2], RESET);
			HAL_GPIO_WritePin(D_Port[lane*2+1], D_Pin[lane*2+1], RESET);
			break;
		default:
			break;
	}
}


void toggleLight(int lane, int light){
	switch (light){
		case RED:
			HAL_GPIO_TogglePin(D_Port[lane*2], D_Pin[lane*2]);
			HAL_GPIO_WritePin(D_Port[lane*2+1], D_Pin[lane*2+1], RESET);
			break;
		case AMBER:
			HAL_GPIO_TogglePin(D_Port[lane*2], D_Pin[lane*2]);
			HAL_GPIO_TogglePin(D_Port[lane*2+1], D_Pin[lane*2+1]);
			break;
		case GREEN:
			HAL_GPIO_WritePin(D_Port[lane*2], D_Pin[lane*2], RESET);
			HAL_GPIO_TogglePin(D_Port[lane*2+1], D_Pin[lane*2+1]);
			break;
		default:
			break;
	}
}

