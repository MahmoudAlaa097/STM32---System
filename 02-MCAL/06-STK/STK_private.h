/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	15 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/

#ifndef	STK_PRIVATE_H
#define	STK_PRIVATE_H

void (*MSTK_Callback)(void);
u8 MSTK_u8ModeOfInterval;

/* Peripheral Registers */
typedef	struct{
	volatile u32    CTRL;
	volatile u32	LOAD;
	volatile u32	VAL;
	volatile u32	CALIB;
}STK_t;

#define STK	((volatile STK_t*)0xE000E010)

/* SysTick Clock Choices */
#define MSTK_AHB				0
#define MSTK_AHB_8				1

/* STK_CTRL Bits */
#define	MSTK_EN					0
#define MSTK_INTEN				1
#define	MSTK_CLK				2
#define	MSTK_FLAG				16

/* Interval Modes */
#define MSTK_SINGLE_INTERVAL	0
#define MSTK_PERIODIC_INTERVAL	1

#endif
