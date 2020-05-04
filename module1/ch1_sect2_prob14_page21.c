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

/* sort algorithm given by problem and return number of evals*/
int sortAndCount(char * name, int *array, int size) {
    int i, j, numEvaluations = 0;

    for (i = 2; i <= size; i++) {
        j = i;
        printArray(name, &array[0], size);
        while (j >= 2 && (array[j] < array[j-1])) {
            // increment number of evaluations of while loop
            numEvaluations++;

            // swap values
            array[j] = array[j] ^ array[j-1];
            array[j-1] = array[j] ^ array[j-1];
            array[j] = array[j] ^ array[j-1];
            j = j - 1;
        }
    }
    
    return numEvaluations;
}

/* find max evaluations for two lists and print results */
int main(void) {
    int numEvaluations = 0;
    // max eval - out of order
    int A_max[7] = {0, 1, 10, 7, 5, 3, 2};
    int n_max = sizeof(A_max)/sizeof(int);

    // find number of while evaluations for ordered array
    numEvaluations = sortAndCount("A_min", &A_min[0], n_min);
    printf("number of times while was evaluated: %d\n", numEvaluations);
    
    return 0;
}