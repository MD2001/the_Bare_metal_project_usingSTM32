
/*
******************************************************************************
* @file     : NVIC.c														 *
* @Version  : 1.1.4															 *
* @Auther   : Mohamed diaa													 *
* @Detailes : the functions of NVIC											 *
******************************************************************************
*/


/***************************** Includes Section *****************************/
#include "BIT_MATH.h"
#include "STDTYPE.h"

#include "NVIC_interface.h"
#include "NVIC_privet.h"
#include "NVIC_config.h"

/***************************** Code Section *********************************/

void MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptId)
{
    if(Copy_u8InterruptId > 67)
    {
        if(Copy_u8InterruptId<=31)
        {
            SET_BIT(ISER0,Copy_u8InterruptId);
        }
        else if (Copy_u8InterruptId<=63)
        {
            SET_BIT(ISER1,Copy_u8InterruptId);
        }
        else if(Copy_u8InterruptId<=67)
        {
            SET_BIT(ISER2,Copy_u8InterruptId);
        }
    }
    else
    {
       /*error*/
    }
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8InterruptId)
{
    if(Copy_u8InterruptId > 67)
    {
        if(Copy_u8InterruptId<=31)
        {
            SET_BIT(ICER0,Copy_u8InterruptId);
        }
        else if (Copy_u8InterruptId<=63)
        {
            SET_BIT(ICER1,Copy_u8InterruptId);
        }
        else if(Copy_u8InterruptId<=67)
        {
            SET_BIT(ICER2,Copy_u8InterruptId);
        }
    }
    else
    {
        /*error*/
    }
}

void MNVIC_voidSetPindingFlag(u8 Copy_u8InterruptId)
{
    if(Copy_u8InterruptId > 67)
    {
        if(Copy_u8InterruptId<=31)
        {
            SET_BIT(ISPR0,Copy_u8InterruptId);
        }
        else if (Copy_u8InterruptId<=63)
        {
            SET_BIT(ISPR1,Copy_u8InterruptId);
        }
        else if(Copy_u8InterruptId<=67)
        {
            SET_BIT(ISPR2,Copy_u8InterruptId);
        }
    }
    else
    {
         /*error*/
    }
}

void MNVIC_voidClearPindingFlag(u8 Copy_u8InterruptId)
{
    if(Copy_u8InterruptId > 67)
    {
        if(Copy_u8InterruptId<=31)
        {
            SET_BIT(ICPR0,Copy_u8InterruptId);
        }
        else if (Copy_u8InterruptId<=63)
        {
            SET_BIT(ICPR1,Copy_u8InterruptId);
        }
        else if(Copy_u8InterruptId<=67)
        {
            SET_BIT(ICPR2,Copy_u8InterruptId);
        }
    }
    else
    {
        /*error*/
    }
}

//u8   MNVIC_u8ActiveFlagStause(u8 Copy_u8InterruptId)
//{
//    if(Copy_u8InterruptId > 67)
//    {
//        if(Copy_u8InterruptId<=31)
//        {
//            return GET_BIT(ICPR0,Copy_u8InterruptId);
//        }
//        else if (Copy_u8InterruptId<=63)
//        {
//           return GET_BIT(ICPR1,Copy_u8InterruptId);
//        }
//        else if(Copy_u8InterruptId<=67)
//        {
//           return GET_BIT(ICPR2,Copy_u8InterruptId);
//        }
//    }
//    else
//    {
//    	return 0;
//         /*error*/
//    }
//}

// void MNVIC_voidSetInterruptProirity(u8 Copy_u8InterruptId,u8 Copy_u8Value)
// {

//     IPR[Copy_u8InterruptId] = Copy_u8Value;                                      //v1

// }

void MNVIC_voidSWInterrupt(u8 Copy_u8InterruptId)
{
    STIR = Copy_u8InterruptId;
}

void MNVIC_voidConfigPriortyMode(u8 Copy_u8Gropu)
{
   SCP_AIRCR = Copy_u8Gropu;
}

void MNVIC_voidSetInterruptProirity(u8 Copy_u8InteruptId,u8 Copy_u8Group,u8 Copy_SubGroup)
{
    Copy_SubGroup |= Copy_u8Group << ((GROUP_MODE-0x5FA0300)/256);                  //v2

    IPR[Copy_u8InteruptId] = (Copy_SubGroup << 4);

}


/*
*******************************************************************************
ID      User          Date            Detailes
*******************************************************************************
1       Mohamed diaa	17Mar2024 		Task_3 write & designe the files 
2       Mohamed diaa    18Mar2024       Task_4 write (
                                                        Enable Interrupt,
                                                        Disable Interrupt,
                                                        Pednding flag,
                                                        Get active flage stuates
                                                    ) Function

3       Mohamed diaa    20Mar2024       Task_5 write (
                                                        Set Interrupt Proirity : leave the shape of priorty Enterd by user v1,
                                                        generate Software intterrupt 
                                                    ) Function 
4       Mohamed diaa    26Mar2024       Task_6 write (  Config priorit group mode  )
5       Mohamed diaa    27Mar2024       Task_7 Modifay ( Set Interrupt Proirit function : ask user for #grpup & #subgroup v2)
6       Mohamed diaa    28Mar2024       Task_9 solve some error 
                                                                {
                                                                   1- #include incorecte path
                                                                   2- some uncorecte decler in some regesters (ICPR1 , ICPR2)
                                                                   3- wrong defention of IPR regester : remove * in defention to use IPR as pointer 
                                                                }
*/
