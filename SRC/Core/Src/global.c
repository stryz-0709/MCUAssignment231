/*
 * global.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#include "global.h"

int LED_MODE [3] = {INIT, INIT, INIT};
int TRAFFIC_MODE = AUTO;
int PED_MODE = INIT;

int RED_DURATION = 5;
int AMBER_DURATION = 2;
int GREEN_DURATION = 3;
int PED = 0;
