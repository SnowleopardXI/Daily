#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100

typedef struct stack
{
    char data[Maxsize];
    int top;
} stack;

stack *Creat_stack()
{
    stack *L;
    L = (stack *)malloc(sizeof(stack));
    if (!L)
        exit(0);
    L->top = 0;
    return L;
}

void insert_stack(stack *L, char x)
{
    L->data[L->top] = x;
    L->top++;
}

void display(stack *L)
{
    while (L->top > 0)
    {
        printf("%c", L->data[L->top - 1]);
        L->top--;
    }
}

int main()
{
    stack *L;
    L = Creat_stack();
    int num, N;
    scanf("%d %d", &num, &N);
    int x, y, temp;
    x = num / N;
    y = num % N;
    while (x != 0)
    {
        if (y >= 0 && y < 10)
        {
            char a = '0' + y;
            insert_stack(L, a);
        }
        else if (y >= 10)
        {
            char b = 'A' + y - 10;
            insert_stack(L, b);
        }
        if (x < N)
        {
            if (x >= 0 && x < 10)
            {
                char c = '0' + x;
                insert_stack(L, c);
            }
            else if (x >= 10)
            {
                char d = 'A' + x - 10;
                insert_stack(L, d);
            }
            break;
        }
        temp = x;
        x = x / N;
        y = temp % N;
    }
    display(L);
}
