#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
const float letterStat[] = {0.082, 0.015, 0.028, 0.043, 0.127, 0.022, 0.02, 0.061,
                            0.07, 0.002, 0.008, 0.04, 0.024, 0.067, 0.075, 0.019, 
                            0.001, 0.06, 0.063, 0.091, 0.028, 0.01, 0.023, 0.001,
                            0.02, 0.001};

// 求解密钥
void getk(string c, string c1)
{
    // 求出密钥长度
    int klen = 1;        // 密钥长度
    int clen = c.size(); // 密文的长度
    while (1)
    {

        float IC[klen];                // 重合指数
        float avgIC = 0;               // 平均重合指数
        for (int i = 0; i < klen; i++) // 求每组重合指数
        {
            int out[26] = {0}; // 盛放字母个数的数组
            for (int j = 0; i + j * klen < clen; j++)
            {
                if (c[i + j * klen] >= 'a' && c[i + j * klen] <= 'z') // 小写
                    out[(int)(c[i + j * klen] - 'a')]++;
                else if (c[i + j * klen] >= 'A' && c[i + j * klen] <= 'Z') // 大写
                    out[(int)(c[i + j * klen] - 'A')]++;
            }
            float e = 0;
            int L = 0;
            for (int k = 0; k < 26; k++)
                L += out[k];
            L *= (L - 1);
            for (int k = 0; k < 26; k++)
                if (out[k] != 0)
                    e += ((float)out[k] * (float)(out[k] - 1)) / (float)L;
            IC[i] = e;
        }

        for (int i = 0; i < klen; i++) // 求IC的平均值
            avgIC += IC[i];
        avgIC /= klen;

        if (avgIC >= 0.06)
            break; // 判断退出条件，重合指数的平均值是否大于0.06
        else
            klen++;
    }

    cout << "密钥长度为：" << klen << endl;

    // 求出密钥具体值
    string k = "";
    int key[klen] = {0};           // 存放密钥
    for (int i = 0; i < klen; i++) // 逐个推测密钥字
    {
        int g = 0; // 密文移动g个位置
        for (int t = 0; t < 26; t++)
        {
            float x = 0.000f;  // 拟重合指数
            int out[26] = {0}; // 盛放字母个数的数组
            for (int j = 0; i + j * klen < clen; j++)
            {
                if (c[i + j * klen] >= 'a' && c[i + j * klen] <= 'z') // 小写
                    out[(int)(c[i + j * klen] - 'a')]++;
                else if (c[i + j * klen] >= 'A' && c[i + j * klen] <= 'Z') // 大写
                    out[(int)(c[i + j * klen] - 'A')]++;
            }
            int L = 0;
            for (int k = 0; k < 26; k++)
            {
                L += out[k];                            // 子串密文长度
                x += letterStat[k] * out[(k + g) % 26]; // 逐个尝试字母表，求出拟重合指数无偏估计量
            }

            if (x / L > 0.055)
            {
                key[i] = g;
                break;
            }
            else
                g++;
        }
    }
    for (int i = 0; i < klen; i++) // 输出密钥字
        k += char('a' + key[i]);
    cout << "密钥为：" << k << endl;
    decrypt(c1, k);
}

int main()
{
    string c1;
    cout << "请输入密文：";
    getline(cin, c1);
    int clen = c1.size();

    string c = "";
    for (int i = 0; i < clen; i++)
    {
        if (c1[i] >= 'a' && c1[i] <= 'z')
        {
            c += c1[i];
        }
        else if (c1[i] >= 'A' && c1[i] <= 'Z')
        {
            c += c1[i];
        }
        else
        {
            continue;
        }
    }

    getk(c, c1);
    return 0;
}