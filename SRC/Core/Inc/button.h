/*
 * button.h
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
