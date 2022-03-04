#include <iostream>
using namespace std;
//Deprecated
/*
int Area(int x, int y)
{
    return x*y;
}
int Perimeter(int x, int y)
{
    return 2*(x+y);
}
void print(int x, int y)
{
    cout << "Area=" << Area(x, y) << endl;
    cout << "Perimeter=" << Perimeter(x, y) << endl;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
int main()
{
    int len,wid;
    cout << "Enter the length and width of the rectangle: ";
    cin >> len >> wid;
    print(len, wid);
    return 0;
}
*/
//Unsafe Coding

int lent, widt;
int Area(int x, int y)
{
    return x*y;
}
int Perimeter(int x, int y)
{
    return 2*(x+y);
}
void print(int x, int y)
{
    cout << "Area=" << Area(x, y) << endl;
    cout << "Perimeter=" << Perimeter(x, y) << endl;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
int main()
{
    cout << "Enter the length and width of the rectangle: ";
    cin >> lent >> widt;
    print(lent, widt);
    return 0;
}