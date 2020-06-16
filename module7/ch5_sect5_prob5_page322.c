/** 
 * Chapter 5 - Probability
 * Section 5 - Probability Calculations in Hashing
 * Problem 5 - Page 322
 * Description -
 *  In Problem 1, if there are 20 kinds of candy, how many children have to buy
 *  candy for the probability to be at least 1/2 that (at least) two children
 *  buy the same kind of candy?
 */

/** 
 * Chapter 5 - Probability
 * Section 5 - Probability Calculations in Hashing
 * Problem 5 - Page 322
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main(void)
{
    // Hash table collision detector… number of iterations vs when 2nd slot is filled… 
    // this can be repeated many times to get the overall average.
    time_t t;
    uint32_t iterations = 1000;
    uint32_t hashSize = 20;
    uint32_t hashTable[hashSize];
    uint32_t collisionCount = 0;
    uint32_t hashIndex = 0;

    // start randomness with current time
    srand((unsigned)time(&t));

    // start with seperation so results are easier to see
    printf("\n");
    printf("let's see how long it takes to hit a collision in a hashtable of size %d\n", hashSize);

    // initialize hash table to have values of 0
    for (int i = 0; i < hashSize; i++)
    {
        hashTable[i] = 0;
    }

    for (int i = 1; i <= hashSize; i++)
    {
        hashIndex = rand() % hashSize;
        if (hashTable[hashIndex] == 0)
        {
            hashTable[hashIndex] = i;
        }
        else
        {
            printf("collision found at hash table insert %d, which is probability of %f", i, (float)i / hashSize);
            break;
        }
    }

    // now let's get average probability after more iterations
    printf("\nhere are the list of n values till a collision:\n");
    for (int j = 0; j < iterations; j++)
    {
        // initialize hash table to have values of 0
        for (int i = 0; i < hashSize; i++)
        {
            hashTable[i] = 0;
        }
        for (int i = 1; i <= hashSize; i++)
        {
            hashIndex = rand() % hashSize;
            if (hashTable[hashIndex] == 0)
            {
                hashTable[hashIndex] = i;
            }
            else
            {
                collisionCount += i;
                printf("%d, ", i);
                break;
            }
        }
    }

    // print average of n value of collisions over all iterations
    printf("\ntotal collision probability average is %f\n", (float)collisionCount / iterations);

    // some space
    printf("\n");
}