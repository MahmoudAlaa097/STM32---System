/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	14 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* Functions Prototypes */
void MEXTI_voidInit();							/* Initialize EXTI line and mode */
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode);
void MEXTI_voidSetCallBack(void (*Copy_ptr)(void));

/* Lines */
#define		EXTI_LINE0		     0
#define		EXTI_LINE1           1
#define		EXTI_LINE2           2
#define		EXTI_LINE3           3
#define		EXTI_LINE4           4
#define		EXTI_LINE5           5
#define		EXTI_LINE6           6
#define		EXTI_LINE7           7
#define		EXTI_LINE8           8
#define		EXTI_LINE9           9
#define		EXTI_LINE10          10
#define		EXTI_LINE11          11
#define		EXTI_LINE12          12
#define		EXTI_LINE13          13
#define		EXTI_LINE14          14
#define		EXTI_LINE15			 15

/* Modes */
#define		RISING			0
#define		FALLING			1
#define		ON_CHANGE		2

#endif
