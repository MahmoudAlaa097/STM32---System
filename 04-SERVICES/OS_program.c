/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	26 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

/* Tasks Array Definition */
static Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};

void SOS_voidCreateTask(u8 Copy_u8Id,u8 Copy_u8Periodicity,void (*Copy_ptr),u8 Copy_u8FirstDelay,u8 Copy_u8State)
{
	/* Adding New Task Data to the array */
	OS_Tasks[Copy_u8Id].Periodicity = Copy_u8Periodicity;
	OS_Tasks[Copy_u8Id].Fptr 		= Copy_ptr;
	OS_Tasks[Copy_u8Id].FirstDelay 	= Copy_u8FirstDelay;
	OS_Tasks[Copy_u8Id].State 		= Copy_u8State;
}

void SOS_voidStart(void)
{
	/* Initialization */
	MSTK_voidInit();								/* SysTick Clock : AHB/8 = 1 MHz 	*/
	MSTK_voidSetIntervalPeriodic(1000,Scheduler);	/* Tick = 1 msec 					*/
	
}

static void Scheduler(void)
{
	/* Iterate over tasks array */
	for(u8 Local_u8Index=0;Local_u8Index<NUMBER_OF_TASKS;Local_u8Index++)
	{
		/* Check if task's functions exist and if task is in ready state */
		if((OS_Tasks[Local_u8Index].Fptr != NULL) && (OS_Tasks[Local_u8Index].State == READY))
		{
			/* Check if this is the time to run this task */
			if(OS_Tasks[Local_u8Index].FirstDelay == 0)
			{
				/* Set Task State to Running */
				OS_Tasks[Local_u8Index].State = RUNNING;
				/* Assign Periodicity to FirstDelay */
				OS_Tasks[Local_u8Index].FirstDelay = OS_Tasks[Local_u8Index].Periodicity-1;
				/* Call Taks's Function */
				OS_Tasks[Local_u8Index].Fptr();
				/* Set Task State to Ready */
				OS_Tasks[Local_u8Index].State = READY;
			}
			else
			{
				/* Decrement Periodicity */
				OS_Tasks[Local_u8Index].FirstDelay--;
			}
		}
	}
}

void SOS_voidSuspendTask(u8 Copy_u8Id)
{
	/* Change Task State to Suspend */
	OS_Tasks[Copy_u8Id].State = SUSPEND;
}

void SOS_voidResumeTask(u8 Copy_u8Id)
{
	/* Change Task State to Ready */
	OS_Tasks[Copy_u8Id].State = READY;
}

void SOS_voidKillTask(u8 Copy_u8Id)
{
	/* Set Task Function to NULL */
	OS_Tasks[Copy_u8Id].Fptr = NULL;
}
