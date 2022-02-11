/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	09 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SEVSEG_interface.h"
#include "SEVSEG_private.h"
#include "SEVSEG_config.h"

#include "MGPIO_interface.h"

void SEVSEG_voidInit(u8 Copy_u8Type)
{
	switch(Copy_u8Type)
	{
		case SEVSEG_Anode:
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,LOW);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,LOW);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,LOW);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,LOW);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_E,LOW);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,LOW);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,LOW);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_DOT,LOW);
			break;
		case SEVSEG_Cathode:
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,HIGH);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,HIGH);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,HIGH);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,HIGH);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_E,HIGH);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,HIGH);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,HIGH);
			MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_DOT,HIGH);
			break;
		default :
			/* Error: Wrong type */
			break;
	}
}

void SEVSEG_voidDisplay(u8 Copy_u8Type,u8  Copy_u8Number)
{
	switch(Copy_u8Type)
	{
		case SEVSEG_Anode:
			switch(Copy_u8Number)
			{
				case 0:
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_E,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,HIGH);
					break;
			    case 1:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,HIGH);
			    	break;
			    case 2:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_E,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,HIGH);
			    	break;
			    case 3:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,HIGH);
					break;
			    case 4:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,HIGH);
					break;
			    case 5:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_E,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,HIGH);
			    	break;
			    case 6:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_E,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,HIGH);
			    	break;
			    case 7:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,HIGH);
			    	break;
			    case 8:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,HIGH);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,HIGH);
			   		MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,HIGH);
	 				MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,HIGH);
	  				MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_E,HIGH);
	 				MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,HIGH);
	 				MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,HIGH);
	 				break;
			    case 9:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,HIGH);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,HIGH);
					break;
			    default:
			    	/* Error: Wrong Number */
			    	break;
			}
			break;
		case SEVSEG_Cathode:
			switch(Copy_u8Number)
			{
            	case 0:
            		MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_E,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,LOW);
					break;
			    case 1:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,LOW);
			    	break;
			    case 2:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_E,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,LOW);
			    	break;
			    case 3:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,LOW);
					break;
			    case 4:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,LOW);
					break;
			    case 5:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_E,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,LOW);
                	break;
			    case 6:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_E,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,LOW);
			    	break;
			    case 7:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,LOW);
			    	break;
			    case 8:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,LOW);
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,LOW);
			   		MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_E,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,LOW);
					break;
			    case 9:
			    	MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_A,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_B,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_C,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_D,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_F,LOW);
					MGPIO_voidSetPinValue(SEVSEG_Port,SEVSEG_G,LOW);
					break;
			    default:
			    	/* Error: Wrong Number */
			    	break;
			}
			break;
		default:
			/* Error: Wrong type */
			break;
	}
}


















