/** 
 * Chapter 3 - Reflections on Logic and Proof
 * Section 2 - Variables and Quantifiers
 * Problem 9 - Page 147
 * Description -
 *  Write the statement “The square of every real number is greater than or
 *  equal to 0” as a quantified statement about the universe of real numbers.
 *  You may use R to stand for the universe of real numbers.
 */

/** 
 * Chapter 3 - Reflections on Logic and Proof
 * Section 2 - Variables and Quantifiers
 * Problem 9 - Page 147
 */
#include <stdio.h>
#include <string.h>

/* exponent helper function for simple use with output up to 2,147,483,647 */
int power(int val, int exp) {
    int newVal = 1;

    for (int i = 0; i < exp; i++) {
        newVal *= val;
    }

    return newVal;
}

/* main function */
int main(void) {
    // needed variables
    int s, neg_s;
    double s_dbl, neg_s_dbl;

    // space at the start
    printf("\n");

    // go through each iteration of s and t and print results
    for (s = 1; s <= 0xFFF; s++) {
        s_dbl = power(s,2);
        neg_s = -s;
        neg_s_dbl = power(neg_s,2);
        printf("%d^2= %0.f\t%d^2= %0.f\t%s\n", s, s_dbl, neg_s, neg_s_dbl, (s_dbl && neg_s_dbl) >= 0?"TRUE":"FALSE");
        if (!(s_dbl >= 0) || !(neg_s_dbl >= 0)) {
            printf("\n\nNOT TRUE: s = %d, -s = %d\n", s, neg_s);
            break;
        }
    }

    // space at the end
    printf("\n");

    return 0;
}