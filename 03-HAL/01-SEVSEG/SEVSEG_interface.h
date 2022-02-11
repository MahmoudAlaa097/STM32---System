/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	09 JAN 2022                                            */
/* Version	:	V01									                   */
/***********************************************************************/
#ifndef SEVSEG_INTERFACE_H
#define SEVSEG_INTERFACE_H

/* Functions Prototypes*/
void SEVSEG_voidInit(u8 Copy_u8Type);
void SEVSEG_voidDisplay(u8 Copy_u8Type, u8 Copy_u8Number);

/* 7SEGement Types */
#define SEVSEG_Anode    1
#define SEVSEG_Cathode  0

#endif
