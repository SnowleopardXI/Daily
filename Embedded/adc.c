#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BASE_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#define MAX_BUF 64

double convertToVoltage(int rawValue) {
    return rawValue * (1.8 / 4096.0);
}

int main() {
    char path[MAX_BUF];
    char buf[MAX_BUF];
    int rawValue;

    for (int i = 0; i <= 6; i++) {
        snprintf(path, sizeof(path), "%s%d_raw", BASE_PATH, i);
        
        FILE *file = fopen(path, "r");
        if (!file) {
            perror("Error opening file");
            return 1;
        }
        
        if (fgets(buf, sizeof(buf), file) == NULL) {
            perror("Error reading file");
            fclose(file);
            return 1;
        }
        
        fclose(file);

        rawValue = atoi(buf);
        double voltage = convertToVoltage(rawValue);
        
        printf("%d\tadc=%.6fV\n", rawValue, voltage);
    }

    return 0;
}
