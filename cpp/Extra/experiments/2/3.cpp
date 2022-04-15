#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str[5];
    cout << "请分别输入5个字符串：" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> str[i];
    }
    cout << "逆转后的顺序为:" << endl;
    cout << str[4] << " " << str[3] << " " << str[2] << " " << str[1] << " " << str[0] << endl;
    return 0;
}