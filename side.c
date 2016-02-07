#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

const int DX_SIZE = 8;
const int DX[] = {-1,-1,-1,0,0,1,1,1};
const int DY[] = {-1,0,1,-1,1,-1,0,1};



int main(){
    int i, j, testCase, row, column;

    scanf("%d", &testCase);

    for(i=0; i<testCase; i++){

        scanf("%d %d", &row, &column);

        char line[column+1];

        for(j=0; j<row; j++){
        scanf("%s", line);
        printf("what you just scanned in: %s\n", line);
        }
        printf("new row and column\n");
        scanf("%d %d", &row, &column);

        printf("\n\n\n");
        printf("new row: %d, new column: %d\n", row, column);
        printf("\n\n\n");
    }
return 0;
}
