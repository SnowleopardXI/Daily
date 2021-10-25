#include <stdio.h>
#include <math.h>
long timestamp()
{
    time_t t=time(NULL);
	return time(&t);
}
int main()
{
    printf("%ld",timestamp());
    return 0;
}