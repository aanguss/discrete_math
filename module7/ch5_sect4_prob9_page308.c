/** 
 * Chapter 5 - Probability
 * Section 4 - Random Variables
 * Problem 9 - Page 380
 * Description -
 *  How many times do you expect to have to roll a die until you see a six on
 *  the top face? 
 */

/** 
 * Chapter 5 - Probability
 * Section 4 - Random Variables
 * Problem 9 - Page 380
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

#define ATTEMPTS 1000 // number of roll attempts to average over

int main(void)
{
    //Random dice roll
    time_t t;
    int rollAttempts[ATTEMPTS];
    float averageRolls = 0;
    int rollCount = 0;

    // initialize all index to 0
    for (int i = 0; i < ATTEMPTS; i++)
    {
        rollAttempts[i] = 0;
    }

    // start with seperation so results are easier to see
    printf("\n");
    printf("roll a dice 1000 times until 6 is found, results are:\n");

    // start randomness with current time
    srand((unsigned)time(&t));

    // go through 1000 dice rolls and find how many rolls it takes to get a 6
    for (int i = 0; i < ATTEMPTS; i++)
    {
        rollCount = 1;
        while (((rand() % 6) + 1) != 6) {
            rollCount++;
        }
        rollAttempts[i] = rollCount;
        printf("rollCount #%d: %d, ", (i+1), rollCount);
        averageRolls += rollCount;
    }

    // print results
    printf("\n\naverage rollCount: %.2f\n", (averageRolls / ATTEMPTS));

    // some space
    printf("\n");
}