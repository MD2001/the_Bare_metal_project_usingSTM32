
/*
******************************************************************************
* @file     : main.c														 *
* @Version  : 1.0.0															 *
* @Auther   : Mohamed diaa										 			 *
* @Detailes : the main application								     		 *
******************************************************************************
*/


/***************************** Includes Section *****************************/

#include "BIT_MATH.h"
#include "STDTYPE.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"




/***************************** Function protype Section *****************************/


/***************************** Globale variable Section *****************************/



/***************************** main code Section *****************************/

int main()
{
    MRCC_voidInitSysClock();
    MRCC_voidEnablePeripheral(RCC_APB2, 2);
    MGPIO_voidSetPinDirection(MGPIO_GPIOA,MGPIO_PIN1,Output_PP_2MHZ);
    MGPIO_voidSetPinValue(MGPIO_GPIOC,MGPIO_PIN13,High);
    while(1)
    {
        
    }
    return 0;
}


/*
*******************************************************************************
ID		User          Date            Detailes
*******************************************************************************
1		Mohamed diaa	17Mar2024 		Task_11 mange the main file

*/
