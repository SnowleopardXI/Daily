#include <stdio.h>
#include <math.h>
#define NUM_SYMBOLS 4
#define TOTAL_CHARS 29
#define CHAR_LENGTH 100
#define NUM_CATEGORIES 3
#define MATRIX_SIZE 2

typedef struct {
    int index;
    double prob;
} Source;

double entropy(double prob) {
    return prob == 0.0 ? 0.0 : -prob * log2(prob);
}

int main() {
    // Q1
    Source source[NUM_SYMBOLS] = {
        {1, 0.5}, {2, 0.25}, {3, 0.125}, {4, 0.125}
    };
    double total_entropy = 0.0;
    printf("第一题：\n各个符号的概率和信息量如下：\n");
    for (int i = 0; i < NUM_SYMBOLS; ++i) {
        // 单位bit
        double info = -log2(source[i].prob);
        printf("Symbol of %d: prob = %.3lf, info = %.3lf\n", source[i].index, source[i].prob, info);
        total_entropy += source[i].prob * info;
    }
    printf("信源熵为: %.3lf\n", total_entropy);

    // Q2
    double probability = 1.0 / TOTAL_CHARS;
    double self_info = -log2(probability);
    double total_information = CHAR_LENGTH * self_info;
    printf("第二题：\n100个字符的信息量为: %.3lf bits\n", total_information);

    // Q3
    int chars_per_category[NUM_CATEGORIES] = {9, 13, 7};
    double probs_per_category[NUM_CATEGORIES] = {1.0 / 7.0, 2.0 / 7.0, 4.0 / 7.0};
    double H = 0.0;
    printf("第三题：\n");
    for (int i = 0; i < NUM_CATEGORIES; ++i) {
        H += entropy(probs_per_category[i]);
    }
    printf("信源熵为: %.3lf bits\n", H);

    // Q4
    double joint_prob[MATRIX_SIZE][MATRIX_SIZE] = {
        {1.0 / 8, 3.0 / 8},
        {3.0 / 8, 1.0 / 8}
    };
    double HX = 0.0, HY = 0.0, HXY = 0.0;
    double PX[MATRIX_SIZE] = {0}, PY[MATRIX_SIZE] = {0};

    printf("第四题：\n");
    for (int x = 0; x < MATRIX_SIZE; ++x) {
        for (int y = 0; y < MATRIX_SIZE; ++y) {
            PX[x] += joint_prob[x][y];
            PY[y] += joint_prob[x][y];
            HXY += entropy(joint_prob[x][y]);
        }
        HX += entropy(PX[x]);
    }
    for (int y = 0; y < MATRIX_SIZE; ++y) {
        HY += entropy(PY[y]);
    }

    double HX_given_Y = HXY - HY;
    double IXY = HX + HY - HXY;

    printf("H(X) = %.3lf\n", HX);
    printf("H(Y) = %.3lf\n", HY);
    printf("H(X,Y) = %.3lf\n", HXY);
    printf("H(X|Y) = %.3lf\n", HX_given_Y);
    printf("I(X,Y) = %.3lf\n", IXY);
    return 0;
}