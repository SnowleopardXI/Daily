#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80
#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <server_name>\n", argv[0]);
        return 1;
    }

    char *server_name = argv[1];
    int client_socket;
    struct sockaddr_in server_address;
    struct hostent *host_info;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket == -1) {
        perror("Socket");
        exit(1);
    }

    host_info = gethostbyname(server_name);
    if(!host_info) {
        fprintf(stderr, "Cannot get IP address for %s\n", server_name);
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    memcpy(&server_address.sin_addr, host_info->h_addr_list[0], host_info->h_length);

    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Connect");
        exit(1);
    }

    char request[] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, server_name);
    strcat(request, "\r\n\r\n");

    if(write(client_socket, request, strlen(request)) == -1) {
        perror("Write");
        exit(1);
    }

    char response[BUFFER_SIZE];
    if(read(client_socket, response, BUFFER_SIZE) == -1) {
        perror("Read");
        exit(1);
    }

    printf("%s\n", response);

    close(client_socket);
    return 0;
}
