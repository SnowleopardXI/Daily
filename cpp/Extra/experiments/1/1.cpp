#include <iostream>
using namespace std;

class Coordinate
{
public:
    Coordinate(int x1=0, int y1=0)
    {
        x = x1;
        y = y1;
        cout << "Constructor is called." << endl;
    }
    Coordinate(Coordinate &p);
    ~Coordinate() { cout << "Destructor is called." << endl; }
    int getx() { return x; }
    int gety() { return y; }

private:
    int x, y;
};

Coordinate::Coordinate(Coordinate &p)
{
    x = p.x;
    y = p.y;
    cout << "Copy initianization constructor is called." << endl;
}

int main()
{
    Coordinate p1(3, 4);
    Coordinate p2(p1);
    Coordinate p3 = p2;
    Coordinate p4;
    Coordinate p5(2);

    cout << "p3=(" << p3.getx() << "," << p3.gety() << ")" << endl;

    return 0;
}
