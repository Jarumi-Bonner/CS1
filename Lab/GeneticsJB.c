//Jarumi Bonner COP3502-Arup Guha RP2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int toBaseFour(int b, char letters[]){

    int length, num=0, convert, *rem, i = 0, j = 0; //Declare variables
    char arr1[4] = {'A', 'C', 'G', 'T'}; //Make an array that holds the letters we need

    rem = malloc(sizeof(int)*32);

    convert = atoi(letters);

    while(1)
    {
        rem[num] = convert%4; //Mod the number and collect the remainder
        convert = convert/4;  //Divide the number and get rid of the remainder
        num++;//Takes the size of the array
        if(convert < 1){
            break; //Once it is lower than O break out of loop
        }
    }

    printf("Sequence #%d: ", b); //print out the converted base 10 to 4
    for (i = num-1; i >= 0; i--) { //Go in reverse order in array to print out
        printf("%c", arr1[rem[i]]); //print out the proper char
    }
    printf("\n");
return 0;
}


int toBaseTen(int a, char *gene){
int product = 4;

    int i, j, length, convert, res =0, baseTen=0; //Declare all the variables
    char arr1[5] = {'A', 'C', 'G', 'T'}; //Make an array that holds the letters we need

    length = strlen(gene); //figure out the length of the string that has come in to use in for loop
    for(i=0; i<length; i++){
        for(j=0; j<=3; j++){
            if(gene[i] == arr1[j])
            {            gene[i] = j + '0'; //loop through array and convert the letter to number by ascii table
            }
        }
    }

    printf("Sequence #%d: ", a); //print out the number base 4 to 10
    for(i=0; i<length; i++){
        gene[i] = gene[i] - '0'; //make int so you can convert to base 10
        baseTen += gene[i]*pow(product, length-1-i); //use the base and then the power function to generate new number
    }
    printf("%d\n", baseTen); //print out new num.
return gene;
}


int main(){
char input[15]; //create a char array to hold the everything you're bringing in
int n, t, i; //declare variables

    scanf("%d", &t); //scan in times of cases
    int *arr = malloc(sizeof(int)*t); //malloc size of array

    for(i=0; i<t; i++){
        scanf("%s", input); //scan input as string
        arr[i] = input; //set the array to the input
        if(isalpha(input[0])){
        toBaseTen(i+1, input);//if it is an alpha send to base 4 to 10 func
        }
        else
        toBaseFour(i+1, input); //else send string to base 4 to 10 func
    }
    free(arr); //free the array
return 0;
}
