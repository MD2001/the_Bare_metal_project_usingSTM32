/*
 ******************************************************************************
 * @file     : LCD.c															 *
 * @Version  : 1.0.0															 *
 * @Auther   : Mohamed diaa													 *
 * @Detailes : the functions of LCD											 *
 ******************************************************************************
 */

/***************************** Includes Section *****************************/
#include "BITMATH.h"
#include "STDTYPE.h"

#include "LCD_interface.h"
#include "LCD_privet.h"
#include "LCD_config.h"

#include "GPIO_interface.h"
#include "SysTic_interface.h"
/************************* Globale Variable section *****************************/
static u8 Function_Set = 0b00100000 | ((DL << 4) | ((N << 3) | (F << 2)));
static u8 Entery_mode = 0b00000100 | ((SH << 1) | ID);
static u8 Display_ON_OFF = 0b00001000 | (((D << 2) | C << 1) | B);
static u8 Init_Pins = 0;

/***************************** Code Section *********************************/
#if LCD_MODE == LCD_8_BIT
  /* use this function to set the LCD to 8-bit mode  */
    void HLCD_voidInit(void)
    { 
        MSysTic_voidSetBusyWait(520000);   //requier to initalize the systic peripheral 40ms 72MHz
        HLCD_voidSendCommand(Function_Set);
        MSysTic_voidSetBusyWait(13000);
        HLCD_voidSendCommand(Display_ON_OFF);
        MSysTic_voidSetBusyWait(13000);
        HLCD_voidSendCommand(Display_Clera);
        MSysTic_voidSetBusyWait(26000);
        HLCD_voidSendCommand(Entery_mode);
    } 
    
     /*write function that use to send Command to LCD */
    void HLCD_voidSendCommand(u8 Copy_data)
    {
        HLCD_voidInitPins();
        MGPIO_voidSetPinValue(RS,MGPIO_Low);     // Clear RS MGPIO_Low
        MSysTic_voidSetBusyWait(13000);             //requier to initalize the systic peripheral 1ms 72MHz 
        MGPIO_voidSetPinValue(RW,MGPIO_Low);      // Clear RW MGPIO_low
        MSysTic_voidSetBusyWait(13000); 
        MGPIO_voidSetPinValue(EN,MGPIO_High);     // Set EN MGPIO_high
        MSysTic_voidSetBusyWait(26000);     // wiat 2ms 72MHz

        MGPIO_voidSetPinValue(DB0,GET_BIT(Copy_data,0));        /*send data to LCD in DB0*/
        MGPIO_voidSetPinValue(DB1,GET_BIT(Copy_data,1));        /*send data to LCD in DB1*/
        MGPIO_voidSetPinValue(DB2,GET_BIT(Copy_data,2));        /*send data to LCD in DB2*/
        MGPIO_voidSetPinValue(DB3,GET_BIT(Copy_data,3));        /*send data to LCD in DB3*/
        MGPIO_voidSetPinValue(DB4,GET_BIT(Copy_data,4));        /*send data to LCD in DB4*/
        MGPIO_voidSetPinValue(DB5,GET_BIT(Copy_data,5));        /*send data to LCD in DB5*/
        MGPIO_voidSetPinValue(DB6,GET_BIT(Copy_data,6));        /*send data to LCD in DB6*/
        MGPIO_voidSetPinValue(DB7,GET_BIT(Copy_data,7));        /*send data to LCD in DB7*/

        MGPIO_voidSetPinValue(EN,MGPIO_Low);     // Clear EN MGPIO_low
    }


    /*write function that use to send data to LCD */
    void HLCD_voidSendData(u8 Copy_data)
    {   
        HLCD_voidInitPins();
        MGPIO_voidSetPinValue(RS,MGPIO_High);     // Set RS MGPIO_high
        MSysTic_voidSetBusyWait(13000);             //requier to initalize the systic peripheral 1ms 72MHz 
        MGPIO_voidSetPinValue(RW,MGPIO_Low);      // Clear RW MGPIO_low
        MSysTic_voidSetBusyWait(13000); 
        MGPIO_voidSetPinValue(EN,MGPIO_High);     // Set EN MGPIO_high
        MSysTic_voidSetBusyWait(26000);     // wiat 2ms 72MHz

        MGPIO_voidSetPinValue(DB0,GET_BIT(Copy_data,0));        /*sed data to LCD in DB0*/
        MGPIO_voidSetPinValue(DB1,GET_BIT(Copy_data,1));        /*sed data to LCD in DB1*/
        MGPIO_voidSetPinValue(DB2,GET_BIT(Copy_data,2));        /*sed data to LCD in DB2*/
        MGPIO_voidSetPinValue(DB3,GET_BIT(Copy_data,3));        /*sed data to LCD in DB3*/
        MGPIO_voidSetPinValue(DB4,GET_BIT(Copy_data,4));        /*sed data to LCD in DB4*/
        MGPIO_voidSetPinValue(DB5,GET_BIT(Copy_data,5));        /*sed data to LCD in DB5*/
        MGPIO_voidSetPinValue(DB6,GET_BIT(Copy_data,6));        /*sed data to LCD in DB6*/
        MGPIO_voidSetPinValue(DB7,GET_BIT(Copy_data,7));        /*sed data to LCD in DB7*/

        MGPIO_voidSetPinValue(EN,MGPIO_Low);     // Clear EN MGPIO_low
        
    }
    /*to chick if the right pins get config in right way*/
       static void HLCD_voidInitPins(void)
       {
           if (Init_Pins==0)
           {
               MGPIO_voidSetPinDirection(RS,PINS_MODE);
               MGPIO_voidSetPinDirection(RW,PINS_MODE);
               MGPIO_voidSetPinDirection(EN,PINS_MODE);

               MGPIO_voidSetPinDirection(DB0,PINS_MODE);
               MGPIO_voidSetPinDirection(DB1,PINS_MODE);
               MGPIO_voidSetPinDirection(DB2,PINS_MODE);
               MGPIO_voidSetPinDirection(DB3,PINS_MODE);
               MGPIO_voidSetPinDirection(DB4,PINS_MODE);
               MGPIO_voidSetPinDirection(DB5,PINS_MODE);
               MGPIO_voidSetPinDirection(DB6,PINS_MODE);
               MGPIO_voidSetPinDirection(DB7,PINS_MODE);
               Init_Pins=1;
           }
       }

  #elif LCD_MODE == LCD_4_BIT

