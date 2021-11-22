#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>
int point(int line, int x)
{
    if (x == 0 || x == 20 || line == pow(3, 19))
        return 3;
    else
        return line % ((int)(pow(3, 20 - x))) / ((int)(pow(3, 19 - x)));
}
int main()
{
    int line[21] = {0}, x, y, i, m, winner = 0, x_last1, y_last1, x_last2, y_last2, count = 0;
    line[0] = pow(3, 19);
    line[20] = pow(3, 19);
    bool color = 0, tuan[21][21] = {0}, eatable;
    while (1)
    {
        system("cls");
        printf("  1 2 3 4 5 6 7 8 9 10111213141516171819\n");
        for (i = 1; i <= 19; i++)
        {
            printf("%d", i);
            if (i < 10)
                printf(" ");
            for (m = 1; m <= 19; m++)
            {
                if (point(line[i], m) == 0)
                    printf("＋");
                if (point(line[i], m) == 1)
                    printf("＠");
                if (point(line[i], m) == 2)
                    printf("＃");
            }
            printf("\n");
        } //输出棋盘
        if (count >= 200)
            printf("输入0 0以认输\n");
        if (!color)
            printf("轮到黑方下棋，输入横纵坐标");
        if (color)
            printf("轮到白方下棋，输入横纵坐标");
        scanf("%d%d", &x, &y); //输入棋子位置
        if (count >= 200 && x == 0 && y == 0)
        {
            winner = !color + 1;
            break;
        }
        if (x >= 1 && x <= 19 && y >= 1 && y <= 19)
        {
            if (point(line[y], x) == 0)
                line[y] = line[y] + pow(3, 19 - x) * (color + 1);
            else
            {
                printf("该位置已被占用\n");
                system("pause");
                continue;
            }
        }
        else if (x == x_last2 && y == y_last2)
        {
            printf("不可循环下棋");
            system("pause");
            continue;
        }
        else
        {
            printf("超出范围\n");
            system("pause");
            continue;
        } //放置棋子
        for (int number = 1; i <= 4; i++)
        {
            eatable = 1;
            if (number == 1 && point(line[y], x + 1) == (!color + 1))
                tuan[x + 1][y] = 1;
            else if (number == 2 && point(line[y], x - 1) == (!color + 1))
                tuan[x - 1][y] = 1;
            else if (number == 3 && point(line[y + 1], x) == (!color + 1))
                tuan[x][y + 1] = 1;
            else if (number == 4 && point(line[y - 1], x) == (!color + 1))
                tuan[x][y - 1] = 1;
            for (int tuann = 1; tuann <= 36; tuann++)
                for (i = 1; i <= 19; i++)     //zong
                    for (m = 1; m <= 19; m++) //heng
                        if (tuan[m][i] == 1)
                        {
                            if (point(line[i], m + 1) == point(line[i], m))
                                tuan[m + 1][i] = 1;
                            if (point(line[i], m - 1) == point(line[i], m))
                                tuan[m - 1][i] = 1;
                            if (point(line[i + 1], m) == point(line[i], m))
                                tuan[m][i + 1] = 1;
                            if (point(line[i - 1], m) == point(line[i], m))
                                tuan[m][i - 1] = 1;
                        }
            for (i = 1; i <= 19; i++)
            {
                for (m = 1; m <= 19; m++)
                {
                    if ((tuan[m][i] == 1) && (point(line[i], m + 1) == 0 || point(line[i], m - 1) == 0 || point(line[i + 1], m) == 0 || point(line[i - 1], m) == 0))
                    {
                        eatable = 0;
                        break;
                    }
                }
                if (!eatable)
                    break;
            }
            if (eatable)
                for (i = 1; i <= 19; i++)
                    for (m = 1; m <= 19; m++)
                        if (tuan[m][i] == 1)
                            line[i] = line[i] - (pow(3, 19 - m)) * point(line[i], m);
            for (i = 1; i <= 19; i++)
                for (m = 1; m <= 19; m++)
                    tuan[m][i] = 0;
        }
        eatable = 1;
        tuan[x][y] = 1;
        for (int tuann = 1; tuann <= 36; tuann++)
            for (i = 1; i <= 19; i++) //zong
                for (m = 1; m <= 19; m++) //heng
                    if (tuan[m][i] == 1)
                    {
                        if (point(line[i], m + 1) == point(line[i], m))
                            tuan[m + 1][i] = 1;
                        if (point(line[i], m - 1) == point(line[i], m))
                            tuan[m - 1][i] = 1;
                        if (point(line[i + 1], m) == point(line[i], m))
                            tuan[m][i + 1] = 1;
                        if (point(line[i - 1], m) == point(line[i], m))
                            tuan[m][i - 1] = 1;
                    }
        for (i = 1; i <= 19; i++)
        {
            for (m = 1; m <= 19; m++)
            {
                if ((tuan[m][i] == 1) && (point(line[i], m + 1) == 0 || point(line[i], m - 1) == 0 || point(line[i + 1], m) == 0 || point(line[i - 1], m) == 0))
                {
                    eatable = 0;
                    break;
                }
            }
            if (!eatable)
                break;
        }
        for (i = 1; i <= 19; i++)
            for (m = 1; m <= 19; m++)
                tuan[m][i] = 0;
        if (eatable)
        {
            printf("该位置不可下棋");
            system("pause");
            line[y] = line[y] - (pow(3, 19 - x)) * (color + 1);
            continue;
        }
        color = !color;
        count++;
        x_last2 = x_last1;
        y_last2 = y_last1;
        x_last1 = x;
        y_last1 = y;
    }
    system("cls");
    printf("  1 2 3 4 5 6 7 8 9 10111213141516171819\n");
    for (i = 1; i <= 19; i++)
    {
        printf("%d", i);
        if (i < 10)
            printf(" ");
        for (m = 1; m <= 19; m++)
        {
            if (point(line[i], m) == 0)
                printf("＋");
            if (point(line[i], m) == 1)
                printf("＠");
            if (point(line[i], m) == 2)
                printf("＃");
        }
        printf("\n");
    } //输出棋盘
    if (winner == 1)
        printf("黑方胜利");
    if (winner == 2)
        printf("白方胜利");
    system("pause");
    return 0;
}