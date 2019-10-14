
#ifndef _Oled_H
#define _Oled_H
#define byte uint8
#define word uint16
#define GPIO_PIN_MASK      0x1Fu    //0x1f=31,限制位数为0--31有效
#define GPIO_PIN(x)        (((1)<<(x & GPIO_PIN_MASK)))  //把当前位置1

#define LCD_Port_Init()            gpio_init (B2, GPO,0);   \
                                   gpio_init (B3, GPO,0);   \
                                   gpio_init (B1, GPO,0);   \
                                   gpio_init (B0, GPO,0);


#define LCD_SCL_HIGH    gpio_set(B2, 1)
#define LCD_SCL_LOW     gpio_set(B2, 0)

#define LCD_SDA_HIGH    gpio_set(B3, 1)
#define LCD_SDA_LOW     gpio_set(B3, 0)

#define LCD_RST_HIGH    gpio_set(B1, 1)
#define LCD_RST_LOW     gpio_set(B1, 0)

#define LCD_DC_HIGH     gpio_set(B0, 1)
#define LCD_DC_LOW      gpio_set(B0, 0)
void LCD_Init();

 void LCD_Print(byte x, byte y, byte ch[]);//输出汉字和字符混合字符串
 void Dis_Num(byte x, byte y, uint16 num,byte N);
 void LCD_Fill(byte bmp_data);
 void Dis_Float(byte X,byte Y,double real,byte N);
void LCD_CLS(void);
#endif