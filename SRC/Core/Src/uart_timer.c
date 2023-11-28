/*
 * uart_timer.c
 *
 *  Created on: Nov 28, 2023
 *      Author: minht
 */

#include "uart_timer.h"
char* str;

void displayUART(int mode, int num){
	switch (mode){
	case AUTO_MODE:
		//TODO
		HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!7SEG=%d#\n\r", num), 12);
		break;
	case RED_MODE:
		//TODO
		HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!RED=%d#\n\r", num), 12);
		break;
	case AMBER_MODE:
		//TODO
		HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!AMBER=%d#\n\r", num), 12);

		break;
	case GREEN_MODE:
		//TODO
		HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!GREEN=%d#\n\r", num), 12);

		break;
	}



}
