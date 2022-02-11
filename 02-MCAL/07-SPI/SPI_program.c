/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	5 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void (*MSPI1_CallBack) (void);

void MSPI1_voidInit(void)
{
	MSPI -> CR1 = 0x0300;

	/* Data Order */
	#if MSPI_DATA_ORDER == MSPI_LSB
		SET_BIT(MSPI -> CR1, 7);
	#elif MSPI_DATA_ORDER == MSPI_MSB
		CLR_BIT(MSPI -> CR1, 7);
	#else
		#error ("Wrong Data Order")
	#endif

	/* Baud Rate PreScaler */
	#if MSPI_BAUDRATE == MSPI_FREQ_2
		SET_VAL(MSPI -> CR1, 3,MSPI_FREQ_2);
	#elif MSPI_BAUDRATE == MSPI_FREQ_4
		SET_VAL(MSPI -> CR1, 3,MSPI_FREQ_4);
	#elif MSPI_BAUDRATE == MSPI_FREQ_8
		SET_VAL(MSPI -> CR1, 3,MSPI_FREQ_8);
	#elif MSPI_BAUDRATE == MSPI_FREQ_16
		SET_VAL(MSPI -> CR1, 3,MSPI_FREQ_16);
	#elif MSPI_BAUDRATE == MSPI_FREQ_32
		SET_VAL(MSPI -> CR1, 3,MSPI_FREQ_32);
	#elif MSPI_BAUDRATE == MSPI_FREQ_64
		SET_VAL(MSPI -> CR1, 3,MSPI_FREQ_64);
	#elif MSPI_BAUDRATE == MSPI_FREQ_128
		SET_VAL(MSPI -> CR1, 3,MSPI_FREQ_128);
	#elif MSPI_BAUDRATE == MSPI_FREQ_256
		SET_VAL(MSPI -> CR1, 3,MSPI_FREQ_256);
	#else
		#error ("Wrong Baud Rate PreScaler");
	#endif

	/* SPI Mode */
	#if MSPI_TYPE == MSPI_MASTER
		SET_BIT(MSPI -> CR1, 2);
	#elif MSPI_TYPE == MSPI_SLAVE
		CLR_BIT(MSPI -> CR1, 2);
	#else
		#error ("Wrong Mode");
	#endif

	/*  Clock Polarity */
	#if MSPI_CLOCK_POLAR == MSPI_RISING
		CLR_BIT(MSPI -> CR1, 1);
	#elif MSPI_CLOCK_POLAR == MSPI_FALLING
		SET_BIT(MSPI -> CR1, 1);
	#else
		#error("Wrong Clock Polarization");
	#endif

	/*  Clock Phase */
	#if MSPI_CLOCK_PHASE == MSPI_READ
		CLR_BIT(MSPI -> CR1, 1);
	#elif MSPI_CLOCK_PHASE == MSPI_WRITE
		SET_BIT(MSPI -> CR1, 1);
	#else
		#error("Wrong Clock Phase");
	#endif

	/*Enable SPI1 */
	SET_BIT(MSPI -> CR1, 6);
}

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8* Copy_u8DataToReceive)
{
	/* Clear For Slave Select Pin */
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,LOW);
	
	/* Send Data */
	MSPI -> DR = Copy_u8DataToTransmit;
	
	/* Wait Busy Flag to finish */
	while(GET_BIT(MSPI -> SR, 7) == 1);
	
	/* Return the received data */
	Copy_u8DataToReceive = MSPI -> DR;
	
	/* Set For Slave Select Pin */
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,HIGH);
}

