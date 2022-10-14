// sendfile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//



#include <iostream>
#include <fstream> 
#include <cstdlib>
#include<winsock.h>
#include <string>
#include "time.h"
#include<windows.h>
#include <exception>
//使用localtime
#pragma warning(disable:4996)
//使用套接字库
#pragma comment(lib,"ws2_32.lib")
using namespace std;

string timetoStr() {
	char tmp[64];
	time_t t = time(NULL);
	tm* _tm = localtime(&t);
	int year = _tm->tm_year + 1900;
	int month = _tm->tm_mon + 1;
	int date = _tm->tm_mday;
	int hh = _tm->tm_hour;
	int mm = _tm->tm_min;
	int ss = _tm->tm_sec;
	sprintf(tmp, "%04d%02d%02d %02d:%02d:%02d   ", year, month, date, hh, mm, ss);
	return string(tmp);
}
string GetLogNameByDate() {
	char tmp[30];
	time_t t = time(NULL);
	tm* _tm = localtime(&t);
	int year = _tm->tm_year + 1900;
	int month = _tm->tm_mon + 1;
	int date = _tm->tm_mday;
	sprintf(tmp, "%04d%02d%02d.txt", year, month, date);
	return string(tmp);
}
void ErrorHandling(const string& s)
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
// Parameter: string file_name	文件名
// Parameter: string clinet_IP 客户端IP
// Parameter: ostream & out_stream 输出流 这里主要为日志文件输出流/cout
//************************************
void ClientDownloadFile(SOCKET s_accept, string file_name, string clinet_IP, ostream& out_stream)
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
		out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送给客户端的信息：" << "error" << endl;
		if (send_len < 0)
		{
			out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送客户端信息失败！断开连接" << endl;
			closesocket(s_accept);
			return;
		}
		out_stream << timetoStr() << "客户端为：" << clinet_IP << " 请求文件不存在而断开连接" << endl;
		closesocket(s_accept);
		return;
	}
	//文件存在，返回客户端文件大小
	else
	{
		infile.seekg(0, ios::end);
		int length = infile.tellg();
		infile.seekg(0, ios::beg);
		send_info = to_string(length);
		send_len = send(s_accept, send_info.c_str(), send_info.length(), 0);
		//Sleep(1000);
		if (send_len < send_info.length())
		{
			out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送客户端信息失败！断开连接" << endl;
			closesocket(s_accept);
			return;
		}
		else
			out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送客户端信息:" << send_info << endl;
		//等待客户端开辟缓冲区，接收信息后再发送文件
		memset(recv_buf, '\0', 100);
		recv_len = recv(s_accept, recv_buf, 100, 0);
		if (recv_len < 0)
		{
			out_stream << timetoStr() << "客户端为：" << clinet_IP << " 接收数据失败！断开连接" << endl;
			closesocket(s_accept);
			return;
		}
		else
			out_stream << timetoStr() << "客户端为：" << clinet_IP << " 接收来自客户端的信息：" << recv_buf << endl;

		if (string(recv_buf) == "ok")
		{
			//发送整个文件
			char* data;
			//此处没有考虑到new失败的情况！！！！
			data = new char[length];
			infile.read(data, length);
			send_len = send(s_accept, data, length, 0);
			if (send_len < length)
			{
				out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送客户端文件信息失败！断开连接" << endl;
				closesocket(s_accept);
				return;
			}
			delete data;
			out_stream << timetoStr() << "客户端为：" << clinet_IP << " 文件发送成功！断开连接" << endl;
			closesocket(s_accept);
			return;
		}

		out_stream << timetoStr() << "客户端为：" << clinet_IP << " 客户端缓冲区开辟失败！断开连接" << endl;
		closesocket(s_accept);
	}
}

