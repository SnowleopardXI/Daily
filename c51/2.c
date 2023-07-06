#include "reg52.h"
#include "intrins.h"
#define KEY1_PRESS  1
#define KEY2_PRESS  2
#define KEY3_PRESS  3
#define KEY4_PRESS  4
#define KEY_UNPRESS 0
typedef unsigned int u16;
typedef unsigned char u8;
#define NIXIE_A_DP_PORT P0
#define LED_PORT        P2
// 定义独立按键控制脚
sbit KEY1 = P1 ^ 1;
sbit KEY2 = P1 ^ 0;
sbit KEY3 = P1 ^ 2;
sbit KEY4 = P1 ^ 3;

sbit LSA = P1 ^ 2;
sbit LSB = P1 ^ 3;
sbit LSC = P1 ^ 4;
// 定义74HC595控制管脚
sbit SRCLK = P3 ^ 6; // 移位寄存器时钟输入
sbit R0CLK = P3 ^ 5; // 存储寄存器时钟输入
sbit SER   = P3 ^ 4; // 串行数据输入
u16 id[8]  = {2, 0, 2, 1, 2, 5, 3, 9};
u16 id1[8] = {2, 0, 2, 1, 2, 5, 4, 5};
u16 id2[8] = {2, 0, 2, 1, 2, 5, 4, 7};

void delay_10us(u16 ten_us)
{
    while (ten_us--)
        ;
}
void delay(u16 ms)
{
    u16 i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 114; j++)
            ;
    }
}
u16 gsmg_code[17] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
                     0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

void smg_display(u16 id[8])
{
    u16 i = 0, j = 0;
    for (i = 0; i < 8; i++) {
        // 选择数码管
        switch (7 - i) {
            case 0:
                LSA = 0;LSB = 0;LSC = 0;break;
            case 1:
                LSA = 1;LSB = 0;LSC = 0;break;
            case 2:
                LSA = 0;LSB = 1;LSC = 0;break;
            case 3:
                LSA = 1;LSB = 1;LSC = 0;break;
            case 4:
                LSA = 0;LSB = 0;LSC = 1;break;
            case 5:
                LSA = 1;LSB = 0;LSC = 1;break;
            case 6:
                LSA = 0;LSB = 1;LSC = 1;break;
            case 7:
                LSA = 1;LSB = 1;LSC = 1;break;
        }
        // 显示数码管
        NIXIE_A_DP_PORT = gsmg_code[id[i]];
        delay_10us(100);
        NIXIE_A_DP_PORT = 0x00;
    }
}
u8 key_scan(u8 mode)
{
    static u8 key = 1;

    if (KEY1 == 0 || KEY2 == 0 || KEY3 == 0 || KEY4 == 0) // 任意按键按下
    {
        delay_10us(1000); // 消抖
        key = 0;
        if (KEY1 == 0)
            return KEY1_PRESS;
        else if (KEY2 == 0)
            return KEY2_PRESS;
        else if (KEY3 == 0)
            return KEY3_PRESS;
        else if (KEY4 == 0)
            return KEY4_PRESS;
    }
    return KEY_UNPRESS;
}
void for_single()
{
    u8 i;
    for (i = 0; i < 8; i++) {
        LED_PORT = ~(0x01 << i); // 依次点亮LED灯
        delay(100);              // 延时一段时间
    }
}
void rev_single()
{
    u8 i;
    for (i = 0; i < 8; i++) {
        LED_PORT = ~(0x80 >> i); // 依次点亮LED灯
        delay(100);              // 延时一段时间
    }
}
void for_multiple()
{
    u8 i;
    //从右往左点亮多个,依次为1个，2个，3个，4个，5个，6个，7个，8个
    for (i = 8; i >=1; i--) {
        LED_PORT = ~(0xff >> i); // 依次点亮LED灯
        delay(100);              // 延时一段时间
    }
    LED_PORT = ~0xff;
}
void rev_multiple()
{
    u8 i;
    //从右往左点亮多个,依次为1个，2个，3个，4个，5个，6个，7个，8个
    for (i = 0; i <= 8; i++) {
        LED_PORT = ~(0xff >> i); // 依次点亮LED灯
        delay(100);              // 延时一段时间
    }
}
void main()
{
    u8 i = 0, key = 1, temp;
    unsigned short time = 500;
    u8 count            = 3;
    NIXIE_A_DP_PORT     = 0x00;
    LSA = 0;LSB = 0;LSC = 0;
    delay(1000);
    time = 80;
    while (time--) {smg_display(id);}
    time = 80;
    while (time--) {smg_display(id1);}
    time = 80;
    while (time--) {smg_display(id2);}
    time = 100;
    while (1) {
        temp = key;
        for (time = 10000; time > 0; time--) {
            key = key_scan(0);
            if (key == 0)
            {
                key = temp;
            }
            else
            {
                break;
            }
        }
        LED_PORT = ~0x01;
        switch (key) {
            case 1:
                for_single();break;
            case 2:
                rev_single();break;
            case 3:
                for_multiple();
                break;
            case 4:
                rev_multiple();
                break;
            default:
                break;
        }
    }
}
