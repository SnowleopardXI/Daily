#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pwd.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_INFO_LENGTH 256

typedef struct ProcessInfo
{
    int pid;
    char user[32];
    char state;
    int ppid;
    int pgid;
    int sid;
    int tty_nr;
    char comm[256];
    unsigned long vsize;
    unsigned long utime;
    unsigned long stime;
    unsigned long cutime;
    unsigned long cstime;
    int start_time;
    long rss;
} ProcessInfo;

typedef struct ProcessNode
{
    ProcessInfo info;
    struct ProcessNode *parent;
    struct ProcessNode *children[MAX_PROCESSES];
    int child_count;
} ProcessNode;

typedef struct
{
    ProcessNode *processes[MAX_PROCESSES];
    int process_count;
} ProcessList;

ProcessList list;
void get_username(uid_t uid, char *username)
{
    struct passwd *pw = getpwuid(uid);
    if (pw)
    {
        strcpy(username, pw->pw_name);
    }
    else
    {
        strcpy(username, "unknown");
    }
}

void read_process_info(ProcessInfo *info, const char *pid_str)
{
    char path[256];
    char buffer[256];
    FILE *file;

    snprintf(path, sizeof(path), "/proc/%s/stat", pid_str);
    file = fopen(path, "r");
    if (file)
    {
        fscanf(file, "%d %s %c %d %d %d %d %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %*u %lu %ld %*d %*d %*d %*d %*u %*u %*d",
               &info->pid, info->comm, &info->state, &info->ppid, &info->pgid, &info->sid, &info->tty_nr,
               &info->utime, &info->stime, &info->cutime, &info->cstime, &info->vsize, &info->rss);
        fclose(file);
    }
    // 计算进程运行时间
    info->start_time = time(NULL) - (info->utime + info->stime + info->cutime + info->cstime) / sysconf(_SC_CLK_TCK);
    snprintf(path, sizeof(path), "/proc/%s/status", pid_str);
    file = fopen(path, "r");
    if (file)
    {
        while (fgets(buffer, sizeof(buffer), file))
        {
            if (strncmp(buffer, "Uid:", 4) == 0)
            {
                uid_t uid;
                sscanf(buffer, "Uid: %*d %d", &uid);
                get_username(uid, info->user);
                break;
            }
        }
        fclose(file);
    }
}

void add_process(ProcessList *list, ProcessInfo *info)
{
    if (list->process_count < MAX_PROCESSES)
    {
        ProcessNode *node = malloc(sizeof(ProcessNode));
        node->info = *info;
        node->child_count = 0;
        list->processes[list->process_count++] = node;
    }
}

void read_all_processes(ProcessList *list)
{
    struct dirent *entry;
    DIR *dp = opendir("/proc");

    if (dp == NULL)
    {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)))
    {
        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0]))
        {
            ProcessInfo info;
            read_process_info(&info, entry->d_name);
            add_process(list, &info);
        }
    }

    closedir(dp);
}

void print_process_list(ProcessList *list, const char *format)
{
    int current_tty = ttyname(STDOUT_FILENO) ? atoi(ttyname(STDOUT_FILENO) + 5) : 0; // 获取当前TTY编号

    for (int i = 0; i < list->process_count; ++i)
    {
        if (strcmp(format, "aux") == 0)
        {
            printf("%-10s %-5d %-5c %-5d %-5d %-5d %-5d %-10s %-10lu %-10ld\n",
                   list->processes[i]->info.user, list->processes[i]->info.pid, list->processes[i]->info.state,
                   list->processes[i]->info.ppid, list->processes[i]->info.pgid, list->processes[i]->info.sid,
                   list->processes[i]->info.tty_nr, list->processes[i]->info.comm, list->processes[i]->info.vsize,
                   list->processes[i]->info.rss);
        }
        else if (strcmp(format, "default") == 0)
        {
            // 打印与当前终端相关的进程信息
            if (list->processes[i]->info.tty_nr == current_tty)
            {
                printf("PID\tTTY\t\tTIME\t\tCOMMAND\n");
                printf("%d\t%s\t%d\t%s\n",
                       list->processes[i]->info.pid, ttyname(STDOUT_FILENO),
                       (int)(time(NULL) - list->processes[i]->info.start_time), // 运行时间假定已在结构中
                       list->processes[i]->info.comm);
            }
        }
    }
}

void build_process_tree(ProcessList *list)
{
    for (int i = 0; i < list->process_count; ++i)
    {
        ProcessNode *child = list->processes[i];
        for (int j = 0; j < list->process_count; ++j)
        {
            ProcessNode *parent = list->processes[j];
            if (child->info.ppid == parent->info.pid)
            {
                child->parent = parent;
                parent->children[parent->child_count++] = child;
                break;
            }
        }
    }
}

void print_process_tree(ProcessNode *node, int level)
{
    // 打印当前进程信息，每一级增加两个空格的缩进
    for (int i = 0; i < level; ++i)
    {
        printf("  ");
    }
    printf("%d\t%s\t%c\t%d\t%d\t%d\t%d\t%s\t%lu\t%ld\n",
           node->info.pid, node->info.user, node->info.state, node->info.ppid,
           node->info.pgid, node->info.sid, node->info.tty_nr, node->info.comm,
           node->info.vsize, node->info.rss);

    // 递归打印所有子进程
    for (int i = 0; i < node->child_count; ++i)
    {
        print_process_tree(node->children[i], level + 1);
    }
}

int main(int argc, char *argv[])
{

    list.process_count = 0;
    read_all_processes(&list);

    if (argc == 1)
    {
        // 只打印ps无参数的情况
        print_process_list(&list, "default");
    }
    else if (strcmp(argv[1], "aux") == 0)
    {
        printf("USER       PID  STAT  PPID  PGID   SID  TTY_NR  COMMAND    VSIZE      RSS\n");
        print_process_list(&list, "aux");
    }
    else if (strcmp(argv[1], "axjf") == 0)
    {
        build_process_tree(&list);
        printf("PID\tUSER\tSTAT\tPPID\tPGID\tSID\tTTY_NR\tCOMMAND\tVSIZE\tRSS\n");
        for (int i = 0; i < list.process_count; ++i)
        {
            if (list.processes[i]->parent == NULL) // 只从根节点开始打印
            {
                print_process_tree(list.processes[i], 0);
            }
        }
    }
    else
    {
        fprintf(stderr, "Usage: %s [aux|axjf]\n", argv[0]);
        return 1;
    }

    return 0;
}