#include <iostream>
#include <queue>
using namespace std;
class Process {
public:
    int id;
    int priority;
    int totalTime;   // 所需总时间
    int elapsedTime; // 已运行时间

    Process(int id, int priority, int totalTime) 
        : id(id), priority(priority), totalTime(totalTime), elapsedTime(0) {}

    // 运行一个时钟周期
    void run() {
        elapsedTime++;
        priority--;
    }

    bool isCompleted() const {
        return elapsedTime == totalTime;
    }
};

// 自定义比较类，用于优先队列
struct Compare {
    bool operator() (const Process &a, const Process &b) const {
        if (a.priority != b.priority) {
            return a.priority < b.priority; // 优先级高的在前
        }
        return a.elapsedTime > b.elapsedTime; // 运行时间短的在前
    }
};

int main() {
    priority_queue<Process, vector<Process>, Compare> queue;
    int clockCycles = 0;
    for (int i=0; i<5; i++) {
        int priority, totalTime;
        cout << "请输入进程" << i << "的优先级和所需时间：";
        cin >> priority >> totalTime;
        queue.push(Process(i, priority, totalTime));
    }
    while (!queue.empty()) {
        clockCycles++;
        Process current = queue.top();
        queue.pop();

        cout << "Clock Cycle: " << clockCycles << ", Running Process ID: " << current.id << endl;

        current.run();
        if (!current.isCompleted()) {
            queue.push(current);
        }
        else {
            cout << "Process " << current.id << " is completed." << endl;
        }
    }

    return 0;
}
