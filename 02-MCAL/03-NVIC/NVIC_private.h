/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	13 JAN 2022                                            */
/* Version	:	V01													   */
/***********************************************************************/

#ifndef NVIC_PRIVATE_H
#define	NVIC_PRIVATE_H

/* Peripheral Registers */
#define	NVIC_ISER0		*((u32*)0xE000E100)					/* Enable  External interrupts 0  from  to 31 */
#define	NVIC_ISER1		*((u32*)0xE000E104)					/* Enable  External interrupts 32 from  to 63 */
			
#define	NVIC_ICER0		*((u32*)0xE000E180)					/* Disable External interrupts 0  from  to 31 */
#define	NVIC_ICER1		*((u32*)0xE000E184)					/* Disable External interrupts 32 from  to 63 */
			
#define	NVIC_ISPR0		*((u32*)0xE000E200)					/* Set Pending Flag for External interrupts 0  from  to 31 */
#define	NVIC_ISPR1		*((u32*)0xE000E204)					/* Set Pending Flag for External interrupts 32 from  to 63 */

#define	NVIC_ICPR0		*((u32*)0xE000E280)					/* Clear Pending Flag for External interrupts 0  from  to 31 */
#define	NVIC_ICPR1		*((u32*)0xE000E284)					/* Clear Pending Flag for External interrupts 32 from  to 63 */

#define	NVIC_IABR0		*((volatile u32*)0xE000E300)		/* Set Pending Flag for External interrupts 0  from  to 31 */
#define	NVIC_IABR1		*((volatile u32*)0xE000E304)		/* Set Pending Flag for External interrupts 32 from  to 63 */

#define	NVIC_IPR		((volatile u8*)0xE000E400)

/* Priority Groups */
#define		MNVIC_GROUP_4_SUB_0		0x05FA0300	// 4 Bits for group
#define		MNVIC_GROUP_3_SUB_1		0x05FA0400	// 3 Bits for group and 1 bit for sub
#define		MNVIC_GROUP_2_SUB_2		0x05FA0500	// 2 Bits for group and 2 bits for sub
#define		MNVIC_GROUP_1_SUB_3		0x05FA0600	// 1 Bit  for group and 3 bits for sub
#define		MNVIC_GROUP_0_SUB_4		0x05FA0700	// 4 bit  for sub

#endif
