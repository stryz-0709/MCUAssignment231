/*
 * traffic_light.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "traffic_light.h"

uint16_t REDLIGHT [2] = {RED1_Pin, RED2_Pin};
uint16_t GREENLIGHT [2] = {GREEN1_Pin, GREEN2_Pin};
uint16_t AMBERLIGHT [2] = {YELLOW1_Pin, YELLOW2_Pin};


void setTrafficLightDefault(int lane){
	HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], SET);
}

void setTrafficLightRed(int lane){
	HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], RESET);
	HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], SET);
}

void setTrafficLightGreen(int lane){
	HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], RESET);
	HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], SET);
}
void setTrafficLightAmber(int lane){
	HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], RESET);
}

