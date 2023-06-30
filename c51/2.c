#include "reg52.h"
#include "intrins.h"
typedef unsigned int u16;
typedef unsigned char u8;
#define NIXIE_A_DP_PORT P0
#define LED_PORT        P2


u16 id[8]  = {2, 0, 2, 1, 2, 5, 3, 9};
u16 id1[8] = {2, 0, 2, 1, 2, 5, 4, 5};
u16 id2[8] = {2, 0, 2, 1, 2, 5, 4, 7};

sbit LSA = P2 ^ 2;
sbit LSB = P2 ^ 3;
sbit LSC = P2 ^ 4;
// 定义74HC595控制管脚
sbit SRCLK = P3 ^ 6; // 移位寄存器时钟输入
sbit R0CLK = P3 ^ 5; // 存储寄存器时钟输入
sbit SER   = P3 ^ 4; // 串行数据输入

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

void single_smg(u16 id[10])
{
    u16 i = 0, j = 0;
    LSA = 0;
    LSB = 0;
    LSC = 0;
    for (i = 0; i < 10; i++) {
        NIXIE_A_DP_PORT = gsmg_code[id[i]];
        delay_10us(100);
        NIXIE_A_DP_PORT = 0x00;
    }
}

void smg_display(u16 id[8])
{
    u16 i = 0, j = 0;
    for (i = 0; i < 8; i++) {
        // 选择数码管
        switch (7 - i) {
            case 0:
                LSA = 0;
                LSB = 0;
                LSC = 0;
                break;
            case 1:
                LSA = 1;
                LSB = 0;
                LSC = 0;
                break;
            case 2:
                LSA = 0;
                LSB = 1;
                LSC = 0;
                break;
            case 3:
                LSA = 1;
                LSB = 1;
                LSC = 0;
                break;
            case 4:
                LSA = 0;
                LSB = 0;
                LSC = 1;
                break;
            case 5:
                LSA = 1;
                LSB = 0;
                LSC = 1;
                break;
            case 6:
                LSA = 0;
                LSB = 1;
                LSC = 1;
                break;
            case 7:
                LSA = 1;
                LSB = 1;
                LSC = 1;
                break;
        }
        // 显示数码管
        NIXIE_A_DP_PORT = gsmg_code[id[i]];
        delay_10us(100);
        NIXIE_A_DP_PORT = 0x00;
    }
}

void main()
{
    u8 i = 0, time = 500;
    u8 count        = 3;
    NIXIE_A_DP_PORT = 0x00;
    LSA  = 0;
    LSB  = 0;
    LSC  = 0;
    delay(1000);
    while (count) {
        NIXIE_A_DP_PORT = gsmg_code[count];
        delay(1000); // 延时1秒
        count--;     // 数值减1
    }
    while (1) {
        time = 500;
        while (time--) {
            smg_display(id);
        }
        time = 500;
        while (time--) {
            smg_display(id1);
        }
        time = 500;
		while (time--) {
			smg_display(id2);
		}
		time = 500;
        LED_PORT = ~0x01;
        for (i = 0; i < 8; i++) {
            LED_PORT = ~(0x01 << i); // 将1右移i位，然后取反将结果赋值到LED_PORT
            delay_10us(50000);
        }
    }
}