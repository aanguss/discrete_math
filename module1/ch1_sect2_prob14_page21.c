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

/* find max evaluations for two lists and print results */
int main(void) {
    // keep track of the number of combinations
    int totalCombinations = 0;
    
    // 10 flavors, simply noted from #0 to #9
    int iceCream[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int iceCreamSize = sizeof(iceCream) / sizeof(int);
    int iceCreamCombinations;
    
    // 3 final toppings, noted #0 to #2
    int finalTopping[3] = {0, 1, 2};
    int finalToppingSize = sizeof(finalTopping) / sizeof(int);
    int finalToppingCombinations;

    // 3 options for second layer
    int secondLayerSize = 3;
    
    // choose 3 ice cream flavors - it can be the same flavor for each
    printf("\nICE-CREAM_SECOND-LAYER_FINAL-TOPPINGS:\n");
    // first flavor
    for (int i = 0; i < iceCreamSize; i++) {
        // second flavor
        for (int j = i; j < iceCreamSize; j++) {
            // third flavor
            for (int k = j; k < iceCreamSize; k++) {
                // second layer to choose from
                for (int secondLayer = 0; secondLayer < secondLayerSize; secondLayer++) {
                    // final layer of toppings
                    // select no toppings
                    printf("%d%d%d_%d_xxx ", iceCream[i], iceCream[j], iceCream[k], secondLayer);
                    totalCombinations++;

                    // choose 2 of the final toppings - one or two
                    // first option
                    for (int finalTopping1 = 0; finalTopping1 < finalToppingSize; finalTopping1++) {
                        // second options
                        for (int finalTopping2 = finalTopping1; finalTopping2 < finalToppingSize; finalTopping2++) {
                            printf("%d%d%d_%d_%d%d ", iceCream[i], iceCream[j], iceCream[k], secondLayer, finalTopping1, finalTopping2);
                            totalCombinations++;
                        }
                    }

                    // select all 3 toppings
                    printf("%d%d%d_%d_012 ", iceCream[i], iceCream[j], iceCream[k], secondLayer);
                    totalCombinations++;
                }      
            }   
        }
    }

    printf("\nnumber of sundae combinations: %d\n", totalCombinations);
    
    return 0;
}