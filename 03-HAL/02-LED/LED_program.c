/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	09 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

#include "MGPIO_interface.h"

void HLED_voidLedOn(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case MGPIOA:
			SET_BIT(MGPIOA_ODR,Copy_u8Pin);
			break;
		case MGPIOB:
			SET_BIT(MGPIOB_ODR,Copy_u8Pin);
			break;
		case MGPIOC:
			SET_BIT(MGPIOC_ODR,Copy_u8Pin);
			break;
		default:
			/* Error: Wrong port */
			break;
	}
}

void HLED_voidLedOff(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case MGPIOA:
			CLR_BIT(MGPIOA_ODR,Copy_u8Pin);
			break;
		case MGPIOB:
			CLR_BIT(MGPIOB_ODR,Copy_u8Pin);
			break;
		case MGPIOC:
			CLR_BIT(MGPIOC_ODR,Copy_u8Pin);
			break;
		default:
			/* Error: Wrong port */
			break;
	}
}

void HLED_voidLedToggle(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case MGPIOA:
			TOG_BIT(MGPIOA_ODR,Copy_u8Pin);
			break;
		case MGPIOB:
			TOG_BIT(MGPIOB_ODR,Copy_u8Pin);
			break;
		case MGPIOC:
			TOG_BIT(MGPIOC_ODR,Copy_u8Pin);
			break;
		default:
			/* Error: Wrong port */
			break;
	}
}