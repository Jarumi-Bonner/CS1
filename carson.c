//Carson Gedeus
//COP-3502 Assignment
//01-24-2015
#include<stdio.h>
#include<stdlib.h>
#define CUBE 3
#define SIZE 9

int checkRows(int multiDimension[][SIZE])
{
    //Initializing the variables
    int i, j;
    //Creating a frequency array
    for(i=0; i<SIZE; i++)
    {
        //setting frequencies to 0
        int getFreq[SIZE+1];

        for(j=0; j<=SIZE; j++)
            getFreq[j]=0;

        for(j=0; j<SIZE; j++)
            getFreq[multiDimension[i][j]]++;

        for(j=1; j<=SIZE; j++)
            if(getFreq[j] != 1)
                return 0;
        }
        printf("test1");
    return 1;
}









int checkColumns(int multiDimension[][SIZE])
{
    //Initializing the variables
    int j, i;
    //setting a frequency array
    for(i=0; i<SIZE; i++){
        int getFreq[SIZE+1];
    //Frequency array to make sure each integer is included exactly once
    for(j=0; j<=SIZE; j++)
        getFreq[j] = 0;

    for(j=0; j<SIZE; j++)
        getFreq[multiDimension[j][i]]++;

    for(j=1; j<=SIZE; j++)
        if(getFreq[j]!=1)
        return 0;
        //If incorrect return 0
    }
    //If valid return 1
            printf("test2");
    return 1;
}









int checkBoxes(int multiDimension[][SIZE], int ROW, int COLUMN)
{
    //Initializing the variables
    int i, j, getFreq[SIZE+1];
    for(i=0; i<=SIZE; i++){
        getFreq[i] = 0;

    for(i=ROW; i<ROW+CUBE; i++)
        for(j=COLUMN; j<COLUMN+CUBE; j++)
        getFreq[multiDimension[i][j]]++;

    for(i=1; i<=SIZE; i++)
        if(getFreq[i] != 1)
            return 0;
    }
//return 1 if correct
        printf("test3");
    return 1;
}










int checkOverall(int multiDimension[][SIZE])
{
    int i, j;
//Functions checks to see if the results in the boxes are all unique
    for(i=0; i<SIZE; i+=CUBE)
        for(j=0; j<SIZE; j+=CUBE)
            if(!checkBoxes(multiDimension, i, j))
            return 0;
                    printf("test4");
    return 1;
}









int checkAll(int multiDimension[][SIZE])
{//Function checks to see if all the row, columns, and squares are correct
            printf("test5");
    return checkRows(multiDimension) && checkColumns(multiDimension) && checkOverall(multiDimension);
}









int main(){
    //A for loop to print the amount of sets we have
        //Initializing the variables
    int i, j, k, set;
    //Scans in all the integers from sudoku
    int row[SIZE][SIZE];
    char line[SIZE+1];
    printf("How many set?\n");
    scanf("%d", &set);
    for(i=0; i<set; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            scanf("%s", line);

            for(k=0; k<SIZE; k++)
                row[j][k] = line[k] - '0';
        }
        //Calling the checkAll function
        if(checkAll(row))
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
return 0;
}
