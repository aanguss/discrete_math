/** 
 * Chapter 6 - Graphs
 * Section 1 - Graphs
 * Problem 1 - Page 373
 * Description -
 *  Find a shortest path from vertex 1 to vertex 5 in Figure 6.8 (below).
 */

/** 
 * Chapter 6 - Graphs
 * Section 1 - Graphs
 * Problem 1 - Page 373
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
    // a variable to signify that we found vertex 5
    // bool fiveFound = false;

    // variable to keep track of current location and goal location
    int currentVertex = 1;
    int goalVertex = 5;
    int nextVertex = 0;
    int pathLength = 0;
    int shortestPath = 100; // start with a very high number
    int currentSequence[100];
    int shortestSequence[100];
    int stepIndex = 0; // keep track of indexes of steps

    // will be using time for randomness of choice
    time_t t;

    // all available vertice choices from a given vertex, will not be
    // using [0][x] so that it easier to keep track of graph vertices
    uint32_t connectedVertex[13][13];

    // first mark all locations invalid
    for(int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            connectedVertex[i][j] = 0;
        }
    }

    // initialize sequence arrays to 0
    for (int i = 0; i < 100; i++) {
        currentSequence[i] = 0;
        shortestSequence[i] = 0;
    }

    // now mark all valid locations as a value of 1
    // vertex 1
    connectedVertex[1][2] = 1;
    connectedVertex[1][11] = 1;
    connectedVertex[1][12] = 1;

    // vertex 2
    connectedVertex[2][1] = 1;
    connectedVertex[2][3] = 1;
    connectedVertex[2][8] = 1;
    connectedVertex[2][9] = 1;
    connectedVertex[2][10] = 1;
    connectedVertex[2][11] = 1;
    connectedVertex[2][12] = 1;

    // vertex 3
    connectedVertex[3][2] = 1;
    connectedVertex[3][4] = 1;

    // vertex 4
    connectedVertex[4][3] = 1;
    connectedVertex[4][5] = 1;

    // vertex 5
    connectedVertex[5][4] = 1;
    connectedVertex[5][6] = 1;
    connectedVertex[5][7] = 1;

    // vertex 6
    connectedVertex[6][5] = 1;
    connectedVertex[6][7] = 1;
    connectedVertex[6][8] = 1;
    connectedVertex[6][10] = 1;

    // vertex 7
    connectedVertex[7][5] = 1;
    connectedVertex[7][6] = 1;
    connectedVertex[7][8] = 1;
    connectedVertex[7][9] = 1;
    connectedVertex[7][11] = 1;

    // vertex 8
    connectedVertex[8][2] = 1;
    connectedVertex[8][6] = 1;
    connectedVertex[8][7] = 1;
    connectedVertex[8][9] = 1;
    connectedVertex[8][10] = 1;

    // vertex 9
    connectedVertex[9][2] = 1;
    connectedVertex[9][7] = 1;
    connectedVertex[9][8] = 1;
    connectedVertex[9][10] = 1;
    connectedVertex[9][11] = 1;
    connectedVertex[9][12] = 1;

    // vertex 10
    connectedVertex[10][2] = 1;
    connectedVertex[10][6] = 1;
    connectedVertex[10][8] = 1;
    connectedVertex[10][9] = 1;

    // vertex 11
    connectedVertex[11][1] = 1;
    connectedVertex[11][2] = 1;
    connectedVertex[11][7] = 1;
    connectedVertex[11][9] = 1;
    connectedVertex[11][12] = 1;

    // vertex 12
    connectedVertex[12][1] = 1;
    connectedVertex[12][2] = 1;
    connectedVertex[12][9] = 1;
    connectedVertex[12][11] = 1;

    // start with seperation so results are easier to see
    printf("\n");

    // start randomness with current time
    srand((unsigned) time(&t));

    // print to verify we are getting random values between 1 and 12
    for (int i = 0; i < 100; i++) {
        printf("%d ", ((rand() % 12) + 1));
    }

    // iterate this 100 times and find keep track of the smallest route
    for (int i = 0; i < 100; i++) {
        pathLength = 0;
        currentVertex = 1;
        stepIndex = 0;
        // reset currentSequence
        for (int i = 0; i < 100; i++) {
            currentSequence[i] = 0;
        }
        currentSequence[stepIndex] = currentVertex;
        // print starting vertex
        printf("\nStarting vertex is 1, the random path to 5 is:\n");
        printf("%d, ", currentVertex);
        while (currentVertex != 5) {
            pathLength += 1;
            while (1) { // keep doing random choices till a valid one is found
                nextVertex = ((rand() % 12) + 1);
                if (connectedVertex[currentVertex][nextVertex] == 1) {
                    currentVertex = nextVertex;
                    currentSequence[stepIndex++] = currentVertex;
                    printf("%d, ", currentVertex);
                    break;
                }
            }
        }
        printf("path length = %d", pathLength);
        if (pathLength < shortestPath) {
            shortestPath = pathLength;
            // save sequence of steps
            for (int i = 0; i < 100; i++) {
                shortestSequence[i] = currentSequence[i];
            }
        }
    }
    
    // print results
    printf("\n\n");
    printf("After 100 iterations, the shortest path was the length of %d\n", shortestPath);
    printf("1"); // starting vertex
    for (int i = 0; i < 100; i++) {
        if (shortestSequence[i] == 0) {
            break;
        }
        printf("->%d", shortestSequence[i]);
    }

    // some space
    printf("\n");
}