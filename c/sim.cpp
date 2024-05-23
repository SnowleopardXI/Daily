#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define M 1024
#define A 256
#define avg_dest

using namespace std;
struct Vehicle
{
    double enter_time;
    double leave_time;
    double speed;
    double status;
    double position;
} sims[1000];
// 存储随机数
double n_rand[1000];

// 线性同余生成随机数
void randGen(int seed, int times, int a, int m)
{
    long long int tempSeed = seed;
    for (int i = 0; i < times; i++)
    {
        tempSeed = (a * tempSeed) % m;
        cout << tempSeed << endl;
        n_rand[i] = (double)tempSeed / m;
    }
}

// 反变换法生成负指数分布随机数
double inverseTransform(double u, double lambda)
{
    return -log(1 - u) / lambda;
}

int main()
{
    int rand_seed;
    cout << "输入随机数种子: (0-999) ";
    cin >> rand_seed;
    rand_seed = rand_seed % 1000;
    randGen(rand_seed, 5, A, M);
    // 设置初始参数
    int numVehicles;
    double roadLength, simulationTime, enter_time;
    cout << "输入仿真时长(s)（大于60）: ";
    cin >> simulationTime;
    cout << "输入3分钟内进入的车辆数:（5~20pcu/min）";
    cin >> numVehicles;
    for (int i = 0; i < numVehicles; i++)
    {
        cout << "随机数" << i + 1 << "：" << n_rand[i] << endl;
    }
    cout << "输入路段长度(m):（100-400m）";
    cin >> roadLength;
    cout << "输入第一辆车进入时刻（s）: （0-59s）";
    cin >> enter_time;
    sims[0].enter_time = (double)enter_time;
    // 初始化车辆
    for (int i = 1; i < numVehicles; i++)
    {
        sims[i].enter_time = sims[i - 1].enter_time + inverseTransform(n_rand[i], 1000 / 3600);
    }
    for (int i = 0; i < numVehicles; i++)
    {
        cout << "第" << i + 1 << "辆车进入时间：" << sims[i].enter_time << endl;
    }

    return 0;
}
