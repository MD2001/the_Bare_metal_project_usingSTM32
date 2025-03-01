

/*
******************************************************************************
* @file     : SysTic.c														 *
* @Version  : 1.1.3															 *
* @Auther   : Mohamed diaa													 *
* @Detailes : the functions of SysTic										 *
******************************************************************************
*/


/***************************** Includes Section *****************************/
#include "BITMATH.h"
#include "STDTYPE.h"

#include "SysTic_interface.h"
#include "SysTic_Privet.h"
#include "SysTic_Config.h"

/****************************** Gloable variable Section ****************************************/

static void (*CallBack1) (void) = NULL_PTR_FUNCTION ;
static MsysTic_u8Mode = MSYSTIC_MODE_SINGLE;

/***************************** Code Section *********************************/


//Set Start value of load regester
void MSysTic_voidSetBusyWait(u32 Copy_u32Value)
{
    if(Copy_u32Value<=0x7FFFFF)              // if the value you enter is higher than 23-bit that is mean you enter not valied value 
    {
        STK_LOAD = Copy_u32Value;                      //Set the reload register value
        SET_BIT(STK_CTRL,0);                           ///Set the Enable value to enable counter
        while(GET_BIT(STK_CTRL,16)==0);                //bull up the prosessor till the load finsh 
    }
    else{
        //erorr
    }                       

}

// intialize some paramter the configerd in config file
void MSysTic_voidInit()
{
    if(CLOCK_SOURCE == AHPDIV)
    {
        CLR_BIT(STK_CTRL,2);        // Set the speed clock to AHP/8
    }
    else
    {
        SET_BIT(STK_CTRL,2);        // Set to AHP 
    }

    if(TICK_INTERRUPT == DISTIC) 
    {
        CLR_BIT(STK_CTRL,1);        // to disable the interrupt 
    }
    else
    {
        SET_BIT(STK_CTRL,1);        // to enable the interrupt
    }      
}


static void MSysTic_voidEnableInterrupt(void)
{
    SET_BIT(STK_CTRL,1);
}

static void MSysTic_voidDisableInterrupt(void)
{
    CLR_BIT(STK_CTRL,1);
}

void MSysTic_voidinterruptInterval(u32 Copy_u32Value,void (*Copy_ptr)(void))
{
    if(Copy_u32Value<=0x7FFFFF)                          // if the value you enter is higher than 23-bit that is mean you enter not valied value 
    {
        STK_LOAD = Copy_u32Value;                       //Set the reload register value
        SET_BIT(STK_CTRL,0);                            ///Set the Enable value to enable counter
    }
    else {
        //erorr
    }                       
    CallBack1 = Copy_ptr;                      //Set call back function 

    MSysTic_voidEnableInterrupt();                      // just for readablity
    /* Set mode to single Intervale */
    MsysTic_u8Mode = MSYSTIC_MODE_INTERVAL;
}

void MSysTic_voidinterruptSingle(u32 Copy_u32Value,void (*Copy_ptr)(void))
{
    /*Disable timer  */
    CLR_BIT(STK_CTRL,0);
    STK_VAL=0;

    if(Copy_u32Value<=0x7FFFFF)                          // if the value you enter is higher than 23-bit that is mean you enter not valied value 
    {
        STK_LOAD = Copy_u32Value;                       //Set the reload register value
        SET_BIT(STK_CTRL,0);                            ///Set the Enable value to enable counter
    }
    else {
        //erorr
    }                       
    CallBack1 = Copy_ptr;                      //Set call back function 

    MSysTic_voidEnableInterrupt();                      // just for readablity
    /* Set mode to single Intervale */
    MsysTic_u8Mode = MSYSTIC_MODE_SINGLE;
}

void MSysTic_voidStopTimer()
{
	STK_VAL=0;
	STK_LOAD=0;
	}

u32 MSysTic_u32GetElapsedTime()
{
    return STK_VAL;
}
/***************************** Handlers Section *********************************/

void SysTick_IRQHandler()
{
    if( MsysTic_u8Mode == MSYSTIC_MODE_SINGLE)
    {
        MSysTic_voidStopTimer();
    }
    CallBack1();
}


/*
*******************************************************************************
ID      User          Date            Detailes
*******************************************************************************
1       Mohamed diaa	27Mar2024 		Task_8 write & designe the files 
2       Mohamed diaa    15APR2024       Task19 write function {SetStartValue, init }
3       Mohamed diaa    16APR2024       Task_20 Write {Enable Interrupt , Disable interrupt}
4       Mohamed diaa    28APR2024       Task_28 write functuin { 
                                                                + change(set start value) <==> set busy wait
                                                                + interval timer (with call back function)
                                                                + Systick IRQ handler
                                                                }
                                                                + add glable variable section
                                                                + add handler section
5       Mohamed diaa    07OCT2024       Task93              make functions interaval and single & add single and interval options as variables
*/
