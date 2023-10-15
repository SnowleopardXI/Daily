#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"
#define ADC_RESOLUTION 1.8  // BeagleBone Black ADC resolution is 1.8V
#define ADC_MAX_VALUE 4095  // 12-bit ADC

float readADC() {
    int fd = open(ADC_PATH, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open ADC");
        return -1;
    }

    char buf[1024];
    read(fd, buf, sizeof(buf));
    close(fd);

    int raw = atoi(buf);
    return raw;
}

float voltageToTemperature(float voltage) {
    return voltage*100-50;  // Convert voltage to temperature
}

int main() {
    while(1) {
        int ADC = readADC();
        float voltage = ADC*(float)ADC_RESOLUTION/ADC_MAX_VALUE;
        float temperature = voltageToTemperature(voltage);
        
        printf("%d\tadc=%f\ntemp=%f\n", ADC, voltage, temperature);
        
        sleep(1);
    }
    return 0;
}
