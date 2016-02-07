// Arup Guha
// Binary Search Example
// COP 3502 - Written in class 1/12/2016
// Also used to introduce malloc.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarysearch(int searchval, int* array, int length);
int* makeRandSortedArray(int length);

int main() {

    srand(time(0));

    /*** I CAN"T DO THIS
    int n;
    scanf("%d", &n);
    int numbers[n];
    ***/

    // Do this instead:
    int n, i;
    printf("How big do you want your array?\n");
    scanf("%d", &n);

    // Create a sorted array of numbers.
    int* numbers = makeRandSortedArray(n);

    // Search for first 100 numbers.
    for (i = 0; i<100; i++)
        if (binarysearch(i, numbers, n))
            printf("Found %d\n", i);

    for (i=0; i<30; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    free(numbers);

    return 0;
}

// Fills numbers[0..length-1] with random integers in sorted order.
int* makeRandSortedArray(int length) {

    int i;

    // Allocate space.
    int* numbers = malloc(sizeof(int)*length);

    // Fill the array.
    numbers[0] = rand()%20;
    for (i=1; i<length; i++)
        numbers[i] = numbers[i-1] + rand()%10 + 1;

    // Return a pointer to the front of the array.
    return numbers;
}

// Precondition: array is sorted.
// Returns 1 iff array[0..length-1] contains searchval. Returns 0 otherwise.
int binarysearch(int searchval, int* array, int length) {

    int low = 0, high = length-1;

    // Search while there is a valid search space.
    while (low <= high) {

        int mid = (low+high)/2;

        // Value is too small.
        if (searchval < array[mid])
            high = mid-1;

        // too big.
        else if (searchval > array[mid])
            low = mid+1;

        // found it!
        else
            return 1;
    }

    // Never found it.
    return 0;

}
