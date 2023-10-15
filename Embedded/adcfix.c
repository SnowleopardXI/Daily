#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define SYSFS_ADC_DIR "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"
#define MAX_BUF 64

void main()
{
    int fd,len;
    char buf[MAX_BUF];
    int ch[5],i;
    for (i=0;i<50;i++)
    {
        snprintf(buf, sizeof(buf), SYSFS_ADC_DIR);
        fd = open(buf, O_RDONLY);
        read(fd, ch, 4);
        printf("%s\n",ch);
        close(fd);
        usleep(1000);
    }
    return 0;
}