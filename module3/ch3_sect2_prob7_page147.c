/** 
 * Chapter 3 - Reflections on Logic and Proof
 * Section 2 - Variables and Quantifiers
 * Problem 9 - Page 147
 * Description -
 *  Which of the following statements (in which Z+ stands for the positive
 *  integers and Z stands for all integers) is true and which is false? Explain
 *  why. 
 *      a. ∀z ∈ Z+(z2 + 6z + 10 > 20) 
 *      b. ∀z ∈ Z(z2 − z ≥ 0) 
 *      c. ∃z ∈ Z+(z − z2  > 0) 
 *      d. ∃z ∈ Z(z2 − z = 6)
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
    int z, problem_a, problem_b, problem_c, problem_d;

    // space at the start
    printf("\nPROBLEM A) looking for FALSE\n");

    // problem a - go through each iteration and stop if false found
    for (z = 1; z <= 10; z++) {
        problem_a = power(z,2) + (6 * z) + 10;
        printf("%d^2 + (6 * %d) + 10 = %d\n", z, z, problem_a);
        printf("\t%d > 20 = %s\n", problem_a, (problem_a > 20)?"TRUE":"FALSE");
        if (!(problem_a > 20)) {
            printf("---->FALSE FOUND when z = %d, z^2 + 6z + 10 = %d\n", z, problem_a);
            break;
        }
    }

    // space at the start
    printf("\nPROBLEM B) looking for FALSE\n");

    // problem b - go through each iteration and stop if false found
    for (z = -10; z <= 10; z++) {
        problem_b = power(z,2) - z;
        printf("%d^2 - %d = %d", z, z, problem_b);
        printf(", %d > 20 = %s\n", problem_b, (problem_b >= 0)?"TRUE":"FALSE");
        if (!(problem_b >= 0)) {
            printf("---->FALSE FOUND when z = %d, z^2 - z = %d\n", z, problem_b);
            break;
        }
    }

    // space at the start
    printf("\nPROBLEM C) looking for TRUE\n");

    // problem b - go through each iteration and stop if false found
    for (z = 1; z <= 10; z++) {
        problem_c = z - power(z,2);
        printf("%d - %d^2 = %d", z, z, problem_c);
        printf(", %d > 0 = %s\n", problem_c, (problem_c > 0)?"TRUE":"FALSE");
        if (problem_c > 0) {
            printf("---->TRUE FOUND when z = %d, z^2 - z = %d\n", z, problem_c);
            break;
        }
    }

    // space at the start
    printf("\nPROBLEM D) looking for TRUE\n");

    // problem b - go through each iteration and stop if false found
    for (z = -25; z <= 10; z++) {
        problem_d = power(z,2) - z;
        printf("%d^2 - %d = %d", z, z, problem_d);
        printf(", %d = 6 = %s\n", problem_d, (problem_d == 6)?"TRUE":"FALSE");
        if (problem_d == 6) {
            printf("---->TRUE FOUND when z = %d, z^2 - z = %d\n", z, problem_d);
            break;
        }
    }

    // space at the end
    printf("\n");

    return 0;
}