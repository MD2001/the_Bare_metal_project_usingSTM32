#ifndef AFIO_CONFIG_H
#define AFIO_CONFIG_H

#define AFIO_EVCR         *((volatile u32 *)0x40010000)
#define AFIO_MAPR         *((volatile u32 *)0x40010004)
#define AFIO_EXTICR1      *((volatile u32 *)0x40010008)
#define AFIO_EXTICR2      *((volatile u32 *)0x4001000C)
#define AFIO_EXTICR3      *((volatile u32 *)0x40010010)
#define AFIO_EXTICR4      *((volatile u32 *)0x40010014)
#define AFIO_MAPR2        *((volatile u32 *)0x4001001C)


#define LINE0           0
#define LINE1           1
#define LINE2           2
#define LINE3           3
#define LINE4           4
#define LINE5           5
#define LINE6           6
#define LINE7           7
#define LINE8           8
#define LINE9           9
#define LINE10          10
#define LINE11          11
#define LINE12          12
#define LINE13          13
#define LINE14          14
#define LINE15          15

#define PORTA           0
#define PORTB           1
#define PORTC           2
#define PORTD           3
#define PORTE           4
#define PORTF           5
#define PORTG           6


#endif