/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	5 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidInit(void)
{
	/* Reset Pulse */
	MGPIO_voidSetPinValue(HTFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(HTFT_RST_PIN,LOW);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(HTFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(HTFT_RST_PIN,LOW);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(HTFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(120000);

	/* Sleep Out Command */
	voidWriteCommand(0x11);

	/* Wait 150 ms */
	MSTK_voidSetBusyWait(150000);

	/* Color Mode Command */
	voidWriteCommand(0x3A);
	voidWriteData(HTFT_CLR_MODE);

	/* Display On Command */
	voidWriteCommand(0x29);
}

void HTFT_voidDisplayImage(const u16* Copy_u16Image)
{
	u16 Local_u16Counter;
	u8  Local_u8Data;

	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/* RAM Write */
	voidWriteCommand(0x2C);

	for(Local_u16Counter=0;Local_u16Counter<20480;Local_u16Counter++)
	{
		/* Write the high byte */
		Local_u8Data = Copy_u16Image[Local_u16Counter] >> 8;
		voidWriteData(Local_u8Data);

		/* Write the low byte */
		Local_u8Data = Copy_u16Image[Local_u16Counter] & 0x00FF;
		voidWriteData(Local_u8Data);
	}
}

void HTFT_voidFillColor(u16 Copy_u16Color)
{
	u16 Local_u16Counter;
	u8  Local_u8Data;

	/* Set X Address */
	voidWriteCommand(0x2A);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(127);

	/* Set Y Address */
	voidWriteCommand(0x2B);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(0);
	voidWriteData(159);

	/* RAM Write */
	voidWriteCommand(0x2C);

	for(Local_u16Counter=0;Local_u16Counter<20480;Local_u16Counter++)
	{
		/* Write the high byte */
		Local_u8Data = Copy_u16Color >> 8;
		voidWriteData(Local_u8Data);

		/* Write the low byte */
		Local_u8Data = Copy_u16Color & 0x00FF;
		voidWriteData(Local_u8Data);
	}
}

void HTFT_voidDrawRect(u8 x1, u8 x2, u8 y1, u8 y2, u16 Copy_u16Color)
{
	if( (x1 < 128) && (x2 < 128) && (y1 < 160) && (y2 < 160) )
	{
		u16 Local_u16Counter;
		u8  Local_u8Data;
		u16 Local_u16Size = (x2 - x1) * (y2 - y1);
		
		/* Set X Address */
		voidWriteCommand(0x2A);
		voidWriteData(0);
		voidWriteData(x1);
		voidWriteData(0);
		voidWriteData(x2);

		/* Set Y Address */
		voidWriteCommand(0x2B);
		voidWriteData(0);
		voidWriteData(y1);
		voidWriteData(0);
		voidWriteData(y2);

		/* RAM Write */
		voidWriteCommand(0x2C);

		for(Local_u16Counter=0;Local_u16Counter<Local_u16Size;Local_u16Counter++)
		{
			/* Write the high byte */
			Local_u8Data = Copy_u16Color >> 8;
			voidWriteData(Local_u8Data);

			/* Write the low byte */
			Local_u8Data = Copy_u16Color & 0x00FF;
			voidWriteData(Local_u8Data);
		}
	}
	else
	{
		/* Error: Wrong Coordinates */
	}
}

static void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;

	/* Set A0 Pin to low */
	MGPIO_voidSetPinValue(HTFT_A0_PIN,LOW);

	/* Send Command over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Command,&Local_u8Temp);
}

static void voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;

	/* Set A0 Pin to high */
	MGPIO_voidSetPinValue(HTFT_A0_PIN,HIGH);

	/* Send Command over SPI */
	MSPI1_voidSendReceiveSynch(Copy_u8Data,&Local_u8Temp);
}
