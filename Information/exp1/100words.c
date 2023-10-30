#include <stdio.h>
#include <math.h>

int main() {
    int total = 29;  // 26 letters + 3 punctuation marks
    int length = 100;

    double probability = 1.0 / total;
    double self_info = -log2(probability);
    double total_information = length * self_info;
    printf("The information provided by the 100-character message is: %lf bits\n", total_information);
    return 0;
}
