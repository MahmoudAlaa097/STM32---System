/***********************************************************************/
/* Author	:	Mahmoud Alaa                                           */
/* Date		:	6 FEB 2022                                             */
/* Version	:	V01											           */
/***********************************************************************/

#include "UART_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

void HESP_voidInit(void)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Disable ECHO */
		MUSART1_voidTransmit("ATE0\r\n");
		Local_u8Result = voidEspValidateCmd();
	}
	
	Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Set Station Mode */
		MUSART1_voidTransmit("AT+CWMODE=1\r\n");
		Local_u8Result = voidEspValidateCmd();
	}
}

void HESP_voidConnectWiFi(u8* Copy_u8UserName, u8* Copy_u8Password)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Connect to WiFi */
		MUSART1_voidTransmit("AT+CWJAP_CUR=\"%s\",\"%s\"\r\n", Copy_u8UserName, Copy_u8Password);
		Local_u8Result = voidEspValidateCmd();
	}
}

void HESP_voidConnectToServer(u8* Copy_u8IP)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Connect to Server */
		MUSART1_voidTransmit("AT+CIPSEND=\"TCP\",\"%s\",80\r\n", Copy_u8IP);
		Local_u8Result = voidEspValidateCmd();
	}
}

void HESP_voidSendData(u8* Copy_u8Length, u8* Copy_u8Link)
{
	u8 Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Send Data Length */
		MUSART1_voidTransmit("AT+CIPSEND=%s\r\n", Copy_u8Length);
		Local_u8Result = voidEspValidateCmd();
	}
	
	Local_u8Result = 0;
	
	while(Local_u8Result == 0)
	{
		/* Send Data */
		MUSART1_voidTransmit("GET%s\r\n", Copy_u8Length);
		Local_u8Result = voidEspValidateCmd();
	}
}

static u8 voidEspValidateCmd(void)
{
	u8 Local_u8Response[100] = {0};
	u8 Local_u8Index = 0;
	u8 Local_u8Temp = 0;
	
	while(Local_u8Temp != 255)
	{
		Local_u8Temp = MUSART1_u8Receive();
		Local_u8Response[Local_u8Index] = Local_u8Temp;
		Local_u8Index++;
	}
	
	/* Check if "OK" */
	if(Local_u8Response[0] == 'O' && Local_u8Response[1] == 'K')
	{
		Local_u8Result = 1;
	}
		
	return Local_u8Result;
}