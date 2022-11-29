#include <iostream>
#include <cstring>
using namespace std;
void * bsearch(const void *key, const void *base, size_t nel, size_t width, int (*cmp)(const void *, const void *)){ 
    void *mid = NULL; 
    int sign; 
    while (nel > 0) { 
         
        mid = (char *)base + width*(nel/2); 
        sign = cmp(key, mid); 
        if (sign == 0) return mid;//找到  
        if (nel == 1) break; 
        else if (sign < 0) 
            nel /= 2;//下取整  
        else { 
            base = mid; 
            nel -= nel/2;//上取整  
        } 
   } 
    return NULL; 
} 

int compare(const void *val1, const void *val2) { 
    int iVal1 = *(int*)val1; 
    int iVal2 = *(int*)val2; 
    if (iVal1 > iVal2) { 
        return 1; 
    } 
    else if (iVal1 == iVal2) { 
        return 0; 
    } 
    return -1; 
}

#define NUM 8

int main(int argc, char** argv) {
	int array[NUM] = {9, 2, 7, 11, 3, 87, 34, 6};
	int key = 3;
	int *p;

	qsort(array, NUM, sizeof(int), compare);
	p = (int *)bsearch(&key, array, NUM, sizeof(int), compare);
	(p == NULL) ? puts("not found") : puts("found");
	return 0;
}
void qsort(void *base ,size_t num,size_t width , int (_cdecl *compare)(const void *,const void *))
{
    int i,j;
	void *temp;
	temp = malloc(width);
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (compare((char *)base + j*width, (char *)base + (j + 1)*width) > 0)
			{
				memcpy(temp, (char *)base + j*width, width);
				memcpy((char *)base + j*width, (char *)base + (j + 1)*width, width);
				memcpy((char *)base + (j + 1)*width, temp, width);
			}
		}
	}
	free(temp);
}