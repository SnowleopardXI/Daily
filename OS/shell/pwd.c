#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char *cwd;
    char buffer[1024];  // 设定一个合理的缓冲区大小

    cwd = getcwd(buffer, sizeof(buffer));
    if (cwd == NULL) {
        perror("getcwd() error");
        return -1;
    }

    printf("Current working directory: %s\n", cwd);
    return 0;
}
