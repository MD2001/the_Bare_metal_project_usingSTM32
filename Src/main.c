
/*
******************************************************************************
* @file     : main.c														 *
* @Version  : 1.0.0															 *
* @Auther   : Mohamed diaa										 			 *
* @Detailes : the main application								     		 *
******************************************************************************
*/


/***************************** Includes Section *****************************/

#include "BITMATH.h"
#include "STDTYPE.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"



/***************************** Function protype Section *****************************/


/***************************** Globale variable Section *****************************/



/***************************** main code Section *****************************/

int main()
{
	MRCC_voidEnablePeripheral(RCC_GPIOAEnable);
	MGPIO_voidSetPinDirection(MGPIO_GPIOA, MGPIO_PIN0, MGPIO_AF_PP_2MHZ);
	MGPIO_voidSetPinDirection(MGPIO_GPIOA, MGPIO_PIN1, MGPIO_AF_PP_2MHZ);
	MGPIO_voidSetPinDirection(MGPIO_GPIOA, MGPIO_PIN2, MGPIO_AF_PP_2MHZ);

	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidSetPindingFlag(6);
    while(1)
    {
        
    }
    return 0;
}

void EXTI0_IRQHandler()
{
	MGPIO_voidSetPinValue(MGPIO_GPIOA, MGPIO_PIN0, MGPIO_High);
}

void EXTI1_IRQHandler()
{

}
/*
*******************************************************************************
ID		User          Date            Detailes
*******************************************************************************
1		Mohamed diaa	17Mar2024 		Task_11 mange the main file

*/




