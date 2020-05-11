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

/* caeser cipher encode in main function */
int main(void) {
    

    return 0;
}