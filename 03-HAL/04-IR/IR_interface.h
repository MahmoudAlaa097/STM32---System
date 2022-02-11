/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	25 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/

#ifndef	IR_INTERFACE_H
#define	IR_INTERFACE_H

/* RCC must be intialized to be 8 MHZ (HSE_Crystal)*/
/* STK clock source must be AHB/8 = 1 MHZ		   */

/* Functions Pprototypes */
void HIR_voidInit(void);
void HIR_voidGetFrame(void);

#endif