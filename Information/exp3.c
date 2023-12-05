#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX_SYMBOLS 4
#define MAX_CODE_LEN 4

typedef struct
{
    char symbol[MAX_SYMBOLS];
    float probability;
    char code[MAX_CODE_LEN];
} Symbol;

void encode(Symbol symbols[], int start, int end, char *prefix)
{
    if (start == end)
    {
        strcpy(symbols[start].code, prefix);
        return;
    }

    // 分割点的查找
    float total_prob = 0;
    for (int i = start; i <= end; i++)
    {
        total_prob += symbols[i].probability;
    }

    float cum_prob = 0;
    int split_index = start;
    for (int i = start; i <= end; i++)
    {
        cum_prob += symbols[i].probability;
        if (cum_prob >= total_prob / 2)
        {
            split_index = i;
            break;
        }
    }

    // 为两部分生成新的前缀
    char newPrefix[MAX_CODE_LEN];
    strcpy(newPrefix, prefix);
    strcat(newPrefix, "0");
    encode(symbols, start, split_index, newPrefix);

    strcpy(newPrefix, prefix);
    strcat(newPrefix, "1");
    encode(symbols, split_index + 1, end, newPrefix);
}

int main()
{
    Symbol symbols[MAX_SYMBOLS] = {
        {"x1", 0.5, ""},
        {"x2", 0.25, ""},
        {"x3", 0.125, ""},
        {"x4", 0.125, ""}};
    encode(symbols, 0, MAX_SYMBOLS - 1, "");
    printf("符号\t概率\t香农编码\t累计概率\t码长\n");
    float entropy = 0, avg_code_len = 0, code_len = 0, cum_prob = 0;
    for (int i = 0; i < MAX_SYMBOLS; i++)
    {
        code_len = strlen(symbols[i].code);
        avg_code_len += symbols[i].probability * code_len;
        cum_prob += symbols[i].probability;
        entropy += symbols[i].probability * log2(1 / symbols[i].probability);
        printf("%s\t%.3f\t%s\t\t%.3f\t\t%.0f\n", symbols[i].symbol, symbols[i].probability, symbols[i].code, cum_prob, code_len);
    }
    printf("信源熵：%.2f\n", entropy);
    printf("平均码长：%.2f\n", avg_code_len);
    printf("编码效率：%.0f%%\n", entropy / avg_code_len * 100);
    return 0;
}