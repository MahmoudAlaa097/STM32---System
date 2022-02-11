/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	23 JAN 2022                                            */
/* Version	:	V03											           */
/***********************************************************************/

#ifndef GPIO_PRIVATE
#define GPIO_PRIVATE

/* GPIOA Registers */
typedef	struct{
	volatile u32	CRL;
	volatile u32	CRH;
	volatile u32 	IDR;
	volatile u32	ODR;
	volatile u32	BSRR;
	volatile u32	BRR;
	volatile u32	LCK;
}GPIOA_t;

#define		GPIOA		((volatile GPIOA_t*)0x40010800)

/* GPIOB Registers */
typedef	struct{
	volatile u32	CRL;
	volatile u32	CRH;
	volatile u32 	IDR;
	volatile u32	ODR;
	volatile u32	BSRR;
	volatile u32	BRR;
	volatile u32	LCK;
}GPIOB_t;

#define		GPIOB		((volatile GPIOB_t*)0x40010C00)

/* GPIOC Registers */
typedef	struct{
	volatile u32	CRL;
	volatile u32	CRH;
	volatile u32 	IDR;
	volatile u32	ODR;
	volatile u32	BSRR;
	volatile u32	BRR;
	volatile u32	LCK;
}GPIOC_t;

#define		GPIOC		((volatile GPIOC_t*)0x40011000)

#endif
