/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	09 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#ifndef	LED_INTERFACE_H
#define	LED_INTERFACE_H

/* Functions Prototypes */
void HLED_voidLedOn(u8 Copy_u8Port, u8 Copy_u8Pin);
void HLED_voidLedOff(u8 Copy_u8Port, u8 Copy_u8Pin);
void HLED_voidLedToggle(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif