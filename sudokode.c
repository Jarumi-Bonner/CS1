//Jarumi Bonner
//COP 3502 Program 1
//01-24-2015
#include<stdio.h>
#include<stdlib.h>

#define SQUARE 3
#define SIZE 9

int puzzleCorrect(int game[][SIZE]){

    return rowCheck(game) && columnCheck(game) && entireBox(game);
}



int rowCheck(int game[][SIZE]){
    //Initializing the variables
    int i, j;

    for(i=0; i<SIZE; i++){
        //setting frequencies to 0
        int freq[SIZE+1];

        for(j=0; j<=SIZE; j++)
            freq[j]=0;

        for(j=0; j<SIZE; j++)
            freq[game[i][j]]++;

        for(j=1; j<=SIZE; j++)
            if(freq[j] != 1)
                return 0;
        }

    return 1;
}



int columnCheck(int game[][SIZE])
{
    //Initializing the variables
    int i, j;
    //setting a frequency array
    for(j=0; j<SIZE; j++){
        int freq[SIZE+1];

    for(i=0; i<=SIZE; i++)
        freq[i] = 0;

    for(i=0; i<SIZE; i++)
        freq[game[i][j]]++;

    for(i=1; i<=SIZE; i++)
        if(freq[i]!=1)
        return 0;
    }
    return 1;
}



int boxCheck(int game[][SIZE], int ROW, int COLUMN)
{
    //Initializing the variables
    int i, j, Freq[SIZE+1];
    for(i=0; i<=SIZE; i++)
        Freq[i] = 0;

    for(i=ROW; i<ROW+SQUARE; i++)
        for(j=COLUMN; j<COLUMN+SQUARE; j++)
        Freq[game[i][j]]++;

    for(i=1; i<=SIZE; i++)
        if(Freq[i] != 1)
            return 0;

    return 1;
}



int entireBox(int game[][SIZE])
{
    int i, j;

    for(i=0; i<SIZE; i+=SQUARE)
        for(j=0; j<SIZE; j+=SQUARE)
            if(!boxCheck(game, i, j))
            return 0;

    return 1;
}


int main(){

    //A for loop to print the amount of sets we have
    int i, j, k, key;
    int puzzle[SIZE][SIZE];
    char line[SIZE+1];

    scanf("%d\n", &key);
    for(i=0; i<key; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            scanf("%s", line);

            for(k=0; k<SIZE; k++)
                puzzle[j][k] = line[k] - '0';//Turning strings into int
        }

        if(puzzleCorrect(puzzle)== 1){

            printf("\nYES\n");
        }
        else
            printf("\nNO\n");
    }
    return 0;
}
