/*
 * global.h
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "traffic_light.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "fsm_ped.h"
#include "uart_timer.h"

//First state of fsm_automatic
#define INIT 1

#define AUTO_MODE 11 //To make fsm_automatic run
#define EDIT_MODE 12 //To make fsm_automatic stop working
//#define PED_MODE 13  //To add pedestrian light

//Three modes for light, reusable
#define RED_MODE 21
#define AMBER_MODE 22
#define GREEN_MODE 23


extern int LED_MODE [3];

//For tuning traffic lights
extern int MODE; //AUTO_MODE, EDIT_MODE

//To add pedestrian light and buzzer
extern int TRAFFIC_MODE;

//Light duration
extern int RED_DURATION;
extern int YELLOW_DURATION;
extern int GREEN_DURATION;

#endif /* INC_GLOBAL_H_ */
