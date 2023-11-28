/*
 * button.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "button.h"

int button_flag [4] = {0, 0, 0, 0};

GPIO_TypeDef *BUTTON_PORT [4] = {BUTTON1_GPIO_Port, BUTTON2_GPIO_Port, BUTTON3_GPIO_Port, Ped_BUTTON_GPIO_Port};
uint16_t BUTTON_PIN [4] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin, Ped_BUTTON_Pin};

int KeyReg0 [4] = {NORMAL_STATE};
int KeyReg1 [4] = {NORMAL_STATE};
int KeyReg2 [4] = {NORMAL_STATE};
int KeyReg3 [4] = {NORMAL_STATE};
int TimerForKeyPress [4] = {500};

int isButtonPressed(int button){
	if (button_flag[button]){
		button_flag[button] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int button){
	button_flag[button] = 1;
}


void getKeyInput(int button){
	KeyReg0[button] = KeyReg1[button];
	KeyReg1[button] = KeyReg2[button];
	KeyReg2[button] = HAL_GPIO_ReadPin(BUTTON_PORT[button], BUTTON_PIN[button]);
	if ((KeyReg0[button] == KeyReg1[button]) && (KeyReg1[button] == KeyReg2[button])){
		if (KeyReg3[button] != KeyReg2[button]){
			KeyReg3[button] = KeyReg2[button];
			if (KeyReg2[button] == PRESSED_STATE){
				subKeyProcess(button);
				TimerForKeyPress[button] = 500;
			}
		}
		else{
			TimerForKeyPress[button]--;
			if (TimerForKeyPress[button] <= 0){
				KeyReg3[button] = NORMAL_STATE;
			}
		}
	}
}
