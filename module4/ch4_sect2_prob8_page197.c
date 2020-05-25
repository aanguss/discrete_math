/** 
 * Chapter 4 - Induction, Recursion, and Recurrences
 * Section 2 - Recursion, Recurrences, and Indcution
 * Problem 8 - Page 197
 * Description -
 *  Use induction to prove that
 *  1 · 2 + 2 · 3 + · · · + n(n + 1) = n(n + 1)(n + 2)/3
 */

/** 
 * Chapter 4 - Induction, Recursion, and Recurrences
 * Section 2 - Recursion, Recurrences, and Indcution
 * Problem 8 - Page 197
 */
#include <stdio.h>
#include <string.h>

/* recursive function */
int findTotalFish(int n) {
    int fishCount;

    /* no value if less than 1 */
    if (n < 1) {
        return 0;
    }

    /* base condition is 1, return when found n = 1 */
    if (n == 1) {
        return (4000);
    }

    fishCount = 2^(n-1)*findTotalFish(n-1)+2000*(2^(n-1)-1);

    return fishCount;
}

/* main function */
int main(void) {
    // needed variables
    int totalFish;

    // add some space and print a header for the first truth table
    printf("\n");
    
    /* find and print sum with n(n+1)(n+2)/3 */
    for (int i = 0; i < 10; i++) {
        totalFish = findTotalFish(i);
        printf("----Year %d ", i);
        printf("total fish:   %d\n", totalFish);
    }
    
    printf("\n");

    return 0;
}