#include "BITMATH.h"
#include "STDTYPE.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SysTic_interface.h"
#include "EXTI_interface.h"



void IR_u8Init()
{
    /* initialize the RCC to get 1MHz */
	MRCC_voidInitSysClock();
    	/*EXTI0 initialization*/
	MEXTI_voidSetCallBack(voidGetFrame);
    	/* Enable interrupts in EXTI0*/
	MNVIC_voidEnableInterrupt(6);

	/* Enable Systick peripheral */
	MSysTic_voidInit();		/*Enable Systick in AHP/8=1 MHz*/
}
static volatile u8  u8HasData          = 0;
static volatile u8  u8StartFlag         = 0;
static volatile u32 u32FrameData[50]    = {0};
static volatile u8  u8EdgeCounter       = 0;
static volatile u8  u8Data = 0;
static void voidTakeAction(void)
{

	u8Data = 0;

    if ((u32FrameData[0] >= 10000) &&( u32FrameData[0] <= 14000)) {

    for (u8 i = 0; i < 8; i++) {
        if ((u32FrameData[17 + i] >= 2000) &&( u32FrameData[17 + i] <= 2300)) {
            SET_BIT(u8Data, i);
        } else {
            CLR_BIT(u8Data, i);
        }
    }
    }
    else
    {
        /* Invalid frame*/
    }
    u8StartFlag       = 0;
    u32FrameData[0] = 0;
    u8EdgeCounter     = 0;
    u8Data = 0;
    u8HasData=1;
}

static void voidGetFrame(void)
{
    if (u8StartFlag == 0)
    {
        /* Start Timer */
        MSysTic_voidinterruptSingle(1000000, voidTakeAction);
        u8StartFlag = 1;
    }
    else
    {
        u32FrameData[u8EdgeCounter] = MSysTic_u32GetElapsedTime();
        MSysTic_voidinterruptSingle(1000000, voidTakeAction);
        u8EdgeCounter++;
    }
}

u32 IR_u32GetData()
{
    if(u8HasData==1)
    {u8HasData=0;
    return u32FrameData;

    }
}