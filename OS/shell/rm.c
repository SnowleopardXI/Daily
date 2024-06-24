#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

void remove_file(const char *path, int force, int interactive) {
    if (interactive) {
        printf("rm: remove '%s'? ", path);
        int response = getchar();
        if (response != 'y' && response != 'Y') {
            while (getchar() != '\n');  // 清空输入缓冲区
            return;  // 不删除，直接返回
        }
        while (getchar() != '\n');  // 清空输入缓冲区
    }

    if (unlink(path) && !force) {
        perror("Error deleting file");
    }
}

void remove_directory(const char *path, int recursive, int force, int interactive) {
    DIR *dir;
    struct dirent *entry;
    char full_path[1024];
    struct stat statbuf;

    if (!(dir = opendir(path))) {
        if (!force) {
            perror("Failed to open directory");
        }
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        stat(full_path, &statbuf);

        if (S_ISDIR(statbuf.st_mode)) {
            if (recursive) {
                remove_directory(full_path, recursive, force, interactive);
            } else if (!force) {
                fprintf(stderr, "rm: cannot remove '%s': Is a directory\n", full_path);
            }
        } else {
            remove_file(full_path, force, interactive);
        }
    }

    closedir(dir);

    if (rmdir(path) && !force) {
        perror("Error removing directory");
    }
}

int main(int argc, char *argv[]) {
    int recursive = 0;
    int force = 0;
    int interactive = 0;
    int opt;

    while ((opt = getopt(argc, argv, "rfi")) != -1) {
        switch (opt) {
            case 'r':
                recursive = 1;
                break;
            case 'f':
                force = 1;
                break;
            case 'i':
                interactive = 1;
                break;
            default:
                fprintf(stderr, "Usage: %s [-rfi] file...\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "Expected argument after options\n");
        exit(EXIT_FAILURE);
    }

    struct stat statbuf;
    for (int i = optind; i < argc; i++) {
        if (stat(argv[i], &statbuf) == -1) {
            if (!force) {
                perror("File or directory does not exist");
            }
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            remove_directory(argv[i], recursive, force, interactive);
        } else {
            remove_file(argv[i], force, interactive);
        }
    }

    return EXIT_SUCCESS;
}
