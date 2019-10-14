#include "headfile.h"
float Z_zero_gyro_out=0;
float Z_base_data=0;
float Z_Dir_Gyro_data=0;


void get_Gyroscope_zero()//≤…ºØ¡„∆Æ
{
   float Gyro_zero_Z=0;
   for(uint8 i=0;i<200;i++)
   Gyro_zero_Z+=GetData(GYRO_ZOUT_H);
   Z_zero_gyro_out=Gyro_zero_Z/200;
}
 void get_Gyroscope_data()
 {
   Z_base_data=GetData(GYRO_ZOUT_H);
   Z_Dir_Gyro_data= Z_base_data-Z_zero_gyro_out;


 }
