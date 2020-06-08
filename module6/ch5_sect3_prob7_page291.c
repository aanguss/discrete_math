/** 
 * Chapter 5 - Probability
 * Section 3 - Conditional Probability and Independence
 * Problem 7 - Page 291
 * Description - 
 *  A nickel, two dimes, and two quarters are in a cup. You draw three 
 *  coins, one at a time, without replacement. Draw the tree diagram 
 *  that represents the process. Use the tree to determine the probability
 *  of getting a nickel on the last draw. Use the tree to determine the 
 *  probability that the first coin is a quarter, given that the last coin
 *  is a quarter.
 */

/** 
 * Chapter 5 - Probability
 * Section 3 - Conditional Probability and Independence
 * Problem 7 - Page 291
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

#define TRUE 1

int main(void)
{
    //Simulate the randomness of getting the coins out… and output
    time_t t;
    uint32_t iterations = 1000;
    uint32_t coinDraws[iterations][5]; // each fresh cup will have 5 coins
    uint32_t lastQuarter = 0;
    uint32_t lastDime = 0;
    uint32_t lastNickel = 0;
    uint32_t quartersLeft = 2;
    uint32_t nickelsLeft = 1;
    uint32_t dimesLeft = 2;
    
    // start with seperation so results are easier to see
    printf("\n");
    printf("draw from %d fresh cups and track the coils pulled:\n", iterations);

    // start randomness with current time
    srand((unsigned) time(&t));

    // null out all values in deck
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < 5; j++) {
            coinDraws[i][j] = 0;
        }
    }

    // let's draw coins and keep track of each available coin draw
    for (int i = 0; i < iterations; i++) {
        quartersLeft = 2;
        nickelsLeft = 1;
        dimesLeft = 2;
        for (int j = 0; j < 5; j++) {
            while(TRUE) {
                coinDraws[i][j] = (rand() % 5) + 1;
                // printf("%d", coinDraws[i][j]);
                if ((quartersLeft != 0) && (coinDraws[i][j] >= 1 && coinDraws[i][j] <= 2)) {
                    quartersLeft--;
                    if (dimesLeft == 0 && nickelsLeft == 0) {
                        lastQuarter++;
                    }
                    break;
                } else if ((nickelsLeft != 0) && (coinDraws[i][j] == 3)) {
                    nickelsLeft--;
                    if (quartersLeft == 0 && dimesLeft == 0) {
                        lastNickel++;
                    }
                    break;
                } else if ((dimesLeft != 0) && (coinDraws[i][j] >= 4 && coinDraws[i][j] <= 5)) {
                    dimesLeft--;
                    if (quartersLeft == 0 && nickelsLeft == 0) {
                        lastDime++;
                    }
                    break;
                }
            }
        }
        // printf("\n");
    }

    // print all results
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c", coinDraws[i][j]<=2?'Q':(coinDraws[i][j]==3?'N':'D'));
        }
        printf(", ");
    }

    // print probabilities
    printf("\n\n");
    printf("nickels were drawn last %d times, which gives a probability of %f\n", lastNickel, (float)lastNickel/iterations);    
   
    int lastPickedNickel = 0;
    int firstAndLastQuarter = 0;
    for (int i = 0; i < iterations; i++) {
        if (coinDraws[i][4] == 3) {
            lastPickedNickel++;
        }
        if ((coinDraws[i][0] <= 2) && (coinDraws[i][4] <= 2)) {
            firstAndLastQuarter++;
        }
    }

    printf("found last nickels: %d, which gives probability of %f\n", lastPickedNickel, (float)lastPickedNickel/iterations);
    printf("found first and last quarters: %d, which gives probability of %f\n", firstAndLastQuarter, (float)firstAndLastQuarter/iterations);

    // some space
    printf("\n");
}