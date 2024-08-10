#ifndef NVIC_PRIVET_H
#define NVIC_PRIVET_H



/********************************* Registers Map Section *********************************/
#define ISER0 			*((volatile u32*)0xE000E100)
#define ISER1 			*((volatile u32*)0xE000E104)
#define ISER2 			*((volatile u32*)0xE000E108)

#define ICER0 			*((volatile u32*)0xE000E180)
#define ICER1 			*((volatile u32*)0xE000E184)
#define ICER2 			*((volatile u32*)0xE000E188)

#define ISPR0 			*((volatile u32*)0xE000E200)
#define ISPR1 			*((volatile u32*)0xE000E204)
#define ISPR2 			*((volatile u32*)0xE000E208)

#define ICPR0 			*((volatile u32*)0xE000E280)
#define ICPR1 			*((volatile u32*)0xE000E284)
#define ICPR2 			*((volatile u32*)0xE000E288)

#define IABR0 			*((volatile u32*)0xE000E300)
#define IABR1 			*((volatile u32*)0xE000E304)
#define IABR2 			*((volatile u32*)0xE000E308)

#define IPR 			((volatile u8* )0xE000E400)
#define STIR            *((volatile u32*)0xE000EF00)

#define SCP_AIRCR       *((volatile u32*)0xE000ED0C)  
						
#endif                 