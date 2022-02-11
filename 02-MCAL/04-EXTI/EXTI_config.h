/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	14 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#ifndef EXTI_CONFIG_H
#define EXTI_CONFIG_H

// Choose External Interrupt Line
/* Options: EXTI_LINE0,
			EXTI_LINE1,
			EXTI_LINE2,
			.
			.
			.
			EXTI_LINE15 */
#define		EXTI_LINE		EXTI_LINE0

// Choose External Interrupt Mode
/* Options: RISING,
			FALLING,
			ON_CHANGE */
#define		EXTI_MODE		FALLING

#endif
