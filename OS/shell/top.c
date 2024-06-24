/*
    my Linux top command source code of C program 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void get_cpu_usage() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    char *match;
    double user, nice, system, idle;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return;
    }

    bytes_read = fread(buffer, 1, sizeof(buffer) - 1, fp);
    fclose(fp);

    if (bytes_read == 0 || bytes_read == sizeof(buffer) - 1) {
        perror("Failed to read /proc/stat");
        return;
    }

    buffer[bytes_read] = '\0';
    match = strstr(buffer, "cpu ");
    if (match == NULL) {
        perror("Failed to find 'cpu' in /proc/stat");
        return;
    }

    sscanf(match, "cpu %lf %lf %lf %lf", &user, &nice, &system, &idle);
    printf("CPU Usage: User: %.2lf%% Nice: %.2lf%% System: %.2lf%% Idle: %.2lf%%\n", 
           user, nice, system, idle);
}

void get_memory_usage() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    char *match;
    unsigned long total, free;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    bytes_read = fread(buffer, 1, sizeof(buffer) - 1, fp);
    fclose(fp);

    if (bytes_read == 0 || bytes_read == sizeof(buffer) - 1) {
        perror("Failed to read /proc/meminfo");
        return;
    }

    buffer[bytes_read] = '\0';

    match = strstr(buffer, "MemTotal:");
    if (match == NULL) {
        perror("Failed to find 'MemTotal' in /proc/meminfo");
        return;
    }
    sscanf(match, "MemTotal: %lu kB", &total);

    match = strstr(buffer, "MemFree:");
    if (match == NULL) {
        perror("Failed to find 'MemFree' in /proc/meminfo");
        return;
    }
    sscanf(match, "MemFree: %lu kB", &free);

    printf("Memory Usage: Total: %lu kB Free: %lu kB\n", total, free);
}

void list_processes() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("PID\tCMD\n");

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char *end;
            long pid = strtol(entry->d_name, &end, 10);
            if (*end == '\0') {
                char cmdline_path[BUFFER_SIZE];
                char cmdline[BUFFER_SIZE];
                int fd;
                ssize_t length;

                snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%ld/cmdline", pid);
                fd = open(cmdline_path, O_RDONLY);
                if (fd != -1) {
                    length = read(fd, cmdline, sizeof(cmdline) - 1);
                    close(fd);
                    if (length > 0) {
                        cmdline[length] = '\0';
                        printf("%ld\t%s\n", pid, cmdline);
                    }
                }
            }
        }
    }

    closedir(dir);
}

int main() {
    while (1) {
        system("clear");
        get_cpu_usage();
        get_memory_usage();
        list_processes();
        sleep(2);
    }

    return 0;
}
