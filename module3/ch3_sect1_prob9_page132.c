/** 
 * Chapter 3 - Reflections on Logic and Proof
 * Section 1 - Eqivalence And Implication
 * Problem 9 - Page 132
 * Description -
 *  Use DeMorgan’s law, the distributive law, and Problems 7 and/or 8 to show that 
 *
 *  ¬(s ∨ t) ∨ ¬(s ∨ ¬t)
 *
 *  is equivalent to ¬s.
 */

/** 
 * Chapter 3 - Reflections on Logic and Proof
 * Section 1 - Eqivalence And Implication
 * Problem 9 - Page 132
 */
#include <stdio.h>
#include <string.h>

/* main function */
int main(void) {
    // needed variables
    int s, t, snot;
    int s_or_t, not_s_or_t;
    int s_or_tnot, not_s_or_tnot;
    int final;

    // add some space and print a header for the first truth table
    printf("\n");
    // printf("s\tt\t!s\t!(s||t)\t!(s||!t)\t!(s||t)&&!(s||!t)\n");
    printf("s\tt\t!s\t!(s||t)&&!(s||!t)\tEQUIVALENT\n");
    
    // go through each iteration of s and t and print results
    for (s = 0; s < 2; s++) {
        for (t = 0; t < 2; t++) {
            snot = !s;
            s_or_t = s || t;
            not_s_or_t = !s_or_t;
            s_or_tnot = s || !t;
            not_s_or_tnot = !s_or_tnot;
            final = not_s_or_t || not_s_or_tnot;
            // printf("%d\t%d\t%d\t%d\t%d\t\t%d\n", s, t, snot, not_s_or_t, not_s_or_tnot,final);
            printf("%d\t%d\t%d\t%d\t\t\t%s\n", s, t, snot, final, final == snot?"TRUE":"FALSE");
        }
    }

    // space at the end
    printf("\n");

    return 0;
}