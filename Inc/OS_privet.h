#ifndef  OS_PRIVET_H
#define OS_PRIVET_H

typedef struct 
{
    u16 priorite;
    void(*Ftpr)(void);
}task;

task Tasks_arr[NUMBER_OF_TASKS]={nullptr};

#endif