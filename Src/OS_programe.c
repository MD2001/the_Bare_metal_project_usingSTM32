#include "BITMATH.h"
#include "STDTYPE.h"
#include "RCC_interface.h"
#include "SysTic_interface.h"
#include "OS_config.h"
#include "OS_privet.h"
#include "OS_interface.h"

volatile static TickCountOS=0;

void SOS_voidCreateTask(u16 Copy_id,u16 Copy_priority,void (*ptr)(void))
{
    Tasks_arr[Copy_id].priorite=Copy_priority;
    Tasks_arr[Copy_id].Ftpr=ptr;
}
void SOS_voidStartOS()
{
    /*intitalize the systick peripheral */
    MSysTic_voidInit();

    /* set the schedular for each 1ms */
    MSysTic_voidInterval(1000,Schedular);
}

static void Schedular()
{
    for(u8 i=0;i<=NUMBER_OF_TASKS;i++)
    {
        if((TickCountOS  %  Tasks_arr[i].priorite )==0)
        {
            Tasks_arr[i].Ftpr();
        }
    }


}
