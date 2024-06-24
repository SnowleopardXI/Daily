#include <stdio.h>
#include <time.h>

int main() {
    time_t now;
    struct tm *now_tm;

    time(&now);  // 获取当前的时间（自Epoch以来的秒数）
    now_tm = localtime(&now);  // 转换为本地时间

    printf("Current date and time: %s", asctime(now_tm));  // 输出可读格式的日期和时间

    return 0;
}
