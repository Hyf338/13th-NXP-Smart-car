#ifndef INIT_H_
#define INIT_H_
#include "headfile.h"
void all_Init();
uint8 Bubble(uint8 *var);
void senser_collect();
float Abs(float i);
void vcan_sendware(uint8 *wareaddr, uint32 waresize);
#endif