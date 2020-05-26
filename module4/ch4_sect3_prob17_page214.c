/** 
 * Chapter 4 - Induction, Recursion, and Recurrences
 * Section 3 - Growth Rates of Solutions to Recurrences
 * Problem 17 - Page 214
 * Description -
 *  If S(n) = aS(n − 1) + g(n) and g(n) = cn with 0 < a < c,
 *  how fast does S(n) grow in big-O terms?
 */

/** 
 * Chapter 4 - Induction, Recursion, and Recurrences
 * Section 3 - Growth Rates of Solutions to Recurrences
 * Problem 17 - Page 214
 */
#include <stdio.h>
#include <string.h>

/* recursive function */
int findTotal(int a, int c, int n) {
    int total;

    /* no value if less than 1 */
    if (n < 1) {
        return 0;
    }
    
    total = a * findTotal(a, c, n-1) + c^n;

    return total;
}

/* main function */
int main(void) {
    // needed variables
    int a = 1;
    int c = 2;
    int total;
    int increaseCount;

    // add some space and print a header for the first truth table
    printf("\n");

    /* output with given input a and c values */
    printf("----[ a = %d | c = %d ]----\n", a, c);
    for (int i = 0; i < 100; i++) {
        total = findTotal(a, c, i);
        printf("#%d total:   %d\n", i, total);
    }
        
    printf("\n");

    return 0;
}