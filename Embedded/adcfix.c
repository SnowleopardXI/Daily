#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define SYSFS_ADC_DIR "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"
#define MAX_BUF 64

int main()
{
    int fd;
    char buf[MAX_BUF];
    char ch[MAX_BUF]; // 用字符缓冲区代替整型数组
    int i;
    for (i=0; i<50; i++)
    {
        snprintf(buf, sizeof(buf), SYSFS_ADC_DIR);
        fd = open(buf, O_RDONLY);
        if(fd < 0) {
            perror("Failed to open the file");
            exit(1);
        }
        read(fd, ch, sizeof(ch) - 1);
        ch[sizeof(ch) - 1] = '\0'; // 确保以 null 结尾
        printf("%s\n", ch);
        close(fd);
        usleep(1000);
    }
    return 0;
}
