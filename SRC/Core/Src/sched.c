/*
 * sched.c
 *
 *  Created on: 28 Nov 2023
 *      Author: khanh
 */


#include "sched.h"

sTask SCH_tasks_G[SCH_MAX_TASKS] ;
uint8_t current_index_task = 0;

void SCH_Init(void)
{
	current_index_task = 0;
}


void SCH_Update(void){
	current_index_task ++;
	if (SCH_tasks_G[0].callback && SCH_tasks_G[0].runMe == 0)
	{
		if(SCH_tasks_G[0].delay > 0)
		{
			SCH_tasks_G[0].delay = SCH_tasks_G[0].delay - 1;
		}
		if (SCH_tasks_G[0].delay == 0)
		{
			SCH_tasks_G[0].runMe = 1;
		}
	}
}

uint32_t SCH_Add_Task( CALLBACK callback ,
							unsigned int delay,
							unsigned int period)
{
	uint8_t newTaskIndex = 0;
	uint32_t sumDelay = 0;
	uint32_t newDelay = 0;

	for(newTaskIndex = 0; newTaskIndex < SCH_MAX_TASKS; newTaskIndex ++)
	{
		sumDelay = sumDelay + SCH_tasks_G[newTaskIndex].delay;
		if(sumDelay > delay)
		{
			newDelay = delay - (sumDelay - SCH_tasks_G[newTaskIndex].delay);
			SCH_tasks_G[newTaskIndex].delay = sumDelay - delay;

			for(uint8_t i = SCH_MAX_TASKS - 1; i > newTaskIndex; i --)
			{
				SCH_tasks_G[i].callback = SCH_tasks_G[i - 1].callback;
				SCH_tasks_G[i].period = SCH_tasks_G[i - 1].period;
				SCH_tasks_G[i].delay = SCH_tasks_G[i - 1].delay;
				SCH_tasks_G[i].TaskID = SCH_tasks_G[i - 1].TaskID;
			}

			SCH_tasks_G[newTaskIndex].callback = callback;
			SCH_tasks_G[newTaskIndex].delay = newDelay;
			SCH_tasks_G[newTaskIndex].period = period;

			if(SCH_tasks_G[newTaskIndex].delay == 0)
			{
				SCH_tasks_G[newTaskIndex].runMe = 1;
			}
			else
			{
				SCH_tasks_G[newTaskIndex].runMe = 0;
			}

			SCH_tasks_G[newTaskIndex].TaskID = Get_New_Task_ID();

			return SCH_tasks_G[newTaskIndex].TaskID;
		}
		else
		{
			if(SCH_tasks_G[newTaskIndex].callback == 0x0000)
			{
				SCH_tasks_G[newTaskIndex].callback = callback;
				SCH_tasks_G[newTaskIndex].delay = delay - sumDelay;
				SCH_tasks_G[newTaskIndex].period = period;

				if(SCH_tasks_G[newTaskIndex].delay == 0)
				{
					SCH_tasks_G[newTaskIndex].runMe = 1;
				}
				else
				{
					SCH_tasks_G[newTaskIndex].runMe = 0;
				}

				SCH_tasks_G[newTaskIndex].TaskID = Get_New_Task_ID();
				return SCH_tasks_G[newTaskIndex].TaskID;
			}
		}
	}
	return SCH_tasks_G[newTaskIndex].TaskID;
}
void SCH_Dispatcher_Tasks(void)
{
	if(SCH_tasks_G[0].runMe > 0)
	{
		SCH_tasks_G[0].callback(); // Run the task
		SCH_tasks_G[0].runMe = 0; // Reset / reduce RunMe flag
		sTask temtask = SCH_tasks_G[0];
		SCH_Delete_Task(temtask.TaskID);

		if (temtask.period != 0)
		{
			SCH_Add_Task(temtask.callback, temtask.period, temtask.period);
		}
	}
}
uint32_t SCH_Delete_Task(uint32_t taskID)
{
	//implement the delete task
	uint8_t Return_code  = 0;
	uint8_t taskIndex;
	uint8_t j;
	if(taskID != NO_TASK_ID)
	{
		for(taskIndex = 0; taskIndex < SCH_MAX_TASKS; taskIndex ++)
		{
			if(SCH_tasks_G[taskIndex].TaskID == taskID)
			{
				Return_code = 1;
				if(taskIndex != 0 && taskIndex < SCH_MAX_TASKS - 1)
				{
					if(SCH_tasks_G[taskIndex+1].callback != 0x0000)
					{
						SCH_tasks_G[taskIndex+1].delay += SCH_tasks_G[taskIndex].delay;
					}
				}

				for( j = taskIndex; j < SCH_MAX_TASKS - 1; j ++)
				{
					SCH_tasks_G[j].callback = SCH_tasks_G[j+1].callback;
					SCH_tasks_G[j].period = SCH_tasks_G[j+1].period;
					SCH_tasks_G[j].delay = SCH_tasks_G[j+1].delay;
					SCH_tasks_G[j].runMe = SCH_tasks_G[j+1].runMe;
					SCH_tasks_G[j].TaskID = SCH_tasks_G[j+1].TaskID;
				}

				SCH_tasks_G[j].callback = 0;
				SCH_tasks_G[j].period = 0;
				SCH_tasks_G[j].delay = 0;
				SCH_tasks_G[j].runMe = 0;
				SCH_tasks_G[j].TaskID = 0;
				return Return_code;
			}
		}
	}
	return Return_code; // return status
}


int newTaskID = 0;
int Get_New_Task_ID(void)
{
	newTaskID++;
	if(newTaskID == NO_TASK_ID){
		newTaskID++;
	}
	return newTaskID;
}

#ifdef __cplusplus
}
#endif

void SCH_Report_Status ( void )
{
	# ifdef SCH_REPORT_ERRORS
	if ( Error_code_G != Last_error_code_G )
	{
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
