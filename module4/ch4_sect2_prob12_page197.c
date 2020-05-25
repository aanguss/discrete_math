/** 
 * Chapter 4 - Induction, Recursion, and Recurrences
 * Section 2 - Recursion, Recurrences, and Indcution
 * Problem 12 - Page 197
 * Description -
 *  Solve the recurrence T(n) = 2T(n − 1) + n32n, 
 *  with the initial condition T(0) = 2.
 */

/** 
 * Chapter 4 - Induction, Recursion, and Recurrences
 * Section 2 - Recursion, Recurrences, and Indcution
 * Problem 12 - Page 197
 */
#include <stdio.h>
#include <string.h>

/* recursive function */
int findTotal(int n) {
    int total;

    /* no value if less than 1 */
    if (n < 1) {
        return 0;
    }
    
    total = (2 * findTotal(n -1)) + ((n^3) * (2^n)); 

    return total;
}

/* main function */
int main(void) {
    // needed variables
    int sum, rsum, bsum;

    // add some space and print a header for the first truth table
    printf("\n");
    
    /* find and print sum  */
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            sum = 2;
            bsum = 2;
            rsum = 2;
        } else {
            sum = (2^(i+1)) + (2^(i)) * (i^3) * (-1 + (2^(i)));
            bsum = (2^(i+1)) + (2^(i)) * ((i^2) * ((i + 1)^2) / 4);
            rsum = findTotal(i);
        }
        printf("----%d----\n", i);
        printf("calculated total:   (2^(%d+1)) + (2^(%d)) * (%d^3) * (-1 + (2^(%d)))        = %d\n", i, i, i, i, sum);
        printf("book's total:       (2^(%d+1)) + (2^(%d)) * ((%d^2) * ((%d + 1)^2) / 4)     = %d\n", i, i, i, i, bsum);
        printf("calc recursive:     (2) * T(n-1) + ((n^3) * (2^n)                       = %d\n", rsum);
    }
    
    printf("\n");

    return 0;
}