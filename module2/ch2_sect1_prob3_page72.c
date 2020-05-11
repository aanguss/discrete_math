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
        if (userString[i] == ' ') {
            printf("%c", userString[i]);
        } else {
            int alphaIndex = (int)userString[i] - ASCII_START_INDEX - SHIFT_AMOUNT;
            alphaIndex = mod(alphaIndex, ALPHABET_SIZE) + ASCII_START_INDEX;
            printf("%c", alphaIndex);
        }
    }
    printf("\n\n");

    return 0;
}