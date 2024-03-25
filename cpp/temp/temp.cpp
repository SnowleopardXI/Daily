#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    const int size = 10000;
    int prime[size];
    int count = 0;
    int number = 2; // 质数检查从2开始

    while (count < size) {
        if (isPrime(number)) {
            prime[count++] = number;
        }
        number++;
    }

    // 打印前100个质数
    for (int i = 0; i < size; ++i) {
        std::cout << prime[i] << " ";
        if ((i + 1) % 10 == 0) { // 每行打印10个数，便于阅读
            std::cout << std::endl;
        }
    }

    return 0;
}
