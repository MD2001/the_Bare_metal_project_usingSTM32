
/*
******************************************************************************
* @file     : RCC.c														     *
* @Version  : 1.0.1															 *
* @Auther   : Mohamed diaa													 *
* @Detailes : the functions of RCC											 *
******************************************************************************
*/


/***************************** Includes Section *****************************/
#include "BITMATH.h"
#include "STDTYPE.h"

#include "RCC_interface.h"
#include "RCC_privet.h"
#include "RCC_config.h"
/***************************** Code Section *********************************/
void MRCC_voidInitSysClock(void)
{
	#if			RCC_Clock_TYPE	==	RCC_HSE_CRYSTAL	
				RCC_CR = 0x00010000;	//set HSEON HIGH / HSEBYP LOW
				RCC_CFGR = 0x00000001;	//Set Source clcok HSE
	#elif       RCC_Clock_TYPE	==  RCC_HSE_RC
				RCC_CR = 0x00050000;     //Set HSEON/HSEBYP HIGH
				RCC_CFGR = 0x00000001;	//Set Source clcok  HSE	
    #elif       RCC_Clock_TYPE	==  RCC_HSI	
				RCC_CR = 0x00000081;	// Set HSI HIGH + terming 0
				RCC_CFGR = 0x00000000; //Set Source clcok  HSI
    #elif       RCC_Clock_TYPE	==  RCC_PLL	
		#if 		RCC_PLL_INPUT ==RCC_PLL_IN_HSI_DIV_2
					RCC_CR= 0x01000001;		// Enable PLL & HSI
					RCC_CFGR = 0x00000002;	//Set HSI div 2
        #elif       RCC_PLL_INPUT ==RCC_PLL_IN_HSE_DIV_2
					RCC_CR= 0x01010000;		// Enable PLL & HSE
					RCC_CFGR = 0x00030002;	//Set HSE div 2
        #elif       RCC_PLL_INPUT == RCC_PLL_IN_HSE
					RCC_CR= 0x01010000;		// Enable PLL & HSE
					RCC_CFGR = 0x00010002;	//Set HSE no divide
		#else		
			#error "pll clock source is wrong"
		
		#endif
	#else 		
		#error "clock sourc type is worng"
	 
	#endif
}	



void MRCC_voidEnablePeripheral(u8 Copy_IdBus,u8 Copy_Peripheral)
{
	if(Copy_Peripheral<=31)
	{	
	switch(Copy_IdBus)
	{
		case RCC_AHB	:SET_BIT(RCC_AHBENR,Copy_Peripheral);break;
		case RCC_APB1   :SET_BIT(RCC_APB1ENR,Copy_Peripheral);break;
		case RCC_APB2   :SET_BIT(RCC_APB2ENR,Copy_Peripheral);break;
	}
	}
	else
	{
		//error
	}
	
}

void MRCC_voidDisablePeripheral(u8 Copy_IdBus,u8 Copy_Peripheral)
{
	if(Copy_Peripheral<=31)
	{	
	switch(Copy_IdBus)
	{
		case RCC_AHB	:CLR_BIT(RCC_AHBENR,Copy_Peripheral);break;
		case RCC_APB1   :CLR_BIT(RCC_APB1ENR,Copy_Peripheral);break;
	    case RCC_APB2   :CLR_BIT(RCC_APB2ENR,Copy_Peripheral);break;
	}
	}
	else
	{
		//error
	}
}

/*
*******************************************************************************
 User          Date            Detailes
*******************************************************************************
Mohamed diaa	17Mar2024 		Task_1 the main functions of RCC

*/
