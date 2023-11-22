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
uint16_t BIT [16] = {BIT0_Pin, BIT1_Pin, BIT2_Pin, BIT3_Pin, BIT4_Pin,
		BIT5_Pin, BIT6_Pin, BIT7_Pin, BIT8_Pin, BIT9_Pin, BIT10_Pin,
		BIT11_Pin, BIT12_Pin, BIT13_Pin, BIT14_Pin, BIT15_Pin};


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

void displaySEG(int bit, uint16_t type){
	GPIO_TypeDef *GPIO = (bit >= 9)? GPIOB : GPIOA;
	HAL_GPIO_WritePin(GPIO, BIT[bit], type);
}

void display7SEG(int type, int num){
	switch(num){
		case 0:
			displaySEG(type*4, RESET);
			displaySEG(type*4+1, RESET);
			displaySEG(type*4+2, RESET);
			displaySEG(type*4+3, RESET);
			break;
		case 1:
			displaySEG(type*4, SET);
			displaySEG(type*4+1, RESET);
			displaySEG(type*4+2, RESET);
			displaySEG(type*4+3, RESET);
			break;
		case 2:
			displaySEG(type*4, RESET);
			displaySEG(type*4+1, SET);
			displaySEG(type*4+2, RESET);
			displaySEG(type*4+3, RESET);
			break;
		case 3:
			displaySEG(type*4, SET);
			displaySEG(type*4+1, SET);
			displaySEG(type*4+2, RESET);
			displaySEG(type*4+3, RESET);
			break;
		case 4:
			displaySEG(type*4, RESET);
			displaySEG(type*4+1, RESET);
			displaySEG(type*4+2, SET);
			displaySEG(type*4+3, RESET);
			break;
		case 5:
			displaySEG(type*4, SET);
			displaySEG(type*4+1, RESET);
			displaySEG(type*4+2, SET);
			displaySEG(type*4+3, RESET);
			break;
		case 6:
			displaySEG(type*4, RESET);
			displaySEG(type*4+1, SET);
			displaySEG(type*4+2, SET);
			displaySEG(type*4+3, RESET);
			break;
		case 7:
			displaySEG(type*4, SET);
			displaySEG(type*4+1, SET);
			displaySEG(type*4+2, SET);
			displaySEG(type*4+3, RESET);
			break;
		case 8:
			displaySEG(type*4, RESET);
			displaySEG(type*4+1, RESET);
			displaySEG(type*4+2, RESET);
			displaySEG(type*4+3, SET);
			break;
		case 9:
			displaySEG(type*4, SET);
			displaySEG(type*4+1, RESET);
			displaySEG(type*4+2, RESET);
			displaySEG(type*4+3, SET);
			break;
		default:
			displaySEG(type*4, RESET);
			displaySEG(type*4+1, RESET);
			displaySEG(type*4+2, RESET);
			displaySEG(type*4+3, SET);
			break;
	}
}
