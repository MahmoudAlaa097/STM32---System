/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	15 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/

#ifndef	STK_INTERFACE_H
#define	STK_INTERFACE_H

/* Functions Prototypes */
void MSTK_voidInit(void);														/* Apply clock choice, Disable SysTick and Disable SysTick Interrupt 	 */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);									/* Load value and wait till the overflow (delay)					 	 */
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void));		/* Load value and do some function once when the overflow happens	 	 */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void));	/* Load value and do some function periodiclly when the overflow happens */
void MSTK_voidStopTimer(void);													/* Stop the timer 														 */
u32	MSTK_u32GetElapsedTime(void);												/* Returns Elapsed time 												 */	
u32	MSTK_u32GetRemaningTime(void);												/* Returns remaining time												 */

#endif
