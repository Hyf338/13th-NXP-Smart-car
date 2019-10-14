/*********************************************************************************************************************
* COPYRIGHT NOTICE
* Copyright (c) 2017,逐飞科技
* All rights reserved.
* 技术讨论QQ群：179029047
*
* 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
* 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
*
* @file       		main
* @company	   		成都逐飞科技有限公司
* @author     		逐飞科技(QQ3184284598)
* @version    		v2.0
* @Software 		IAR 7.7 or MDK 5.23
* @Target core		S9KEA128AMLK
* @Taobao   		https://seekfree.taobao.com/
* @date       		2017-11-6
********************************************************************************************************************/

#include "headfile.h"
#define senser_max  (FLASH_SECTOR_NUM -1)
#define straight_max  (FLASH_SECTOR_NUM -2)

uint8 normal= 0;//这两个是归一化标志位
uint8 boma=0 ;
uint8 adc[5]= {0};
uint8 senmax[3]= {0};
uint8 straight[2]= {0};
extern int16 Motor_right;
extern int16 Motor_left;
float Disbuff[8]={0};
float Display[8]={0};

extern uint8 ser_right, ser_left, ser_middle;
extern float ser_err;
extern int16 ser_duty;
extern uint8 bluetooth_flag;
extern uint8 start_flag;
extern uint8 open_flag ;
extern uint8 round_flag;
extern int16 motor_pulse_speed;
extern int16 Expect_speed;
extern  int16 actual_speed;
extern float  Z_Dir_Gyro_data;//z轴陀螺仪，最后没用
extern uint8 round_turn ;
extern float ser_ec;
extern  float k_p;
extern int16 right_count,left_count ;

extern uint8 straight_left;
extern uint8 straight_right;
extern uint8 ser_left,ser_right,ser_middle;
extern float ser_err;
extern uint16 round_hight;
extern uint8 round_low;
extern uint8 out_flag;
extern uint8 out_round;
uint8 direction_stop_flag=0;
uint8 speed_switch=0;
extern uint8 threshold;
extern uint16 k_d;
extern float PID_P;
extern float PID_I;
extern uint8 stop;
extern uint8 stop_count;


