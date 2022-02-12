/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	13 FEB 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC_interface.h"
#include "FPEC_private.h"
#include "FPEC_config.h"

void FPEC_voidEraseAppArea(void)
{
	u8 Local_u8Index;
	
	for(Local_u8Index=MFPEC_APP_BEG;Local_u8Index<MFPEC_APP_END;Local_u8Index++)
	{
		FPEC_voidFlashPageErase(Local_u8Index);
	}
}

void FPEC_voidFlashPageErase(u8 Copy_u8PageNumber)
{
	/* Wait for Busy Flag */
	while( GET_BIT(FPEC -> SR, 0) == 1 );
	
	/* Check if FPEC locked or not */
	if( GET_BIT(FPEC -> CR, 7) == 1 )
	{
		FPEC -> KEYR = 0x45670123;
		FPEC -> KEYR = 0xCDEF89AB;
	}
	
	/* Page Erase Operation */
	SET_BIT(FPEC -> CR, 1);
	
	/* Write Page address */
	FPEC -> AR = (u32)(Copy_u8PageNumber * 1024) + FLASH_BASE_ADDRESS ;

	/* Start operation */
	SET_BIT(FPEC->CR,6);

	/* Wait Busy Flag */
	while (GET_BIT(FPEC->SR,0) == 1);

	/* EOP */
	SET_BIT(FPEC->SR,5);
	CLR_BIT(FPEC->CR,1);
}

void FPEC_voidFlashWrite(u32 Copy_u32Address, u16* Copy_u16Data, u8 Copy_u8Length)
{
	u8 Local_u8Index;
	volatile u16 Local_u16Temp;
	
	/* Wait for Busy Flag */
	while( GET_BIT(FPEC -> SR, 0) == 1 );
	
	/* Check if FPEC is locked or not */
	if ( GET_BIT(FPEC -> CR, 7) == 1 )
	{
		FPEC -> KEYR = 0x45670123;
		FPEC -> KEYR = 0xCDEF89AB;
	}
	
	for (Local_u8Index=0;Local_u8Index<Copy_u8Length;Local_u8Index++)
	{
		/* Write Flash Programming */
		SET_BIT(FPEC -> CR, 0);

		/* Half word operation */
		Local_u16Temp = Copy_u16Data[i];
		*((volatile u16*)Copy_u32Address) = Local_u16Temp;
		Copy_u32Address += 2 ;

		/* Wait for Busy Flag */
		while (GET_BIT(FPEC->SR,0) == 1);
	
		/* EOP */
		SET_BIT(FPEC->SR,5);
		CLR_BIT(FPEC->CR,0);
	}
}