#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_voidInit();
void MEXTI_voidEnableLine(u8 Copy_u8line);
void MEXTI_voidDisableLine(u8 Copy_u8line);
void MEXTI_voidSWInterupt(u8 Copy_u8line);
void MEXTI_voidSignalLuche(u8 Copy_u8line, u8 Copy_u8Mode);
void MEXTI_voidSetCallBack(void (*ptf)(void));
#endif
