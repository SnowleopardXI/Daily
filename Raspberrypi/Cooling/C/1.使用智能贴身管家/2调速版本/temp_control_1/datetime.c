// 导入wiringPi/I2C库
#include <wiringPi.h>
#include <wiringPiI2C.h>

// 导入oled显示屏库
#include "ssd1306_i2c.h"

// 导入文件控制函数库
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <sys/timeb.h>
#include <time.h>
#define CPU_USAGE_PATH "/proc/stat"
#define HARDWARE_PATH "/proc/device-tree/model"
#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp"
#define MAX_SIZE 32

int main(void)
{
	int readed_ip = 0;
	int count = 0;
	int fd_temp;
	double temp = 0, level_temp = 0;
	char buf[MAX_SIZE];

	char buf_cpu[128];
	FILE *fp_CPUusage;
	char cpu[5];
	float usage;
	long int user, nice, sys, idle, iowait, irq, softirq;
	long int total_1, total_2, idle_1, idle_2;

	struct sysinfo sys_info;

	struct ifaddrs *ifAddrStruct = NULL;
	void *tmpAddrPtr = NULL;

	getifaddrs(&ifAddrStruct);
	ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);

	// 定义I2C相关参数
	int fd_i2c;
	wiringPiSetup();
	fd_i2c = wiringPiI2CSetup(0x0d);
	while (fd_i2c < 0)
	{
		fd_i2c = wiringPiI2CSetup(0x0d);
		fprintf(stderr, "fail to init I2C\n");
		delay(500);
	}

	wiringPiI2CWriteReg8(fd_i2c, 0x07, 0x00);
	// wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x00);   // close fan
	// delay(500);
	printf("init ok!\n");

	while (1)
	{
		// 读取系统信息
		if (sysinfo(&sys_info) != 0) // sysinfo(&sys_info) != 0
		{
			printf("sysinfo-Error\n");
			ssd1306_clearDisplay();
			char *text = "sysinfo-Error";
			ssd1306_drawString(text);
			ssd1306_display();
			continue;
		}
		else
		{
			// 清除屏幕内容
			ssd1306_clearDisplay();

			// 读取CPU温度
			char CPUTemp[MAX_SIZE];
			fd_temp = open(TEMP_PATH, O_RDONLY);
			if (fd_temp < 0)
			{
				temp = 0;
				printf("failed to open thermal_zone0/temp\n");
			}
			else
			{
				// 读取温度并判断
				if (read(fd_temp, buf, MAX_SIZE) < 0)
				{
					temp = 0;
					printf("fail to read temp\n");
				}
				else
				{
					// 转换为浮点数打印
					temp = atoi(buf) / 1000.0;
					// printf("temp: %.1f\n", temp);
					sprintf(CPUTemp, "Temp:%.1fC", temp);
				}
			}
			close(fd_temp);
			delay(800);
			struct timeb tTimeB;
			ftime(&tTimeB);							  // 获取当前的秒数和毫秒数
			struct tm *tTM = localtime(&tTimeB.time); // 将秒数转为时间格式
			char datetime[32];
			sprintf(datetime, "%04d-%02d-%02d %02d:%02d:%02d", tTM->tm_year + 1900, tTM->tm_mon + 1, tTM->tm_mday,tTM->tm_hour, tTM->tm_min, tTM->tm_sec);
			// 在显示屏上要显示的内容
			ssd1306_drawText(0, 0, datetime);
			ssd1306_drawText(0, 8, CPUTemp);

			// 刷新显示
			ssd1306_display();
		}
		wiringPiI2CWriteReg8(fd_i2c, 0x07, 0x00);
		if (abs(temp - level_temp) >= 1)
		{
			if (temp <= 43)
			{
				level_temp = 43;
				wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x03);
			}
			else if (temp <= 46)
			{
				level_temp = 45;
				wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x06);
			}
			else if (temp <= 48)
			{
				level_temp = 48;
				wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x08);
			}
			else if (temp <= 55)
			{
				level_temp = 55;
				wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x09);
			}
			else if (temp >= 60)
			{
				level_temp = 60;
				wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x01);
			}
		}
	}
	return 0;
}
