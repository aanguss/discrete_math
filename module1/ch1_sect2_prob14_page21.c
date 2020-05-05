/** 
 * Chapter 1 - Counting
 * Section 2 - Counting Lists, Permutations, and Subsets
 * Problem 14 - Page 21
 * Description -
    At the local ice cream shop, you may get a three-way 
    sundae with up to three of the 10 flavors of ice cream; 
    any one of three flavors of topping; and any (or all, 
    some, or none) of whipped cream, nuts, and a cherry. 
    How many different sundaes are possible? (In accordance 
    with your mother’s rule from Problem 11 in Section 1.1, 
    the way the scoops sit in the dish does not matter.)
 */

/** 
 * Chapter 1 - Counting
 * Section 1 - Basic Counting
 * Problem 1 - Page 8
 */
#include <stdio.h>

/* print array helper function */
void printArray(char * name, int *array, int size) {
    printf("%s[%d] = ", name, size);
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/* find max evaluations for two lists and print results */
int main(void) {
    // keep track of the number of combinations
    int numCombinations = 0;
    
    // 10 flavors, simply noted from #0 to #9
    int iceCream[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int iceCreamSize = sizeof(iceCream) / sizeof(int);
    int iceCreamAllowed = 3;
    int iceCreamCombinations[1000];
    
    // choose 3 ice cream flavor - first flavor
    for (int i = 0; i < iceCreamAllowed; i++) {
        // second flavor
        for (int j = 0; j < iceCreamSize; j++) {
            // third flavor
            for (int k = 0; k < iceCreamSize; k++) {
                printf("%d%d%d ", iceCream[i], iceCream[j], iceCream[k]);
                numCombinations;                
            }   
        }
    }
    
    printf("number of sundae combinations: %d\n", numCombinations);
    
    return 0;
}