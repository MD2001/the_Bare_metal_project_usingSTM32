#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

  #if LCD_MODE == LCD_8_BIT 
  /* use this function to set the LCD to 8-bit mode  */
    void HLCD_voidInit(void); 
  /*write function that use to send data to LCD */
    void HLCD_voidSendData(u8 Copy_data);
 /*write function that use to send Command to LCD */
    void HLCD_voidSendCommand(u8 Copy_data);

  #elif LCD_MODE == LCD_4_BIT
    /* use this function to set the LCD to 8-bit mode  */
      void HLCD_voidInit(void);
    /*write function that use to send data to LCD */
      void HLCD_voidSendData(u8 Copy_data);
   /*write function that use to send Command to LCD */
      void HLCD_voidSendCommand(u8 Copy_data);



  #else
   #error "you choise wrong configration"

  #endif
      /*use to write string on lcd*/
      void HLCD_voidSendString(u8 *Copy_u8Str);
      /*use to move curser in display*/
      void HLCD_voidGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

#endif

/*
*******************************************************************************
ID		User          Date            Detailes
*******************************************************************************
1		    Mohamed diaa	  07MAY2024 	  	Task_42 setup the files for LCD Driver
2       Mohamed diaa    08MAY2024       Task_43 creat functions  { init }
*/
