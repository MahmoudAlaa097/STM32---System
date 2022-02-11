/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	30 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void HSTP_voidSendSynchronus(u8 Copy_u8Data)
{
	s8 Local_s8Counter;
	for(Local_s8Counter=7;Local_s8Counter>=0;Local_s8Counter--)
	{
		/* Send Data bit by bit */
		MGPIO_voidSetPinValue(HSTP_SERIAL_DATA,GET_BIT(Copy_u8Data,Local_s8Counter));
		/* Send Pulse to shift clock */
		HSTP_voidSendPulse(HSTP_SHIFT_CLOCK);
	}
	/* Send Pulse to store clock */
	HSTP_voidSendPulse(HSTP_STORE_CLOCK);
}

static void HSTP_voidSendPulse(u8 Copy_u8ClockPin)
{
	/* Set high level of width = us */
	MGPIO_voidSetPinValue(Copy_u8ClockPin,HIGH);
	MSTK_voidSetBusyWait(1);
	/* Set low level of width = us */
	MGPIO_voidSetPinValue(Copy_u8ClockPin,LOW);
	MSTK_voidSetBusyWait(1);
}