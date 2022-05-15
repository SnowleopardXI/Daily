#include <iostream>

using namespace std;
struct Node
{
    int value,index;
};
int getStandard(struct Node array[], int i, int j) {
    struct Node key = array[i];
    while (i < j) {
        // 因为默认基准是从左边开始，所以从右边开始比较
        // 当队尾的元素大于等于基准数据 时,就一直向前挪动 j 指针
        while (i < j && array[j].value >= key.value) {
            j--;
        }
        // 当找到比 array[i] 小的时，就把后面的值 array[j] 赋给它
        if (i < j) {
            array[i] = array[j];
        }
        // 当队首元素小于等于基准数据 时,就一直向后挪动 i 指针
        while (i < j && array[i].value <= key.value) {
            i++;
        }
        // 当找到比 array[j] 大的时，就把前面的值 array[i] 赋给它
        if (i < j) {
            array[j] = array[i];
        }
    }
    array[i] = key;
    return i;
}
void QuickSort(struct Node array[], int low, int high) {
    // 开始默认基准为 low
    if (low < high) {
        // 分段位置下标
        int standard = getStandard(array, low, high);
        // 递归调用排序
        // 左边排序
        QuickSort(array, low, standard - 1);
        // 右边排序
        QuickSort(array, standard + 1, high);
    }
}

int main()
{
    int n,l,t;
    cin>>n>>l>>t;
    struct Node loc[n];
    int dir[n];
    for(int i=0;i<n;i++)
    {
        cin>>loc[i].value;
        loc[i].index=i;
        dir[i]=1;
    }
    QuickSort(loc,0,n-1);
    if(loc[n-1].value==l)
        dir[n-1]=-1;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<n;j++)
        {
            loc[j].value+=dir[j];
        }
        if(loc[0].value==0)
            dir[0]=1;
        if(loc[n-1].value==l)
            dir[n-1]=-1;
        for(int j=0;j<n-1;j++)
        {
            if(loc[j].value==loc[j+1].value)
            {
                dir[j]=dir[j]*(-1);
                dir[j+1]=dir[j+1]*(-1);
                j++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(loc[j].index==i)
            {
                cout<<loc[j].value<<" ";
                break;
            }  
        }
    }
    cout<<endl;
    system("pause");
    return 0;
}