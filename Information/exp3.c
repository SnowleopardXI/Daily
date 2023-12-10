#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX_SYMBOLS 6
#define MAX_CODE_LEN 8

typedef struct
{
    char symbol[MAX_SYMBOLS];
    double probability;
    char code[MAX_CODE_LEN];
} Symbol;

void encode(Symbol symbols[], int start, int end, char *prefix)
{
    // 递归出口
    if (start == end)
    {
        strcpy(symbols[start].code, prefix);
        return;
    }

    // 分割点的查找
    double total_prob = 0;
    for (int i = start; i <= end; i++)
    {
        total_prob += symbols[i].probability;
    }

    double cum_prob = 0;
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

    // 递归调用
    char left_prefix[MAX_CODE_LEN], right_prefix[MAX_CODE_LEN];
    strcpy(left_prefix, prefix);
    strcat(left_prefix, "0");
    encode(symbols, start, split_index, left_prefix);
    strcpy(right_prefix, prefix);
    strcat(right_prefix, "1");
    encode(symbols, split_index + 1, end, right_prefix);
}

int main()
{
    Symbol symbols[MAX_SYMBOLS] = {
        {"u1", 0.15, ""},
        {"u2", 0.25, ""},
        {"u3", 0.2, ""},
        {"u4", 0.25, ""},
        {"u5", 0.05, ""},
        {"u6", 0.1, ""}
        };
    encode(symbols, 0, MAX_SYMBOLS - 1, "");
    printf("符号\t概率\t香农编码\t累计概率\t码长\n");
    double entropy = 0, avg_code_len = 0, code_len = 0, cum_prob = 0;
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