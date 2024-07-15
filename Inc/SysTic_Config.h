#ifndef SYSTIC_CONFIG_H
#define SYSTIC_CONFIG_H





/****************************** Prameters Section *************************************/

#define  AHPDIV   0
#define  AHPNODIV 1
/**
 *      Options for RETURN_MODE 
 *        if you want AHP/8 then   "AHPDIV"         (defult)
 *        if you want AHP   then   "AHPNODIV"
 * 
*/
#define CLOCK_SOURCE    AHPDIV
/**********************************/

#define ENTIC   1
#define DISTIC  0
/**
 *  OPTIONS for TICKINT
 *  if you want to Enalble Interrupt if the counter reach zero ---> ENTIC
 *  if you want to Disalble Interrupt if the counter reach zero ---> DISTIC     (defult)
 * 
 * 
*/
#define TICK_INTERRUPT     DISTIC


#endif

/*
*******************************************************************************
ID      User          Date            Detailes
*******************************************************************************
1       Mohamed diaa	15APR2024 		Task_17 write & designe the files & set some configuration
                                                    {CLOCK_SOURCE , TICK_INTERRUPT}

*/