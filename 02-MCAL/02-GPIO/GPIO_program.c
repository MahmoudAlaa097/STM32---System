/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	23 JAN 2022                                            */
/* Version	:	V03											           */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode)
{
	/* Switch on Port */
	switch(Copy_u8Port)
	{
		case MGPIOA:
			/* Check on pin */
			if(Copy_u8Pin <= 7)
			{
				GPIOA->CRL &= ~((0b1111)<< (Copy_u8Pin*4));			/* Reset corresponding bits */
				GPIOA->CRL |= ((Copy_u8Mode)<< (Copy_u8Pin*4));		/* Set corresponding bits   */
			}
			else if (Copy_u8Pin <= 15)
			{
				GPIOA->CRH &= ~((0b1111)<< ((Copy_u8Pin-8)*4));		/* Reset corresponding bits */
				GPIOA->CRH |= ((Copy_u8Mode)<< ((Copy_u8Pin-8)*4));  /* Set corresponding bits   */
			}
			else
			{
				/* Error: wrong pin */
			}
			break;
		case MGPIOB:
			/* Check on pin */
			if(Copy_u8Pin <= 7)
			{
				GPIOB->CRL &= ~((0b1111)<< (Copy_u8Pin*4));			/* Reset corresponding bits */
				GPIOB->CRL |= ((Copy_u8Mode)<< (Copy_u8Pin*4));  	/* Set corresponding bits   */
			}
			else if (Copy_u8Pin <= 15)
			{
				GPIOB->CRH &= ~((0b1111)<< ((Copy_u8Pin-8)*4));		/* Reset corresponding bits */
				GPIOB->CRH |= ((Copy_u8Mode)<< ((Copy_u8Pin-8)*4));  /* Set corresponding bits   */
			}
			else
			{
				/* Error: wrong pin */
			}
			break;
		case MGPIOC:
			/* Check on pin */
			if(Copy_u8Pin <= 7)
			{
				GPIOC->CRL &= ~((0b1111)<< (Copy_u8Pin*4));			/* Reset corresponding bits */
				GPIOC->CRL |= ((Copy_u8Mode)<< (Copy_u8Pin*4));  	/* Set corresponding bits   */
			}
			else if (Copy_u8Pin <= 15)
			{
				GPIOC->CRH &= ~((0b1111)<< ((Copy_u8Pin-8)*4));		/* Reset corresponding bits */
				GPIOC->CRH |= ((Copy_u8Mode)<< ((Copy_u8Pin-8)*4));  /* Set corresponding bits   */
			}
			else
			{
				/* Error: wrong pin */
			}
			break;
		default : 
			/* Error: Wrong Port */ 
			break;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	/* Switch on Port */
	switch(Copy_u8Port)
	{
		case MGPIOA:
			/* Check on value */
			if(Copy_u8Value == HIGH)
			{
				GPIOA->BSRR = (1 << Copy_u8Pin);				/* Set bit to high */
			}
			else if(Copy_u8Value == LOW)
			{
				GPIOA->BRR = (1 << Copy_u8Pin);				    /* Set bit to low */
			}
			else
			{
				/* Error: Wrong value */
			}
			break;
		case MGPIOB:
			/* Check on value */
			if(Copy_u8Value == HIGH)
			{
				GPIOB->BSRR = (1 << Copy_u8Pin);				/* Set bit to high */
			}
			else if(Copy_u8Value == LOW)
			{
				GPIOB->BRR = (1 << Copy_u8Pin);				    /* Set bit to low */
			}
			else
			{
				/* Error: Wrong value */
			}
			break;
		case MGPIOC:
			/* Check on value */
			if(Copy_u8Value == HIGH)
			{
				GPIOC->BSRR = (1 << Copy_u8Pin);				/* Set bit to high */
			}
			else if(Copy_u8Value == LOW)
			{
				GPIOC->BRR = (1 << Copy_u8Pin);				    /* Set bit to low */
			}
			else
			{
				/* Error: Wrong value */
			}
			break;
		default : /* Error: Wrong Port */ break;
	}
}

u8 MGPIO_voidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 LOC_u8Result = 0;									/* Create a local variable to hold the pin value */
	/* Switch on Port */
	switch(Copy_u8Port)
	{
		case MGPIOA:
			LOC_u8Result = GET_BIT(GPIOA->IDR,Copy_u8Pin); 	/* Get pin value */
			break;
		case MGPIOB:
			LOC_u8Result = GET_BIT(GPIOB->IDR,Copy_u8Pin);	/* Get pin value */
			break;
		case MGPIOC:
			LOC_u8Result = GET_BIT(GPIOC->IDR,Copy_u8Pin);	/* Get pin value */
			break;
		default :
			/* Error: Wrong Port */
			break;
	}
	return LOC_u8Result;									/* Return Pin value */
}

