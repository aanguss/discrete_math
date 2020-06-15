/** 
 * Chapter 5 - Probability
 * Section 6 - Conditional Expectations, Recurrences, and Algorithms
 * Problem 11 - Page 342
 * Description -
One idea often used in selection is that instead of choosing a random pivot element, we choose three random pivot elements and then use the median of these three as the pivot. What is the probability that a randomly chosen pivot element is in the middle half? What is the probability that the median of three randomly chosen pivot elements is in the middle half? Does this justify the choice of using the median of three elements as the pivot?
 */

/** 
 * Chapter 5 - Probability
 * Section 6 - Conditional Expectations, Recurrences, and Algorithms
 * Problem 11 - Page 342
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