#include <stdio.h>
#include <stdlib.h>

//导入文件控制函数库
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// 导入wiringPi/I2C库
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp"
#define MAX_SIZE 20

int main(void)
{
    // 定义CPU温度相关参数
    int fd_temp;
    double temp = 0, level_temp = 0;
    char buf[MAX_SIZE];

    // 定义I2C相关参数
    int fd_i2c;
    wiringPiSetup();
    fd_i2c = wiringPiI2CSetup(0x0d);
    if (fd_i2c < 0)
    {
        fprintf(stderr, "fail to init I2C\n");
        return -1;
    }

    while (1)
    {
        fd_temp = open(TEMP_PATH, O_RDONLY);
        // 判断文件是否正常打开
        if (fd_temp < 0)
        {
            fprintf(stderr, "fail to open thermal_zone0/temp\n");
            return -1;
        }

        // 读取温度并判断
        if (read(fd_temp, buf, MAX_SIZE) < 0)
        {
            fprintf(stderr, "fail to read temp\n");
            return -1;
        }

        // 转化格式，输出保留小数点后2位
        temp = atoi(buf) / 1000.0;
        printf("temp: %.1fC\n", temp);
        close(fd_temp); //关闭文件

        if (abs(temp - level_temp) >= 1)
        {
            if (temp <= 45)
            {
                level_temp = 45;
                wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x00);
            }
            else if (temp <= 47)
            {
                level_temp = 47;
                wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x04);
            }
            else if (temp <= 49)
            {
                level_temp = 49;
                wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x06);
            }
            else if (temp <= 51)
            {
                level_temp = 51;
                wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x08);
            }
            else if (temp <= 53)
            {
                level_temp = 53;
                wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x09);
            }
            else
            {
                level_temp = 55;
                wiringPiI2CWriteReg8(fd_i2c, 0x08, 0x01);
            }
        }

        delay(500);
    }

    return 0;
}
