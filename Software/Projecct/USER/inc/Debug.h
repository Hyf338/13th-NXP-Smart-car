#ifndef DUBUG_H_
#define DUBUG_H_
#include "headfile.h"

void display();
uint8 key_scan ();
void key_read();

#define Key_Dm gpio_get(D5) //dowm
#define Key_Lt gpio_get(I6) //left
#define Key_Up gpio_get(I5) //up
#define Key_Rt gpio_get(D7) //right
#define Key_Md gpio_get(D6) //Mi
#endif