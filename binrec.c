// Arup Guha
// 9/15/2015
// Recursive binary search written in COP 3502 class.

#include <stdio.h>

int binsearch(int low, int high, int searchVal, int array[]);

int main() {

    // Test array.
    int numbers[] = {2,4,5,6,10,20,30,40,44,45,47,48,50,60,71,72,78,92,1245,826321};

    // Search for different values in it.
    int i;
    for (i=0; i<1000000; i++) {
        if (binsearch(0, 19, i, numbers))
            printf("I found %d\n", i);
    }

    return 0;
}

// Pre-condition: array is sorted from smallest to largest is has length elements.
// Post-condition: returns 1 iff searchVal is in array[low..high], 0 otherwise.
int binsearch(int low, int high, int searchVal, int array[]) {

    if (low > high) return 0;
    int mid = (low+high)/2;

    // my value is smaller than the one in index mid.
    if (searchVal < array[mid])
        return binsearch(low, mid-1, searchVal, array);

    // here it's larger
    else if (searchVal > array[mid])
        return binsearch(mid+1, high, searchVal, array);

    // found it!
    else
        return 1;
}