void MGPIO_voidSetPortValue(u8 Copy_u8Port, u32 Copy_u8Value)
{
	/* Switch on Port */
	switch(Copy_u8Port)
	{
		case MGPIOA:
			/* Check on value */
			if(Copy_u8Value < 0x00010000)
			{
				GPIOA->ODR = Copy_u8Value;				/* Set Port Value */
			}
			else
			{
				/* Error: Wrong Value */
			}
			break;
		case MGPIOB:
			/* Check on value */
			if(Copy_u8Value < 0x00010000)
			{
				GPIOB->ODR = Copy_u8Value;				/* Set Port Value */
			}
			else
			{
				/* Error: Wrong Value */
			}
			break;
		case MGPIOC:
			/* Check on value */
			if(Copy_u8Value < 0x00010000)
			{
				GPIOC->ODR = Copy_u8Value;				/* Set Port Value */
			}
			else
			{
				/* Error: Wrong Value */
			}
			break;
		default:
			/* Error: Wrong Port */
			break;
	}
}
void MGPIO_voidLockPin(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	/* Switch on Port */
	switch(Copy_u8Port)
	{
		case MGPIOA:
			/* Check on pin */
			if(Copy_u8Pin < 16)
			{
				SET_BIT(GPIOA->LCK,Copy_u8Pin);			/* Lock Pin Direction */
			}
			else
			{
				/* Error: wrong pin */
			}
			break;
		case MGPIOB:
			/* Check on pin */
			if(Copy_u8Pin < 16)
			{
				SET_BIT(GPIOB->LCK,Copy_u8Pin);			/* Lock Pin Direction */
			}
			else
			{
				/* Error: wrong pin */
			}
			break;
		case MGPIOC:
			/* Check on pin */
			if(Copy_u8Pin < 16)
			{
				SET_BIT(GPIOC->LCK,Copy_u8Pin);			/* Lock Pin Direction */
			}
			else
			{
				/* Error: wrong pin */
			}
			break;
		default:
			/* Error: Wrong Port */
			break;
	}
}

void MGPIO_voidLockSequence(u8 Copy_u8Port)
{
	u8 Local_u8Seq = 0;
	switch(Copy_u8Port)
	{
		case MGPIOA:
			SET_BIT(GPIOA->LCK,16);
			CLR_BIT(GPIOA->LCK,16);
			SET_BIT(GPIOA->LCK,16);
			Local_u8Seq = GET_BIT(GPIOA->LCK,16);
			Local_u8Seq = GET_BIT(GPIOA->LCK,16);
			if(Local_u8Seq != 1)
			{
				/* error */
			}
			break;
		case MGPIOB:
			SET_BIT(GPIOB->LCK,16);
			CLR_BIT(GPIOB->LCK,16);
			SET_BIT(GPIOB->LCK,16);
			Local_u8Seq = GET_BIT(GPIOB->LCK,16);
			Local_u8Seq = GET_BIT(GPIOB->LCK,16);
			if(Local_u8Seq != 1)
			{
				/* error */
			}
			break;
		case MGPIOC:
			SET_BIT(GPIOC->LCK,16);
			CLR_BIT(GPIOC->LCK,16);
			SET_BIT(GPIOC->LCK,16);
			Local_u8Seq = GET_BIT(GPIOC->LCK,16);
			Local_u8Seq = GET_BIT(GPIOC->LCK,16);
			if(Local_u8Seq != 1)
			{
				/* error */
			}
			break;
	}
}
