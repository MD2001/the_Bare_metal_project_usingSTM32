
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
#include "SysTic_interface.h"
#include "EXTI_interface.h"



/***************************** Function protype Section *****************************/
volatile u8 u8StartFlag       = 0;
volatile u32 u32FrameData[50] = {0};
volatile u8 u8EdgeCounter     = 0;

void voidTakeAction(void)
{
    asm("NOP");
}

void voidGetFrame(void)
{
    if (u8StartFlag == 0)
    {
        /* Start Timer */
        MSysTic_voidinterruptSingle(1000000, voidTakeAction);
        u8StartFlag = 1;
    }
    else
    {
        u32FrameData[u8EdgeCounter] = MSysTic_u32GetElapsedTime();
        MSysTic_voidinterruptSingle(1000000, voidTakeAction);
        u8EdgeCounter++;
    }
}




/***************************** main code Section *****************************/

int main()
{
	/* initialize the RCC to get 1MHz */
	MRCC_voidInitSysClock();
	MRCC_voidEnablePeripheral(RCC_APB2, 2); /*Enable GPIOA peripheral */

	/* initialize GPIOA peripheral */
	MGPIO_voidSetPinDirection(MGPIO_GPIOA, MGPIO_PIN0, MGPIO_Input_Floating); /* GPIOA0 floating input*/
	MGPIO_voidSetPinDirection(MGPIO_GPIOA, MGPIO_PIN1, MGPIO_Output_PP_2MHZ); /* GPIOA1 PP output*/
	MGPIO_voidSetPinDirection(MGPIO_GPIOA, MGPIO_PIN2, MGPIO_Output_PP_2MHZ); /* GPIOA2 PP output*/
	MGPIO_voidSetPinDirection(MGPIO_GPIOA, MGPIO_PIN3, MGPIO_Output_PP_2MHZ); /* GPIOA3 PP output*/

	/*EXTI0 initialization*/
	MEXTI_voidSetCallBack(voidGetFrame);
	MEXTI_voidInit();		/* EXTI0 and in falling edge mood*/

	/* Enable interrupts in EXTI0*/
	MNVIC_voidEnableInterrupt(6);

	/* Enable Systick peripheral */
	MSysTic_voidInit();		/*Enable Systick in AHP/8=1 MHz*/


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
2		Mohamed diaa	02OCT2024		Task_82 make test of IR remote on chip

*/




