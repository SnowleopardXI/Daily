#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
//wstring to string
string wstring2string(wstring wstr, UINT nCode)
{
    string result;
    //获取缓冲区大小，并申请空间，缓冲区大小事按字节计算的
    int len = WideCharToMultiByte(nCode, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
    char *buffer = new char[len + 1];
    //宽字节编码转换成多字节编码
    WideCharToMultiByte(nCode, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
    buffer[len] = '\0';
    //删除缓冲区并返回值
    result.append(buffer);
    delete[] buffer;
    return result;
}
enum Encode
{
    ANSI = 1,
    UTF16_LE,
    UTF16_BE,
    UTF8_BOM,
    UTF8
};

Encode IsUtf8Data(const uint8_t *data, size_t size)
{
    bool bAnsi = true;
    uint8_t ch = 0x00;
    int32_t nBytes = 0;
    for (auto i = 0; i < size; i++)
    {
        ch = *(data + i);
        if ((ch & 0x80) != 0x00)
        {
            bAnsi = false;
        }
        if (nBytes == 0)
        {
            if (ch >= 0x80)
            {
                if (ch >= 0xFC && ch <= 0xFD)
                {
                    nBytes = 6;
                }
                else if (ch >= 0xF8)
                {
                    nBytes = 5;
                }
                else if (ch >= 0xF0)
                {
                    nBytes = 4;
                }
                else if (ch >= 0xE0)
                {
                    nBytes = 3;
                }
                else if (ch >= 0xC0)
                {
                    nBytes = 2;
                }
                else
                {
                    return Encode::ANSI;
                }
                nBytes--;
            }
        }
        else
        {
            if ((ch & 0xC0) != 0x80)
            {
                return Encode::ANSI;
            }
            nBytes--;
        }
    }
    if (nBytes > 0 || bAnsi)
    {
        return Encode::ANSI;
    }
    return Encode::UTF8;
}
Encode DetectEncode(const uint8_t *data, size_t size)
{
    if (size > 2 && data[0] == 0xFF && data[1] == 0xFE)
    {
        return Encode::UTF16_LE;
    }
    else if (size > 2 && data[0] == 0xFE && data[1] == 0xFF)
    {
        return Encode::UTF16_BE;
    }
    else if (size > 3 && data[0] == 0xEF && data[1] == 0xBB && data[2] == 0xBF)
    {
        return Encode::UTF8_BOM;
    }
    else
    {
        return IsUtf8Data(data, size);
    }
}

int main()
{
    char szChn1[5] = {"汉字"};

    wstring wstrChn = L"汉字";
    string strCh = wstring2string(wstrChn, CP_UTF8);
    char szChn2[7] = {0};
    int nSize = sizeof(strCh);
    int nlen = strCh.length();
    int nStrlen = strlen(strCh.c_str());
    strncpy_s(szChn2, strCh.c_str(), nStrlen);

    Encode emCode1;
    emCode1 = IsUtf8Data((const unsigned char *)szChn1, strlen(szChn1));
    Encode emCode2;
    emCode2 = IsUtf8Data((const unsigned char *)szChn2, strlen(szChn2));
    std::cout << "Hello World!\n";
}