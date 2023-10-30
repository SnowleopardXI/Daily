#include <stdio.h>
#include <math.h>

int main() {
    // Given probabilities for categories
    double prob_cat1 = 1.0 / 7.0;
    double prob_cat2 = 2.0 / 7.0;
    double prob_cat3 = 4.0 / 7.0;

    // Given number of characters in each category
    int chars_cat1 = 9;
    int chars_cat2 = 13;
    int chars_cat3 = 7;

    // Calculate the probability of each character within its category
    double prob_char_cat1 = prob_cat1 / chars_cat1;
    double prob_char_cat2 = prob_cat2 / chars_cat2;
    double prob_char_cat3 = prob_cat3 / chars_cat3;

    // Calculate entropy for each category
    double H1 = -chars_cat1 * prob_char_cat1 * log2(prob_char_cat1);
    double H2 = -chars_cat2 * prob_char_cat2 * log2(prob_char_cat2);
    double H3 = -chars_cat3 * prob_char_cat3 * log2(prob_char_cat3);

    // Sum up the entropies to get the total entropy
    double H = H1 + H2 + H3;

    // Print the result
    printf("Entropy of the source is: %lf bits\n", H);

    return 0;
}
