#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char input[BUFFER_SIZE];

    // 创建客户端的套接字
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 转换IP地址格式
    if (inet_pton(AF_INET, "192.168.7.2", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return -1;
    }

    // 连接到服务器
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        return -1;
    }

    std::cout << "Connected to the server. Enter your commands ('on', 'off', 'temp', 'exit', 'adc')" << std::endl;
    while (true) {
        std::cin.getline(input, BUFFER_SIZE);
        
        // 发送数据到服务器
        send(sock, input, strlen(input), 0);

        valread = read(sock, buffer, BUFFER_SIZE);
        buffer[valread] = '\0';

        // 输出服务器的响应
        std::cout << "Server response: " << buffer << std::endl;

        // 如果服务器响应断开连接，客户端也将断开连接
        if (strcmp(buffer, "exit") == 0) {
            std::cout << "Server has disconnected. Exiting client..." << std::endl;
            break;
        }
    }

    close(sock);

    return 0;
}
