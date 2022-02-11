/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	5 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/
#ifndef	SPI_INTERFACE_H
#define	SPI_INTERFACE_H

/* Function Prototypes */
void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8* Copy_u8DataToReceive);
void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*Copy_ptr) (u8));

#endif