/*to chick if the right pins get config in right way*/
static void HLCD_voidInitPins(void) {
	if (Init_Pins == 0) {
		MGPIO_voidSetPinDirection(RS, PINS_MODE);
		MGPIO_voidSetPinDirection(RW, PINS_MODE);
		MGPIO_voidSetPinDirection(EN, PINS_MODE);

		MGPIO_voidSetPinDirection(DB4, PINS_MODE);
		MGPIO_voidSetPinDirection(DB5, PINS_MODE);
		MGPIO_voidSetPinDirection(DB6, PINS_MODE);
		MGPIO_voidSetPinDirection(DB7, PINS_MODE);
		Init_Pins = 1;
	}
}

/* use this function to set the LCD to 4-bit mode  */
void HLCD_voidInit(void) {
	MSysTic_voidSetBusyWait(520000); //requier to initalize the systic peripheral 40ms 72MHz
	HLCD_voidInitPins();

	MGPIO_voidSetPinValue(RS, MGPIO_Low);     // Clear RS MGPIO_Low
	MSysTic_voidSetBusyWait(13000); //requier to initalize the systic peripheral 1ms 72MHz
	MGPIO_voidSetPinValue(RW, MGPIO_Low);      // Clear RW MGPIO_low
	MSysTic_voidSetBusyWait(13000);
	MGPIO_voidSetPinValue(EN, MGPIO_High);     // Set EN MGPIO_high
	MSysTic_voidSetBusyWait(26000);     // wiat 2ms 72MHz

	MGPIO_voidSetPinValue(DB4, GET_BIT(Function_Set, 4)); /*send data to LCD in DB4*/
	MGPIO_voidSetPinValue(DB5, GET_BIT(Function_Set, 5)); /*send data to LCD in DB5*/
	MGPIO_voidSetPinValue(DB6, GET_BIT(Function_Set, 6)); /*send data to LCD in DB6*/
	MGPIO_voidSetPinValue(DB7, GET_BIT(Function_Set, 7)); /*send data to LCD in DB7*/
	MGPIO_voidSetPinValue(EN, MGPIO_Low);     // Set EN MGPIO_Low

	MSysTic_voidSetBusyWait(26000);     // wiat 2ms 72MHz
	HLCD_voidSendCommand(Function_Set);
	MSysTic_voidSetBusyWait(13000);
	HLCD_voidSendCommand(Display_ON_OFF);
	MSysTic_voidSetBusyWait(13000);
	HLCD_voidSendCommand(Display_Clera);
	MSysTic_voidSetBusyWait(26000);
	HLCD_voidSendCommand(Entery_mode);

}

