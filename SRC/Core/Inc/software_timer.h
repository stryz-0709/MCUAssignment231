/*
 * software_timer.h
 *
 *  Created on: Oct 20, 2023
 *      Author: minht
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag [3];
extern int timer_counter [3];

void setTimer(int type, int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
