/** 
 * Chapter 5 - Probability
 * Section 4 - Random Variables
 * Problem 9 - Page 380
 * Description -
 * How many times do you expect to have to roll a die until you see a six on the top face? 
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

int main(void)
{
   
    
    // start with seperation so results are easier to see
    printf("\n");
    

    // print results
    printf("\nnumber of 3 heads: %d, which gives P(H) = %f\n", num3Heads, (float)num3Heads/100);
    printf("number of at least 3 heads: %d, which gives P(H) = %f\n", num3PlusHeads, (float)num3PlusHeads/100);

    // some space
    printf("\n");
}