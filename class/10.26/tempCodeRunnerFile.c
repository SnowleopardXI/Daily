int x, i=0, sum = 0,j=0;
    do
    {
        if (i%2==0)
        {
            sum+=i;
            i++;
        }
    } while (i<10);
    printf("偶数的和为:%d,平均值为%f",sum,(float)sum/i);
    return 0;