/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	13 FEB 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H

typedef struct
{
	volatile u32 	ACR;
	volatile u32	KEYR;
	volatile u32	OPTKEYR;
	volatile u32	SR;
	volatile u32	CR;
	volatile u32	RESERVED;
	volatile u32	OBR;
	volatile u32	WRPR;
}FPEC_Type;

#define		FPEC	((FPEC_Type*) 0x40022000)

#endif