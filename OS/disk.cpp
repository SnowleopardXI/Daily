#include <bits/stdc++.h>
using namespace std;

struct DiskArray {
    int track;
    int complete;
} diskArray[9];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void init(DiskArray *disk, int size) {
    for (int i = 0; i < size; i++) {
        disk[i].complete = 0;
    }
}

void FCFS(DiskArray *diskArray, int size, int initial_head) {
    int seek_count = 0, distance, cur_track;
    for (int i = 0; i < size; i++) {
        cur_track = diskArray[i].track;
        distance = abs(cur_track - initial_head);
        seek_count += distance;
        initial_head = cur_track;
    }
    cout << "FCFS寻道序列为: ";
    for (int i = 0; i < size; i++) {
        cout << diskArray[i].track << " ";
    }
    cout << endl << "寻道长度为: " << seek_count << " ,平均寻道长度为: " << seek_count / (float)size << endl;
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

void SSTF(DiskArray *diskArray, int size, int initial_head, int temp[]) {
    int seek_count = 0, distance;
    for (int i = 0; i < size; i++) {
        int closest_track_index = findClosest(diskArray, size, initial_head);
        temp[i] = diskArray[closest_track_index].track;
        diskArray[closest_track_index].complete = 1;
        distance = abs(diskArray[closest_track_index].track - initial_head);
        seek_count += distance;
        initial_head = diskArray[closest_track_index].track;
    }
    cout << "SSTF寻道序列为: ";
    for (int i = 0; i < size; i++) {
        cout << temp[i] << " ";
    }
    cout << endl << "寻道长度为: " << seek_count << " ,平均寻道长度为: " << seek_count / (float)size << endl;
    init(diskArray, size);
}

void SCAN(DiskArray *diskArray, int size, int initial_head, int temp[]) {
    vector<int> left, right;
    int head_movement = 0;
    for (int i = 0; i < size; i++) {
        if (diskArray[i].track < initial_head) {
            left.push_back(diskArray[i].track);
        } else {
            right.push_back(diskArray[i].track);
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    cout << "SCAN寻道序列为: ";
    for (int i = 0; i < right.size(); i++) {
        head_movement += abs(initial_head - right[i]);
        initial_head = right[i];
        cout << right[i] << " ";
    }
    for (int i = left.size() - 1; i >= 0; i--) {
        head_movement += abs(initial_head - left[i]);
        initial_head = left[i];
        cout << left[i] << " ";
    }
    cout << endl << "总寻道长度为: " << head_movement << " ,平均寻道长度为: " << head_movement / (float)size << endl;
    init(diskArray, size);
}

void CSCAN(DiskArray *disk, int size, int initial_head, int temp[]) {
    vector<int> left, right;
    vector<int> seek_sequence;

    // Adding end values which has to be visited before reversing the direction
    left.push_back(0);
    right.push_back(199); // assuming size of disk is 200

    for (int i = 0; i < size; i++) {
        if (disk[i].track < initial_head) {
            left.push_back(disk[i].track);
        }
        if (disk[i].track > initial_head) {
            right.push_back(disk[i].track);
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    for (int i = 0; i < right.size(); i++) {
        seek_sequence.push_back(right[i]);
    }
    seek_sequence.push_back(left[0]);
    for (int i = 1; i < left.size(); i++) {
        seek_sequence.push_back(left[i]);
    }
    for (int i = 0; i < seek_sequence.size(); i++) {
        temp[i] = seek_sequence[i];
    }
    int head_movement = 0;
    cout << "CSCAN寻道序列为: ";
    for (int i = 0; i < seek_sequence.size(); i++) {
        cout << seek_sequence[i] << " ";
        head_movement += abs(initial_head - seek_sequence[i]);
        initial_head = seek_sequence[i];
    }
    cout << endl << "总寻道长度为: " << head_movement << " ,平均寻道长度为: " << head_movement / (float)size << endl;
    init(diskArray, size);
}

void NStepSCAN(DiskArray *diskArray, int size, int initial_head, int temp[], int n) {
    vector<int> left, right;
    int head_movement = 0;
    for (int i = 0; i < size; i++) {
        if (diskArray[i].track < initial_head) {
            left.push_back(diskArray[i].track);
        } else {
            right.push_back(diskArray[i].track);
        }
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    cout << "SCAN寻道序列为: ";
    for (int i = 0; i < right.size(); i++) {
        head_movement += abs(initial_head - right[i]);
        initial_head = right[i];
        cout << right[i] << " ";
    }
    for (int i = left.size() - 1; i >= 0; i--) {
        head_movement += abs(initial_head - left[i]);
        initial_head = left[i];
        cout << left[i] << " ";
    }
    cout << endl << "总寻道长度为: " << head_movement << " ,平均寻道长度为: " << head_movement / (float)size << endl;
    init(diskArray, size);
}

int main() {
    int tracks[] = {29, 55, 39, 18, 70, 164, 159, 83, 184}, size = sizeof(tracks) / sizeof(tracks[0]);
    int temp[size];
    int initial_head = 100;
    for (int i = 0; i < size; i++) {
        diskArray[i].track = tracks[i];
        diskArray[i].complete = 0;
    }
    FCFS(diskArray, size, initial_head);
    SSTF(diskArray, size, initial_head, temp);
    SCAN(diskArray, size, initial_head, temp);
    CSCAN(diskArray, size, initial_head, temp);
    NStepSCAN(diskArray, size, initial_head, temp, 3);
    return 0;
}
