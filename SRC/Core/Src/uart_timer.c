/*
 * uart_timer.c
 *
 *  Created on: Nov 28, 2023
 *      Author: minht
 */

#include "uart_timer.h"
char str[100];

#define ASCII_ESC 27

void displayUART(int mode, int num0, int num1, int led0, int led1, int led2, int pedLed){
	char* curMode0 = (led0 == RED)? "RED" : (led0 == AMBER)? "AMBER" : "GREEN";
	char* curMode1 = (led1 == RED)? "RED" : (led1 == AMBER)? "AMBER" : "GREEN";
	char* curMode2 = (led2 == RED)? "RED" : "GREEN";
	switch (mode){
		case COUNTDOWN:
			if (num0 != 0 && num1 != 0){
				HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "%c[2J", 0x1b), 100);
				HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "%c[0;0H", 0x1b), 100);
				HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "Lane 0: %s\n\rCountdown: %d\n\r", curMode0, num0), 100);
				HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "Lane 1: %s\n\rCountdown: %d\n\r", curMode1, num1), 100);
				if (pedLed == AUTO){
					int num2 = (led0 == GREEN)? num0 + 2: num0;
					HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "Ped light: %s\n\rCountdown: %d\n\r", curMode2, num2), 100);
				}
			}
			break;
		case RED:
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "%c[2J", 0x1b), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "%c[0;0H", 0x1b), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!TUNING#\n\r"), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!RED=%d#\n\r", num0), 100);
			break;
		case AMBER:
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "%c[2J", 0x1b), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "%c[0;0H", 0x1b), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!TUNING#\n\r"), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!AMBER=%d#\n\r", num0), 100);
			break;
		case GREEN:
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "%c[2J", 0x1b), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "%c[0;0H", 0x1b), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!TUNING#\n\r"), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!GREEN=%d#\n\r", num0), 100);
			break;
		case SAVED:
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!SAVED#\n\r"), 100);
			break;
		case MANUAL:
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "%c[2J", 0x1b), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "%c[0;0H", 0x1b), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!MANUAL#\n\r"), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "Lane 0: %s\n\r", curMode0), 100);
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "Lane 1: %s\n\r", curMode1), 100);
			break;
		case AUTO:
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "!AUTO#\n\r"), 100);
			break;
		case DEBUGGER:
			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "Countdown: %d\n\r", num0), 100);
//			HAL_UART_Transmit(&huart2, (void*) str, sprintf(str, "Countdown: %d\n\r", num1), 100);
			break;
		default:
			break;
	}



}
