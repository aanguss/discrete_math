/** 
 * Chapter 4 - Induction, Recursion, and Recurrences
 * Section 1 - Mathematical Induction
 * Problem 3 - Page 181
 * Description -
 *  Use induction to prove that
 *  1 · 2 + 2 · 3 + · · · + n(n + 1) = n(n + 1)(n + 2)/3
 */

/** 
 * Chapter 4 - Induction, Recursion, and Recurrences
 * Section 1 - Mathematical Induction
 * Problem 3 - Page 181
 */
#include <stdio.h>
#include <string.h>

/* recursive function */
int recursiveTotal(int n) {
    int runningTotal;

    /* no value if less than 1 */
    if (n < 1) {
        return 0;
    }

    /* base condition is 1, return when found n = 1 */
    if (n == 1) {
        return (n*(n+1));
    }

    runningTotal = n*(n+1);
    runningTotal = runningTotal + recursiveTotal(n - 1);

    return runningTotal;
}

/* main function */
int main(void) {
    // needed variables
    int sum, rsum;

    // add some space and print a header for the first truth table
    printf("\n");
    
    /* find and print sum with n(n+1)(n+2)/3 */
    for (int i = 0; i < 10; i++) {
        sum = i*(i+1)*(i+2)/3;
        rsum = recursiveTotal(i);
        printf("----%d----\n", i);
        printf("total:      %d(%d+1)(%d+2)/3    = %d\n", i, i, i, sum);
        printf("recursive:  %d(%d+1)           = %d\n", i, i, rsum);
        if (sum != rsum) {
            printf("ERROR: sum and rsum do not equal.\n");
        }
        printf("\n");
    }
    
    printf("\n");

    return 0;
}