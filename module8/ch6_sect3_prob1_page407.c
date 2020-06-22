/** 
 * Chapter 6 - Graphs
 * Section 3 - Eulerian and Hamiltonian Graphs
 * Problem 1 - Page 407
 * Description -
 *  For each graph in Figure 6.24, either explain why the graph does not
 *  have an Eulerian circuit or find an Eulerian circuit.
 */

/** 
 * Chapter 6 - Graphs
 * Section 3 - Eulerian and Hamiltonian Graphs
 * Problem 1 - Page 407
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>

int main(void)
{
    //Random roll a coin, this can be ran a lot to ensure larger averages
    time_t t;

    
    // start with seperation so results are easier to see
    printf("\n");
    printf("roll a dice 1000 times, results are:\n");

    // start randomness with current time
    srand((unsigned) time(&t));

    // go through 1000 rolls and find the total for each face value rolled
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
    
    // some space
    printf("\n");
}