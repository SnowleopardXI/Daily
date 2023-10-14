#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#include <fstream>

// 设定LED的GPIO路径
const std::string GPIO_PATH = "/sys/class/gpio/gpio44/value";

void toggleLED(const std::string& status) {
    std::ofstream gpioFile(GPIO_PATH);
    if (status == "On") {
        gpioFile << "1";
    } else {
        gpioFile << "0";
    }
    gpioFile.close();
}

std::string getADCValue() {
    // 假设ADC数据在以下路径
    std::ifstream adcFile("/sys/bus/iio/devices/iio:device0/in_voltage0_raw");
    std::string value;
    adcFile >> value;
    return value;
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrLen = sizeof(clientAddr);
    char buffer[1024] = {0};

    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080);

    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 10);

    std::cout << "Server started. Waiting for connections..." << std::endl;
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &addrLen);

    while (true) {
        memset(buffer, 0, sizeof(buffer));
        recv(clientSocket, buffer, sizeof(buffer), 0);

        if (strcmp(buffer, "On") == 0 || strcmp(buffer, "Off") == 0) {
            toggleLED(buffer);
            send(clientSocket, "LED toggled", 12, 0);
        } else if (strcmp(buffer, "temp") == 0) {
            std::string adcValue = getADCValue();
            send(clientSocket, adcValue.c_str(), adcValue.length(), 0);
        } else if (strcmp(buffer, "exit") == 0) {
            break;
        } else {
            send(clientSocket, "Unknown command", 15, 0);
        }
    }

    close(clientSocket);
    close(serverSocket);
    return 0;
}
