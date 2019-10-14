/*********************************************************************************************************************
* COPYRIGHT NOTICE
* Copyright (c) 2017,逐飞科技
* All rights reserved.
* 技术讨论QQ群：179029047
*
* 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
* 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
*
* @file       		中断文件
* @company	   		成都逐飞科技有限公司
* @author     		逐飞科技(QQ3184284598)
* @version    		v2.0
* @Software 		IAR 7.7 or MDK 5.23
* @Target core		S9KEA128AMLK
* @Taobao   		https://seekfree.taobao.com/
* @date       		2017-11-6
********************************************************************************************************************/


#include "headfile.h"
//#define threshold     30
uint8 threshold=0;
float  ser_err=0;
uint8 start_flag=0;
int16 Motor_right=0;
int16 Motor_left=0;
float k_p=0;  // 120-130
int16 ser_duty=0;
int16 ser_duty_last=0;
uint16 k_d=0;
uint8 round_flag=0;
uint8 round_turn=0 ;
float ser_ec=0;
extern uint8 open_flag;//开环跑
extern uint8 close_flag;//闭环跑
extern uint8 ser_right, ser_left,ser_middle;
extern int16 motor_pulse_speed;
extern int16 Expect_speed;
extern float Z_Dir_Gyro_data;//Z轴陀螺仪数值
float ser[5]={0};
extern uint8 straight_left;
extern uint8 straight_right;
uint8 circle_right=0;
uint8 circle_left=0 ;
uint8 speed_count=0;
uint8 dirction_count=0;
uint8 close_round=0;//圆环总开关
uint8 round_status[4]={1,2,3,4};
uint8 round_low=0;//圆环算法变量小值
uint16 round_hight=0;//圆环算法变量小值
uint8 round_count=1;//圆环计数
uint8 count_flag=0;//计数标志
uint8 out_round=0;//出环标志
uint8 out_flag=1;//环内状态标志
extern uint8 direction_stop_flag;//钢簧管二次计数标志位
uint8 stop_count=0;//钢簧管计数值
extern uint8 speed_switch;
uint8 ramp_flag=0;
uint8 ramp_count=0;
uint8 ramp_speed_dowm=0;
uint8 stop=0 ;
extern  int16 actual_speed;

