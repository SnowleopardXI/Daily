#include <iostream>
#include <cstring>
#include "sort.hpp"
#define MAX 7
using namespace std;
int main()
{
    int a[MAX] = {21,25,5,17,9,23,30};
    int b[MAX] = {25,23,30,17,21,5,9};
    int c[MAX] = {21,9,17,30,25,23,5};
    int d[MAX] = {5,9,17,21,23,25,30};
    int times = 0,i;
    qsort(a, MAX, sizeof(int), [](const void *a, const void *b) -> int
    {
        return *(int *)a - *(int *)b;
    },&times);
    for (i = 0; i < MAX; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << times << endl;
    times = 0;
    qsort(b, MAX, sizeof(int), [](const void *a, const void *b) -> int
    {
        return *(int *)a - *(int *)b;
    },&times);
    for (i = 0; i < MAX; i++)
        cout << b[i] << " ";
    cout << endl;
    cout << times << endl;
    times = 0;
    qsort(c, MAX, sizeof(int), [](const void *a, const void *b) -> int
    {
        return *(int *)a - *(int *)b;
    },&times);
    for (i = 0; i < MAX; i++)
        cout << c[i] << " ";
    cout << endl;
    cout << times << endl;
    times = 0;
    qsort(d, MAX, sizeof(int), [](const void *a, const void *b) -> int
    {
        return *(int *)a - *(int *)b;
    },&times);
    for (i = 0; i < MAX; i++)
        cout << d[i] << " ";
    cout << endl;
    cout << times << endl;
    return 0;
}