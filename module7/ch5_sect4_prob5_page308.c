/** 
 * Chapter 5 - Probability
 * Section 4 - Random Variables
 * Problem 5 - Page 380
 * Description -
 * Suppose I offer to play the following game with you if you will pay me some money. You roll a die, and I give you a dollar for each dot that is on top. What is the maximum amount of money a rational person might be willing to pay me to play this game?
 */

/** 
 * Chapter 5 - Probability
 * Section 4 - Random Variables
 * Problem 5 - Page 380
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main(void)
{
    //Random coin flip which outputs % of heads vs tails, this can be ran a lot to ensure larger averages
    time_t t;
    uint32_t dice[6];
    float totalValue;

    // initialize all index to 0
    for(int i = 0; i < 6; i++) {
        dice[i] = 0;
    }
    
    // start with seperation so results are easier to see
    printf("\n");
    printf("roll a dice 1000 times, results are:\n");

    // start randomness with current time
    srand((unsigned) time(&t));

    // go through 1000 coins and find probability of each heads and tails
    for (int i = 0; i < 1000; i++) {
        switch ((rand() % 6) + 1) {
            case 1:
                dice[0] += 1;
                totalValue += 1;
                break;
            case 2:
                dice[1] += 1;
                totalValue += 2;
                break;
            case 3:
                dice[2] += 1;
                totalValue += 3;
                break;
            case 4:
                dice[3] += 1;
                totalValue += 4;
                break;
            case 5:
                dice[4] += 1;
                totalValue += 5;
                break;
            case 6:
                dice[5] += 1;
                totalValue += 6;
                break;
            default:
                break;
        }
    }

    // print results
    for (int i = 0; i < 6; i++) {
        printf("rolled %d: %d\n", i+1, dice[i]);
    }
    printf("average roll (or $ made): %.2f\n", (float)(totalValue/1000));

    // some space
    printf("\n");
}