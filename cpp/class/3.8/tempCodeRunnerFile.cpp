#include <iostream>
using namespace std;
class Complex
{
private:
    double real, imag;

public:
    Complex(double r=4.0, double i = 3.0);
    void print()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};
int main()
{
    Complex c2(2);
    Complex c1(2, 4), c3(3, 5);
    Complex *pc = new Complex(3, 4);
    c2.print();
    return 0;
}
Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}