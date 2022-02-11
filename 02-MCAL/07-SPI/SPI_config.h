/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	5 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/
#ifndef	SPI_CONFIG_H
#define	SPI_CONFIG_H

/* Write in pair PORT,PIN */
#define MSPI1_SLAVE_PIN		MGPIOA,0


/* Configurations */

/* Choose what to do @ leading edge */
/* Options: MSPI_READ
			MSPI_WRITE */
#define	MSPI_CLOCK_PHASE		MSPI_WRITE

/* Choose leading edge */
/* Options: MSPI_RISNG
			MSPI_FALLING */
#define	MSPI_CLOCK_POLAR		MSPI_FALLING

/* Choose the type of device */
/* Options: MSPI_SLAVE
			MSPI_MASTER */
#define	MSPI_TYPE				MSPI_MASTER

/* Choose what to do @ leading edge */
/* Options: MSPI_FREQ_2	
			MSPI_FREQ_4	 
			MSPI_FREQ_8  
			MSPI_FREQ_16 
			MSPI_FREQ_32
			MSPI_FREQ_64 
			MSPI_FREQ_128
			MSPI_FREQ_256    */
#define	MSPI_BAUDRATE			MSPI_FREQ_2

/* Choose what to be sent first */
/* Options: MSPI_MSB
			MSPI_LSB */
#define	MSPI_DATA_ORDER			MSPI_MSB


#endif