void PIT_CH0_IRQHandler(void)
{
  
  //  pit_time_start(pit1);
  uint16 ser_num=0;
  int16 ser_sub=0;
  static float ser_last_err=0;
  uint8 loop=0;
  float ser_original=0;
  static float ser_duty_last=0;
  
  PIT_FLAG_CLR(pit0);
      //钢黄管停车
    if(gpio_get(F3)==0)
    {
      while(!gpio_get(F3));
      stop_count++;  //检测到钢黄管次数
      
    }
    if(stop_count>1) //第二次停下车
      stop=1;
    if(stop==1)
    {
      
      Expect_speed=0;
      if(actual_speed<0)
      {
        direction_stop_flag=1;
        motor_pulse_speed=0;
      }
    }
    
  dirction_count++;   //方向计数
  
  if(direction_stop_flag==0)  //触发钢黄管停车
  {
    speed_count++;   //速度计数
    if(speed_count<=20)
    {
      motor_count_pulse() ;  //编码器采集的值；
    }
    if(speed_count==20) //20ms采一次1ms的中断
    {
      speed_count=0;
      if(ramp_flag==1)  ramp_count++; 
      if(ramp_count>55) 
      {
        ramp_flag=0;
        ramp_count=0;
      }
      if(stop_count<2)
      {
        switch(speed_switch)
        {
        case 1:
          {
           
             if(out_flag==0&&(round_status[round_count-2]==3||round_status[round_count-2]==2))      //直道加速&&环内加速
              Expect_speed=300;
            else if(ramp_flag==0&&ser_middle<100&&ser_middle>90&&ser_err<7&&ser_err>-7)//round_flag==0&&
              Expect_speed=300;
            else
              Expect_speed=250;
            break;
          }
        case 2:
          {
            if(ramp_flag==1) 
              Expect_speed=250;
            else if(out_flag==0&&(round_status[round_count-2]==3||round_status[round_count-2]==2))      //
              Expect_speed=320;
            else if(ramp_flag==0&&ser_middle<100&&ser_middle>90&&ser_err<7&&ser_err>-7)//&&abs(ser_right-ser_left)<10
              Expect_speed=310;
            else Expect_speed=290;
            break;
          }
        case 3:
          {
            if(ramp_flag==1) 
              Expect_speed=250;
            else if(out_flag==0&&(round_status[round_count-2]==3||round_status[round_count-2]==2))      //
              Expect_speed=330;
            else Expect_speed=310;
            break;
          }
        default:break;
        }
      }
      speed_control() ;     //速度控制
    }
  }
  if(dirction_count==4)
  {
    dirction_count=0;
    senser_collect();
   if(ser_right<2&&ser_left<2&&ser_middle<6)
     start_flag=0;

    if(ser_middle>150&&ser_right<90&&ser_left<90)    ramp_flag=1;//坡道
    
    if(close_round==0)
    {
      switch(speed_switch)
      {
      case 1:
        {
          if(ser_middle<95&&round_flag==1&&round_turn==1)//入环清标志位
          {
            round_flag=0;
            round_turn=0;
            out_flag=0;
          }
          break;
        }
      case 2:
        {
          if(ser_middle<85&&round_flag==1&&round_turn==1)
          {
            round_flag=0;
            round_turn=0;
            out_flag=0;
          }
          break;
        }
      case 3:
        {
          if(ser_middle<85&&round_flag==1&&round_turn==1)//正常赛道清入环标志位“们”
          {
            round_flag=0;
            round_turn=0;
            out_flag=0;
          }
          break;
        }
      default:break;
      }
      if(ser_middle>160&&(ser_right>130||ser_left>130)&&out_flag==1&&out_round==0&&(ser_middle>ser_left)&&(ser_middle>ser_right))//&&ser_middle<170
      {
        round_flag=1 ;
      }
      
      if(round_flag==1&&circle_right==0&&circle_left==0)
      {
        if(straight_right>straight_left)  circle_right=1,circle_left=0;
        else if(straight_left>straight_right) circle_left=1,circle_right=0;
      }
      
      if(circle_right==1&&round_flag==1)//&&ser_middle>180
      {
        if(straight_right<straight_left)  round_turn=1;//&&(ser_right>ser_left)
      }
      if(circle_left==1&&round_flag==1)//&&ser_middle>180
      {
        if(straight_left<straight_right)   round_turn=1 ;//&&(ser_left>ser_right)
      }
      
      if(circle_right==1&&out_flag==0&&ser_right>120&&ser_middle>110)  out_round=1;//出环再遇峰值
      if(out_round==1&&ser_right<85&&circle_right==1) 
      {
        out_round=0;
        out_flag=1;
        circle_right=0;
      }
      
      if(circle_left==1&&out_flag==0&&ser_left>120&&ser_middle>110)  out_round=1;//
      if(out_round==1&&ser_left<85&&circle_left==1) 
      {
        out_round=0;
        out_flag=1;
        circle_left=0;
      }
      if(round_turn==0&&count_flag==1)
      {
        count_flag=0;
        round_count+=1;
      }
      if(round_turn==1)
      {
        count_flag=1 ;
        switch(speed_switch)
        {
        case 1:
          {
            switch(round_status[round_count-1])
            {
            case 1: round_hight=225,round_low=210;break;
            case 2: round_hight=205,round_low=ser_middle+15;break;
            case 3: round_hight=205,round_low=ser_middle+10;break;
            default: round_hight=225,round_low=210;break;
            }
            break;
          }
        case 2:
          {
            switch(round_status[round_count-1])
            {
            case 1: round_hight=225,round_low=210;break;
            case 2: round_hight=225,round_low=ser_middle+15;break;
            case 3: round_hight=220,round_low=ser_middle+10;break;
            default: round_hight=235,round_low=215;break;
            }
          }
          case 3:
          {
            switch(round_status[round_count-1])
            {
            case 1: round_hight=235,round_low=215;break;
            case 2: round_hight=225,round_low=ser_middle+15;break;
            case 3: round_hight=220,round_low=ser_middle+10;break;
            default: round_hight=235,round_low=215;break;
            }
          }
          default:break;
        }
        if(circle_right==1) //&&ser_middle>100
        {
          if((round_hight-ser_middle+ser_right)>254) ser_right=254;
          else ser_right=(round_hight-ser_middle+ser_right);
          if((ser_left+ser_middle-round_low)<70) ser_left=70;
          else ser_left=ser_left+ser_middle-round_low;
        }
        if(circle_left==1)//&&ser_middle>100
        {
          if((round_hight-ser_middle+ser_left)>254) ser_left=254;
          else ser_left=(round_hight-ser_middle+ser_left);
          if((ser_right+ser_middle-round_low)<70) ser_right=70;
          else ser_right=ser_right+ser_middle-round_low;
        }
      }
    }
    
    
    ser_num=ser_right+ser_left;
    ser_sub=ser_right-ser_left;
    ser_last_err=ser_err;
    if(ser_num==0)
      ser_err=0;
    else if(ser_num>threshold )
    {
      
      switch(speed_switch)
      {
      case 1:
        {
      ser_original=(float) (1000*ser_sub/powl(ser_num,1.46));
      for(loop=0;loop<5;loop++)
        ser[loop]=ser[loop+1];
      ser[4]=ser_original;
      ser_err=0.8*ser[4]+0.2*ser[3]+0.15*ser[2]+0.1*ser[1]+0.05*ser[0];     //滑动滤波
      //ser_err=0.8*ser_err+0.3*ser_last_err; //低通滤波；
      if((Abs(ser_err)>130)&&(ser_err>0))
        ser_err=130 ;
      else if((Abs(ser_err)>130)&&(ser_err<0))
        ser_err=-130 ;
      break;
        }
      case 2:
        {
          ser_original=(float) (1000*ser_sub/powl(ser_num,1.46));
      for(loop=0;loop<5;loop++)
        ser[loop]=ser[loop+1];
      ser[4]=ser_original;
      ser_err=0.9*ser[4]+0.12*ser[3]+0.09*ser[2]+0.06*ser[1]+0.04*ser[0];     //滑动滤波
      //ser_err=0.8*ser_err+0.3*ser_last_err; //低通滤波；
      if((Abs(ser_err)>130)&&(ser_err>0))
        ser_err=130 ;
      else if((Abs(ser_err)>130)&&(ser_err<0))
        ser_err=-130 ;
      break;
        }
        case 3:
        {
          ser_original=(float) (1000*ser_sub/powl(ser_num,1.46));
      for(loop=0;loop<5;loop++)
        ser[loop]=ser[loop+1];
      ser[4]=ser_original;
      ser_err=0.88*ser[4]+0.12*ser[3]+0.09*ser[2]+0.06*ser[1]+0.04*ser[0];     //滑动滤波
      //ser_err=0.8*ser_err+0.3*ser_last_err; //低通滤波；
      if((Abs(ser_err)>130)&&(ser_err>0))
        ser_err=130 ;
      else if((Abs(ser_err)>130)&&(ser_err<0))
        ser_err=-130 ;
      break;
        }
      default:break;
      }
      
    }
    
    ser_duty_last=ser_duty;
    ser_ec=ser_err-ser_last_err ;
    
    switch(speed_switch)
    {
    case 1:k_p=Fuzzy1(&ser_err,&ser_ec)/10;break;
    case 2:k_p=k_p;break;//Fuzzy2(&ser_err,&ser_ec)/10;break; //
    case 3:k_p=k_p;break;//Fuzzy2(&ser_err,&ser_ec)/10;break;
    default:break;
    }
    
    
    ser_duty=(int)(k_p*ser_err+k_d*ser_ec);
    if((ser_num>0&&ser_num<threshold))//&&ser_middle<50
    {
      if(ser_duty_last>0)
        ser_duty=8000;
      if(ser_duty_last<0)
        ser_duty=-8000;
    }
//    if(ser_duty>20000) ser_duty=20000;
//    if(ser_duty<-20000) ser_duty=-20000;
    
    //方向环调节
#if 1
    Motor_left=motor_pulse_speed-ser_duty;
    Motor_right=motor_pulse_speed+ser_duty;
#else
    Motor_left=-ser_duty;
    Motor_right=ser_duty;
#endif
    //       Motor_left=motor_pulse_left;
    //      Motor_right=motor_pulse_right;
    if(Motor_left>9900)
      Motor_left=9900;
    if(Motor_left<-9900)
      Motor_left=-9900;
    if(Motor_right>9900)
      Motor_right=9900;
    if(Motor_right<-9900)
      Motor_right=-9900;
    
    
    
    
    if(start_flag==1)//  &&close_flag==1
    {
      
      if( Motor_left>0)
      {
        ftm_pwm_duty(ftm2,ftm_ch2,Motor_left);
        ftm_pwm_duty(ftm2,ftm_ch3,0);
      }
      if( Motor_right>0)
      {
        ftm_pwm_duty(ftm2,ftm_ch4,Motor_right);
        ftm_pwm_duty(ftm2,ftm_ch5,0);
      }
      
      if( Motor_left<0)
      {
        ftm_pwm_duty(ftm2,ftm_ch2,0);
        ftm_pwm_duty(ftm2,ftm_ch3,-Motor_left);
      }
      if( Motor_right<0)
      {
        ftm_pwm_duty(ftm2,ftm_ch4,0);
        ftm_pwm_duty(ftm2,ftm_ch5,-Motor_right);
      }
    }
    else if(start_flag==0)
      
    {
      ftm_pwm_duty(ftm2,ftm_ch2,0);
      ftm_pwm_duty(ftm2,ftm_ch3,0);
      ftm_pwm_duty(ftm2,ftm_ch4,0);
      ftm_pwm_duty(ftm2,ftm_ch5,0);
      
    }
  }
  
  // a=pit_time_get(pit1);
  //pit_close(pit0);
}
//
//void PIT_CH1_IRQHandler(void)
//{
//    PIT_FLAG_CLR(pit1);
//
//
//}
//
//void IRQ_IRQHandler(void)
//{
//    CLEAR_IRQ_FLAG;
//
//}
//
//
//void KBI0_IRQHandler(void)
//{
//    CLEAN_KBI0_FLAG;
//
//}
//




/*
中断函数名称，用于设置对应功能的中断函数
Sample usage:当前启用了周期定时器 通道0得中断
void PIT_CH0_IRQHandler(void)
{
;
}
记得进入中断后清除标志位

FTMRE_IRQHandler
PMC_IRQHandler
IRQ_IRQHandler
I2C0_IRQHandler
I2C1_IRQHandler
SPI0_IRQHandler
SPI1_IRQHandler
UART0_IRQHandler
UART1_IRQHandler
UART2_IRQHandler
ADC0_IRQHandler
ACMP0_IRQHandler
FTM0_IRQHandler
FTM1_IRQHandler
FTM2_IRQHandler
RTC_IRQHandler
ACMP1_IRQHandler
PIT_CH0_IRQHandler
PIT_CH1_IRQHandler
KBI0_IRQHandler
KBI1_IRQHandler
Reserved26_IRQHandler
ICS_IRQHandler
WDG_IRQHandler
PWT_IRQHandler
MSCAN_Rx_IRQHandler
MSCAN_Tx_IRQHandler
*/



