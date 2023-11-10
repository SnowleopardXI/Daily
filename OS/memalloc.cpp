#include <iostream>
#include <deque>
#include <algorithm>
#include <climits>
using namespace std;

struct Lnode
{
    int id;
    int length;
    int start;
    int flag;
};

deque<Lnode> freeMemory;
deque<Lnode> allocatedMemory;

void initializeMemory(int totalMemory)
{
    freeMemory.push_back({-1, totalMemory, 0, 0});
}

void splitBlock(deque<Lnode>::iterator it, int size)
{
    Lnode freeBlock = {it->id, it->length - size, it->start + size, 0};
    it->length = size;
    it->flag = 1;
    freeMemory.insert(it + 1, freeBlock);
}

void allocateMemory(int processId, int size, const string &method)
{
    for (auto it = freeMemory.begin(); it != freeMemory.end(); ++it)
    {
        if (it->length >= size)
        {
            if (method == "FirstFit" || (method == "BestFit" && it->length == size))
            {
                it->id = processId;
                if (it->length > size)
                {
                    splitBlock(it, size);
                }
                else
                {
                    it->flag = 1;
                }
                allocatedMemory.push_back(*it);
                freeMemory.erase(it);
                return;
            }
        }
    }

    if (method == "BestFit")
    {
        auto bestIt = freeMemory.end();
        int minSize = INT_MAX;
        for (auto it = freeMemory.begin(); it != freeMemory.end(); ++it)
        {
            if (it->length >= size && it->length < minSize)
            {
                minSize = it->length;
                bestIt = it;
            }
        }
        if (bestIt != freeMemory.end())
        {
            bestIt->id = processId;
            if (bestIt->length > size)
            {
                splitBlock(bestIt, size);
            }
            else
            {
                bestIt->flag = 1;
            }
            allocatedMemory.push_back(*bestIt);
            freeMemory.erase(bestIt);
            return;
        }
    }

    if (method == "WorstFit")
    {
        auto worstIt = freeMemory.end();
        int maxSize = 0;
        for (auto it = freeMemory.begin(); it != freeMemory.end(); ++it)
        {
            if (it->length > maxSize)
            {
                maxSize = it->length;
                worstIt = it;
            }
        }
        if (worstIt != freeMemory.end() && worstIt->length >= size)
        {
            worstIt->id = processId;
            if (worstIt->length > size)
            {
                splitBlock(worstIt, size);
            }
            else
            {
                worstIt->flag = 1;
            }
            allocatedMemory.push_back(*worstIt);
            freeMemory.erase(worstIt);
            return;
        }
    }

    cout << "没有找到适合进程  " << processId << " 的内存块" << endl;
}

void mergeFreeBlocks()
{
    // 按起始地址对空闲内存块进行排序
    sort(freeMemory.begin(), freeMemory.end(), [](const Lnode &a, const Lnode &b)
         { return a.start < b.start; });

    // 合并相邻的空闲块
    for (auto it = freeMemory.begin(); it != freeMemory.end(); ++it)
    {
        while (next(it) != freeMemory.end() && it->start + it->length == next(it)->start)
        {
            it->length += next(it)->length;
            freeMemory.erase(next(it));
        }
    }
}

void deallocateMemory(int processId)
{
    for (auto it = allocatedMemory.begin(); it != allocatedMemory.end(); ++it)
    {
        if (it->id == processId)
        {
            it->id = -1;
            it->flag = 0;
            freeMemory.push_back(*it);
            allocatedMemory.erase(it);
            return;
        }
    }
    cout << "进程 " << processId << " 未分配内存" << endl;
    mergeFreeBlocks();
}

void viewMemoryMap()
{
    mergeFreeBlocks();
    cout << "当前内存视图：" << endl;
    cout << "起始地址\t长度\t\t终止地址\t状态" << endl;

    // 结合空闲内存和分配内存以获得完整视图
    deque<Lnode> combinedMemory = freeMemory;
    combinedMemory.insert(combinedMemory.end(), allocatedMemory.begin(), allocatedMemory.end());

    // 按起始地址对组合内存进行排序
    sort(combinedMemory.begin(), combinedMemory.end(), [](const Lnode &a, const Lnode &b)
         { return a.start < b.start; });

    for (auto it = combinedMemory.begin(); it != combinedMemory.end(); ++it)
    {
        cout << it->start << "\t\t" << it->length << "\t\t" << it->start + it->length << "\t\t";
        if (it->flag == 0)
        {
            cout << "空闲" << endl;
        }
        else
        {
            cout << "已分配给进程 " << it->id << " 从 " << it->start << " 到 " << it->start + it->length << endl;
        }
    }
}
int main()
{
    int totalMemory = 256;
    initializeMemory(totalMemory);
    viewMemoryMap();
    short int choice;
    while (1)
    {
        cout << "1. 分配内存" << endl
             << "2. 释放内存" << endl
             << "Other. Exit" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "输入要分配的进程 ID 和内存大小，-1 退出" << endl;
            int processId, size;
            cin >> processId;
            if (processId == -1)
                break;
            cin >> size;
            cout << "请选择分配方式 \n 1. First Fit \n 2. Best Fit \n 3. Worst Fit" << endl;
            int method;
            cin >> method;
            switch (method)
            {
            case 1:
                allocateMemory(processId, size, "FirstFit");
                break;
            case 2:
                allocateMemory(processId, size, "BestFit");
                break;
            case 3:
                allocateMemory(processId, size, "WorstFit");
                break;
            default:
                cout << "非法输入" << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "输入要释放的进程ID" << endl;
            int processId;
            cin >> processId;
            deallocateMemory(processId);
        }
        else
        {
            break;
        }
        viewMemoryMap();
    }
    return 0;
}
