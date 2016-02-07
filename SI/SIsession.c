#include <stdio.h>

#define ARR_SIZE 3

int main() {

    int rows = ARR_SIZE;
    int cols = ARR_SIZE;
    int i, j;

    const char words[ARR_SIZE][ARR_SIZE] = { {'b', 'p', 'z'}, {'t', 'o', 'z'},{'q', 'z', 'b'}};

    // Algorithm analysis

    // n is the side length of our array
    // when n = 3, this runs 3*3 times.
    // what if n = 1000
    // This algorithm is O(n^2)

    // O(n*10)
    for(i=0; i < ARR_SIZE; i++) {
        for(j=0; j < ARR_SIZE; j++) {
            printf(" %c", words[i][j]);
        }
        printf("\n");
    }

    /*

    // O(4*10)
    // O(1)
    for(i=0; i < ARR_SIZE; i++)
        for(j=0; j < ARR_SIZE; j++)
            //
     */



    // How many iterations

    // given some values of i, and j, print all of the values around it
    i=0;
    j=0;

    /*

    const int DX_SIZE = 8;
    const int DX[] = {-1,-1,-1, 0,0, 1,1,1};
    const int DY[] = {-1, 0, 1,-1,1,-1,0,1};



    (0,0) // printf("%c", words[0][0]);
    (0,1)
    (0,2)
    (1,0)
    (1,2)
    (2,0)
    (2,1)
    (2,2)
    */

    printf("All the characters around index (%d,%d) are: \n", i, j);

    const int DX_SIZE = 8;
    const int DX[] = {-1,-1,-1, 0,0, 1,1,1};
    const int DY[] = {-1, 0, 1,-1,1,-1,0,1};

    int k;

    // Algorithm analysis
    for (k=0; k<DX_SIZE; k++) {
        int nextX = i + DX[k];
        int nextY = j + DY[k];

        if(nextX < 0 || nextX >= ARR_SIZE) continue;
        if(nextY < 0 || nextY >= ARR_SIZE) continue;

        printf("Index (%d, %d) is %c\n", nextX, nextY, words[nextX][nextY]);
    }



    return 0;
}
