#include <stdio.h>
#include <math.h>

double joint_prob[2][2] = {
    {1.0/8, 3.0/8},
    {3.0/8, 1.0/8}
};

double entropy(double prob) {
    if (prob == 0.0) return 0.0;
    return -prob * log2(prob);
}

int main() {
    double HX = 0.0, HY = 0.0, HXY = 0.0;
    double PX[2] = {0.0, 0.0};
    double PY[2] = {0.0, 0.0};

    // Calculate marginal probabilities
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            PX[x] += joint_prob[x][y];
            PY[y] += joint_prob[x][y];
        }
    }

    // Calculate entropies
    for (int x = 0; x < 2; x++) {
        HX += entropy(PX[x]);
        for (int y = 0; y < 2; y++) {
            HXY += entropy(joint_prob[x][y]);
            if (x == 0) {
                HY += entropy(PY[y]);
            }
        }
    }

    // Calculate conditional entropy and mutual information
    double HX_given_Y = HXY - HY;
    double IXY = HX + HY - HXY;

    printf("H(X) = %lf\n", HX);
    printf("H(Y) = %lf\n", HY);
    printf("H(X,Y) = %lf\n", HXY);
    printf("H(X|Y) = %lf\n", HX_given_Y);
    printf("I(X,Y) = %lf\n", IXY);

    return 0;
}
