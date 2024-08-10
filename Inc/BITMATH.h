/*****************************************/
/*        Author: Mohmaed diaa           */
/*        Version: 2.1                   */
/*        Date:30 jun 2023               */
/*****************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/*Bit-Math macros*/
#define SET_BIT(REG , BIT)     REG |= 1<<BIT
#define CLR_BIT(REG , BIT)     REG &= ~(1<<BIT)
#define TOG_BIT(REG , BIT)     REG ^= 1<<BIT
#define GET_BIT(REG , BIT)     ((REG >> BIT) & 1)


#define NULL_PTR_FUNCTION ((void *)0)

#define CONCATE(x,y)        x##y

#endif