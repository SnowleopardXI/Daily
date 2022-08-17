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
// 读取IP库
#include <ifaddrs.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
// 读取磁盘库
#include <sys/vfs.h>
#include <unistd.h>
//读取内存
#include <string.h>
#define startsWith(s, match) (strstr((s), (match)) == (s))
typedef struct MemInfo{
unsigned long long totalMem;
unsigned long long freeMem;
}MemInfo;

#define CPU_USAGE_PATH "/proc/stat"
#define HARDWARE_PATH "/proc/device-tree/model"
#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp"
#define MAX_SIZE 32


int main(void)
{
	int readed_ip = 0;
	int count = 0;
	int fd_temp;
	int fd_hardware;            // 保存查询到的树莓派硬件版本信息
	int raspi_version = 4;      // 4:树莓派4B， 3:树莓派3B/3B+  0：无法识别或其他版本
	double temp = 0, level_temp = 0;
	char buf[MAX_SIZE];

	char buf_cpu[128];
	FILE *fp_CPUusage;
	char cpu[5];
	float usage;
	long int user, nice, sys, idle, iowait, irq, softirq;
	long int total_1, total_2, idle_1, idle_2;

	// get system usage / info
	struct sysinfo sys_info;
	struct statfs disk_info;

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

	// 开启RGB灯特效
	wiringPiI2CWriteReg8(fd_i2c, 0x07, 0x00);

	// wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x00);   // close fan
	ssd1306_clearDisplay();
	ssd1306_display();
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

			// CPU占用率
			char CPUInfo[MAX_SIZE] = {0};
			//unsigned long avgCpuLoad = sys_info.loads[0] / 1000;
			//sprintf(CPUInfo, "CPU:%ld%%", avgCpuLoad);
			fp_CPUusage = fopen(CPU_USAGE_PATH, "r");
			if (fp_CPUusage == NULL)
			{
				printf("failed to open /proc/stat\n");
			}
			else
			{
				/* CPU使用率计算方式：usage = 100*(total-idle/total)
				 * 通过两次获取/proc/stat的数据差得到total和idle
				*/
				// 第一次读取数据
				fgets(buf_cpu, sizeof(buf_cpu), fp_CPUusage);
				sscanf(buf_cpu,"%s%d%d%d%d%d%d%d",cpu,&user,&nice,&sys,&idle,&iowait,&irq,&softirq);
				total_1 = user + nice + sys + idle + iowait + irq + softirq;
				idle_1 = idle;
				rewind(fp_CPUusage);

				// 延时并且清空数据
				sleep(1);
				memset(buf_cpu, 0, sizeof(buf_cpu));
				cpu[0] = '\0';
				user = nice = sys = idle = iowait = softirq = 0;

				// 第二次读取数据
				fgets(buf_cpu, sizeof(buf_cpu), fp_CPUusage);
				sscanf(buf_cpu,"%s%d%d%d%d%d%d%d",cpu,&user,&nice,&sys,&idle,&iowait,&irq,&softirq);
				total_2 = user + nice + sys + idle + iowait + irq + softirq;
				idle_2 = idle;

				usage = (float)(total_2-total_1-(idle_2-idle_1)) / (total_2-total_1)*100;
				//sprintf(CPUInfo, "CPU:%.0f%%", usage);
				//printf("cpu:%.0f%%\n", usage);
				fclose(fp_CPUusage);
			}

			// 运行内存剩余量，剩余/总内存
			char RamInfo[MAX_SIZE];
			FILE *fp = fopen("/proc/meminfo", "r");
			if(fp == NULL)
			wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x09);
			MemInfo memi;
			char buffer[128];

				while(fgets(buffer, 128, fp))
				{
					if(startsWith(buffer, "MemTotal:"))
						sscanf(buffer, "MemTotal: %llu kB", &memi.totalMem);
					else if(startsWith(buffer, "MemFree:"))
						sscanf(buffer, "MemFree: %llu kB", &memi.freeMem);	
				}
				double userate = 1.0 * (memi.totalMem - memi.freeMem) / memi.totalMem * 100.0;
				sleep(2);
				fflush(fp);
				rewind(fp);
				//sprintf(RamInfo, "RAM:%llu/%lluMB\n" , (memi.totalMem-memi.freeMem)/1024,memi.totalMem/1024);

			// 获取IP地址
			char IPInfo[MAX_SIZE];
			if (readed_ip == 0)
			{
				while (ifAddrStruct != NULL)
				{
					if (ifAddrStruct->ifa_addr->sa_family == AF_INET)
					{ // check it is IP4 is a valid IP4 Address
						tmpAddrPtr = &((struct sockaddr_in *)ifAddrStruct->ifa_addr)->sin_addr;
						char addressBuffer[INET_ADDRSTRLEN];
						inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);

						if (strcmp(ifAddrStruct->ifa_name, "eth0") == 0)
						{
							//sprintf(IPInfo, "eth0:%s", addressBuffer);
							readed_ip = 1;
							break;
						}
						else if (strcmp(ifAddrStruct->ifa_name, "wlan0") == 0)
						{
							//sprintf(IPInfo, "wlan0:%s", addressBuffer);
							readed_ip = 1;
							break;
						}else 
						{
							readed_ip = 0;
						}
					}
					ifAddrStruct = ifAddrStruct->ifa_next;
				}
				getifaddrs(&ifAddrStruct);
			}


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
					//sprintf(CPUTemp, "Temp:%.1fC", temp);
				}
			}
			close(fd_temp);

			// 读取磁盘空间，剩余/总空间
			char DiskInfo[MAX_SIZE];
			statfs("/", &disk_info);
			unsigned long long totalBlocks = disk_info.f_bsize;
			unsigned long long totalSize = totalBlocks * disk_info.f_blocks;
			size_t mbTotalsize = totalSize >> 20;
			unsigned long long freeDisk = disk_info.f_bfree * totalBlocks;
			size_t mbFreedisk = freeDisk >> 20;
			//sprintf(DiskInfo, "Disk:%ld/%ldMB", mbFreedisk, mbTotalsize);

			// 在显示屏上要显示的内容

			// 刷新显示
			//ssd1306_display();
			//delay(10);
		}

				if (temp <= 44)
				{
					level_temp = 44;
					wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x03);
				}
				else if (temp <= 48)
				{
					level_temp = 48;
					wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x06);
				}
				else if (temp <= 52)
				{
					level_temp = 52;
                                        wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x09);
				}
				else if (temp >= 56)
				{
					level_temp = 56;
                                        wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x01);
				}
	}

	return 0;
}
