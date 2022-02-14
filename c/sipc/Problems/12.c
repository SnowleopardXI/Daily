int main()
{
    int year;
    scanf("%d",&year);
    if(year<=2000||year>2100)
    {
    printf("Invalid year!");
    return 0;
    }
    else if (year<2004)
    {
      printf("None");
    }
    int i=2001;
    while(i<=year)
    {
        if((i%4==0&&i%100!=0))
        printf("%d\n",i);
        i++;
    }
    return 0;
}