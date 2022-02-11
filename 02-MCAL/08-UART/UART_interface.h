/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	5 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/
#ifndef	UART_INTERFACE_H
#define	UART_INTERFACE_H

/* Functions Prototypes */
void MUSART1_voidInit(void);
void MUSART1_voidTransmit(u8* Copy_u8DataToTransmit);
u8	 MUSART1_voidRecveive();

#endif
