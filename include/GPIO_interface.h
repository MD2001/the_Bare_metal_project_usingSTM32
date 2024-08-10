
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define MGPIO_GPIOA	0
#define MGPIO_GPIOB	1
#define MGPIO_GPIOC	2

#define MGPIO_PIN0	0	
#define MGPIO_PIN1	1	
#define MGPIO_PIN2	2	
#define MGPIO_PIN3	3	
#define MGPIO_PIN4	4	
#define MGPIO_PIN5	5	
#define MGPIO_PIN6	6	
#define MGPIO_PIN7	7	
#define MGPIO_PIN8	8	
#define MGPIO_PIN9	9	
#define MGPIO_PIN10	10	
#define MGPIO_PIN11	11	
#define MGPIO_PIN12	12	
#define MGPIO_PIN13	13	
#define MGPIO_PIN14	14	
#define MGPIO_PIN15	15	

#define Output_PP_10MHZ				0b0001
#define Output_PP_2MHZ				0b0010
#define Output_PP_50MHZ				0b0011

#define Output_OpenDrain_10MHZ		0b0101
#define Output_OpenDrain_2MHZ		0b0110
#define Output_OpenDrain_50MHZ		0b0111

#define AF_PP_10MHZ					0b1001
#define AF_PP_2MHZ					0b1010
#define AF_PP_50MHZ					0b1011
						
#define AF_OpenDrain_10MHZ			0b1101
#define AF_OpenDrain_2MHZ			0b1110
#define AF_OpenDrain_50MHZ			0b1111

#define Input_Analog				0b0000
#define Input_Floating				0b0100
#define Input_PullUp				0b1000	// Set ODR Register to 1
#define Input_PullDown				0b1000	// Set ODR Register to 0

#define High	1
#define Low		0

void MGPIO_voidSetPinDirection(u8 Copy_Port,u8 Copy_Pin,u8 Copy_Mode);
void MGPIO_voidSetPinValue(u8 Copy_Port,u8 Copy_Pin,u8 Copy_Value);
void MGPIO_voidSetPortValue(u8 Copy_Port,u8 Copy_Value);


u8 	 MGPIO_u8GetPinValue(u8 Copy_Port,u8 Copy_Pin);

#endif