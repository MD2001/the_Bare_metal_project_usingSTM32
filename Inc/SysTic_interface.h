#ifndef SYSTIC_INTERFACE_H
#define SYSTIC_INTERFACE_H

#define SyTi_MAX_DELAY          8388607 
/****************************** prototype Section ****************************************/
//Set Start value of load regester
//void MSysTic_voidSetStartValue(u32 Copy_Value);

// intialize some paramter the configerd in config file
void MSysTic_voidInit();
// Set busy wait fucation that hold the programe till time finish
void MSysTic_voidSetBusyWait(u32 Copy_u32Value);
// use to set interval timer interrupt 
void MSysTic_voidinterruptInterval(u32 Copy_u32Value,void (*Copy_ptr)(void));
// use to set single timer interrupt 
void MSysTic_voidinterruptSingle(u32 Copy_u32Value,void (*Copy_ptr)(void));
void MSysTic_voidStopTimer();
#endif




/*
*******************************************************************************
ID      User          Date            Detailes
*******************************************************************************
1       Mohamed diaa	15APR2024 		Task_18 write & designe the files & set some prototype
2       Mohamed diaa    16APR2024       Task_20 write function { Enable Interrupt , Disable interrupt}
3       Mohamed diaa    28APR2024       Task_28 write functuin {
                                                                change(set start value) <==> set busy wait
                                                                
                                                                }
5       Mohamed diaa    07OCT2024       Task93              make functions interaval and single & add single and interval options as variables
*/
