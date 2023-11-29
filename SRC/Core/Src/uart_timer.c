/*
 * uart_timer.c
 *
 *  Created on: Nov 28, 2023
 *      Author: minht
 */

#include "uart_timer.h"
char str[20];

void displayUART(int mode, int num){
	switch (mode){
		case AUTO_MODE:
			if (num != 0) HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!7SEG=%d#\n\r", num), 1000);
			break;
		case RED_MODE:
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!RED=%d#\n\r", num), 1000);
			break;
		case AMBER_MODE:
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!AMBER=%d#\n\r", num), 1000);
			break;
		case GREEN_MODE:
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!GREEN=%d#\n\r", num), 1000);
			break;
		case SAVED:
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!SAVED#\n\r"), 1000);
			break;
		default:
			break;
	}



}
