/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	22 JAN 2022                                            */
/* Version	:	V01											           */
/***********************************************************************/

#ifndef	LEDMRX_PRIVATE_H
#define	LEDMRX_PRIVATE_H

u8 LEDMRX_u8Rows[8][2] = {LEDMRX_ROW0,LEDMRX_ROW1,LEDMRX_ROW2,LEDMRX_ROW3,LEDMRX_ROW4,LEDMRX_ROW5,LEDMRX_ROw6,LEDMRX_ROW7};
u8 LEDMRX_u8Cols[8][2] = {LEDMRX_COL0,LEDMRX_COL1,LEDMRX_COL2,LEDMRX_COL3,LEDMRX_COL4,LEDMRX_COL5,LEDMRX_COL6,LEDMRX_COL7};

/* Private Functions Prototypes */
static void HLEDMRX_voidDisableAllColumns(void);			//Disable All Columns
static void HLEDMRX_voidSetRowsValue(u8 Copy_u8Data);		//Set value to all rows

#endif
