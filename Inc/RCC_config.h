

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/* Options :
			RCC_HSE_CRYSTAL	
			RCC_HSE_RC 		
			RCC_HSI			
			RCC_PLL			
*/

#define RCC_Clock_TYPE	RCC_HSI

/* Options:
			RCC_PLL_IN_HSI_DIV_2
			RCC_PLL_IN_HSE_DIV_2
			RCC_PLL_IN_HSE
	NOTE" Selected only if PLL is slected as input clock source
*/
#if RCC_Clock_TYPE == RCC_PLL
	
	#define  RCC_PLL_INPUT	RCC_PLL_IN_HSI_DIV_2	
	
#endif
#endif	
