/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	5 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/
#ifndef	UART_CONFIG_H
#define	UART_CONFIG_H

/* USART1 Configurations */

/* Baud Rate */
/* Options: MUSART1_4800
 	 	 	MUSART1_9600
 	 	 	MUSART1_115200 */
#define MUSART1_BAUD	MUSART1_9600

/* Word Length */
/* Options: MUSART1_8BIT
 	 	 	MUSART1_9BIT */
#define MUSART1_WORD	MUSART1_8BIT

/* Parity Bit */
/* Options: MUSART1_DISABLE
  			MUSART1_ENABLE */
#define MUSART1__PARITY	MUSART1_PARITY_DISABLE

/* Choose only if Parity is enabled */
#if	MUSART1_PARITY == MUSART1_PARITY_ENABLE
	/* Parity Type */
	/* Options: MUSART1_PARITY_EVEN
	 	 	 	MUSART1_PARITY_ODD */
	#define MUSART1_PARITY_TYPE MUSART1_PARITY_EVEN
#endif

/* Transmitter Enable */
/* Options: MUSART1_DISABLE
	 	 	MUSART1_ENABLE */
#define MUSART1_TX	MUSART1_ENABLE

/* Receiver Enable */
/* Options: MUSART1_DISABLE
	 	 	MUSART1_ENABLE */
#define MUSART1_RX	MUSART1_ENABLE

#endif
