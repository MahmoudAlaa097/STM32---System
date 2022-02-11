/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	21 JAN 2022                                            */
/* Version	:	V02											           */
/***********************************************************************/

#ifndef  RCC_INTERFACE_H
#define	 RCC_INTERFACE_H

/* Register Macros */
#define MRCC_AHB	0
#define MRCC_APB1	1
#define MRCC_APB2	2

/* AHB Peripherals */
#define MRCC_AHB_DMA1				0
#define MRCC_AHB_DMA2				1
#define MRCC_AHB_SRAM				2
#define MRCC_AHB_FLITF				4
#define MRCC_AHB_CRC				6
#define MRCC_AHB_FSMC				8
#define MRCC_AHB_SDIO				10

/* APB2 Peripherals */
#define MRCC_APB2_AFIO				0
#define MRCC_APB2_GPIOA		    	2
#define MRCC_APB2_GPIOB		    	3
#define MRCC_APB2_GPIOC		    	4
#define MRCC_APB2_ADC1				9
#define MRCC_APB2_ADC2				10
#define MRCC_APB2_TIM1				11
#define MRCC_APB2_SPI1				12
#define MRCC_APB2_TIM8				13
#define MRCC_APB2_USART1			14
#define MRCC_APB2_ADC3				15
#define MRCC_APB2_TIM9				19
#define MRCC_APB2_TIM10				20
#define MRCC_APB2_TIM11				21

/* APB1 Peripherals */
#define MRCC_APB1_TIM2				0
#define MRCC_APB1_TIM3				1
#define MRCC_APB1_TIM4				2
#define MRCC_APB1_TIM5				3
#define MRCC_APB1_TIM6				4
#define MRCC_APB1_TIM7				5
#define MRCC_APB1_TIM12				6
#define MRCC_APB1_TIM13				7
#define MRCC_APB1_TIM14				8
#define MRCC_APB1_WWDGEN			11
#define MRCC_APB1_SPI2				14
#define MRCC_APB1_SPI3				15
#define MRCC_APB1_USART2			17
#define MRCC_APB1_USART3			18
#define MRCC_APB1_UART4				19
#define MRCC_APB1_UART5				20
#define MRCC_APB1_I2C1				21
#define MRCC_APB1_I2C2				22
#define MRCC_APB1_USB				23
#define MRCC_APB1_CAN				25
#define MRCC_APB1_BKP				27
#define MRCC_APB1_PWR				28
#define MRCC_APB1_DAC				29

/* Functions Prototypes */
void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8Bus, u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8Bus, u8 Copy_u8PerId);

#endif
