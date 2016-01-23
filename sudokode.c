//Jarumi Bonner
//COP-3502 Program 1
//01-24-2015
#include<stdio.h>
#include<stdlib.h>

#define SIZE 9

int main(){

    //A for loop to print the amount of sets we have
    int i, j, k, column, set;
    int row[SIZE][SIZE];
    char line[SIZE+1];

    printf("How many set?\n");
    scanf("%d\n", &set);
    for(i=0; i<set; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            scanf("%s", line);

            for(k=0; k<SIZE; k++)
                row[j][k] = line[k] - '0';//Turning strings into int
        }
    }
return 0;
}







/*
void checkRows(int line2[a][b])
{

}






void checkColumns()
{

}







void checkBoxes()
{

}








void Overall()
{

}








void freqArray()
{

}
*/







