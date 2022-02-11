/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	5 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/
#ifndef	SPI_PRIVATE_H
#define	SPI_PRIVATE_H

/* SPI1 Registers */
typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR	;
	volatile u32 DR ;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_Register;

#define	MSPI	((volatile SPI_Register*)0x40013000)


/* Configurations Macros */
/* Clock Phase */
#define	MSPI_READ			0
#define	MSPI_WRITE			1

/* Clock Polarity */
#define MSPI_RISING			0
#define MSPI_FALLING		1

/* Device Type */
#define	MSPI_SLAVE			0
#define	MSPI_MASTER			1

/* Baud Rate PreScaler */
#define MSPI_FREQ_2			000
#define MSPI_FREQ_4			001
#define MSPI_FREQ_8     	010
#define MSPI_FREQ_16    	011
#define MSPI_FREQ_32		100
#define MSPI_FREQ_64    	101
#define MSPI_FREQ_128   	110
#define MSPI_FREQ_256   	111

/* Data Order */
#define MSPI_MSB		0
#define MSPI_LSB		1

#endif