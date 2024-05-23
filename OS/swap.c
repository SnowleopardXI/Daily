#include <stdio.h>
#include <string.h>
#define size 1024
#define loaded 4

struct task
{
    int num;
    int flag;
    int block;
    int modify;
    int location;
} task[7] = {
    {0, 1, 5, 0, 010},
    {1, 1, 8, 0, 012},
    {2, 1, 9, 0, 013},
    {3, 1, 1, 0, 021},
    {4, 0, -1, 0, 022},
    {5, 0, -1, 0, 023},
    {6, 0, -1, 0, 125}};

struct memblk
{
    char operation[10];
    int pagenumber;
    int address;
};
int main()
{
    int i = 0, memPage = 0, taskPage = 0, replacedpage = 0, pmodify = 0, writeback = 0;
    int list[4] = {0, 1, 2, 3};
    int k = 0;
    long memaddress;
    int number;
    printf("请输入指令个数：");
    scanf("%d", &number);
    struct memblk mem[number];
    printf("请输入指令：\n");
    for (i = 0; i < number; i++)
    {
        scanf("%s %d %d", mem[i].operation, &mem[i].pagenumber, &mem[i].address);
    }
    printf("\n 操作\t 页号 \t页内地址   标志  绝对地址   修改页号   页架号  绝对地址   是否写回   写回地址\n");
    for (i = 0; i < number; i++)
    {
        memPage = mem[i].pagenumber;
        taskPage = task[memPage].flag;
        if (taskPage == 0)
        {
            replacedpage = list[k];
            pmodify = task[replacedpage].modify;
            list[k] = memPage;
            k = (k + 1) % loaded;
            task[memPage].flag = 1;
            task[memPage].block = task[replacedpage].block;
            task[replacedpage].block = -1;
            task[replacedpage].flag = 0;
            task[replacedpage].modify = 0;
        }
        memaddress = task[memPage].block * size + mem[i].address;
        if (strcmp(mem[i].operation, "save") == 0)
        {
            task[memPage].modify = 1;
            writeback = 1;
        }
        else
        {
            writeback = 0;
        }
        printf(" %s\t", mem[i].operation);
        printf("  %d\t", mem[i].pagenumber);
        printf("   %d\t", mem[i].address);
        printf("     %d\t", taskPage);
        if (taskPage == 1)
            printf("   %d\t", memaddress);
        else
            printf("   *%d\t", mem[i].pagenumber);
        if (taskPage == 1)
            printf("        \t");
        else
            printf("     %d->%d\t", mem[i].pagenumber, replacedpage);
        printf(" %d\t", task[memPage].block);
        printf("  %d\t", memaddress);
        if (writeback == 1)
            printf("   yes\t");
        else
            printf("   no\t");
        if (writeback == 1)
            printf("       %d\n", task[memPage].location);
        printf("\n");
    }
}