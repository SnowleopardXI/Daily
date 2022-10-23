#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100

typedef char Elemtype;
typedef struct Sqstack
{ //栈的数据结构
    Elemtype data[Maxsize];
    int top;
} stack;

Sqstack *Creat_stack()
{ //栈的初始化
    Sqstack *s;
    s = (Sqstack *)malloc(sizeof(Sqstack));
    if (!s)
    {
        printf("内存空间不足，创建失败\n");
    }
    else
    {
        s->top = 0;
    }
    return s;
}

void input_stack(Sqstack *s, Elemtype x)
{ //入栈
    if (s->top > Maxsize)
    {
        printf("栈已经满，无法插入\n");
    }
    else
    {
        s->data[s->top] = x;
        s->top++;
    }
}

Elemtype output_stack(Sqstack *s)
{ //出栈
    if (s->top < 0)
    {
        printf("栈中已无元素，无法栈\n");
        return NULL;
    }
    else
    {
        printf("出栈成功\n");
        Elemtype x = s->data[s->top - 1];
        s->top--;
        return x;
    }
}

Elemtype *display(Sqstack *s)
{
    Elemtype *str;
    str = (Elemtype *)malloc(s->top * sizeof(Elemtype));
    for (int i = 0; i <= s->top; i++)
    {
        *(str + i) = s->data[s->top - i - 1];
    }
    return str;
}

void judge_stack(Sqstack *s, Elemtype str[])
{
    Elemtype *str1;
    str1 = display(s);
    int j = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != *(str1 + i))
            j = -1;
        i++;
    }
    if (j == -1)
        printf("no\n");
    else
        printf("yes\n");
}

int main()
{
    Sqstack *s = Creat_stack();
    char str[100];
    scanf("%s", str);
    int i = 0;
    while (str[i] != '\0')
    { //输入字符串入栈
        input_stack(s, str[i]);
        i++;
    }

    judge_stack(s, str);
    return 0;
}
