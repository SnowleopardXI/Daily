#include <iostream>
using namespace std;
class A
{
public:
	void display();

private:
	int x, y;
};

A::A(int _x, int _y)
{
	x = _x;
	y = _y;
}

void A::display()
{
	cout << x << " " << y << endl;
}

class B : public A
{
	int b;

public:
	B(int a1, int a2, int a3) : A(a1, a2)
	{
		b = a3;
	}
	void display()
	{
		cout<< "  b=" << b << endl;
	}
};
int main()
{
	B(10, 20, 30);
	B.display();
}