void main(void)
{
  uint8 Buf1[20]={0};
  uint8 Buf2[20]={0};
  uint8 Buf3[20]={0}; 
  uint8 Buf4[20]={0};
  uint8 Buf5[20]={0};
  
  /// uint8 Buf4[20]={0};
  DisableInterrupts;
  get_clk();              //获取时钟频率 必须执行
  all_Init();
  
  LCD_Print(10,3,"Welcome");
  LCD_Print(10,5,"My smart car");
  systick_delay_ms(1000) ;
  LCD_Fill(0x00);
  systick_delay_ms(500);
  // get_Gyroscope_zero();  //采集零飘的值。
  //  systick_delay_ms(1000);
  normal=(gpio_get(C2)==0? 1:0);//拨码四
  
  if(normal==1)
  {
    LCD_Fill(0x00);
    //归一化采最大最小值；
    while(normal)
    {
      for(int i=0;i<20;i++)
      {
        Buf1[i]= adc_once(ADC0_SE12,ADC_8bit);
        Buf2[i]= adc_once(ADC0_SE8,ADC_8bit);
        Buf3[i]= adc_once(ADC0_SE14,ADC_8bit);
      }
      adc[0]=Bubble(Buf1);//左
      adc[1]=Bubble(Buf2);//右
      adc[2]=Bubble(Buf3);//中
      for(uint8 i=0;i<3;i++)
      {
        if(adc[i]>senmax[i])
          senmax[i]=adc[i];
      }
      normal=(gpio_get(C2)==0?1:0);
      LCD_Print(2,0,"L");
      Dis_Num(0,2,adc[0],3);
      LCD_Print(50,0,"M");
      Dis_Num(38,2,adc[2],3);
      LCD_Print(90,0,"R");
      Dis_Num(43,2,adc[1],3);
      LCD_Print(0,4,"maxL");
      Dis_Num(0,6,senmax[0],3);
      LCD_Print(40,4,"maxM");
      Dis_Num(38,6,senmax[2],3);
      LCD_Print(85,4,"maxR");
      Dis_Num(43,6,senmax[1],3);
      boma=(gpio_get(C3)==0?1:0);
      if(boma==1)//在拨码四打开的情况下，再打开拨码三，进行斜电感的归一化
      {
        LCD_Fill(0x00);
        while(boma)
        {
          for(int i=0;i<20;i++)
          {
            Buf4[i]= adc_once(ADC0_SE13,ADC_8bit);//左  straight
            Buf5[i]= adc_once(ADC0_SE15,ADC_8bit);//右
          }
          adc[3]=Bubble(Buf4);
          adc[4]=Bubble(Buf5);
          for(uint8 i=0;i<2;i++)
          {
            if(adc[i+3]>straight[i])
              straight[i]=adc[i+3];
          }
          boma=(gpio_get(C3)==0? 1:0);
          LCD_Print(2,0,"L_");
          Dis_Num(0,2,adc[3],3);
          LCD_Print(90,0,"R_");
          Dis_Num(43,2,adc[4],3);
          LCD_Print(0,4,"maxL_");
          Dis_Num(0,6,straight[0],3);
          LCD_Print(85,4,"maxR_");
          Dis_Num(43,6,straight[1],3);
        }
      }
    }
    LCD_Fill(0x00);
    //写入flash;
    FLASH_Init ();
    FLASH_EraseSector(senser_max);
    FLASH_WriteSector(senser_max,(const uint8 *)senmax,3,0);             //写入四个字节到最后一个扇区 偏移0字节
    senmax[0] = flash_read(senser_max,0,uint8);                           //读取数据
    senmax[1] = flash_read(senser_max,1,uint8);
    senmax[2] = flash_read(senser_max,2,uint8);
    
    FLASH_EraseSector(straight_max);
    FLASH_WriteSector(straight_max,(const uint8 *)straight,2,0);             //写入四个字节到最后一个扇区 偏移0字节
    straight[0] = flash_read(straight_max,0,uint8);                           //读取数据
    straight[1] = flash_read(straight_max,1,uint8);                         //读取数据
    
  }
  
  
  senmax[0] = flash_read(senser_max,0,uint8);                           //读取数据
  senmax[1] = flash_read(senser_max,1,uint8);
  senmax[2] = flash_read(senser_max,2,uint8);
  straight[0] = flash_read(straight_max,0,uint8);                           //读取数据
  straight[1] = flash_read(straight_max,1,uint8);                         //读取数据
  

  if(gpio_get(C3)==0)  
    speed_switch=1;
  else if(gpio_get(B4)==0)  
    speed_switch=2;
  else if(gpio_get(B5)==0)  
    speed_switch=3;
  
  switch(speed_switch)//用三个拨码调用三套参数
  {
  case 1:
    {
      threshold=30;
      PID_P=11;  
      PID_I=8.4;
      k_d=2100;
      break;
    }
  case 2:
    {
      threshold=20;
      PID_P=11;  
      PID_I=8.8 ;
      k_d=2700;//2000;
      k_p=200;
      break;
    }
  case 3:
    {
      threshold=20;
      PID_P=12;  
      PID_I=6 ;
      k_d=2700;
      k_p=210;
      break;
    }
  default:break;
  }
  EnableInterrupts;
  enable_irq(PIT_CH0_IRQn);
  while(1)
  {
    key_read();
    display();
    //   Boma();
    
    if(open_flag==1&&start_flag==1&&stop==0)   //开环启动
    {
      ftm_pwm_duty(ftm2,ftm_ch2,Motor_left);
      ftm_pwm_duty(ftm2,ftm_ch3,0);
      ftm_pwm_duty(ftm2,ftm_ch4,Motor_right);
      ftm_pwm_duty(ftm2,ftm_ch5,0);
    }

      if(out_flag==0)
        gpio_set(D0,0);
      
      if(out_flag==1)
        gpio_set(D0,1);
    
//    //钢黄管停车
//    if(gpio_get(F3)==0)
//    {
//      while(!gpio_get(F3));
//      stop_count++;  //检测到钢黄管次数
//      
//    }
//    if(stop_count>1) //第二次停下车
//      stop=1;
//    if(stop==1)
//    {
//      
//      Expect_speed=0;
//      if(actual_speed<0)
//      {
//        direction_stop_flag=1;
//        motor_pulse_speed=0;
//      }
//    }
    
    
    //蓝牙传输；
    switch(bluetooth_flag)
    {
    case 0:
      {
        Disbuff[0]=ser_err;
        Disbuff[1]=Expect_speed;  //  ser_duty   ser_ec
        Disbuff[2]=Motor_right;
        Disbuff[3]=Motor_left;
        Disbuff[4]=ser_right;
        Disbuff[5]=motor_pulse_speed;
        Disbuff[6]=ser_middle;     //       Z_Dir_Gyro_data
        Disbuff[7]=actual_speed;   //       round_duty
        vcan_sendware((uint8 *)Disbuff,sizeof(Disbuff));
        break ;
      }
      
    case 1:
      {
        //         Display[0]=ser_ec;
        //         Display[1]=k_p
        
        Display[0]=ser_left;//ser_right, ser_left,ser_middle,straight_left,straight_right
        Display[1]=ser_middle;
        Display[2]= ser_right;
        Display[3]=straight_left;
        Display[4]=straight_right;
        Display[5]=ser_err;
        Display[6]=Expect_speed;//ser_ec
        Display[7]=actual_speed;
        vcan_sendware((uint8 *)Display,sizeof(Display));
        break ;
        
      }
    default: break ;
    
    }
  }
}
