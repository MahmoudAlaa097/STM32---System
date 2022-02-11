/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	22 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

void HLEDMRX_voidInit(void)
{
	/* Initialize Rows Pins */
	MGPIO_voidSetPinDirection(LEDMRX_ROW0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW7,OUTPUT_SPEED_2MHZ_PP);
	
	/* Initialize Columns Pins */
	MGPIO_voidSetPinDirection(LEDMRX_COL0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL7,OUTPUT_SPEED_2MHZ_PP);
}

void HLEDMRX_voidDisplay(u8* Copy_u8Data)
{
	/* Column 0 */
	/* Disable All Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Set Rows Value */
	HLEDMRX_voidSetRowsValue(Copy_u8Data[0]);
	/* Enable Column 0 */
	MGPIO_voidSetPinValue(LEDMRX_COL0,LOW);
	/* Delay: 2.5 msec */
	MSTK_voidSetBusyWait(2500);
	/* Column 1 */
	/* Disable All Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Set Rows Value */
	HLEDMRX_voidSetRowsValue(Copy_u8Data[1]);
	/* Enable Column 1 */
	MGPIO_voidSetPinValue(LEDMRX_COL1,LOW);
	/* Delay: 2.5 msec */
	MSTK_voidSetBusyWait(2500);
	/* Column 2 */
	/* Disable All Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Set Rows Value */
	HLEDMRX_voidSetRowsValue(Copy_u8Data[2]);
	/* Enable Column 2 */
	MGPIO_voidSetPinValue(LEDMRX_COL2,LOW);
	/* Delay: 2.5 msec */
	MSTK_voidSetBusyWait(2500);
	/* Column 3 */
	/* Disable All Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Set Rows Value */
	HLEDMRX_voidSetRowsValue(Copy_u8Data[3]);
	/* Enable Column 3 */
	MGPIO_voidSetPinValue(LEDMRX_COL3,LOW);
	/* Delay: 2.5 msec */
	MSTK_voidSetBusyWait(2500);
	/* Column 4 */
	/* Disable All Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Set Rows Value */
	HLEDMRX_voidSetRowsValue(Copy_u8Data[4]);
	/* Enable Column 4 */
	MGPIO_voidSetPinValue(LEDMRX_COL4,LOW);
	/* Delay: 2.5 msec */
	MSTK_voidSetBusyWait(2500);
	/* Column 5 */
	/* Disable All Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Set Rows Value */
	HLEDMRX_voidSetRowsValue(Copy_u8Data[5]);
	/* Enable Column 5 */
	MGPIO_voidSetPinValue(LEDMRX_COL5,LOW);
	/* Delay: 2.5 msec */
	MSTK_voidSetBusyWait(2500);
	/* Column 6 */
	/* Disable All Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Set Rows Value */
	HLEDMRX_voidSetRowsValue(Copy_u8Data[6]);
	/* Enable Column 6 */
	MGPIO_voidSetPinValue(LEDMRX_COL6,LOW);
	/* Delay: 2.5 msec */
	MSTK_voidSetBusyWait(2500);
	/* Column 7 */
	/* Disable All Columns */
	HLEDMRX_voidDisableAllColumns();
	/* Set Rows Value */
	HLEDMRX_voidSetRowsValue(Copy_u8Data[7]);
	/* Enable Column 7 */
	MGPIO_voidSetPinValue(LEDMRX_COL7,LOW);
	/* Delay: 2.5 msec */
	MSTK_voidSetBusyWait(2500);
}

static void HLEDMRX_voidDisableAllColumns(void)
{
	MGPIO_voidSetPinValue(LEDMRX_COL0,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL1,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL2,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL3,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL4,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL5,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL6,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL7,HIGH);
}

static void HLEDMRX_voidSetRowsValue(u8 Copy_u8Data)
{
	MGPIO_voidSetPinValue(LEDMRX_ROW0,GET_BIT(Copy_u8Data,0));
	MGPIO_voidSetPinValue(LEDMRX_ROW1,GET_BIT(Copy_u8Data,1));
	MGPIO_voidSetPinValue(LEDMRX_ROW2,GET_BIT(Copy_u8Data,2));
	MGPIO_voidSetPinValue(LEDMRX_ROW3,GET_BIT(Copy_u8Data,3));
	MGPIO_voidSetPinValue(LEDMRX_ROW4,GET_BIT(Copy_u8Data,4));
	MGPIO_voidSetPinValue(LEDMRX_ROW5,GET_BIT(Copy_u8Data,5));
	MGPIO_voidSetPinValue(LEDMRX_ROW6,GET_BIT(Copy_u8Data,6));
	MGPIO_voidSetPinValue(LEDMRX_ROW7,GET_BIT(Copy_u8Data,7));
}
