/** 
 * Chapter 1 - Counting
 * Section 3 - Binomial Coefficients
 * Problem 5 - Page 31
 * Description -
    If you have 10 distinct chairs to paint, in how many ways can 
    you paint three of them green, three of them blue, and four of 
    them red? What does this have to do with labelings?
 */

/** 
 * Chapter 1 - Counting
 * Section 3 - Binomial Coefficients
 * Problem 5 - Page 31
 */
#include <stdio.h>

/* find max evaluations for two lists and print results */
int main(void) {
    // keep track of the number of combinations
    int totalCombinations = 0;
    
    // 3 final toppings, noted #0 to #2
    int finalTopping[3] = {0, 1, 2};
    int finalToppingSize = sizeof(finalTopping) / sizeof(int);
    int finalToppingCombinations;

    int greenChairs = 3;
    int blueChairs = 3;
    int redChairs = 4;
    int validRedChairs[4];
    int redChairIndex = 0;

    // 3 options for second layer
    int secondLayerSize = 3;
    
    // red chairs
    printf("\nChairs Painted Blue:\n");
    // 3 blue chairs
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            for (int k = j + 1; k < 10; k++) {
                // 3 green chairs
                for (int l = 0; l < 10; l++) {
                    for (int m = l + 1; m < 10; m++) {
                        for (int n = m + 1; n < 10; n++) {
                            // green can't use same chairs as blue
                            if (l == i || l == j || l == k) {
                                // do nothing
                            } else if (m == i || m == j || m == k) {
                                // do nothing
                            } else if (n == i || n == j || n == k) {
                                // do nothing
                            } else { 
                                // 4 red chairs remain
                                redChairIndex = 0;
                                for (int p = 0; p < 10; p++) {
                                    if (p == i || p == j || p == k || p == l || p == m || p == n) {
                                        // do nothing
                                    } else {
                                        validRedChairs[redChairIndex] = p;
                                        redChairIndex++;
                                    }
                                }
                                // red can't use same chairs as green or blue
                                printf(" B:%d%d%d_G:%d%d%d_R:%d%d%d%d", i, j, k, 
                                        l, m, n, validRedChairs[0], validRedChairs[1],
                                        validRedChairs[2], validRedChairs[3]);
                                totalCombinations++;
                            }
                        }
                    }
                }
            } 
        }  
    }

    printf("\nnumber of sundae combinations: %d\n", totalCombinations);
    
    return 0;
}