#include "BITMATH.h"
#include "STDTYPE.h"

#include "EXTI_privet.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"


static volatile void (*CALL_BACK_FUNC)(void);

void MEXTI_voidInit()
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
void MEXTI_voidEnableLine(u8 Copy_u8line)
{
    SET_BIT(EXTI->IMR,Copy_u8line);
}
void MEXTI_voidDisableLine(u8 Copy_u8line)
{
    CLR_BIT(EXTI->IMR,Copy_u8line);
}
void MEXTI_voidSWInterupt(u8 Copy_u8line)
{
    SET_BIT(EXTI->SWIER,Copy_u8line);
}
void MEXTI_voidSignalLuche(u8 Copy_u8line, u8 Copy_u8Mode)
{
    switch (Copy_u8Mode)
    {
    case RISING:    SET_BIT(EXTI->RTSR,Copy_u8line); break;
    case FALLING:   SET_BIT(EXTI->FTSR,Copy_u8line); break;
    case ON_CHANE:  SET_BIT(EXTI->RTSR,Copy_u8line);
                    SET_BIT(EXTI->FTSR,Copy_u8line); break;
    }
}

void MEXTI_voidSetCallBack(void(*ptf)(void))
{
	CALL_BACK_FUNC=ptf;
}

void EXTI0_IRQHandler()
{
	CALL_BACK_FUNC();

}
