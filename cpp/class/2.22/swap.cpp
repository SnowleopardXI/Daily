#include <iostream>
using namespace std;
void swap(int &a, int &b) //能交换（引用）
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout<<a<<b<<endl;
}
int main()
{
    int x, y;
    cin >> x >> y;
    swap(x, y);
    return 0;
}