#ifndef EXTI_PRIVET_H
#define EXTI_PRIVET_H

typedef struct {
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;

}EXTI_t ;

#define EXTI ((volatile EXTI_t *)0x40010400)

#define RISING          0
#define FALLING         1
#define ON_CHANE        2

#endif