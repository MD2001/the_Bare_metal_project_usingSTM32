
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*********************************** Macros Section ***********************************/


/* x menas how many digit ref to grpo and y ref to subgruop */

#define GROUP0         0x05FA0300    //0bxxxx    16 Group - None SupGroup
#define GROUP1         0x05FA0400    //0bxxxy    8 Group - 2 SupGroup
#define GROUP2         0x05FA0500    //0bxxyy    4 Group - 4 SupGroup
#define GROUP3         0x05FA0600    //0bxyyy    2 Group - 8 SupGroup
#define GROUP4         0x05FA0700    //0byyyy    None Group - 16 SupGroup


/********************************* Functions Prototype Section *********************************/

void MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptId);  //Enable the interrupt
void MNVIC_voidDisableInterrupt(u8 Copy_u8InterruptId); //Disaple the interrupt
void MNVIC_voidSetPindingFlag(u8 Copy_u8InterruptId);   //Set the pednding flag
void MNVIC_voidClearPindingFlag(u8 Copy_u8InterruptId); //clear the pednding flag
u8   MNVIC_u8ActiveFlagStause(u8 Copy_u8InterruptId);   //return the active flag statues
// void MNVIC_voidSetInterruptProirity(u8 Copy_u8InterruptId,u8 Copy_u8Value); //Set the interrupt proritty value  v1
void MNVIC_voidSWInterrupt(u8 Copy_u8InterruptId);  // generate Software interrupt 
void MNVIC_voidConfigPriortyMode(u8 Copy_u8Gropu); //to set the priority mode

void MNVIC_voidSetInterruptProirity(u8 Copy_u8InteruptId,u8 Copy_u8Group,u8 Copy_SubGroup); //Set the interrupt proritty value  v2
// depend on group mode the max subgroup and group is detrmind

#endif