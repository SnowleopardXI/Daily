#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
int gcd(int a, int b)
{
    if (a < b)
    {
        std::swap(a, b);
    }
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
// RSA加密函数
long long int encrypt(long long int plaintext, long long int e, long long int n)
{
    long long int ciphertext = 1;
    for (int i = 0; i < e; ++i)
    {
        ciphertext = (ciphertext * plaintext) % n;
    }
    return ciphertext;
}

// RSA解密函数
long long int decrypt(long long int ciphertext, long long int d, long long int n)
{
    long long int plaintext = 1;
    for (int i = 0; i < d; ++i)
    {
        plaintext = (plaintext * ciphertext) % n;
    }
    return plaintext;
}

// 生成密钥函数
void generateKeys(long long int p, long long int q, long long int &e, long long int &d, long long int &n)
{
    long long int phi = (p - 1) * (q - 1);
    n = p * q;

    for (e = 2; e < phi; ++e)
    {
        if (gcd(e, phi) == 1)
        { // 使用C++17中的__gcd函数，需要包含头文件<numeric>
            break;
        }
    }

    for (d = 2; d < phi; ++d)
    {
        if ((d * e) % phi == 1)
        {
            break;
        }
    }
}

int main()
{
    // 设置参数
    long long int p = 17;
    long long int q = 23;
    long long int e, d, n;

    // 生成密钥
    generateKeys(p, q, e, d, n);

    // 明文
    std::string plaintext = "Hello, RSA!";
    // 创建明文文件
    std::ofstream plaintextFile("plaintext.txt");
    if (!plaintextFile)
    {
        std::cerr << "无法创建明文文件。" << std::endl;
        return 1;
    }
    plaintextFile << plaintext;
    plaintextFile.close();

    // 加密
    std::ifstream file("plaintext.txt");
    if (!file)
    {
        std::cerr << "无法打开明文文件。" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<long long int> encryptedData;

    while (std::getline(file, line))
    {
        for (char c : line)
        {
            long long int encryptedChar = encrypt(c, e, n);
            encryptedData.push_back(encryptedChar);
        }
    }

    file.close();

    // 创建密文文件
    std::ofstream ciphertextFile("ciphertext.txt");
    if (!ciphertextFile)
    {
        std::cerr << "无法创建明文文件。" << std::endl;
        return 1;
    }

    for (long long int c : encryptedData)
    {
        ciphertextFile << c << std::endl;
    }

    ciphertextFile.close();

    // 解密
    std::ifstream encryptedFile("ciphertext.txt");
    if (!encryptedFile)
    {
        std::cerr << "无法打开明文文件。" << std::endl;
        return 1;
    }

    std::vector<long long int> decryptedData;

    long long int encryptedChar;
    while (encryptedFile >> encryptedChar)
    {
        long long int decryptedChar = decrypt(encryptedChar, d, n);
        decryptedData.push_back(decryptedChar);
    }

    encryptedFile.close();

    // 创建解密后的明文文件
    std::ofstream decryptedFile("decrypted.txt");
    if (!decryptedFile)
    {
        std::cerr << "无法创建解密文件。" << std::endl;
        return 1;
    }

    for (long long int c : decryptedData)
    {
        decryptedFile << static_cast<char>(c);
    }

    decryptedFile.close();

    return 0;
}
