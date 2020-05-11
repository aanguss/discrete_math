/** 
 * Chapter 2 - Cryptography and Number Theory
 * Section 1 - Cryptography and Modular Arithmetic
 * Problem 3 - Page 72
 * Description -
 * Encrypt the message HERE IS A MESSAGE using a Caesar cipher in which each
 *          letter is shifted three places to the left.
 */

/** 
 * Chapter 2 - Cryptography and Number Theory
 * Section 1 - Cryptography and Modular Arithmetic
 * Problem 3 - Page 72
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* defines for type of caeser cipher */
#define SHIFT_AMOUNT 3
#define ASCII_START_INDEX 65
#define ALPHABET_SIZE 26

/* calculate true modulo  to handle negative values */
int mod(int val, int modVal) {
    int remainder = val % modVal;
    
    /* make sure mod is actually returned when negative value calculated */
    if (remainder < 0) {
        remainder += modVal;
    } 

    return remainder;
}

/* caeser cipher encode in main function */
int main(void) {
    
    char * userString = "HERE IS A MESSAGE";

    printf("\n\"%s\" is encoded as: ", userString);
    for (int i = 0; i < strlen(userString); i++) {
        printf("\n");
        printf("%c[%d]->", userString[i], userString[i]);
        if (userString[i] == ' ') {
            printf("%c", userString[i]);
        } else {
            int alphaIndex = (((int)userString[i] - ASCII_START_INDEX - SHIFT_AMOUNT) % ALPHABET_SIZE) + ASCII_START_INDEX;
            int al = (int)userString[i] - ASCII_START_INDEX - SHIFT_AMOUNT;
            int alpha = mod(al, ALPHABET_SIZE);
            printf("%d->", al);
            printf("%d->", alpha);
            printf("%c[%d]", alphaIndex, alphaIndex);
        }
    }
    printf("\n\n");

    return 0;
}