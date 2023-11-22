/*
 * traffic_light.h
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
void setTrafficLightDefault(int lane);
void setTrafficLightRed(int lane);
void setTrafficLightGreen(int lane);
void setTrafficLightAmber(int lane);

void display7SEG(int type, int num);

#endif /* INC_TRAFFIC_LIGHT_H_ */
