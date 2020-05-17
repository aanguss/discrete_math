/** 
 * Chapter 3 - Reflections on Logic and Proof
 * Section 3 - Inference
 * Problem 9 - Page 159
 * Description -
 *  Prove that if x^3 > 8, then x > 2. 
 */

/** 
 * Chapter 3 - Reflections on Logic and Proof
 * Section 3 - Inference
 * Problem 9 - Page 159
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
    int x;
    double x_cubed;

    // space at the start
    printf("\nPROBLEM looking for FALSE\n");

    // problem a - go through each iteration and stop if false found
    for (x = 3; x <= 0xFF; x++) {
        x_cubed = power(x,3);
        printf("%d^3 = %0.f\t%s\n", x, x_cubed, (x_cubed <= 8)?"TRUE":"FALSE");
        if ((x_cubed <= 8)) {
            printf("\n\nNOT TRUE: x = %d and %d^3 = %0.f\n", x, x, x_cubed);
            break;
        }
    }

    // space at the end
    printf("\n");

    return 0;
}