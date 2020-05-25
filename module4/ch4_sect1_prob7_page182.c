/** 
 * Chapter 4 - Induction, Recursion, and Recurrences
 * Section 1 - Mathematical Induction
 * Problem 7 - Page 182
 * Description -
 *  Prove that every number greater than 7 is a sum of a nonnegative integer
 *  multiple of 3 and a nonnegative integer multiple of 5.
 */

/** 
 * Chapter 4 - Induction, Recursion, and Recurrences
 * Section 1 - Mathematical Induction
 * Problem 7 - Page 182
 */
#include <stdio.h>
#include <string.h>

/* main function */
int main(void) {
    // needed variables
    int sum;

    // add some space and print a header for the first truth table
    printf("\n");
    
    /* find and print sum with n(n+1)(n+2)/3 */
    for (int i = 8; i < 10000; i++) {
        sum = 3*i+5*i;
        printf("%d total = %d\n", i, sum);
        if (sum <= 7) {
            printf("ERROR: sum is too small.\n");
            break;
        }
    }
    
    printf("\n");

    return 0;
}