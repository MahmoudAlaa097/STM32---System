/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	26 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#define NULL	(void*)0

/* Task Definition */
typedef struct{
	u16	Periodicity;
	void (*Fptr)(void);
	u8	FirstDelay;
	u8	State;
}Task;



/* Private Functions Prototypes */
static void Scheduler(void);

#endif
