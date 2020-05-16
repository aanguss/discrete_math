/** 
 * Chapter 3 - Reflections on Logic and Proof
 * Section 1 - Eqivalence And Implication
 * Problem 1 - Page 131
 * Description -
 *  Give truth tables for the following expressions. 
 *  a. (s∨t)∧(¬s∨t)∧(s∨¬t) 
 *  b. (s⇒t)∧(t⇒u) 
 *  c. (s ∨t ∨u)∧(s ∨¬t ∨u)
 */

/** 
 * Chapter 3 - Reflections on Logic and Proof
 * Section 1 - Eqivalence And Implication
 * Problem 1 - Page 131
 */
#include <stdio.h>
#include <string.h>

/* main function */
int main(void) {
    // needed variables
    int s, t, s_or_t, snot_or_t, s_or_tnot, final1;

    // add some space and print a header for the first truth table
    printf("\n");
    printf("s\tt\ts||t\t!s||t\ts||!t\t(s||t)&&(!s||t)&&(s||!t)\n");
    
    // go through each iteration of s and t and print results
    for (s = 0; s < 2; s++) {
        for (t = 0; t < 2; t++) {
            s_or_t = s || t;
            snot_or_t = !s || t;
            s_or_tnot = s || !t;
            final1 = s_or_t && snot_or_t && s_or_tnot;
            printf("%d\t%d\t%d\t%d\t%d\t%d\n", s, t, s_or_t, snot_or_t, s_or_tnot, final1);
        }
    }

    // required variables
    int u, s_implies_t, t_implies_u, final2;

    // add some space and print a header for the first truth table
    printf("\n");
    printf("s\tt\tu\ts->t\ts->u\t(s->t)&&(t->u)\n");
    
    // go through each iteration of s and t and print results
    for (s = 0; s < 2; s++) {
        for (t = 0; t < 2; t++) {
            for (u = 0; u < 2; u++) {
                s_implies_t = !s || (s && t);
                t_implies_u = !t || (t && u);
                final2 = s_implies_t && t_implies_u;
                printf("%d\t%d\t%d\t%d\t%d\t%d\n", s, t, u, s_implies_t, t_implies_u, final2);
            }
        }
    }

    // required variables
    int s_or_t_u, s_or_tnot_or_u, final3;

    // add some space and print a header for the first truth table
    printf("\n");
    printf("s\tt\tu\ts||t||u\t\ts||!t||u\t(s||t||u)&&(s||!t||u)\n");
    
    // go through each iteration of s and t and print results
    for (s = 0; s < 2; s++) {
        for (t = 0; t < 2; t++) {
            for (u = 0; u < 2; u++) {
                s_or_t_u = s || t || u;
                s_or_tnot_or_u = s || !t || u;
                final3 = s_or_t_u && s_or_tnot_or_u;
                printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", s, t, u, s_or_t_u, s_or_tnot_or_u, final3);
            }
        }
    }

    printf("\n");

    return 0;
}