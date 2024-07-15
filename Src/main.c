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




/***************************** Function protype Section *****************************/


/***************************** Globale variable Section *****************************/



/***************************** main code Section *****************************/

int main()
{
	u8 Value=1;
	MRCC_voidInitSysClock();
    MRCC_voidEnablePeripheral(RCC_GPIOAEnable);
    MGPIO_voidSetPinDirection(MGPIO_GPIOA,MGPIO_PIN1,Output_PP_2MHZ);
    MGPIO_voidSetPinValue(MGPIO_GPIOA,MGPIO_PIN1,Value);
    while(1)
    {
    	if(Value==1){Value=0;}
    	else{Value=1;}
    	MGPIO_voidSetPinValue(MGPIO_GPIOA,MGPIO_PIN1,Value);
    	for(u32 x=1;x<100000;x++);
    }
    return 0;
}


/*
*******************************************************************************
ID		User          Date            Detailes
*******************************************************************************
1		Mohamed diaa	17Mar2024 		Task_11 mange the main file

*/
