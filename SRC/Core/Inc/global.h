/*
 * global.h
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <fsm_manual.h>
#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "traffic_light.h"
#include "fsm_automatic.h"
#include "fsm_ped.h"
#include "uart_timer.h"
#include "buzzer.h"
#include <stdio.h>
#include <string.h>
#include "sched.h"

//First state of fsm_automatic
#define INIT 1

#define AUTO 11 //To make fsm_automatic run
#define OFF 12 //To make fsm_automatic stop working
#define MANUAL 13  //To add pedestrian light

//Three modes for light, reusable
#define RED 21
#define AMBER 22
#define GREEN 23

#define SAVED 31
#define TUNING 32
#define COUNTDOWN 33

extern int LED_MODE [3];

//For tuning traffic lights
extern int TRAFFIC_MODE; //AUTO_MODE, MANUAL_MODE, EDIT_MODE

//To add pedestrian light and buzzer
extern int PED_MODE;

//Light duration
extern int RED_DURATION;
extern int AMBER_DURATION;
extern int GREEN_DURATION;
extern int PED; //Remember last activation

#endif /* INC_GLOBAL_H_ */
