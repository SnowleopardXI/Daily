import numpy
import matplotlib.pyplot as plt
import random
class Lnode:
    def __init__(self, id, length, start, flag):
        self.id = id
        self.length = length
        self.start = start
        self.flag = flag

# Global variables
freeMemory = []
allocatedMemory = []

def initializeMemory(totalMemory):
    freeMemory.append(Lnode(-1, totalMemory, 0, 0))

def splitBlock(block_index, size):
    it = freeMemory[block_index]
    freeBlock = Lnode(it.id, it.length - size, it.start + size, 0)
    it.length = size
    it.flag = 1
    freeMemory.insert(block_index + 1, freeBlock)

def allocateMemory(processId, size, method):
    for i, it in enumerate(freeMemory):
        if it.length >= size:
            if method == "FirstFit" or (method == "BestFit" and it.length == size):
                it.id = processId
                if it.length > size:
                    splitBlock(i, size)
                else:
                    it.flag = 1
                allocatedMemory.append(it)
                del freeMemory[i]
                return True

    if method == "BestFit":
        best_index = -1
        min_size = float('inf')
        for i, it in enumerate(freeMemory):
            if it.length >= size and it.length < min_size:
                min_size = it.length
                best_index = i
        if best_index != -1:
            best_it = freeMemory[best_index]
            best_it.id = processId
            if best_it.length > size:
                splitBlock(best_index, size)
            else:
                best_it.flag = 1
            allocatedMemory.append(best_it)
            del freeMemory[best_index]
            return True
    if method == "WorstFit":
        worst_index = -1
        max_size = -1
        for i, it in enumerate(freeMemory):
            if it.length >= size and it.length > max_size:
                max_size = it.length
                worst_index = i
        if worst_index != -1:
            worst_it = freeMemory[worst_index]
            worst_it.id = processId
            if worst_it.length > size:
                splitBlock(worst_index, size)
            else:
                worst_it.flag = 1
            allocatedMemory.append(worst_it)
            del freeMemory[worst_index]
            return True
    return False

def deallocateMemory(processId):
    for i in range(len(allocatedMemory)):
        if allocatedMemory[i].id == processId:
            allocatedMemory[i].flag = 0
            freeMemory.append(allocatedMemory[i])
            del allocatedMemory[i]
            combineFreeBlocks()
            return True
    return False

def combineFreeBlocks():
    freeMemory.sort(key=lambda x: x.start)
    i = 0
    while i < len(freeMemory) - 1:
        if freeMemory[i].start + freeMemory[i].length == freeMemory[i + 1].start:
            freeMemory[i].length += freeMemory[i + 1].length
            del freeMemory[i + 1]
        else:
            i += 1

def graphicalMemory():
    plt.figure(figsize=(12, 4))
    plt.xlim(0, 128)
    plt.ylim(0, 1)
    plt.yticks([])
    plt.xticks(numpy.arange(0, 128, 4))
    plt.grid()
    plt.title("Memory")

    # 获取tab20b和tab20c颜色映射
    colors_tab20b = plt.cm.get_cmap('tab20b', 20)
    colors_tab20c = plt.cm.get_cmap('tab20c', 20)

    process_colors = {}

    for block in freeMemory + allocatedMemory:
        if block.flag == 0:  # 空闲块
            color = 'grey'
            label = "Free"
        else:
            if block.id not in process_colors:
                # 使用两个颜色映射中的颜色，确保索引在有效范围内
                if block.id % 40 < 20:
                    color = colors_tab20b(block.id % 20)
                else:
                    color = colors_tab20c(block.id % 20)
                process_colors[block.id] = color
            color = process_colors[block.id]
            label = "P" + str(block.id)

        plt.barh(0.5, block.length, left=block.start, height=0.5, color=color, label=label)

    # 删除重复的标签
    handles, labels = plt.gca().get_legend_handles_labels()
    by_label = dict(zip(labels, handles))
    plt.legend(by_label.values(), by_label.keys())

    plt.show()
    
# Example of usage
initializeMemory(128)
n=int(input("Enter the number of processes: "))
for i in range(n):
    ranint=random.randint(2,16)
    allocateMemory(i, ranint, "FirstFit")
graphicalMemory()
while True:
    print("1. Deallocate a process")
    print("2. Allocate a process")
    print("3. Exit")
    choice=int(input("Enter your choice: "))
    if choice==1:
        processId=int(input("Enter the process id: "))
        deallocateMemory(processId)
        graphicalMemory()
    elif choice==2:
        processId=int(input("Enter the process id: "))
        size=int(input("Enter the size of the process: "))
        print ("1. FirstFit")
        print ("2. BestFit")
        print ("3. WorstFit")
        method=int(input("Enter the method: "))
        if method==1:
            allocateMemory(processId, size, "FirstFit")
        elif method==2:
            allocateMemory(processId, size, "BestFit")
        elif method==3:
            allocateMemory(processId, size, "WorstFit")
        else:
            print("Invalid choice")
        graphicalMemory()
    elif choice==3:
        break
    else:
        print("Invalid choice")