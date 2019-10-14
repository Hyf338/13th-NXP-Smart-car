#include "headfile.h"
extern uint8 ser_right;
extern uint8 ser_left;
extern uint8 ser_middle;
extern uint8 straight_left;
extern uint8 straight_right;
extern uint8 senmax[3];
extern uint8 senmin[3];
uint8 mode=0;
uint8 bluetooth_flag=1;
int8 UI=0;
extern float k_p;
extern uint8 start_flag;
extern uint16 k_d;
//extern uint8 round_flag;
extern uint8 round_flag;
extern uint8 round_turn;
extern float PID_I;
extern float PID_P;
extern uint8 circle_left;
extern uint8 circle_right;
extern uint16 middle_circle ;
extern uint8 small_flag ;
extern uint16 circle_p;
extern uint16 circle_d;
extern uint8 ser_err;
extern uint8 close_round;
extern uint8 ramp_speed_dowm;
extern uint16 round_hight;
extern uint8 round_low;
extern uint8 count_flag;
extern uint8 round_count;
extern uint8 round_status[4];
extern uint8 out_flag;
extern uint8 out_round;
extern uint8 stop_count;
extern uint8 ramp_flag;
void display()
{
  switch (mode)
  {
    
  case 0:
    {
      
      LCD_Print(0,0,"maxR");
      Dis_Num(0,2,senmax[0],3);
      LCD_Print(40,0,"maxM");
      Dis_Num(38,2,senmax[2],3);
      LCD_Print(85,0,"maxL");
      Dis_Num(43,2,senmax[1],3);
      LCD_Print(10,4,"k_d");
      Dis_Float(42,4,k_d,1);
      LCD_Print(10,6,"k_p");
      Dis_Float(42,6,k_p,1);
      Dis_Num(7,6,stop_count,1);
      switch(UI)
      {
      case 2:LCD_Print(0,4,"*");break;
      case 3:LCD_Print(0,6,"*");break;
      default: break;
      }
      break ;
    }
  case 1:
    {
      LCD_Print(10,0,"right");
      Dis_Num(42,0,ser_right,3);
      LCD_Print(10,2,"left");
      Dis_Num(42,2,ser_left,3);
      LCD_Print(10,4,"middle");
      Dis_Num(42,4,ser_middle,3);
      Dis_Num(3,6,round_count,1);
      Dis_Num(5,6,out_flag,1);
      Dis_Num(7,6,out_round,1);
      Dis_Num(9,6,round_flag,1);
      Dis_Num(11,6,round_turn,1);
      Dis_Num(13,6,circle_left,1);
      Dis_Num(15,6,circle_right,1);
      switch(UI)
      {
      case 0: LCD_Print(0,0,"*");break;
      case 1: LCD_Print(0,2,"*");break;
      case 2: LCD_Print(0,4,"*");break;
      case 3: LCD_Print(0,6,"*");break;
      default: break;
      }
      
      
      break ;
      
    }
  case 2:
    {
      LCD_Print(10,0,"S_left");
      Dis_Num(42,0,straight_left,3);
      LCD_Print(10,2,"S_right");
      Dis_Num(42,2,straight_right,3);
      LCD_Print(10,4,"PID_P");
      Dis_Float(42,4,PID_P,1);
      LCD_Print(10,6,"PID_I");
      Dis_Float(42,6,PID_I,2);
      switch(UI)
      {
      case 0: LCD_Print(0,0,"*");break;
      case 1: LCD_Print(0,2,"*");break;
      case 2: LCD_Print(0,4,"*");break;
      case 3: LCD_Print(0,6,"*");break;
      default: break ;
      
      }
      break ;
      
    }
  case 3:
    {
      LCD_Print(10,0,"R_1:");
      Dis_Num(42,0,round_status[0],3);
      LCD_Print(10,2,"R_2:");
      Dis_Num(42,2,round_status[1],3);
      LCD_Print(10,4,"R_3:");
      Dis_Num(42,4,round_status[2],3);
      LCD_Print(10,6,"R_4:");
      Dis_Num(42,6,round_status[3],3);
      switch(UI)
      {
      case 0: LCD_Print(0,0,"*");break;
      case 1: LCD_Print(0,2,"*");break;
      case 2: LCD_Print(0,4,"*");break;
      case 3: LCD_Print(0,6,"*");break;
      default: break ;
      
      }
      
      break ;
    }
  case 4:
    {
      LCD_Print(10,0,"Blue");
      Dis_Num(42,0,bluetooth_flag,1);
      LCD_Print(10,2,"R_close:");
      Dis_Num(42,2,close_round,1);
      LCD_Print(10,4,"Ramp_S_D:");
      Dis_Num(42,4,ramp_speed_dowm,1);
      LCD_Print(10,6,"run:");
      Dis_Num(39,6,ramp_flag,1);
      Dis_Num(42,6,start_flag,1);
      switch(UI)
      {
      case 0: LCD_Print(0,0,"*");break;
      case 1: LCD_Print(0,2,"*");break;
      case 2: LCD_Print(0,4,"*");break;
      case 3: LCD_Print(0,6,"*");break;
      default: break ;
      }
      break ;
    }
  default:  break;
  }
}
uint8 key_scan ()
{
  if (Key_Up==0)
  {
    systick_delay_ms(5);
    if (Key_Up==0)
    {
      while (!Key_Up) ;
      return 1;
    }
  }
  if (Key_Dm==0)
  {
    systick_delay_ms(5);
    if (Key_Dm==0)
    {
      while (!Key_Dm) ;
      return 2;
    }
  }
  else if (Key_Rt==0)
  {
    systick_delay_ms(5);
    if (Key_Rt==0)
    {
      while (!Key_Rt) ;
      return 3;
    }
  }
  else if (Key_Md==0)
  {
    systick_delay_ms(5);
    if (Key_Md==0)
    {
      while (!Key_Md) ;
      return 4;
    }
  }
  else if (Key_Lt==0)
  {
    systick_delay_ms(5);
    if (Key_Lt==0)
    {
      while (!Key_Lt) ;
      return 5;
    }
  }
  else
    return 0;
  return 0;
}
void key_read()
{
  uint8 i=0;
  
  i= key_scan ();
  
  switch (i)
  {
  case 4:
    {
      mode++;
      LCD_Fill(0x00);
      if(mode>4)
        mode=0;
      break ;
    }
  case 1:  //ио
    {
      
      UI-=1 ;
      LCD_Fill(0x00);
      if(UI<0)
        UI=3;
      
      break;
    }
  case 2:  //об
    {
      UI+=1 ;
      LCD_Fill(0x00);
      if(UI>3)
        UI=0;
      break;
      
    }
  case 3:   //ср
    {
      if(mode==0)
      {
        switch(UI)
        {
        case 2:  k_d+=50; break ;
        case 3:  k_p+=1; break ;
        default: break ;
        }
      }
      
      if(mode==2)
      {
        switch(UI)
        {
        case 2: PID_P+=1;break;
        case 3:  PID_I+=0.1; break ;
        default: break ;
        
        }
      }
      
      if(mode==3)
      {
        switch(UI)
        {
        case 0: round_status[0]+=1;break;
        case 1: round_status[1]+=1;break;
        case 2: round_status[2]+=1;break;
        case 3: round_status[3]+=1;break;
        default: break ;
        
        }
        
        
      }
      if(mode==4)
      {
        switch(UI)
        {
        case 0:
          {
            bluetooth_flag+=1 ;
            if(bluetooth_flag>2)
              bluetooth_flag=0;
            break ;
          }
        case 1:  
          {
            close_round+=1;
            if(close_round>1)
              close_round=0;
            break;
          }
        case 2: 
          {
            ramp_speed_dowm+=1;
            ramp_speed_dowm=ramp_speed_dowm>1? 0:1;
            break;
          }
          
        case 3: 
          start_flag=1;break;
          
        default: break ;
        
        }
        
        
      }
      break;
    }
  case 5:  //вС
    {
      if(mode==0)
      {
        switch(UI)
        {
        case 2:  k_d-=50; break ;
        case 3:  k_p-=1; break ;
        default: break ;
        }
      }
     
      if(mode==2)
      {
        switch(UI)
        {
        case 2: PID_P-=1;break;
        case 3:  PID_I-=0.1; break ;
        default: break ;
        
        }
      }
      
      if(mode==3)
      {
        switch(UI)
        {
        case 0: round_status[0]-=1;break;
        case 1:  round_status[1]-=1;break;
        case 2: round_status[2]-=1;break;
        case 3: round_status[3]-=1;break;
        default: break ;
        
        }
        
      }
      if(mode==4)
      {
        switch(UI)
        {
        case 3:start_flag=0;break;
        default:break ;
        }
        
      }
      break;
      
      
    default:  break;
    }
  }
}
//void Bluethooth()
//{
//    bluetooth_flag=gpio_get(G1);
//}

