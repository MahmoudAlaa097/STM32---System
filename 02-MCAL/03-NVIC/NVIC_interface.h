/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	13 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#ifndef NVIC_INTERFACE_H
#define	NVIC_INTERFACE_H

/* Functions Prototypes */
void MNVIC_voidInit(void);
void MNVIC_voidEnableInerrrupt	(u8 Copy_u8IntNumber);
void MNVIC_voidDisnableInerrrupt(u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag	(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag	(u8 Copy_u8IntNumber);
u8 MNVIC_u8GetPendingFlag		(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(u8 Copy_u8PeripheralIdx,u8 Copy_u8Priority);

/* NVIC Vectors */
#define	MNVIC_WWDG						0
#define MNVIC_PVD						1
#define MNVIC_TAMPER					2
#define MNVIC_RTC						3
#define MNVIC_FLASH						4
#define MNVIC_RCC						5
#define MNVIC_EXTI0						6
#define MNVIC_EXTI1						7
#define MNVIC_EXTI2						8
#define MNVIC_EXTI3						9
#define MNVIC_EXTI4						10
#define MNVIC_DMA1_CHANNEL1				11
#define MNVIC_DMA1_CHANNEL2          	12
#define MNVIC_DMA1_CHANNEL3          	13
#define MNVIC_DMA1_CHANNEL4          	14
#define MNVIC_DMA1_CHANNEL5          	15
#define MNVIC_DMA1_CHANNEL6          	16
#define MNVIC_DMA1_CHANNEL7          	17
#define MNVIC_ADC1_2                 	18
#define MNVIC_CAN_TX                 	19
#define MNVIC_CAN_RX0                	20
#define MNVIC_CAN_RX1                	21
#define MNVIC_CAN_SCE                	22
#define MNVIC_EXTI9_5                	23
#define MNVIC_TIM1_BRK               	24
#define MNVIC_TIM1_UP                	25
#define MNVIC_TIM1_TRG_COM           	26
#define MNVIC_TIM1_CC                	27
#define MNVIC_TIM2                   	28
#define MNVIC_TIM3                   	29
#define MNVIC_TIM4                   	30
#define MNVIC_I2C1_EV                	31
#define MNVIC_I2C1_ER                	32
#define MNVIC_I2C2_EV                	33
#define MNVIC_I2C2_ER                	34
#define MNVIC_SPI1                   	35
#define MNVIC_SPI2                   	36
#define MNVIC_USART1                 	37
#define MNVIC_USART2                 	38
#define MNVIC_USART3                 	39
#define MNVIC_EXTI15_10              	40
#define MNVIC_RTCALARM               	41
#define MNVIC_TIM8_BRK               	43
#define MNVIC_TIM8_UP                	44
#define MNVIC_TIM8_TRG_COM           	45
#define MNVIC_TIM8_CC                	46
#define MNVIC_ADC3                   	47
#define MNVIC_FSMC                   	48
#define MNVIC_SDIO                   	49
#define MNVIC_TIM5                   	50
#define MNVIC_SPI3                   	51
#define MNVIC_UART4                  	52
#define MNVIC_UART5                  	53
#define MNVIC_TIM6                   	54
#define MNVIC_TIM7                   	55
#define MNVIC_DMA2_CHANNEL1          	56
#define MNVIC_DMA2_CHANNEL2          	57
#define MNVIC_DMA2_CHANNEL3          	58
#define MNVIC_DMA2_CHANNEL4_5        	59


#endif
