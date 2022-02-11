/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	26 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


/* Functions Prototypes */

/* Create new task */
void SOS_voidCreateTask(u8 Copy_u8Id,u8 Copy_u8Periodicity,void (*Copy_ptr),u8 Copy_u8FirstDelay,u8 Copy_u8State);

/* Start OS */
void SOS_voidStart(void);

/* Suspend task */
void SOS_voidSuspendTask(u8 Copy_u8Id);

/* Resume suspended task */
void SOS_voidResumeTask(u8 Copy_u8Id);

/* Delete task */
void SOS_voidKillTask(u8 Copy_u8Id);

/* Tasks States */
#define	READY		0
#define	RUNNING		1
#define	WAITING		2
#define	SUSPEND		3

#endif
