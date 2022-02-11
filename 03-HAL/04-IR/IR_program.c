/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	25 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

volatile u8 	Global_u8StartFlag 		= 0;
volatile u32	Global_u32FrameData[50] = {0};
volatile u8		Global_u8EdgeCounter 	= 0;
volatile u8		Global_u8Data			= 0;

void HIR_voidInit(void)
{
	/* Set IR Pin as Input floating */
	MGPIO_voidSetPinDirection(HIR_PORT,HIR_PIN,INPUT_FLOATING);
	
	/* Enable IR EXTI Line & Select Falling Edge */
	MEXTI_voidSetSignalLatch(HIR_PIN,FALLING);
	
	/* Set EXTI Callback */
	MEXTI_voidSetCallBack(HIR_PIN,HIR_voidGetFrame)
}

void HIR_voidGetFrame(void)
{
	if(Global_u8StartFlag == 0)
	{
		/* Start Timer */
		MSTK_voidSetIntervalSingle(500000,HIR_voidTakeAction);
		Global_u8StartFlag	= 1;	
	}
	else
	{
		Global_u32FrameData[Global_u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(500000,HIR_voidTakeAction);
		Global_u8EdgeCounter++;
	}
}

void HIR_voidTakeAction(void)
{
	u8 Local_u8Index;
	Global_u8Data = 0;
	if( (Global_u32FrameData[0] >= 10000) && (Global_u32FrameData[0] <= 14000))
	{
		for(Local_u8Index=0;Local_u8Index<8;Local_u8Index++)
		{
			if( (Global_u32FrameData[Local_u8Index] >= 2000) && (Global_u32FrameData[Local_u8Index] <= 2300))
			{
				SET_BIT(Global_u8Data,Local_u8Index);
			}
			else if( (Global_u32FrameData[Local_u8Index] >= 1000) && (Global_u32FrameData[Local_u8Index] <= 1200))
			{
				CLR_BIT(Global_u8Data,Local_u8Index);
			}
			else
			{
				/* Invalid Bit */
			}
		}
	}
	else
	{
		/* Invalid Frame */
	}
}