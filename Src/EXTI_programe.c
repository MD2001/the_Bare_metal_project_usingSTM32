#include "BITMATH.h"
#include "STDTYPE.h"

#include "EXTI_privet.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

void void_MEXTIInit()
{
    #if EXTI_MODE == RISING
        SET_BIT(EXTI->RTSR,EXTI_LINE);
    #elif EXTI_MODE == FALLING
        SET_BIT(EXTI->FTSR,EXTI_LINE);
    #elif EXTI_MODE == ON_CHANE
        SET_BIT(EXTI->RTSR,EXTI_LINE);
        SET_BIT(EXTI->FTSR,EXTI_LINE);
    #else 
        #error "you choise wrong mode"
    #endif
}
void void_MEXTIEnableLine(u8 Copy_u8line)
{
    SET_BIT(EXTI->IMR,Copy_u8line);
}
void void_MEXTIDisableLine(u8 Copy_u8line)
{
    CLR_BIT(EXTI->IMR,Copy_u8line);
}
void void_MEXTISWInterupt(u8 Copy_u8line)
{
    SET_BIT(EXTI->SWIER,Copy_u8line);
}
void void_MEXTISignalLuche(u8 Copy_u8line, u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case RISING:    SET_BIT(EXTI->RTSR,Copy_u8line); break;
    case FALLING:   SET_BIT(EXTI->FTSR,Copy_u8line); break;
    case ON_CHANE:  SET_BIT(EXTI->RTSR,Copy_u8line);
                    SET_BIT(EXTI->FTSR,Copy_u8line); break;
    }
}
