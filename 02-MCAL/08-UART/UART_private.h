/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	5 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/
#ifndef	UART_PRIVATE_H
#define	UART_PRIVATE_H

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}MUART_Register;

#define MUSART1 ((volatile MUART_Register*) 0x40013800)

/* Baud Rate */
#define MUSART1_4800				0
#define MUSART1_9600				1
#define MUSART1_115200				2

/* Word Length  */
#define MUSART1_8BIT				0
#define MUSART1_9BIT				1

/* Parity Bit */
#define	MUSART1_PARITY_DISABLE		0
#define MUSART1_PARITY_ENABLE		1

/* Parity Type */
#define	MUSART1_PARITY_EVEN			0
#define MUSART1_PARITY_ODD			1

/* Transmitter & Receiver */
#define	MUSART1DISABLE				0
#define	MUSART1_ENABLE				1

#endif
