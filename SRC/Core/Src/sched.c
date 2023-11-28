/*
 * sched.c
 *
 *  Created on: 28 Nov 2023
 *      Author: khanh
 */

#include "sched.h"


#include "sched.h"

sTask SCH_tasks_G[SCH_MAX_TASKS] ;
uint8_t current_index_task = 0;

void SCH_Init(void)
{
	current_index_task = 0;
}

void SCH_Update(void)
{
	for(int i = 0; i < current_index_task; i++)
	{
		if(SCH_tasks_G[i].delay > 0)
		{
			SCH_tasks_G[i].delay --;
		}
		else
		{
			SCH_tasks_G[i].delay = SCH_tasks_G[i].period;
			SCH_tasks_G[i].runMe += 1;
		}
	}
}


void SCH_Add_Task( CALLBACK callback ,
							unsigned int delay,
							unsigned int period)
{
	if(current_index_task < SCH_MAX_TASKS)
	{
		SCH_tasks_G[current_index_task].callback = callback;
		SCH_tasks_G[current_index_task].delay = delay;
		SCH_tasks_G[current_index_task].period = period;
		SCH_tasks_G[current_index_task].runMe = 0;
		SCH_tasks_G[current_index_task].TaskID = current_index_task;

		current_index_task++;
	}
}
void SCH_Dispatcher_Tasks(void)
{
	for(int i = 0; i < current_index_task; i++)
	{
		if(SCH_tasks_G[i].runMe > 0)
		{
			SCH_tasks_G[i].runMe --;
			SCH_tasks_G[i].callback();
		}
	}
}
void SCH_Delete_Task(uint32_t TASK_INDEX)
{
	//implement the delete task
}

void SCH_Report_Status ( void )
{
	# ifdef SCH_REPORT_ERRORS
	// ONLY APPLIES IF WE ARE REPORTING ERRORS
	// Check for a new error code
	if ( Error_code_G != Last_error_code_G )
	{
		// Negative logic on LEDs assumed
		Error_port = 255 − Error_code_G ;
		Last_error_code_G = Error_code_G ;

		if ( Error_code_G != 0)
		{
			Error_tick_count_G = 60000;
		}
		else
		{
			Error_tick_count_G = 0;
		}
	}
	else
	{
		if ( Error_tick_count_G != 0)
		{
			if (−−Error_tick_count_G == 0)
			{
				Error_code_G = 0; // Reset error code
			}
		}
	}
	#endif
}
