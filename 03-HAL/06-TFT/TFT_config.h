/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	5 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/
#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H

/* Write pins in pairs port,pin */
#define HTFT_RST_PIN	MGPIOA,PIN1
#define HTFT_A0_PIN		MGPIOA,PIN2

/* Options: HTFT_RGB444,
			HTFT_RGB565,
			HTFT_RGB666 */
#define HTFT_CLR_MODE	HTFT_RGB565
#endif
