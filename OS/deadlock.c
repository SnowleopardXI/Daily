#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 5 // 进程数
#define M 3 // 资源数

typedef struct
{
    int id;            // PID
    int maxClaim[M];   // 最大需求资源
    int allocation[M]; // 已分配资源
    int need[M];       // 所需资源
} Process;

typedef struct
{
    int available[M]; // 可用资源
    Process processes[N];
} SystemState;

void initSystem(SystemState *state);
int requestResources(SystemState *state, int pid, int request[M]);
bool isSafe(SystemState *state);
void printSystemState(SystemState *state);
void releaseResources(SystemState *state, int pid);

void initSystem(SystemState *state)
{
    int i, j;

    // 初始化可用资源
    printf("输入每个资源数 (格式: r1 r2 ... r%d):\n", M);
    for (i = 0; i < M; i++)
    {
        scanf("%d", &state->available[i]);
    }

    // 测试数据
    int maxClaims[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}};
    int allocations[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}};

    // 初始化进程
    for (i = 0; i < N; i++)
    {
        state->processes[i].id = i;
        for (j = 0; j < M; j++)
        {
            state->processes[i].maxClaim[j] = maxClaims[i][j];
            state->processes[i].allocation[j] = allocations[i][j];
            state->processes[i].need[j] = state->processes[i].maxClaim[j] - state->processes[i].allocation[j];
        }
    }
}

void printSystemState(SystemState *state)
{
    printf("------------------ 当前系统状态 ------------------\n");
    printf("可用资源: ");
    for (int i = 0; i < M; i++)
    {
        printf("%d ", state->available[i]);
    }
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        printf("进程 P%d: MaxClaim = (", state->processes[i].id);
        for (int j = 0; j < M; j++)
        {
            printf("%d ", state->processes[i].maxClaim[j]);
        }
        printf(") Allocation = (");
        for (int j = 0; j < M; j++)
        {
            printf("%d ", state->processes[i].allocation[j]);
        }
        printf(") Need = (");
        for (int j = 0; j < M; j++)
        {
            printf("%d ", state->processes[i].need[j]);
        }
        printf(")\n");
    }
}

// 检查系统状态是否安全
bool isSafe(SystemState *state)
{
    int work[M];
    bool finish[N];
    int i, j;

    for (i = 0; i < M; i++)
    {
        work[i] = state->available[i];
    }

    for (i = 0; i < N; i++)
    {
        finish[i] = false;
    }

    for (i = 0; i < N; i++)
    {
        if (!finish[i])
        {
            bool canFinish = true;
            for (j = 0; j < M; j++)
            {
                if (state->processes[i].need[j] > work[j])
                {
                    canFinish = false;
                    break;
                }
            }

            if (canFinish)
            {
                for (j = 0; j < M; j++)
                {
                    work[j] += state->processes[i].allocation[j];
                }
                finish[i] = true;
                i = -1;
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        if (!finish[i])
        {
            return false;
        }
    }

    return true;
}

// 释放资源
void releaseResources(SystemState *state, int pid)
{
    for (int i = 0; i < M; i++)
    {
        state->available[i] += state->processes[pid].allocation[i];
        state->processes[pid].allocation[i] = 0;
        state->processes[pid].need[i] = 0;
    }
}

// 请求资源
int requestResources(SystemState *state, int pid, int request[M])
{
    int i;

    // 检查请求是否合法
    for (i = 0; i < M; i++)
    {
        if (request[i] < 0)
        {
            return 2; // 非法请求
        }
        if (request[i] > state->processes[pid].need[i])
        {
            return 2; // 非法请求
        }
    }

    // 检查是否有足够资源分配
    bool canAllocate = true;
    for (i = 0; i < M; i++)
    {
        if (request[i] > state->available[i])
        {
            canAllocate = false; // 无法分配
            break;
        }
    }

    if (!canAllocate)
    {
        return 3; // 无法满足请求
    }

    // 分配资源
    for (i = 0; i < M; i++)
    {
        state->processes[pid].allocation[i] += request[i];
        state->available[i] -= request[i];
        state->processes[pid].need[i] -= request[i];
    }

    // 检查系统状态是否安全
    if (!isSafe(state))
    {
        // 若不安全，回滚分配
        for (i = 0; i < M; i++)
        {
            state->processes[pid].allocation[i] -= request[i];
            state->available[i] += request[i];
            state->processes[pid].need[i] += request[i];
        }
        return 1; // 不安全
    }

    return 0; // 成功分配
}
int main()
{
    SystemState state;
    initSystem(&state);
    printSystemState(&state);
    while (1)
    {
        printf("1. 请求资源\n2. 释放资源\n3. 打印安全序列\n-1. 退出\n选择操作: ");
        int choice, pid, request[M];
        scanf("%d", &choice);

        if (choice == -1)
            break;

        switch (choice)
        {
        case 1:
            printf("输入请求的进程ID和资源数量 (格式: pid r1 r2 ... r%d): ", M);
            scanf("%d", &pid);
            for (int i = 0; i < M; i++)
            {
                scanf("%d", &request[i]);
            }
            int result = requestResources(&state, pid, request);
            if (result == 0)
            {
                printf("资源分配成功\n");
            }
            else if (result == 1)
            {
                printf("资源分配失败: 系统状态不安全\n");
            }
            else if (result == 2)
            {
                printf("资源分配失败: 非法请求\n");
            }
            else
            {
                printf("是否自动释放资源？(y/n): ");
                char c;
                scanf(" %c", &c);
                if (c == 'y')
                {
                    int releasePid = -1;
                    for (int i = 0; i < N; i++)
                    {
                        bool fullySatisfied = true;
                        for (int j = 0; j < M; j++)
                        {
                            if (state.processes[i].allocation[j] != state.processes[i].maxClaim[j])
                            {
                                fullySatisfied = false;
                                break;
                            }
                        }
                        if (fullySatisfied)
                        {
                            releasePid = i;
                            break;
                        }
                    }
                    printf("资源释放成功\n");
                    releaseResources(&state, releasePid);
                    requestResources(&state, pid, request);
                }
                printf("资源分配失败，进程%d被阻塞\n", pid);
            }
            break;

        case 2:
            printf("输入释放资源的进程ID: ");
            scanf("%d", &pid);
            releaseResources(&state, pid);
            printf("资源释放成功\n");
            break;

        case 3:
            if (isSafe(&state))
            {
                printf("当前系统状态安全\n");
            }
            else
            {
                printf("当前系统状态不安全\n");
            }
            break;

        default:
            printf("无效选择\n");
        }

        printSystemState(&state);
    }

    return 0;
}
