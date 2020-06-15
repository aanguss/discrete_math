/** 
 * Chapter 5 - Probability
 * Section 7 - Probability Distributions and Variance
 * Problem 3 - Page 355
 * Description -
What are the variance and standard deviation for the sum of the tops of n dice that you roll?
 */

/** 
 * Chapter 5 - Probability
 * Section 7 - Probability Distributions and Variance
 * Problem 3 - Page 355
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