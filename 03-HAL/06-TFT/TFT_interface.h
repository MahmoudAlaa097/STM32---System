/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	5 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

/* Functions Prototypes */
void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16* Copy_u16Image);
void HTFT_voidFillColor(u16 Copy_u16Color);

/* Color Modes */
#define HTFT_RGB444		0x03
#define HTFT_RGB565		0x05
#define HTFT_RGB666		0x06

#endif
