/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	21 JAN 2022                                            */
/* Version	:	V02											           */
/***********************************************************************/

#ifndef  RCC_PRIVATE_H
#define	 RCC_PRIVATE_H

/* Register Definitions */
typedef struct{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC_t;

#define RCC ((volatile RCC_t*)0x40021000)

/* Clock Types */
#define MRCC_HSE_CRYSTAL			0
#define MRCC_HSE_RC		  			1
#define MRCC_HSI				    2
#define MRCC_PLL					3

/* PLL Options */
#define	MRCC_PLL_IN_HSI_DIV_2		0
#define	MRCC_PLL_IN_HSE_DIV_2		1
#define	MRCC_PLL_IN_HSE				2

/* PLL HSE Options */
#define MRCC_PLL_HSE_CRYSTAL		0
#define MRCC_PLL_HSE_RC				1

/* PLL Multiplication Factor */
#define	MRCC_PLL_MUL_2				0b0000
#define	MRCC_PLL_MUL_3              0b0001
#define	MRCC_PLL_MUL_4              0b0010
#define	MRCC_PLL_MUL_5              0b0011
#define	MRCC_PLL_MUL_6              0b0100
#define	MRCC_PLL_MUL_7              0b0101
#define	MRCC_PLL_MUL_8              0b0110
#define	MRCC_PLL_MUL_9              0b0111
#define	MRCC_PLL_MUL_10             0b1000
#define	MRCC_PLL_MUL_11             0b1001
#define	MRCC_PLL_MUL_12             0b1010
#define	MRCC_PLL_MUL_13             0b1011
#define	MRCC_PLL_MUL_14             0b1100
#define	MRCC_PLL_MUL_15             0b1101
#define	MRCC_PLL_MUL_16             0b1110

/* MCO Options */
#define	MRCC_MCO_NOCLOCK			0b000
#define	MRCC_MCO_SYSCLOCK			0b100
#define	MRCC_MCO_HSI                0b101
#define	MRCC_MCO_HSE                0b110
#define	MRCC_MCO_PLL_2              0b111

/* CSS Options */
#define	MRCC_CSS_ENABLE				1
#define	MRCC_CSS_DISABLE			0






#endif
