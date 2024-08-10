

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
	
	#define  RCC_PLL_INPUT	RCC_PLL_IN_HSE
/*this value must be between 2 and 16 and the max freq to the clock is 72 MHz*/ //4 is defult
	#define RCC_PLL_MULL_VALL	4
	
#endif
/*this value must be between 0 and 512 "(step by factor 2)" and the max freq to the clock is 72 MHz*/ //2 is defult
#define RCC_AHP_PRESCALLER	0
/*this value must be between 0 and 16 "(step by factor 2)" and the max freq to the clock is 36 MHz*/ //2 is defult
#define RCC_APB1_PRESCALLER	0
/*this value must be between 0 and 16 "(step by factor 2)" and the max freq to the clock is 72 MHz*/ //2 is defult
#define RCC_APB2_PRESCALLER	0

#endif	
