/*
 * traffic_light.h
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "global.h"

void setTrafficLight(int lane, int light);

void toggleLight(int lane, int light);

void display7SEG(int type, int num);

#endif /* INC_TRAFFIC_LIGHT_H_ */
