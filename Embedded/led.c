#include <stdio.h>
#include <unistd.h>

#define GPIO_DIR "/sys/class/gpio/"

void write_to_file(const char *path, const char *value) {
    FILE *stream = fopen(path, "w");
    if (stream) {
        fwrite(value, sizeof(char), strlen(value), stream);
        fclose(stream);
    }
}

int main() {
    unsigned int delay = 500000; // 500ms
    unsigned int cycles = 3;

    // Setup GPIOs
    write_to_file(GPIO_DIR "export", "44");
    write_to_file(GPIO_DIR "export", "45");
    write_to_file(GPIO_DIR "gpio44/direction", "out");
    write_to_file(GPIO_DIR "gpio45/direction", "out");

    // 点亮44
    for (int i = 0; i < cycles; i++) {
        write_to_file(GPIO_DIR "gpio44/value", "1");
        usleep(delay);
        write_to_file(GPIO_DIR "gpio44/value", "0");
        write_to_file(GPIO_DIR "gpio45/value", "1");
        usleep(delay);
        write_to_file(GPIO_DIR "gpio45/value", "0");
    }
    // Reset GPIOs
    write_to_file(GPIO_DIR "gpio44/value", "0");
    write_to_file(GPIO_DIR "gpio45/value", "0");
    write_to_file(GPIO_DIR "export", "44");
    write_to_file(GPIO_DIR "export", "45");
    write_to_file(GPIO_DIR "gpio44/direction", "out");
    write_to_file(GPIO_DIR "gpio45/direction", "out");
    // 点亮45
    for (int i = 0; i < cycles; i++) {
        write_to_file(GPIO_DIR "gpio45/value", "1");
        usleep(delay);
        write_to_file(GPIO_DIR "gpio45/value", "0");
        write_to_file(GPIO_DIR "gpio44/value", "1");
        usleep(delay);
        write_to_file(GPIO_DIR "gpio44/value", "0");
    }
    // Reset the GPIOs to a safe state
    write_to_file(GPIO_DIR "gpio44/value", "0");
    write_to_file(GPIO_DIR "gpio45/value", "0");

    return 0;
}
