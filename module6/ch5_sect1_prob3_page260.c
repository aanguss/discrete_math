/** 
 * Chapter 5 - Probability
 * Section 1 - Introduction to Probability
 * Problem 3 - Page 260
 * Description -  
 *  If you hash three keys into a hash table with 10 slots, what is the
 *  probability that all three keys hash to different slots? How big does
 *  n have to be so that if n keys hash to a table with 10 slots, the
 *  probability is at least 1/2 that some slot has at least two keys hash
 *  to it? How many keys do you need to have probability at least 2/3 that
 *  some slot has at least two keys hash to it? 
 */

/** 
 * Chapter 5 - Probability
 * Section 1 - Introduction to Probability
 * Problem 3 - Page 260
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main(void)
{
    //Hash table collision detector… number of iterations vs when 2nd slot is filled… this can be repeated many times to get the overall average.
    time_t t;
    uint32_t iterations = 1000;
    uint32_t hashSize = 10;
    uint32_t hashTable[hashSize];
    uint32_t collisionCount = 0;
    uint32_t hashIndex = 0;

    // start randomness with current time
    srand((unsigned) time(&t));
    
    // start with seperation so results are easier to see
    printf("\n");
    printf("let's see how long it takes to hit a collision in a hashtable of size %d\n", hashSize);

    // initialize hash table to have values of 0
    for (int i = 0; i < hashSize; i++) {
        hashTable[i] = 0;
    }

    for (int i = 1; i <= hashSize; i++) {
        hashIndex = rand() % hashSize;
        if (hashTable[hashIndex] == 0) {
            hashTable[hashIndex] = i;
        } else {
            printf("collision found at hash table insert %d, which is probability of %f", i, (float)i/hashSize);
            break;
        }
    }

    // now let's get average probability after more iterations
    printf("\nhere are the list of n values till a collision:\n");
    for (int j = 0; j < iterations; j++) {
        // initialize hash table to have values of 0
        for (int i = 0; i < hashSize; i++) {
            hashTable[i] = 0;
        }
        for (int i = 1; i <= hashSize; i++) {
            hashIndex = rand() % hashSize;
            if (hashTable[hashIndex] == 0) {
                hashTable[hashIndex] = i;
            } else {
                collisionCount += i;
                printf("%d, ", i);
                break;
            }
        }
    }

    // print average of n value of collisions over all iterations
    printf("\ntotal collision probability average is %f\n", (float)collisionCount/iterations);

    // some space
    printf("\n");
}