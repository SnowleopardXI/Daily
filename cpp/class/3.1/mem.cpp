#include <iostream>
using namespace std;
int main()
{
    int *s,i=0;
    s = new int[5];
    for ( i = 0; i < 5; i++)
    {
        s[i] = 100+2*i;
    }
    for ( i = 0; i < 5; i++)
    {
        cout << s[i] << endl;
    }
    //cout << s[i] <<""<< endl;
    delete [] s;
    return 0;
}