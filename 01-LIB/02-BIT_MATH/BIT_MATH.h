/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	10 JAN 2022                                            */
/* Version	:	V02											           */
/***********************************************************************/

#ifndef BIT_MATH_H
#define	BIT_MATH_H


#define SET_BIT(VAR,BIT)			VAR |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT)			VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)			((VAR >> BIT) & 1  )
#define TOG_BIT(VAR,BIT)			VAR ^=  (1 << (BIT))
#define	SET_VAL(VAR,VAL,BIT)		VAR |= ((VAL) << (BIT))
#endif
