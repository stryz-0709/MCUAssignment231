/*
 * traffic_light.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "traffic_light.h"

uint16_t D_Pin[4] = {D2_Pin, D3_Pin, D4_Pin, D5_Pin};
GPIO_TypeDef *D_Port[4] = {D2_GPIO_Port, D3_GPIO_Port, D4_GPIO_Port, D5_GPIO_Port};
//uint16_t AMBERLIGHT [2] = {YELLOW1_Pin, YELLOW2_Pin};
//uint16_t BIT [16] = {BIT0_Pin, BIT1_Pin, BIT2_Pin, BIT3_Pin, BIT4_Pin,
//		BIT5_Pin, BIT6_Pin, BIT7_Pin, BIT8_Pin, BIT9_Pin, BIT10_Pin,
//		BIT11_Pin, BIT12_Pin, BIT13_Pin, BIT14_Pin, BIT15_Pin};


void setTrafficLightDefault(int lane){
	HAL_GPIO_WritePin(D_Port[lane*2], D_Pin[lane*2], RESET);
	HAL_GPIO_WritePin(D_Port[lane*2+1], D_Pin[lane*2+1], RESET);
}

void setTrafficLightRed(int lane){
	HAL_GPIO_WritePin(D_Port[lane*2], D_Pin[lane*2], SET);
	HAL_GPIO_WritePin(D_Port[lane*2+1], D_Pin[lane*2+1], RESET);
}

void setTrafficLightGreen(int lane){
	HAL_GPIO_WritePin(D_Port[lane*2], D_Pin[lane*2], RESET);
	HAL_GPIO_WritePin(D_Port[lane*2+1], D_Pin[lane*2+1], SET);
}
void setTrafficLightAmber(int lane){
	HAL_GPIO_WritePin(D_Port[lane*2], D_Pin[lane*2], SET);
	HAL_GPIO_WritePin(D_Port[lane*2+1], D_Pin[lane*2+1], SET);
}

//void displaySEG(int bit, uint16_t type){
//	GPIO_TypeDef *GPIO = (bit >= 9)? GPIOB : GPIOA;
//	HAL_GPIO_WritePin(GPIO, BIT[bit], type);
//}

//void display7SEG(int type, int num){
//	switch(num){
//		case 0:
//			displaySEG(type*4, RESET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 1:
//			displaySEG(type*4, SET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 2:
//			displaySEG(type*4, RESET);
//			displaySEG(type*4+1, SET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 3:
//			displaySEG(type*4, SET);
//			displaySEG(type*4+1, SET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 4:
//			displaySEG(type*4, RESET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, SET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 5:
//			displaySEG(type*4, SET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, SET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 6:
//			displaySEG(type*4, RESET);
//			displaySEG(type*4+1, SET);
//			displaySEG(type*4+2, SET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 7:
//			displaySEG(type*4, SET);
//			displaySEG(type*4+1, SET);
//			displaySEG(type*4+2, SET);
//			displaySEG(type*4+3, RESET);
//			break;
//		case 8:
//			displaySEG(type*4, RESET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, SET);
//			break;
//		case 9:
//			displaySEG(type*4, SET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, SET);
//			break;
//		default:
//			displaySEG(type*4, RESET);
//			displaySEG(type*4+1, RESET);
//			displaySEG(type*4+2, RESET);
//			displaySEG(type*4+3, SET);
//			break;
//	}
//}
