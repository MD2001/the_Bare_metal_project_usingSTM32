#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void void_MEXTIInit();
void void_MEXTIEnableLine(u8 Copy_u8line);
void void_MEXTIDisableLine(u8 Copy_u8line);
void void_MEXTISWInterupt(u8 Copy_u8line);
void void_MEXTISignalLuche(u8 Copy_u8line, u8 Copy_u8Mode);
#endif