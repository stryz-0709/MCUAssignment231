/*
 * software_timer.c
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */


#include "software_timer.h"

int timer_counter [3] = {0,0,0};
int timer_flag [3] = {0,0,0};

void setTimer(int type, int duration){
	timer_counter[type] = duration;
	timer_flag[type] = 0;
}

void timerRun(){
	if(timer_counter[0] > 0){
		timer_counter[0]--;
		if(timer_counter[0] <= 0){
			timer_flag[0] = 1;
		}
	}
	if(timer_counter[1] > 0){
		timer_counter[1]--;
		if(timer_counter[1] <= 0){
			timer_flag[1] = 1;
		}
	}
	if(timer_counter[2] > 0){
		timer_counter[2]--;
		if(timer_counter[2] <= 0){
			timer_flag[2] = 1;
		}
	}
}
