/*
 ******************************************************************************
 * @file     : main.c														 *
 * @Version  : 1.0.0															 *
 * @Auther   : Mohamed diaa										 			 *
 * @Detailes : the main application								     		 *
 ******************************************************************************
 */

/***************************** Includes Section *****************************/
#include <stdint.h>
#include "BITMATH.h"
#include "STDTYPE.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SysTic_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_privet.h"

/***************************** Function protype Section *****************************/

/***************************** Globale variable Section *****************************/

/***************************** main code Section *****************************/

int main() {
	u32 x=0;
	MRCC_voidInitSysClock();
	MRCC_voidEnablePeripheral(RCC_GPIOAEnable);
	MRCC_voidEnablePeripheral(RCC_GPIOBEnable);
	MGPIO_voidSetPinDirection(MGPIO_GPIOA, MGPIO_PIN1, Output_PP_2MHZ);
	MGPIO_voidSetPinDirection(MGPIO_GPIOA, MGPIO_PIN2, Input_PullUp);
	MGPIO_voidSetPinDirection(MGPIO_GPIOA, MGPIO_PIN3, Output_PP_2MHZ);
	MGPIO_voidSetPinValue(MGPIO_GPIOA, MGPIO_PIN1, High);
	MGPIO_voidSetPinValue(MGPIO_GPIOA, MGPIO_PIN3, Low);
	MSysTic_voidInit();
	HLCD_voidInit();
	HLCD_voidSendCommand(Display_Clera);
//	HLCD_voidSendData(' ');
	HLCD_voidGotoXY(0,0);
	HLCD_voidSendString("Mohamed");
	HLCD_voidGotoXY(1,0);
	HLCD_voidSendString("diaa");
	HLCD_voidGotoXY(1,8);
	HLCD_voidSendString("Willcome");
	MSysTic_voidSetBusyWait(320000);
	HLCD_voidSendCommand(Display_Clera);
	HLCD_voidGotoXY(0, 3);
	HLCD_voidSendString("Start");
	HLCD_voidGotoXY(1, 5);
	HLCD_voidSendString("New_Session");
	while (1) {
		HLCD_voidGotoXY(0, 0);
		HLCD_voidSendCommand(Display_Clera);
		MSysTic_voidSetBusyWait(320000);
		x++;
		HLCD_voidSendData(x);
		MSysTic_voidSetBusyWait(320000);


	}
	return 0;
}

/*
 *******************************************************************************
 ID		User          Date            Detailes
 *******************************************************************************
 1		Mohamed diaa	17Mar2024 		Task_11 mange the main file

 */
