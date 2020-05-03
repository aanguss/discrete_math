/** Chapter 1 - Counting
 *  Section 1 - Basic Counting
 *  Problem 1 - Page 8
 *  Description -
 *      The following segment of code is part of a program 
 *      that uses insertion sort to sort a list A.
 *          for i = 2 to n
 *              j=i
 *              while(j ≥ 2)and(A[j] < A[j-1])
 *                  exchange A[j] and A[j-1]
 *                  j = j - 1
 *      What is the maximum number of times (considering all 
 *      lists of n items that you could be asked to sort) the 
 *      program makes the comparison A[j] < A[j-1]?  Describe 
 *      as succinctly as you can those lists that require this 
 *      number of comparisons.
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
    // min eval - in order
    int A_min[7] = {0, 1, 2, 3, 5, 7, 10};
    int n_min = sizeof(A_min)/sizeof(int);
    // max eval - out of order
    int A_max[7] = {0, 1, 10, 7, 5, 3, 2};
    int n_max = sizeof(A_max)/sizeof(int);

    // find number of while evaluations for ordered array
    numEvaluations = sortAndCount("A_min", &A_min[0], n_min);
    printf("number of times while was evaluated: %d\n", numEvaluations);
    
    // find number of while evaluations for max unordered array
    numEvaluations = sortAndCount("A_max", &A_max[0], n_max);
    printf("number of times while was evaluated: %d\n", numEvaluations);

    return 0;
}