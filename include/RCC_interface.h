

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/********************************* define buses *********************************/
#define RCC_AHB			1
#define RCC_APB1		2
#define RCC_APB2		3
/********************************* define clock source *********************************/
#define	RCC_HSE_CRYSTAL		1
#define RCC_HSE_RC 			2
#define RCC_HSI				3
#define RCC_PLL				4
/********************************* define PLL sources *********************************/
#define RCC_PLL_IN_HSI_DIV_2	1
#define RCC_PLL_IN_HSE_DIV_2	2
#define RCC_PLL_IN_HSE			3
/********************************* functions section *********************************/
void MRCC_voidInitSysClock(void);
void MRCC_voidEnablePeripheral(u8 Copy_IdBus,u8 Copy_Peripheral);
void MRCC_voidDisablePeripheral(u8 Copy_IdBus,u8 Copy_Peripheral);

#endif