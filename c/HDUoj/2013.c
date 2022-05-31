/*Problem Description

对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。

Input

输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。

Output

对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。

Sample Input

0 1 0 0

Sample Output

OK
*/
#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int sum=1;
        while(n>1){
            sum++;
            sum=sum*2;
            n--;
        }
        printf("%d",sum);
        printf("\n");
    }
    return 0;
}
