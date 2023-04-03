#include "reg52.h"
#include "intrins.h"
typedef unsigned int u16;	
typedef unsigned char u8;
#define SMG_A_DP_PORT	P0	

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit BEEP=P2^5;	//将P2.5管脚定义为BEEP

u16 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
				0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void delay(u16 ms){
    u16 i, j;
    for(i = 0; i < ms; i++){
        for(j = 0; j < 114; j++);
    }
}
void delay_10us(u16 ten_us)
{ 
    while(ten_us--);	
}
//显示时间
void display_time(u16 time[8])
{
    u16 i=0,j=0;
    for(i=0;i<8;i++)
    {
        //选择数码管
        switch(i)
        {
            case 0:LSA=0;LSB=0;LSC=0;break;
            case 1:LSA=1;LSB=0;LSC=0;break;
            case 2:LSA=0;LSB=1;LSC=0;break;
            case 3:LSA=1;LSB=1;LSC=0;break;
            case 4:LSA=0;LSB=0;LSC=1;break;
            case 5:LSA=1;LSB=0;LSC=1;break;
            case 6:LSA=0;LSB=1;LSC=1;break;
            case 7:LSA=1;LSB=1;LSC=1;break;
        }
        //显示数码管
        SMG_A_DP_PORT=gsmg_code[time[i]];
        delay_10us(100);
        SMG_A_DP_PORT=0x00;
    }
}
void main()
{
    u8 i=0, flag=0,j=0,btime=200;
    u16 time[8]={0,6,0,0,0,0,0,0};
    u8 count=3;
    SMG_A_DP_PORT=0x00;
    LSA=0;LSB=0;LSC=0;
    delay(1000);
    while(count){
        SMG_A_DP_PORT = gsmg_code[count]; 
        delay(1000); // 延时1秒
        count--; // 数值减1
    }
    while(1)
    {
        //1s自增
        j=120;
        while(j--)
        {
            display_time(time);
        }
        //秒倒计时
        if(time[0]==0)
        {
            time[0]=9;
            if(time[1]==0)
            {
                time[1]=5;
                if(time[2]==0)
                {
                    time[2]=9;
                    if(time[3]==0)
                    {
                        time[3]=5;
                        if(time[4]==0)
                        {
                            time[4]=9;
                            if(time[5]==0)
                            {
                                time[5]=5;
                                if(time[6]==0)
                                {
                                    time[6]=9;
                                    if(time[7]==0)
                                    {
                                        time[7]=5;
                                    }
                                    else
                                    {
                                        time[7]--;
                                    }
                                }
                                else
                                {
                                    time[6]--;
                                }
                            }
                            else
                            {
                                time[5]--;
                            }
                        }
                        else
                        {
                            time[4]--;
                        }
                    }
                    else
                    {
                        time[3]--;
                    }
                }
                else
                {
                    time[2]--;
                }
            }
            else
            {
                time[1]--;
            }
        }
        else
        {
            time[0]--;
        }
        //检查数组是否为0
        for(i=0;i<8;i++)
        {
            if(time[i]==0)
            {
                flag++;
            }
        }
        //如果数组全为0，跳出循环
        if(flag==8)
            break;
    }
    while(btime--)
    {
        BEEP=~BEEP;
        delay(100);
    }
    BEEP=0;
}