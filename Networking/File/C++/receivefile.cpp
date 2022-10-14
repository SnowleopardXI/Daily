// receivefile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <cstdlib>
#include<winsock.h>
#include <string>
#include <fstream>
#include <cstdio>
#pragma warning( disable : 4996)
#pragma comment(lib,"ws2_32.lib")
using namespace std;
void ErrorHandling(const string& s)
{
	cerr << s << endl;
	exit(1);
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
	cout << "欢迎使用：文件传输TCP实现——客户端" << endl;
	//初始化套接字库
	InitiallizationWSA();
	string server_ip;
	int port = 0;
	//发送、接收数据的大小
	int send_len = 0, recv_len = 0;
	int len = 0;
	//发送、接收缓冲区
	char send_buf[100];
	char recv_buf[100];
	string send_info;
	memset(recv_buf, '\0', 100);
	memset(send_buf, '\0', 100);
	//定义服务端套接字
	SOCKET s_server;
	//定义服务端地址
	SOCKADDR_IN server_addr;
	//创建套接字
	s_server = socket(AF_INET, SOCK_STREAM, 0);
	//填充服务端信息
	cout << "请输入服务端IP地址（点分十进制）：";
	cin >> server_ip;
	cout << "请输入服务端端口号：";
	cin >> port;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.S_un.S_addr = inet_addr(server_ip.c_str());
	server_addr.sin_port = htons(port);//5010


	//连接服务端
	if (connect(s_server, (SOCKADDR*)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR)
		ErrorHandling("服务端连接失败！");
	cout << "连接服务端成功！" << endl;
	//发送/接收数据
	cout << "请输入发送信息的内容：（格式为 命令：文件名：）";
	cin >> send_buf;
	//根据协议解析命令数据，格式为命令：文件名：文件大小
	string order;//文件操作命令
	string file_name;//文件名
	int size_of_file;//文件大小
	string file_info(send_buf);
	auto id_addr1 = file_info.find_first_of(':');
	order = file_info.substr(0, id_addr1);
	auto id_addr2 = file_info.find_first_of(':', id_addr1 + 1);
	file_name = file_info.substr(id_addr1 + 1, id_addr2 - id_addr1 - 1);
	//auto Size = file_info.substr(id_addr2 + 1, file_info.length() - id_addr2 - 1);
	if (order == "download")
	{
		send_len = send(s_server, send_buf, 100, 0);
		if (send_len < 0)
		{
			ErrorHandling("发送失败！断开连接");
		}
		//获取反馈的命令

		memset(recv_buf, '\0', 100);
		recv_len = recv(s_server, recv_buf, 100, 0);
		if (recv_len < 0)
		{
			ErrorHandling("接收失败！断开连接");
		}
		else
			cout << "接收服务端信息：" << recv_buf << endl;

		string recv_info(recv_buf);
		if (recv_info != "error")
		{
			//接收文件大小，开辟文件缓冲区
			ofstream outfile;
			outfile.open(file_name, ios::out | ios::binary | ios::trunc);
			if (!outfile.good())
			{
				//文件无法打开
				cerr << "文件无法建立" << endl;
			}
			else
			{
				//开辟缓冲区
				auto size_of_file = atoi(recv_info.c_str());
				char* data = nullptr;
				try
				{
					data = new char[size_of_file];
				}
				catch (const std::exception&)
				{
					//失败，发送error		
					memset(send_buf, '\0', 100);
					strcpy(send_buf, "error");
					send_len = send(s_server, send_buf, 100, 0);
					if (send_len < 0)
					{
						ErrorHandling("发送失败！断开连接");
					}
					ErrorHandling("开辟缓冲区失败！");
				}
				//成功，发送ok
				memset(send_buf, '\0', 100);
				strcpy(send_buf, "ok");
				send_len = send(s_server, send_buf, 100, 0);
				if (send_len < 0)
				{
					ErrorHandling("发送失败！断开连接");
				}
				recv_len = recv(s_server, data, size_of_file, 0);
				outfile.write(data, size_of_file);
				outfile.close();
				//cout << data << endl;
				cout << "接收文件大小为：" << recv_len << endl;
				if (recv_len < size_of_file)
				{
					cout << "接收失败！" << endl;
					//接收的信息不全，需要删除文件
					remove(file_name.c_str());
				}
				else
					cout << "接收成功！" << endl;
				delete data;
			}

		}
		cout << "断开连接" << endl;
		//关闭套接字
		closesocket(s_server);
	}

	if (order == "upload")
	{
		//获取文件长度，并发送给服务端
		ifstream infile;
		infile.open(file_name, ios::in | ios::binary);
		if (!infile.good())
			//文件不存在，提示
			ErrorHandling("文件不存在！");
		else
		{
			infile.seekg(0, ios::end);
			int length = infile.tellg();
			infile.seekg(0, ios::beg);
			send_info = string(send_buf) + to_string(length);
			//发送 命令：文件名：文件大小
			//等待服务端开辟缓冲区
			send_len = send(s_server, send_info.c_str(), 100, 0);
			if (send_len < 0)
			{
				ErrorHandling("发送失败！断开连接");
			}
			memset(recv_buf, '\0', 100);
			recv_len = recv(s_server, recv_buf, 100, 0);
			if (recv_len < 0)
			{
				ErrorHandling("接收失败！断开连接");
			}
			else
				cout << "接收服务端信息：" << recv_buf << endl;
			string recv_info(recv_buf);
			if (recv_info == "ok")
			{
				//服务端开辟缓冲区成功，上传文件数据
				//发送整个文件
				char* data;
				data = new char[length];
				infile.read(data, length);
				send_len = send(s_server, data, length, 0);
				if (send_len < length)
					ErrorHandling("发送文件失败！断开连接");
				delete data;
				cout << "文件上传成功！" << endl;

			}
			else
				cout << "服务端开辟缓冲区失败！" << endl;
			infile.close();
			cout << "断开连接" << endl;
			//关闭套接字
			closesocket(s_server);
		}
	}
	while (true)
	{
		string in;
		cout << "输入任意字符退出程序：" << endl;
		if (cin >> in)
			break;
	}
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
