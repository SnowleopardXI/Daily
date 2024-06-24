#include <stdio.h>
#include <stdlib.h>

int main() {
    char* username = getenv("USER");  // 在大多数UNIX系统上, 或者尝试 "USERNAME" 在Windows系统
    if (username == NULL) {
        printf("Cannot find the USER environment variable.\n");
    } else {
        printf("Current user is: %s\n", username);
    }
    return 0;
}
