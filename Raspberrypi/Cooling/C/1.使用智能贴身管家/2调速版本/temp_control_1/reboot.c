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


int main(void)
{
	ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
	char indicator[20] = "Restarting...";
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
	printf("I2C init success\n");
	ssd1306_clearDisplay();
	ssd1306_drawText(0, 0, indicator);
	ssd1306_display();
	wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x01);
	wiringPiI2CWriteReg8(fd_i2c, 0x07, 0x00);
	
	return 0;
}
