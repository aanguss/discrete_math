/** 
 * Chapter 2 - Cryptography and Number Theory
 * Section 2 - Inverses and Greatest Common Divisors
 * Problem 9 - Page 91
 * Description -
 * 
 * Bob and Alice want to choose a key that they can use for cryptography, but all
 * they have to communicate is a bugged phone line. Bob proposes that they each
 * choose a secret number, a for Alice and b for Bob. They also choose, over the
 * phone, a prime number p, with more digits than any key they want to use, and
 * one more number q. Bob will send Alice bq mod p, and Alice will send Bob aq
 * mod p. Their key (which they will keep secret) will then be abq mod p. (In
 * this case, don’t worry about the details of how they use their key; only worry
 * about how they choose it.) As Bob explains, their wiretapper will know p, q,
 * aq mod p, and bq mod p but will not know a or b, so their key should be safe.
 * Is this scheme safe—that is, can the wiretapper compute abq mod p? If so, how?
 * Alice says, “You know, the scheme sounds good, but wouldn’t it be more
 * complicated for the wiretapper if I send you qa mod p, you send me qb mod p,
 * and we use qab mod p as our key?” In this case, can you think of a way for the
 * wiretapper to compute qab mod p? If so, how? If not, what is the stumbling
 * block? (It is fine for the stumbling block to be that you don’t know how to
 * compute something; you don’t need to prove that you can’t compute it.) 
 */

/** 
 * Chapter 2 - Cryptography and Number Theory
 * Section 2 - Inverses and Greatest Common Divisors
 * Problem 9 - Page 91
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

/* calculate gcd for two numbers and return T(1)/F(0) with value set if true*/
int gcd(int a, int b) {
    int returnValue = 0;
    
    for (int i = 1; i <= a && i <= b; i++) {
        if ((a % i == 0) && (b % i == 0)) {
            returnValue = i;
        }
    }
    
    return returnValue;
}

/* 
 * calculate gcd with extended Euclidean algorithm as fround from:
 * https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended 
 */
int egcd(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call  
    int gcd = egcd(b%a, a, &x1, &y1);  
  
    // Update x and y using results of  
    // recursive call  
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;
}

/* calculate inverse of a number */
int inverse(int val, int n) {
    int x,y;

    if(egcd(val,n,&x,&y) == 1) {
        return mod(x,n);
    } else {
        return 0; // no inverse found
    }
}

/* main function for 2.2-9 */
int main(void) {
    int a = 6;
    int b = 9;
    int q = 10;
    int p = 29;
    int bobMessage = mod(b*q, p);
    int aliceMessage = mod(a*q, p);
    int key = mod(a*b*q, p);
    int x, y;

    printf("\nIterate with a different given q from 0 to %d:\n", p - 1);

    for (int i = 0; i < p; i++) {
        q = i;
        bobMessage = mod(b*q, p);
        aliceMessage = mod(a*q, p);
        key = mod(a*b*q, p);

        printf("[   q = %d   ]\n", i);
        printf("gcd of %d and %d = %d\n", a, b, gcd(a,b));
        if (egcd(a,b,&x,&y) > 0) {
            printf("egcd of %d and %d = %d\n", a, b, egcd(a,b,&x,&y));
            printf("egcd found x = %d and y = %d\n", x, y);
        }
        // printf("--------------\n");
        printf("\n");
        printf("they are using: a = %d, b = %d, q = %d and p = %d\n", a, b, q, p);
        printf("bob's message = %d, alice's message = %d and their key = %d\n", bobMessage, aliceMessage, key);
        printf("inverse of %d in %d = %d --> %d mod %d = %d\n", q, p, inverse(q,p), inverse(q,p), p, inverse(q,p)/a);
        printf("--------------\n");
        // printf("\n");
    }
    printf("\n");

    return 0;
}