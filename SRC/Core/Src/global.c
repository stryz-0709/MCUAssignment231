/*
 * global.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "global.h"

int LED_MODE [3] = {INIT, INIT, INIT};
int MODE = AUTO_MODE;
int TRAFFIC_MODE = AUTO_MODE;

int RED_DURATION = 5;
int YELLOW_DURATION = 2;
int GREEN_DURATION = 3;
