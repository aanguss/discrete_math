/** 
 * Chapter 2 - Cryptography and Number Theory
 * Section 4 - The RSA Cryptosystem
 * Problem 3 - Page 114
 * Description -
 * 
 * A gigabyte is one billion bytes; a terabyte is one trillion bytes. A byte is
 * 8 bits, each a 0 or a 1. Because 2^10 = 1024, which is about 1000, you can
 * store about three digits (any number between 0 and 999) in 10 bits. About
 * how many decimal digits could you store in five gigabytes of memory (a 
 * gigabyte is 2^30, or approximately one billion bytes)? About how many decimal
 * digits could you store in five terabytes of memory (a terabyte is 2^40, or
 * approximately one trillion bytes)? How does this compare with the number 
 * 10^120? (To do this problem, it is reasonable to continue to assume that 1024
 * is about 1000.)
 */

/** 
 * Chapter 2 - Cryptography and Number Theory
 * Section 4 - The RSA Cryptosystem
 * Problem 3 - Page 114
 */
#include <stdio.h>
#include <stdint.h>

/* exponent helper function for simple use with output up to 2,147,483,647 */
double power(int val, int exp) {
    double newVal = 1;

    for (int i = 0; i < exp; i++) {
        newVal *= val;
    }

    return newVal;
}

int digitAmount(uint64_t val) {
    int digitCount = 1;

    /* keep shifting till nothing is left */
    while (val > 0) {
        val = val >> 4;
        digitCount++;
    }

    return digitCount;
}

/* main function for 2.4-3 */
int main(void) {
    int digits = digitAmount(1000);
    printf("\n");
    printf("2^10 (%.0f) has %d many digits\n", power(2,10), digitAmount(power(2,10)));
    printf("10^3 (%.0f) has %d many digits\n", power(10,3), digitAmount(power(10,3)));
    printf("2^30 (%.0f) has %d many digits\n", power(2,30), digitAmount(power(2,30)));
    printf("10^8 (%.0f) has %d many digits\n", power(10,8), digitAmount(power(10,8)));
    printf("2^40 (%.0f) has %d many digits\n", power(2,40), digitAmount(power(2,40)));
    printf("10^12 (%.0f) has %d many digits\n", power(10,12), digitAmount(power(10,12)));
    printf("-------------\n");
    printf("2^120 = (2^40)(2^40)(2^40) and has %d many digits\n", 3*digitAmount(power(2,40)));
    printf("\n");
    return 0;
}