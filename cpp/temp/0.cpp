#include <iostream>
using namespace std;

void gcd_lcm(int x, int y)
{
    int a = x, b = y;
    int r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    cout << "最大公约数：" << b << endl;
    cout << "最小公倍数：" << x * y / b << endl;
}

int main()
{
    int x, y;
    cout << "请输入两个正整数：" << endl;
    cin >> x >> y;
    gcd_lcm(x, y);
}