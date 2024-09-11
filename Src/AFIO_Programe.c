#include "../../LIB/STDTYPE.h"
#include "../../LIB/BITMATH.h"

#include "AFIO_Privet.h"
#include "AFIO_Config.h"
#include "AFIO_Interface.h"

void void_MAFIOSetEXTIConfiguration(u8 Copy_u8Line, u8 Copy_PortMap)
{
    if (Copy_u8Line<=4)
    {
        AFIO_EXTICR1 &= ~((0b1111)<<(Copy_u8Line*4));
        AFIO_EXTICR1 |= ((Copy_PortMap)<<(Copy_u8Line*4));
    }
    else if (Copy_u8Line<=8)
    {
        Copy_u8Line%=4;
        AFIO_EXTICR2 &= ~((0b1111)<<(Copy_u8Line*4));
        AFIO_EXTICR2 |= ((Copy_PortMap)<<(Copy_u8Line*4));
    }
     else if (Copy_u8Line<=12)
    {
        Copy_u8Line%=4;
        AFIO_EXTICR3 &= ~((0b1111)<<(Copy_u8Line*4));
        AFIO_EXTICR3 |= ((Copy_PortMap)<<(Copy_u8Line*4));
    }
     else if (Copy_u8Line<=16)
    {
        Copy_u8Line%=4;
        AFIO_EXTICR4 &= ~((0b1111)<<(Copy_u8Line*4));
        AFIO_EXTICR4 |= ((Copy_PortMap)<<(Copy_u8Line*4));
    }
}