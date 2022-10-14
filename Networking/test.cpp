
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <winsock.h>
#include <string>
#include "time.h"
#include <windows.h>
#include <exception>
//使用localtime
#pragma warning(disable : 4996)
//使用套接字库
#pragma comment(lib, "ws2_32.lib")
using namespace std;

string timetoStr()
{
    char tmp[64];
    time_t t = time(NULL);
    tm *_tm = localtime(&t);
    int year = _tm->tm_year + 1900;
    int month = _tm->tm_mon + 1;
    int date = _tm->tm_mday;
    int hh = _tm->tm_hour;
    int mm = _tm->tm_min;
    int ss = _tm->tm_sec;
    sprintf(tmp, "%04d%02d%02d %02d:%02d:%02d   ", year, month, date, hh, mm, ss);
    return string(tmp);
}
string GetLogNameByDate()
{
    char tmp[30];
    time_t t = time(NULL);
    tm *_tm = localtime(&t);
    int year = _tm->tm_year + 1900;
    int month = _tm->tm_mon + 1;
    int date = _tm->tm_mday;
    sprintf(tmp, "%04d%02d%02d.txt", year, month, date);
    return string(tmp);
}
void ErrorHandling(const string &s)
{
    cerr << timetoStr() << s << endl;
    exit(1);
}
//************************************
// Method:    ClientDownloadFile
// FullName:  ClientDownloadFile
// Access:    public
// Returns:   void
// Qualifier: 客户端下载文件处理函数
// Parameter: SOCKET s_accept 服务端接收套接字
// Parameter: string file_name 文件名
// Parameter: string clinet_IP 客户端IP
// Parameter: ostream & out_stream 输出流 这里主要为日志文件输出流/cout
//************************************
void ClientDownloadFile(SOCKET s_accept, string file_name, string clinet_IP, ostream &out_stream)
{
    int send_len = 0, recv_len = 0;
    //发送、接收缓冲区
    char send_buf[100], recv_buf[100];
    memset(send_buf, '\0', 100);
    memset(recv_buf, '\0', 100);
    string send_info;

    ifstream infile;
    infile.open(file_name, ios::in | ios::binary);
    if (!infile.good())
    {
        //文件不存在，回复客户端
        send_len = send(s_accept, "error", 100, 0);
        out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送给客户端的信息："
                   << "error" << endl;
        if (send_len < 0)
        {
            out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送客户端信息失败！断开连接" << endl;
            closesocket(s_accept);
