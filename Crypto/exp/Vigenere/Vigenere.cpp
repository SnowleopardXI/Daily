#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const float letterStat[26] = {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228,
                              0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025,
                              0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987,
                              0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150,
                              0.01974, 0.00074};

char encrypt(char ch1, char ch2)
{
    if (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'A' && ch2 <= 'Z')
        return 'A' + (ch1 - 'A' + ch2 - 'A') % 26;
    if (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'a' && ch2 <= 'z')
        return 'A' + (ch1 - 'A' + ch2 - 'a') % 26;
    if (ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'a' && ch2 <= 'z')
        return 'a' + (ch1 - 'a' + ch2 - 'a') % 26;
    if (ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'A' && ch2 <= 'Z')
        return 'a' + (ch1 - 'a' + ch2 - 'A') % 26;
    return ch1;
}
char decrypt(char ch1, char ch2)
{
    if (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'A' && ch2 <= 'Z')
        return 'A' + (ch1 - 'A' - ch2 + 'A' + 26) % 26;
    if (ch1 >= 'A' && ch1 <= 'Z' && ch2 >= 'a' && ch2 <= 'z')
        return 'A' + (ch1 - 'A' - ch2 + 'a' + 26) % 26;
    if (ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'a' && ch2 <= 'z')
        return 'a' + (ch1 - 'a' - ch2 + 'a' + 26) % 26;
    if (ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'A' && ch2 <= 'Z')
        return 'a' + (ch1 - 'a' - ch2 + 'A' + 26) % 26;
    return ch1;
}
void decrypt_brute(string c, string k)
{
    string p = "";
    int lk = k.size(), cl = c.size(), s = 0;
    for (int i = 0; i < cl; i++)
    {
        // 其它字符
        if (c[i] >= 'a' && c[i] <= 'z')
        {
            int j = (i - s) % lk;
            p += (c[i] - 'a' + 26 - (k[j] - 'a')) % 26 + 'a';
        }
        else if (c[i] >= 'A' && c[i] <= 'Z')
        {
            int j = (i - s) % lk;
            p += (c[i] - 'A' + 26 - (k[j] - 'a')) % 26 + 'a';
        }
        else
        {
            p += c[i];
            s++;
        }
    }
    cout << "明文为：" << p;
}
// Encrypt file
void encrypt_file(string &orig, vector<int> &key)
{
    for (int i = 0; i < orig.length(); i++)
    {
        orig[i] = encrypt(orig[i], key[i % key.size()] + 'A');
    }
}
// Decrypt file
void decrypt_file(string &orig, vector<int> &key)
{
    for (int i = 0; i < orig.length(); i++)
    {
        orig[i] = decrypt(orig[i], key[i % key.size()] + 'A');
    }
}

// 求解密钥
void getk(string c, string text)
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
    decrypt_brute(text, k);
}

int main()
{
    string plain, cipher, crack;
    plain = "plaintext.txt";
    cipher = "ciphertext.txt";
    crack = "cracked.txt";

    char key[5] = {0};
    char unknown[5] = {0};

    vector<int> key2;

    printf("1. Encrypt\n2. Decrypt\n3. Crack\n");
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "Input key: ";
        cin >> key;
        vector<int> key1;
        for (int i = 0; i < 5; i++)
            key1.push_back(key[i] - 'A');
        ifstream fin(plain);
        ofstream fout(cipher);
        string text;
        getline(fin, text);
        for (int i = 0; i < text.length(); i++)
        {
            fout << encrypt(text[i], key[i % 5]);
        }
        fin.close();
        fout.close();
        break;
    }
    case 2:
    {
        cout << "Input key: ";
        cin >> key;
        vector<int> key1;
        for (int i = 0; i < 5; i++)
            key1.push_back(key[i] - 'A');
        ifstream fin(cipher);
        ofstream fout(plain);
        string text;
        getline(fin, text);
        for (int i = 0; i < text.length(); i++)
        {
            fout << decrypt(text[i], key[i % 5]);
        }
        fin.close();
        fout.close();
        break;
    }
    case 3:
    {
        ifstream fin(cipher);
        string text;
        getline(fin, text);
        int clen = text.size();

        string c = "";
        for (int i = 0; i < clen; i++)
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                c += text[i];
            }
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                c += text[i];
            }
            else
            {
                continue;
            }
        }

        getk(c, text);
        fin.close();
        break;
    }
    default:
        break;
    }
    return 0;
}