//************************************
// Method:    ClientUploadFile
// FullName:  ClientUploadFile
// Access:    public 
// Returns:   void
// Qualifier:客户端上传文件处理函数
// Parameter: SOCKET s_accept 服务端接收套接字
// Parameter: string file_name	文件名
// Parameter: int file_size	文件大小
// Parameter: string clinet_IP	客户端IP
// Parameter: ostream & out_stream  输出流 这里主要为日志文件输出流/cout
//************************************
void ClientUploadFile(SOCKET s_accept, string file_name, int file_size, string clinet_IP, ostream& out_stream)
{
	int send_len = 0, recv_len = 0;
	//发送、接收缓冲区
	char send_buf[100], recv_buf[100];
	memset(send_buf, '\0', 100);
	memset(recv_buf, '\0', 100);
	string send_info;

	//根据文件大小，开辟文件缓冲区
	ofstream outfile;
	outfile.open(file_name, ios::out | ios::binary | ios::trunc);
	if (!outfile.good())
	{
		//文件无法打开
		send_len = send(s_accept, "error", 100, 0);
		out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送给客户端的信息：" << "error" << endl;
		if (send_len < 0)
		{
			out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送客户端信息失败！断开连接" << endl;
			closesocket(s_accept);
			return;
		}
		out_stream << timetoStr() << "客户端为：" << clinet_IP << " 上传的文件无法建立而断开连接" << endl;
		closesocket(s_accept);
		return;
	}
	//文件打开成功，开辟缓冲区，并返回客户端结果
	else
	{
		char* data = nullptr;
		try
		{
			data = new char[file_size];
		}
		catch (const std::exception&)
		{
			//失败，发送error		
			memset(send_buf, '\0', 100);
			strcpy(send_buf, "error");
			send_len = send(s_accept, send_buf, 100, 0);
			out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送给客户端的信息：" << send_buf << endl;
			if (send_len < 0)
			{
				out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送客户端信息失败！断开连接" << endl;
				closesocket(s_accept);
				return;
			}
			out_stream << timetoStr() << "客户端为：" << clinet_IP << " 服务端开辟缓冲区失败！断开连接" << endl;
			closesocket(s_accept);
			return;
		}
		//成功，发送ok
		memset(send_buf, '\0', 100);
		strcpy(send_buf, "ok");
		send_len = send(s_accept, send_buf, 100, 0);
		out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送给客户端的信息：" << send_buf << endl;
		if (send_len < 0)
		{
			out_stream << timetoStr() << "客户端为：" << clinet_IP << " 发送客户端信息失败！断开连接" << endl;
			closesocket(s_accept);
			return;
		}
		recv_len = recv(s_accept, data, file_size, 0);
		outfile.write(data, file_size);
		outfile.close();
		if (recv_len < file_size)
		{
			//接收的信息不全，需要删除文件
			remove(file_name.c_str());
			out_stream << timetoStr() << "客户端为：" << clinet_IP << " 接收客户端文件信息失败！断开连接" << endl;
			closesocket(s_accept);
			return;
		}
		else
			out_stream << timetoStr() << "客户端为：" << clinet_IP << " 接收客户端文件成功！断开连接" << endl;
		delete data;

		closesocket(s_accept);
	}
}


void InitiallizationWSA()
{
	WSADATA wsaData;
	//初始化套接字库
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("初始化套接字库失败！");
	//检查版本号
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wHighVersion) != 2)
		ErrorHandling("套接字库版本号不符！");

}

int main()
{
	//创建日志文件，存储日志
	string log_file_name = GetLogNameByDate();
	ofstream Log;
	try
	{
		Log.open(log_file_name, std::ofstream::out | std::ofstream::app);
	}
	catch (ios_base::failure& e)
	{
		cout << "创建日志文件失败！退出程序" << endl;
		exit(1);
	}

	Log << timetoStr() << "启动：文件传输TCP实现——服务端。。。" << endl;
	//初始化套接字库
	InitiallizationWSA();
	//发送、接收数据的大小
	int send_len = 0, recv_len = 0;
	int len = 0;
	//发送、接收缓冲区
	char send_buf[100], recv_buf[100];
	memset(send_buf, '\0', 100);
	memset(recv_buf, '\0', 100);
	string send_info;
	//定义服务端套接字，接受请求套接字
	SOCKET s_server, s_accept;
	//客户端IP
	string clinet_IP;
	//定义服务端地址，客户端地址
	SOCKADDR_IN server_addr, clnt_addr;
	//创建服务端套接字
	s_server = socket(AF_INET, SOCK_STREAM, 0);
	//填充服务端信息
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(5010);
	//绑定套接字
	if (bind(s_server, (SOCKADDR*)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR)
		ErrorHandling("套接字绑定失败！");
	//监听套接字
	if (listen(s_server, SOMAXCONN) < 0)
		ErrorHandling("监听套接字失败！");
	//接受连接
	while (true)
	{
		len = sizeof(SOCKADDR);
		s_accept = accept(s_server, (SOCKADDR*)&clnt_addr, &len);
		if (s_accept == SOCKET_ERROR)
			ErrorHandling("连接失败！");
		//获取客户端IP
		clinet_IP = inet_ntoa(clnt_addr.sin_addr);
		Log << timetoStr() << "连接" << clinet_IP << "成功！" << endl;
		//获取客户端发送的文件基本信息：命令：文件名：文件大小
		memset(recv_buf, '\0', 100);
		recv_len = recv(s_accept, recv_buf, 100, 0);
		if (recv_len < 0)
		{
			Log << timetoStr() << "客户端为：" << clinet_IP << " 接收数据失败！断开连接" << endl;
			closesocket(s_accept);
			continue;
		}
		else
		{
			Log << timetoStr() << "客户端为：" << clinet_IP << " 接收来自客户端的信息：" << recv_buf << endl;
		}
		//根据协议解析命令数据，格式为命令：文件名：文件大小
		string order;//文件操作命令
		string file_name;//文件名
		int size_of_file;//文件大小
		string file_info(recv_buf);
		auto id_addr1 = file_info.find_first_of(':');
		order = file_info.substr(0, id_addr1);
		auto id_addr2 = file_info.find_first_of(':', id_addr1 + 1);
		file_name = file_info.substr(id_addr1 + 1, id_addr2 - id_addr1 - 1);
		auto Size = file_info.substr(id_addr2 + 1, file_info.length() - id_addr2 - 1);
		//下载文件
		if (order == "download")
		{
			ClientDownloadFile(s_accept, file_name, clinet_IP, Log);

		}
		if (order == "upload")
		{
			ClientUploadFile(s_accept, file_name, atoi(Size.c_str()), clinet_IP, Log);
		}
	}
	Log.close();
	//关闭套接字
	closesocket(s_server);
	//释放DLL资源
	WSACleanup();
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
