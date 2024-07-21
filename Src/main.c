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

/***************************** Function protype Section *****************************/

/***************************** Globale variable Section *****************************/

/***************************** main code Section *****************************/

int main() {
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
	HLCD_voidSendData('S');
	HLCD_voidSendData('S');
	HLCD_voidSendData('S');
	HLCD_voidSendData('S');
	HLCD_voidSendData('W');
	HLCD_voidSendData('W');
	HLCD_voidSendData('W');
	HLCD_voidSendData('W');

	while (1) {



	}
	return 0;
}

/*
 *******************************************************************************
 ID		User          Date            Detailes
 *******************************************************************************
 1		Mohamed diaa	17Mar2024 		Task_11 mange the main file

 */
