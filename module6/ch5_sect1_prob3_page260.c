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
    uint32_t heads = 0;
    uint32_t tails = 0;
    
    // start with seperation so results are easier to see
    printf("\n");
    printf("flip a coin 1000 times, results are:\n");

    // start randomness with current time
    srand((unsigned) time(&t));

    // go through 1000 coins and find probability of each heads and tails
    for (int i = 0; i < 1000; i++) {
        if (((rand() % 2) + 1) == 2) {
            heads++;
        } else {
            tails++;
        }
    }
    printf("heads: %d\n", heads);
    printf("tails: %d\n", tails);
    
    printf("\n");
    printf("now let's flip a coin 5 times and find out how many times heads lands 3 times:\n");
    uint32_t five_flips[100][5];

    // initialize all the coin flips to -1
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 5; j++) {
            five_flips[i][j] = 0;
        }
    }

    // now add a coin value for each
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 5; j++) {
            five_flips[i][j] = ((rand() % 2) + 1);
        }
    }

    // let's print them for funzies
    int num3Heads = 0;
    int num3PlusHeads = 0;
    for (int i = 0; i < 100; i++) {
        int numHeads = 0;
        for (int j = 0; j < 5; j++) {
            if (five_flips[i][j] == 2) {
                numHeads++;
            }
            printf("%c, ", five_flips[i][j]==1?'H':'T');
        }
        if (numHeads == 3) { num3Heads++; }
        if (numHeads >= 3) { num3PlusHeads++; }
        printf("\n"); // new line for each five flips
    }

    // print results
    printf("number of 3 heads: %d, which gives P(H) = %f\n", num3Heads, (float)num3Heads/100);
    printf("number of at least 3 heads: %d, which gives P(H) = %f\n", num3PlusHeads, (float)num3PlusHeads/100);

    // some space
    printf("\n");
}
}