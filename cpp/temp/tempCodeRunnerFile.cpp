#include <iostream>
using namespace std;
class Rectangle
{
private:
    int w;
    int h;

public:
    int Area(); 
    void init(int _w, int _h);
    int Compare(Rectangle &r);
};
int main()
{
    Rectangle r1, r2;
    r1.init(3, 4);
    r2.init(4, 6);
    if (r1.Compare(r2))
    {
        cout << "r1>r2" << endl;
    }
    else
    {
        cout << "r1<=r2" << endl;
    }
    return 0;
}
int Rectangle::Area()
{
    return w * h;
}
void Rectangle::init(int _w, int _h)
{
    if (_w <= 0)
        _w = 1;
    if (_h <= 0)
        _h = 1;
    w = _w;
    h = _h;
}
int Rectangle::Compare(Rectangle &r)
{
    int a = Area();
    int b = r.Area();
    cout<<a<<" "<<b<<endl;
    if (a > b)
        return 1;
    else
        return 0;
}
