#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void print_month(int year, int month);
void print_year(int year);

int main(int argc, char *argv[]) {
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int year = local->tm_year + 1900;
    int month = local->tm_mon + 1;

    if (argc == 1) {
        // 无参数显示当前月份
        print_month(year, month);
    } else if (argc == 2 && strcmp(argv[1], "-y") == 0) {
        // 参数为-y显示当前年份
        print_year(year);
    } else if (argc == 3 && strcmp(argv[1], "-m") == 0) {
        // 参数为-m后跟月份显示该月份
        month = atoi(argv[2]);
        if (month < 1 || month > 12) {
            printf("Invalid month\n");
            return 1;
        }
        print_month(year, month);
    } else {
        printf("Usage: %s [-y] [-m month]\n", argv[0]);
        return 1;
    }
    
    return 0;
}

void print_month(int year, int month) {
    printf("Printing month: %d-%d\n", month, year);
    // 这里应添加实际打印月历的代码
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    int days = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            days = 29;
        else
            days = 28;
    }
    int weekday = (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + 1) % 7;
    for (int i = 0; i < weekday; i++)
        printf("    ");
    for (int i = 1; i <= days; i++) {
        printf("%3d ", i);
        if ((i + weekday) % 7 == 0)
            printf("\n");
    }
    printf("\n");
}

void print_year(int year) {
    printf("Printing year: %d\n", year);
    for (int month = 1; month <= 12; month++) {
        print_month(year, month);
        if (month % 3 == 0)
            printf("\n");
    }
}
