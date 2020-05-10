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
#define SHIFT_LEFT 1
#define SHIFT_RIGHT 0

/* caeser cipher encode in main function */
int main(void) {
    char alphabet[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char * userString = "HERE IS A MESSAGE";

    printf("\n%s is encoded as: ", userString);
    for (int i = 0; i < strlen(userString); i++) {
        printf("%c", alphabet[ (userString[i] - SHIFT_AMOUNT) % 26 ]);
    }
    printf("\n\n");

    return 0;
}