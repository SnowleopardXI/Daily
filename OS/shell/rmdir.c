#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <directory_name>\n", prog_name);
    fprintf(stderr, "  <directory_name> : Name of the directory to remove\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *dir_name = argv[1];

    if (rmdir(dir_name) == -1) {
        perror("rmdir");
        exit(EXIT_FAILURE);
    }

    printf("Directory '%s' removed\n", dir_name);
    return EXIT_SUCCESS;
}
