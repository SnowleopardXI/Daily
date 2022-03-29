#include <iostream>
using namespace std;
class ClsName
{
    private:
        int x;
        int y;
    public:
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void setXY(int x, int y)
    {
        setX(x);
        setY(y);
    }
    void setXY(int x)
    {
        setX(x);
        setY(0);
        cout << "单参数，设置y=0" << endl;
    }
    void setXY()
    {
        setX(0);
        setY(0);
        cout << "无参数，设置x=0,y=0" << endl;
    }
    void printXY()
    {
        cout << "x = " << getX() << ", y = " << getY() << endl;
    }
};
int main()
{
    ClsName obj;
    obj.setXY(1, 2);
    obj.printXY();
    obj.setXY(3);
    obj.printXY();
    obj.setXY();
    obj.printXY();
    return 0;
}