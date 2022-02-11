/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	14 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*MEXTI_Callback[16])(void) = {NULL};

void MEXTI_voidInit()
{
	#if	EXTI_MODE == RISING
		SET_BIT(EXTI->RTSR,EXTI_LINE);
	#elif	EXTI_MODE == FALLING
		SET_BIT(EXTI->FTSR,EXTI_LINE);
	#elif	EXTI_MODE == ON_CHANGE
		SET_BIT(EXTI->RTSR,EXTI_LINE);
		SET_BIT(EXTI->FTSR,EXTI_LINE);
	#else
		#error "Wrong Mode"
	#endif
	/* Disable External Interrupts */
	EXTI->IMR = 0x00000000;
}

void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR,Copy_u8Line);
}

void MEXTI_voidDIableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR,Copy_u8Line);
}

void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI->SWIER,Copy_u8Line);
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case RISING:
			SET_BIT(EXTI->RTSR,Copy_u8Line);
			break;
		case FALLING:
			SET_BIT(EXTI->FTSR,Copy_u8Line);
			break;
		case ON_CHANGE:
			SET_BIT(EXTI->RTSR,Copy_u8Line);
			SET_BIT(EXTI->FTSR,Copy_u8Line);
			break;
		default:
			/* Error: Wrong Mode */
			break;
	}
}

void MEXTI_voidSetCallBack(void (*Copy_ptr)(void))
{
	MEXTI_Callback[0] = Copy_ptr;
}

/* EXTI0 ISR */
void EXTI0_IRQHandler(void)
{
	MEXTI_Callback[0]();
	SET_BIT(EXTI->PR,0);
}

/* EXTI1 ISR */
void EXTI1_IRQHandler(void)
{
	MEXTI_Callback[1]();
	SET_BIT(EXTI->PR,1);
}

/* EXTI2 ISR */
void EXTI20_IRQHandler(void)
{
	MEXTI_Callback[2]();
	SET_BIT(EXTI->PR,2);
}

/* EXTI3 ISR */
void EXTI3_IRQHandler(void)
{
	MEXTI_Callback[3]();
	SET_BIT(EXTI->PR,3);
}

/* EXTI4 ISR */
void EXTI4_IRQHandler(void)
{
	MEXTI_Callback[4]();
	SET_BIT(EXTI->PR,4);
}

/* EXTI5 ISR */
void EXTI5_IRQHandler(void)
{
	MEXTI_Callback[5]();
	SET_BIT(EXTI->PR,5);
}

/* EXTI6 ISR */
void EXTI6_IRQHandler(void)
{
	MEXTI_Callback[6]();
	SET_BIT(EXTI->PR,6);
}

/* EXTI7 ISR */
void EXTI7_IRQHandler(void)
{
	MEXTI_Callback[7]();
	SET_BIT(EXTI->PR,7);
}

/* EXTI8 ISR */
void EXTI8_IRQHandler(void)
{
	MEXTI_Callback[8]();
	SET_BIT(EXTI->PR,8);
}

/* EXTI9 ISR */
void EXTI9_IRQHandler(void)
{
	MEXTI_Callback[9]();
	SET_BIT(EXTI->PR,9);
}

/* EXTI10 ISR */
void EXTI10_IRQHandler(void)
{
	MEXTI_Callback[10]();
	SET_BIT(EXTI->PR,10);
}

/* EXTI11 ISR */
void EXTI11_IRQHandler(void)
{
	MEXTI_Callback[11]();
	SET_BIT(EXTI->PR,11);
}

/* EXTI12 ISR */
void EXTI12_IRQHandler(void)
{
	MEXTI_Callback[12]();
	SET_BIT(EXTI->PR,12);
}

/* EXTI13 ISR */
void EXTI13_IRQHandler(void)
{
	MEXTI_Callback[13]();
	SET_BIT(EXTI->PR,13);
}

/* EXTI14 ISR */
void EXTI14_IRQHandler(void)
{
	MEXTI_Callback[14]();
	SET_BIT(EXTI->PR,14);
}

/* EXTI5 ISR */
void EXTI15_IRQHandler(void)
{
	MEXTI_Callback[15]();
	SET_BIT(EXTI->PR,15);
}
