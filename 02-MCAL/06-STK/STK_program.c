/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	15 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

void SysTick_Handler(void)
{
	MSTK_Callback();
	if(MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Single Interval */
		STK->LOAD = 0;		/* Clear Load  Register */
		STK->VAL  = 0;		/* Clear Value Register */
	}
	else if(MSTK_u8ModeOfInterval == MSTK_PERIODIC_INTERVAL)
	{
		/* Periodic Interval */
	}
	else
	{
		/* Error */
	}
}

void MSTK_voidInit()
{
	#if		MSTK_CLOCK == MSTK_AHB
		STK->CTRL = 0x00000100;		/* Select AHB as STK Clock and Disable STK and STK interrupt */
		
	#elif	MSTK_CLOCK == MSTK_AHB_8
		STK->CTRL = 0x00000000;		/* Select AHB/8 as STK Clock and Disable STK and STK interrupt */
		
	#else
		#error("You chose wrong Clock type")
	#endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/* Load Required Value */
	STK->LOAD = Copy_u32Ticks;
	
	/* Enable SysTick */
	SET_BIT(STK->CTRL,MSTK_EN);
	
	/* Stay here till the end */
	while(GET_BIT(STK->CTRL,MSTK_FLAG) == 0);
}
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	/* Disable Timer */
	MSTK_voidStopTimer();
	
	/* Load Required Value */
	STK->LOAD = Copy_u32Ticks;
	
	/* Enable SysTick */
	SET_BIT(STK->CTRL,MSTK_EN);

	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	
	/* Assign MSTK_Callback Function */
	MSTK_Callback = Copy_ptr;
	
	/* Enable SysTick Interrupt */
	SET_BIT(STK->CTRL,MSTK_INTEN);
}
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
	/* Load Required Value */
	STK->LOAD = Copy_u32Ticks;
	
	/* Enable SysTick */
	SET_BIT(STK->CTRL,MSTK_EN);
	
	/* Set Mode to Periodic */
	MSTK_u8ModeOfInterval = MSTK_PERIODIC_INTERVAL;
	
	/* Assign MSTK_Callback Function */
	MSTK_Callback = Copy_ptr;
	
	/* Enable SysTick Interrupt */
	SET_BIT(STK->CTRL,MSTK_INTEN);
}

void MSTK_voidStopTimer()
{
	/* Disable SysTick */
	CLR_BIT(STK->CTRL,MSTK_EN);
	
	/* Disable SysTick Interrupt */
	CLR_BIT(STK->CTRL,MSTK_INTEN);
	
	/* Clear Load Register */
	STK->LOAD = 0;
	
	/* Clear Value Register */
	STK->VAL  = 0;
}

u32	MSTK_u32GetElapsedTime()
{
	/* Return the elapsed time */
	return (STK->LOAD - STK->VAL);
}

u32	MSTK_u32GetRemaningTime()
{
	/* Return the remaning time */
	return STK->VAL;
}
