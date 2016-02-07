#include <stdio.h>
#include <stdlib.h>

#define limit 104730 /*size of integers array*/

int* findPrime();
int primeSum(int times, int cases[], int* primeNum);
int * primes;

int main(){
    int t, n, i;
    int *arr2 = malloc(sizeof(int)*10000);

    scanf("%d", &t);
    int *arr = malloc(sizeof(int)*t);

    for(i=0; i<t; i++){
        scanf("%d", &n);
        arr[i] = n;
    }



  //  memcpy(arr2, primes, sizeof(primes));
    //    printf("%d-\n", arr2[4]);
        printf("Test1\n");

    primeSum(t, arr, findPrime());
        printf("Test2\n");
    free(arr);
return 0;
}

int* findPrime(){
    unsigned long long int i,j;
  //  int *primes;
    int z = 1;

    primes = malloc(sizeof(int) * limit);

    for (i = 2;i < limit; i++)
        primes[i] = 1;

    for (i = 2;i < limit; i++)
    {
        if (primes[i])
            for (j = i;i * j < limit; j++)
                primes[i * j] = 0;
    }
//printf("%d*\n", primes[0]);

    printf("\nPrime numbers in range 1 to 100 are: \n");
    for (i = 2;i < limit; i++)
    {
        if (primes[i])
            printf("%d\n", i);
    }

return primes;
}


int primeSum(int times, int *cases, int *primeNum){
int i, j, res =0;

  printf("Test7\n");
        printf("%d----\n", primeNum[3]);
    for(i=0; i<times; i++){
        for(j=0; j<cases[i]; j++){
                    printf("Test6\n");
            res += primeNum[i];
            printf("%d\n", res);
        }
    }

    printf("Test3\n");
return 0;
}
