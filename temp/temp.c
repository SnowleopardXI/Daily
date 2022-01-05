#include <stdio.h>
int isprime(int n);
int main()
{
  int i, j = 1, a, b, c, d, e, n, flag = 0;
  for (i = 10000; j <= 5; i++)
  {
    a = i % 10;
    b = i / 10 % 10;
    c = i / 100 % 10;
    d = i / 1000 % 10;
    e = i / 10000;
    for (n = 1; n < 46; n++)
    {
      if (a + b + c + d + e == 4 * n + 1)
      {
        flag = 1;
        break;
      }
      else
        flag = 0;
    }
    if (isprime(i) && flag)
    {
      printf("%d ", i);
      j++;
    }
  }
  return 0;
}

int isprime(int n)
{
  int i;
  for (i = 2; i < n; i++)
  {
    if (n % 2 == 0)
      return 0;
  }
  return 1;
}