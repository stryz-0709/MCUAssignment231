/*
 * sched.h
 *
 *  Created on: 28 Nov 2023
 *      Author: khanh
 */

#ifndef INC_SCHED_H_
#define INC_SCHED_H_

#include "global.h"
#include <stdio.h>
typedef void (*CALLBACK)(void);


typedef struct {
	CALLBACK callback ;

	uint32_t delay ;
	uint32_t period ;
	uint8_t runMe; //timer flag

	uint32_t TaskID ;
} sTask ;

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

void SCH_Init(void);
void SCH_Update(void);
void SCH_Add_Task( CALLBACK callback ,
							unsigned int delay,
							unsigned int period);
void SCH_Dispatcher_Tasks(void);
void SCH_Delete_Task(uint32_t TASK_INDEX);

void SCH_Report_Status (void);
#endif /* INC_SCHED_H_ */
