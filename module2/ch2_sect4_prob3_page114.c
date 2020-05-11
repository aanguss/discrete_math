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

/* calculate true modulo  to handle negative values */
int mod(int val, int modVal) {
    int remainder = val % modVal;
    
    /* make sure mod is actually returned when negative value calculated */
    if (remainder < 0) {
        remainder += modVal;
    } 

    return remainder;
}

/* exponent helper function for simple use with output up to 2,147,483,647 */
int power(int val, int exp) {
    int newVal = 1;

    for (int i = 0; i < exp; i++) {
        newVal *= val;
    }

    return newVal;
}

/* main function for 2.4-3 */
int main(void) {
    

    return 0;
}