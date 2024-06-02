#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct DiskArray {
    int track;
    int complete;
};

void init(DiskArray *disk, int size) {
    for (int i = 0; i < size; i++) {
        disk[i].complete = 0;
    }
}

int findClosest(DiskArray *diskArray, int size, int initial_head) {
    int min_distance = INT_MAX;
    int closest_track_index = -1;
    for (int i = 0; i < size; i++) {
        if (!diskArray[i].complete && abs(diskArray[i].track - initial_head) < min_distance) {
            min_distance = abs(diskArray[i].track - initial_head);
            closest_track_index = i;
        }
    }
    return closest_track_index;
}

void SSTF(DiskArray *diskArray, int size, int initial_head) {
    int seek_count = 0, distance;
    cout << "当前磁头位置\t寻道长度" << endl;
    for (int i = 0; i < size; i++) {
        int closest_track_index = findClosest(diskArray, size, initial_head);
        distance = abs(diskArray[closest_track_index].track - initial_head);
        seek_count += distance;
        initial_head = diskArray[closest_track_index].track;
        diskArray[closest_track_index].complete = 1;
        cout << initial_head << "\t\t" << distance << endl;
    }
    cout << "总寻道长度为: " << seek_count << "，平均寻道长度为: " << seek_count / (float)size << endl;
}

int main() {
    int size;
    cout << "请输入磁盘请求的数量: ";
    cin >> size;

    DiskArray *diskArray = new DiskArray[size];
    cout << "请输入每个请求的磁道号: ";
    for (int i = 0; i < size; i++) {
        cin >> diskArray[i].track;
        diskArray[i].complete = 0;
    }

    int initial_head;
    cout << "请输入初始磁头位置: ";
    cin >> initial_head;

    SSTF(diskArray, size, initial_head);

    delete[] diskArray;
    return 0;
}