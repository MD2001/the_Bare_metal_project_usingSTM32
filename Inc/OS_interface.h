#ifndef  OS_INTERFACE_H
#define OS_INTERFACE_H

void SOS_voidCreateTask(u16 Copy_id,u16 Copy_priority,void (ptr*)(void));
void SOS_voidStartOS();
#endif