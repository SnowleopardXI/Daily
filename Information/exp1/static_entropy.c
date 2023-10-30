#include <stdio.h>
#include <math.h>

struct source {
    int index;
    double prob;
}source[50];

int main() {
    int i, j, num, temp1, temp2;
    double entropy = 0.0;
    printf("Enter the number of symbols: ");
    scanf("%d", &num);
    printf("Enter the possibilities of the symbols: (Using fraction)\n");
    for (i = 0; i < num; i++) {
        printf("Symbol %d: ", i + 1);
        source[i].index = i + 1;
        scanf("%d/%d", &temp1, &temp2);
        source[i].prob = (double)temp1 / temp2;
    }
    printf("The possibilities and the self-information of the symbols are:\n");
    for (i = 0; i < num; i++) {
        printf("Symbol %d: %lf\t%lf bits\n", source[i].index, source[i].prob, log2(1 / source[i].prob));
    }
    for (i = 0; i < num; i++) {
        entropy += source[i].prob * log2(1 / source[i].prob);
    }
    printf("The entropy of the source is: %lf\n", entropy);
    return 0;
}