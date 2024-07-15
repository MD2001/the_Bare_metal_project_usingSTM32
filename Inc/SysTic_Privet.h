#ifndef SYSTIC_PRIEVET_H
#define SYSTIC_PRIEVET_H


/********************************* Registers Map Section *********************************/
#define STK_CTRL 			*((volatile u32*)0xE000E010) 
#define STK_LOAD 			*((volatile u32*)0xE000E014) 
#define STK_VAL 			*((volatile u32*)0xE000E018) 
#define STK_CALIB 			*((volatile u32*)0xE000E01C) 
/********************************* Macros *********************************/
#define ENTIC   1
#define DISTIC  0
#define  AHPDIV   0
#define  AHPNODIV 1

#endif
