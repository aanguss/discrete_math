/** 
 * Chapter 2 - Cryptography and Number Theory
 * Section 1 - Cryptography and Modular Arithmetic
 * Problem 13 - Page 74
 * Description -
 * 
 * Explain why, if you were encoding messages x1, x2, and x3 to obtain y1, y2,
 * and y3 by adding an arbitrary number a and taking the sum mod n, your
 * adversary would know that at least one of the differences y1 − y2, y1 −y3,
 * ory2 −y3 taken in the integers, not in Zn, would be the difference of two
 * unencoded messages. (Note: We are not saying that your adversary would know
 * which of the three was such a difference.)
 */

/** 
 * Chapter 2 - Cryptography and Number Theory
 * Section 1 - Cryptography and Modular Arithmetic
 * Problem 13 - Page 74
 */
#include <stdio.h>
#include <stdlib.h>

/* defines for type of caeser cipher */
#define SHIFT_AMOUNT 3
#define MOD_AMOUNT 26

/* calculate true modulo  to handle negative values */
int mod(int val, int modVal) {
    int remainder = val % modVal;
    
    /* make sure mod is actually returned when negative value calculated */
    if (remainder < 0) {
        remainder += modVal;
    } 

    return remainder;
}

/* encode a given value per a given shift and modSize to be used */
int encode(int value, int shift, int modSize) {
    int cipherValue = value + shift;

    if (cipherValue >= modSize) {
        abs(modSize - cipherValue) - 1;
    }
    return cipherValue;
}

/* main function of 2.1-13 */
int main(void) {

    int x1 = 25;
    int x2 = 15;
    int x3 = 10;
    int a = SHIFT_AMOUNT;
    int n = MOD_AMOUNT;
    int y1 = mod(encode(x1, a, n), n);
    int y2 = mod(encode(x2, a, n), n);
    int y3 = mod(encode(x3, a, n), n);

    printf("\n");
    for (int i = 0; i < 5; i++) {
        a = SHIFT_AMOUNT + i;
        y1 = mod(encode(x1, a, n), n);
        y2 = mod(encode(x2, a, n), n);
        y3 = mod(encode(x3, a, n), n);

        printf("---------------\n");
        printf("x1(%d)-->y1(%d)\n", x1, y1);
        printf("x2(%d)-->y2(%d)\n", x2, y2);
        printf("x3(%d)-->y3(%d)\n", x3, y3);
        printf("\n");
        printf("x1(%d) - x2(%d) = %d ----> y1(%d) - y2(%d) = %d\n", x1, x2, (x1 - x2), y1, y2, (y1 - y2));
        printf("x1(%d) - x2(%d) = %d ----> y1(%d) - y3(%d) = %d\n", x1, x3, (x1 - x3), y1, y3, (y1 - y3));
        printf("x1(%d) - x2(%d) = %d ----> y2(%d) - y3(%d) = %d\n", x2, x3, (x2 - x3), y2, y3, (y2 - y3));
        printf("\n");
    }

    return 0;
}