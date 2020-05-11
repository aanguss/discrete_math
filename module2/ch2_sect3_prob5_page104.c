/** 
 * Chapter 2 - Cryptography and Number Theory
 * Section 3 - The RSA Cryptosystem
 * Problem 9 - Page 104
 * Description -
 * 
 * The numbers 29 and 43 are primes. What is (29 − 1)(43 − 1)? What is
 * 199 · 1111 in Z1176? What is (105^1111)^199 in Z29? In Z43? In Z1247?
 * How does this answer the second question in Exercise 2.3-5?
 */

/** 
 * Chapter 2 - Cryptography and Number Theory
 * Section 3 - The RSA Cryptosystem
 * Problem 9 - Page 104
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

/* main function for 2.3-5 */
int main(void) {
    printf("\nPROBLEMS FROM BOOK:\n");
    printf("(29-1)(43-1) = %d\n", (29-1)*(43-1));
    printf("(199)(111) mod 1176 = %d\n", mod((199*1111), 1176));
    printf("(105^1111)^199 mod 29 = %d\n", mod(105, 29));
    printf("(105^1111)^199 mod 43 = %d\n", mod(105, 43));
    printf("(105^1111)^199 mod 1247 = %d\n", mod(105, 1247));
    
    printf("\nExample 2.1-5, multiples of y mod p = x mod p:\n");
    for (int i = 0; i < 4; i++) {
        printf("(13^%d) mod 47 = %d mod 47 = %d\n", i, power(13,i), mod(power(13,i), 47));
    }
    printf("---------------\n");
    for (int i = 0; i < 4; i++) {
        printf("(13^2)^%d mod 47 = %d mod 47 = %d\n", i, power(power(13,2),i), mod(power(power(13,2),i), 47));
        printf("(13^2 mod 47)^%d = %d^%d mod 47 = %d mod 47 = %d\n",    i, 
                                                                        mod(power(13,2),47), 
                                                                        i, 
                                                                        power(mod(power(13,2),47), i), 
                                                                        mod(power(mod(power(13,2),47), i), 47));
        
    printf("\n");

    return 0;
}