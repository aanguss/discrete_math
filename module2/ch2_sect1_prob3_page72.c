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

/* caeser cipher encode in main function */
int main(void) {
    char lowerAlphabet[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char upperAlphabet[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char * userString = "HERE IS A MESSAGE";

    printf("\n%s is encoded as: ", userString);
    for (int i = 0; i < strlen(userString); i++) {
        if (userString[i] == ' ') {
            printf("%c", userString[i]);
        } else {
            printf("%c", upperAlphabet[ (userString[i] - SHIFT_AMOUNT) % 26 ]);
        }
    }
    printf("\n\n");

    return 0;
}