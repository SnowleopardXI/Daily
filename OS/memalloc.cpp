#include <iostream>
#include <deque>
#include <algorithm>
#include <climits>
using namespace std;

static int lastAllocatedPos = 0;
struct Lnode
{
    int id;
    int length;
    int start;
    int flag;
};

deque<Lnode> freeMemory;
deque<Lnode> allocatedMemory;

void initializeMemory(int totalMemory);
void splitBlock(deque<Lnode>::iterator it, int size);
void allocateMemory(int processId, int size, const string &method);
void mergeFreeBlocks();
void deallocateMemory(int processId);
void viewMemoryMap();

int main()
{
    int totalMemory = 640;
    initializeMemory(totalMemory);

    allocateMemory(0, 2, "FirstFit");
    allocateMemory(1, 4, "FirstFit");
    allocateMemory(2, 3, "FirstFit");
    allocateMemory(3, 2, "FirstFit");
    allocateMemory(4, 3, "FirstFit");
    allocateMemory(5, 2, "FirstFit");
    allocateMemory(6, 3, "FirstFit");
    allocateMemory(7, 2, "FirstFit");
    allocateMemory(8, 3, "FirstFit");
    allocateMemory(9, 2, "FirstFit");
    viewMemoryMap();
    short int choice;
    while (1)
    {
        int type = 1;
        cout << "1. 分配内存" << endl
             << "2. 释放内存" << endl
             << "3. 首次适应算法" << endl
             << "4. 最佳适应算法" << endl
             << "5. 最坏适应算法" << endl
             << "6. 循环首次适应算法" << endl
             << "其他. 退出" << endl
             << "当前算法：" << (type == 1 ? "首次适应算法" : type == 2 ? "最佳适应算法"
                                                          : type == 3   ? "最坏适应算法"
                                                                        : "循环首次适应算法")
             << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "输入要分配的进程 ID 和内存大小，-1 退出" << endl;
            int processId, size;
            cin >> processId;
            if (processId == -1)
                break;
            cin >> size;

            switch (type)
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
            case 4:
                allocateMemory(processId, size, "LoopFirstFit");
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
        else if (choice == 3)
        {
            type = 1;
        }
        else if (choice == 4)
        {
            type = 2;
        }
        else if (choice == 5)
        {
            type = 3;
        }
        else if (choice == 6)
        {
            type = 4;
        }
        else
        {
            break;
        }
        viewMemoryMap();
    }
    return 0;
}

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
    if (method == "NextFit")
    {
        bool wrappedAround = false;
        auto it = freeMemory.begin();
        while (it != freeMemory.end())
        {
            if (it->start >= lastAllocatedPos && it->length >= size)
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
                lastAllocatedPos = it->start + size;
                freeMemory.erase(it);
                return;
            }

            if (it == freeMemory.end() - 1 && !wrappedAround)
            {
                it = freeMemory.begin() - 1;
                wrappedAround = true;
                lastAllocatedPos = 0;
            }
            ++it;
        }
    }
    else
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
    }

    cout << "没有找到适合进程 " << processId << " 的内存块" << endl;
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