/*默认gpio44为led，ADC使用voltage0*/
#include <iostream>
#include <cstring>
#include <fstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define GPIO_DIR "/sys/class/gpio/"
#define adc_path "/sys/bus/iio/devices/iio:device0/in_voltage0_raw"
#define PORT 8080
void write_to_file(const char *path, const char *value)
{
    FILE *stream = fopen(path, "w");
    if (stream)
    {
        fwrite(value, sizeof(char), strlen(value), stream);
        fclose(stream);
    }
}
void led_control(int action)
{
    write_to_file(GPIO_DIR"gpio44/direction", "out");
    write_to_file(GPIO_DIR"gpio44/value", "0");
    if (action == 1)
    {
        write_to_file(GPIO_DIR "gpio44/value", "1");
    }
    else
    {
        write_to_file(GPIO_DIR "gpio44/value", "0");
    }
}

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    write_to_file(GPIO_DIR "unexport", "44");
    write_to_file(GPIO_DIR "export", "44");
    // Create socket connnection
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation error");
        return -1;
    }
    // Bind socket to port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Set socket option error");
        return -1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind error");
        return -1;
    }
    // Establish connection
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen error");
        return -1;
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("Accept error");
        return -1;
    }
    // Listening
    listen(new_socket, 10);
    // Accept connection
    while (true)
    {
        ssize_t valread = read(new_socket, buffer, 1024);
        buffer[valread] = '\0';
        std::cout << "Client request: " << buffer << std::endl;
        if (strcmp(buffer, "on") == 0)
        {
            led_control(1);
            send(new_socket, "LED is on", strlen("LED is on"), 0);
        }
        else if (strcmp(buffer, "off") == 0)
        {
            led_control(0);
            send(new_socket, "LED is off", strlen("LED is off"), 0);
        }
        else if (strcmp(buffer, "temp") == 0)
        {
            std::ifstream adc_file(adc_path);
            std::string adc_value;
            std::getline(adc_file, adc_value);
            send(new_socket, adc_value.c_str(), strlen(adc_value.c_str()), 0);
        }
        else if (strcmp(buffer, "exit") == 0)
        {
            send(new_socket, "exit", strlen("exit"), 0);
            break;
        }
        else
        {
            send(new_socket, buffer, strlen(buffer), 0);
        }
    }
    close(new_socket);
    close(server_fd);

    return 0;
}
