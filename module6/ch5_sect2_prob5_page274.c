/** 
 * Chapter 5 - Probability
 * Section 2 - Unions and Intersections
 * Problem 5 - Page 274
 * Description -  
 *  Remove one card from an ordinary deck of 52 cards. What is the probability
 *  that it is an ace, a diamond, or black?
 */

/** 
 * Chapter 5 - Probability
 * Section 2 - Unions and Intersections
 * Problem 5 - Page 274
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main(void)
{
    //Grab random card and check probability over 1000 draws
    time_t t;
    uint32_t iterations = 1000;
    uint32_t cardDraws[iterations]; // 100 iterations, 4 types, 13 of each
    uint32_t black = 0;
    uint32_t diamond = 0;
    uint32_t ace = 0;
    uint32_t diamond_ace = 0;
    uint32_t black_ace = 0;
    uint32_t black_or_diamond_or_ace = 0;
    
    // start with seperation so results are easier to see
    printf("\n");
    printf("draw from %d fresh decks and track the card pulled:\n", iterations);

    // start randomness with current time
    srand((unsigned) time(&t));

    // null out all values in deck
    for (int i = 0; i < iterations; i++) {
        cardDraws[i] = 0;
    }

    // null out all values in deck
    for (int i = 0; i < iterations; i++) {
        cardDraws[i] = (rand() % 53) + 1;
        // clubs 1 - 13
        // spades 14 - 26
        // diamonds 27 - 39
        // hearts 40 - 52
        if (cardDraws[i] >= 1 && cardDraws[i] <= 13) {
            black++;
            black_or_diamond_or_ace++;
            if (cardDraws[i] == 13) {
                ace++;
                black_ace++;
            }
        } else if (cardDraws[i] >= 14 && cardDraws[i] <= 26) {
            black++;
            black_or_diamond_or_ace++;
            if (cardDraws[i] == 26) {
                ace++;
                black_ace++;
            }
        } else if (cardDraws[i] >= 27 && cardDraws[i] <= 39) {
            diamond++;
            black_or_diamond_or_ace++;
            if (cardDraws[i] == 39) {
                ace++;
                diamond_ace++;
            }
        } else if (cardDraws[i] >= 40 && cardDraws[i] <= 52) {
            if (cardDraws[i] == 52) {
                ace++;
                black_or_diamond_or_ace++;
            }
        }
    }

    // let's print all the values out
    for (int i = 0; i < iterations; i++) {
        printf("%d, ", cardDraws[i]);
    }

    printf("\n");
    printf("found results for each type:\n");
    printf("ace card: %d, gives P(ace) = %f\n", ace, (float)ace/iterations);
    printf("black card: %d, gives P(black) = %f\n", black, (float)black/iterations);
    printf("black ace card: %d, gives P(black_ace) = %f\n", black_ace, (float)black_ace/iterations);
    printf("diamond card: %d, gives P(diamond) = %f\n", diamond, (float)diamond/iterations);
    printf("diamond ace card: %d, gives P(diamond_ace) = %f\n", diamond_ace, (float)diamond_ace/iterations);
    printf("black or diamond or ace card: %d, gives P(black_or_diamond_or_ace) = %f\n", black_or_diamond_or_ace, (float)black_or_diamond_or_ace/iterations);

    // some space
    printf("\n");
}