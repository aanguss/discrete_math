/** 
 * Chapter 5 - Probability
 * Section 5 - Probability Calculations in Hashing
 * Problem 1 - Page 321
 * Description -
 A candy machine in a school has d different kinds of candy. Assume (for simplicity) that all these kinds of candy are equally popular and there is a large supply of each. Suppose that c children come to the machine, and each child purchases one package of candy. One of the kinds of candy is a Snackers bar. 
a. What is the probability that any given child purchases a Snackers bar? 
b. Let Yi be the number of Snackers bars that Child i purchases—Yi is either 0 or 1. What is the expected value of Yi ? 
c. LetY be the random variable Y1 +Y2 +···+Yc. What is the expected value of Y ? 
d. What is the expected number of Snackers bars that are purchased? 
e. Does the same result apply to any of the varieties of candy?

 */

/** 
 * Chapter 5 - Probability
 * Section 5 - Probability Calculations in Hashing
 * Problem 1 - Page 321
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