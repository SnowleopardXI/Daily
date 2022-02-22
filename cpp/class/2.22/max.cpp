/*#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d %d max is %d",x,y,max(x,y));
}*/
#include <iostream>
using namespace std;
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int x, y;
    cin >> x >> y;
    cout << x << " " << y << " max is " << max(x, y);
    ;
}