/*write function that use to send Command to LCD */
void HLCD_voidSendCommand(u8 Copy_data) {
	HLCD_voidInitPins();
	MGPIO_voidSetPinValue(RS, MGPIO_Low);     // Clear RS MGPIO_Low
	MSysTic_voidSetBusyWait(13000); //requier to initalize the systic peripheral 1ms 72MHz
	MGPIO_voidSetPinValue(RW, MGPIO_Low);      // Clear RW MGPIO_low
	MSysTic_voidSetBusyWait(13000);
	MGPIO_voidSetPinValue(EN, MGPIO_High);     // Set EN MGPIO_high
	MSysTic_voidSetBusyWait(26000);     // wiat 2ms 72MHz

	MGPIO_voidSetPinValue(DB4, GET_BIT(Copy_data, 4)); /*send data to LCD in DB4*/
	MGPIO_voidSetPinValue(DB5, GET_BIT(Copy_data, 5)); /*send data to LCD in DB5*/
	MGPIO_voidSetPinValue(DB6, GET_BIT(Copy_data, 6)); /*send data to LCD in DB6*/
	MGPIO_voidSetPinValue(DB7, GET_BIT(Copy_data, 7)); /*send data to LCD in DB7*/
	MGPIO_voidSetPinValue(EN, MGPIO_Low);     // Clear EN MGPIO_low
	MSysTic_voidSetBusyWait(26000);     // wiat 2ms 72MHz
	MGPIO_voidSetPinValue(EN, MGPIO_High);     // Set EN MGPIO_high
	MSysTic_voidSetBusyWait(26000);     // wiat 2ms 72MHz
	MGPIO_voidSetPinValue(DB4, GET_BIT(Copy_data, 0)); /*send data to LCD in DB4*/
	MGPIO_voidSetPinValue(DB5, GET_BIT(Copy_data, 1)); /*send data to LCD in DB5*/
	MGPIO_voidSetPinValue(DB6, GET_BIT(Copy_data, 2)); /*send data to LCD in DB6*/
	MGPIO_voidSetPinValue(DB7, GET_BIT(Copy_data, 3)); /*send data to LCD in DB7*/

	MGPIO_voidSetPinValue(EN, MGPIO_Low);     // Clear EN MGPIO_low
}

/*write function that use to send data to LCD */
void HLCD_voidSendData(u8 Copy_data) {
	HLCD_voidInitPins();
	MGPIO_voidSetPinValue(RS, MGPIO_High);     // Set RS MGPIO_high
	MSysTic_voidSetBusyWait(13000); //requier to initalize the systic peripheral 1ms 72MHz
	MGPIO_voidSetPinValue(RW, MGPIO_Low);      // Clear RW MGPIO_low
	MSysTic_voidSetBusyWait(13000);
	MGPIO_voidSetPinValue(EN, MGPIO_High);     // Set EN MGPIO_high
	MSysTic_voidSetBusyWait(26000);     // wiat 2ms 72MHz

	MGPIO_voidSetPinValue(DB4, GET_BIT(Copy_data, 4)); /*send data to LCD in DB4*/
	MGPIO_voidSetPinValue(DB5, GET_BIT(Copy_data, 5)); /*send data to LCD in DB5*/
	MGPIO_voidSetPinValue(DB6, GET_BIT(Copy_data, 6)); /*send data to LCD in DB6*/
	MGPIO_voidSetPinValue(DB7, GET_BIT(Copy_data, 7)); /*send data to LCD in DB7*/
	MGPIO_voidSetPinValue(EN, MGPIO_Low);     // Clear EN MGPIO_low
	MSysTic_voidSetBusyWait(26000);     // wiat 2ms 72MHz
	MGPIO_voidSetPinValue(EN, MGPIO_High);     // Set EN MGPIO_high
	MSysTic_voidSetBusyWait(26000);     // wiat 2ms 72MHz
	MGPIO_voidSetPinValue(DB4, GET_BIT(Copy_data, 0)); /*send data to LCD in DB4*/
	MGPIO_voidSetPinValue(DB5, GET_BIT(Copy_data, 1)); /*send data to LCD in DB5*/
	MGPIO_voidSetPinValue(DB6, GET_BIT(Copy_data, 2)); /*send data to LCD in DB6*/
	MGPIO_voidSetPinValue(DB7, GET_BIT(Copy_data, 3)); /*send data to LCD in DB7*/

	MGPIO_voidSetPinValue(EN, MGPIO_Low);     // Clear EN MGPIO_low
	MSysTic_voidSetBusyWait(26000);     // wiat 2ms 72MHz
}

#else
   #error "you choise wrong configration"

  #endif
void HLCD_voidSendString(u8 *Copy_u8Str)
{

    while (*Copy_u8Str != '\0')
    {
    	HLCD_voidSendData(*Copy_u8Str);
        Copy_u8Str++;
    }
}

void HLCD_voidGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{

    u8 Local_u8Address = 0;

    if (Copy_u8XPos == 0)
    {
        Local_u8Address = Copy_u8YPos;
    }

    else if (Copy_u8XPos == 1)
    {

        Local_u8Address = 0x40 + Copy_u8YPos;
    }

    //Send this adderess to the DDram  128 + Local_u8Address because of the 1 in bit 7 of data sheet

    HLCD_voidSendCommand(0b010000000 + Local_u8Address);
}
/*
 *******************************************************************************
 ID		User          Date            Detailes
 *******************************************************************************
 1		Mohamed diaa	07MAY2024 		Task_42 setup the files for LCD Driver
 2       Mohamed diaa    08MAY2024       Task_43 creat functions  { init }
 */
