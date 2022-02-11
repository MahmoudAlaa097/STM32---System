/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	21 JAN 2022                                            */
/* Version	:	V02											           */
/***********************************************************************/

#ifndef  RCC_CONFIG_H
#define	 RCC_CONFIG_H

/* Options:		MRCC_HSE_CRYSTAL
				MRCC_HSE_RC
				MRCC_HSI
				MRCC_PLL				*/
#define	MRCC_CLOCK_TYPE	MRCC_HSE_CRYSTAL

/* Note: Select value only if you have PLL as input clock source */
#if MRCC_CLOCK_TYPE == MRCC_PLL
	/* Options:		MRCC_PLL_IN_HSI_DIV_2
					MRCC_PLL_IN_HSE_DIV_2
					MRCC_PLL_IN_HSE		*/
	#define	MRCC_PLL_INPUT	MRCC_PLL_IN_HSE_DIV_2

	#if (MRCC_PLL_INPUT == MRCC_PLL_IN_HSE_DIV_2) || (MRCC_PLL_INPUT == MRCC_PLL_IN_HSE)
		/* Options:		MRCC_PLL_HSE_CRYSTAL
						MRCC_PLL_HSE_RC		*/
		#define	MRCC_PLL_HSE		MRCC_PLL_HSE_CRYSTAL
	#endif
	/* Note: Clock must not exceed 72 MHZ */
	/* Options:		MRCC_PLL_MUL_2,	
                    MRCC_PLL_MUL_3, 
                    MRCC_PLL_MUL_4, 
                    MRCC_PLL_MUL_5, 
                    MRCC_PLL_MUL_6, 
                    MRCC_PLL_MUL_7, 
                    MRCC_PLL_MUL_8, 
                    MRCC_PLL_MUL_9, 
                    MRCC_PLL_MUL_10,
                    MRCC_PLL_MUL_11,
                    MRCC_PLL_MUL_12,
                    MRCC_PLL_MUL_13,
                    MRCC_PLL_MUL_14,
                    MRCC_PLL_MUL_15,
                    MRCC_PLL_MUL_16 */
	#define MRCC_PLL_MUL_FACTOR		MRCC_PLL_MUL_2

#endif
/* Options:			MRCC_MCO_NOCLOCK,
                    MRCC_MCO_SYSCLOCK,
                    MRCC_MCO_HSI,     
                    MRCC_MCO_HSE,     
                    MRCC_MCO_PLL_2 */
#define MRCC_MCO_CLOCK	MRCC_MCO_NOCLOCK

/* Options:			MRCC_CSS_ENABLE,
					MRCC_CSS_DISABLE */
#define MRCC_CSS	MRCC_CSS_DISABLE

#endif
