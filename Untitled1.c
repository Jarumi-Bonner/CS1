// Arup Guha
// 8/31/2015
// Solution to COP 3502 Program #1: Sudokode

#include <stdio.h>

// Useful constants.
#define BOXSIZE 3
#define SIZE 9

// Function prototypes
int checkRows(int grid[][SIZE]);
int checkCols(int grid[][SIZE]);
int checkBox(int grid[][SIZE], int startRow, int startCol);
int checkBoxes(int grid[][SIZE]);
int validSudoku(int grid[][SIZE]);

int main() {

    // Get number of cases.
    int i, j, loop, numCases;
    scanf("%d", &numCases);

    // Process each case.
    for (loop=0; loop<numCases; loop++) {

        int grid[SIZE][SIZE];
        char line[SIZE+1];

        // Read in grid.
        for (i=0; i<SIZE; i++) {
            scanf("%s", line);
            for (j=0; j<SIZE; j++)
                grid[i][j] = line[j] - '0';
        }

        // Output the result.
        if (validSudoku(grid))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

// Returns 1 iff grid stores a valid Sudoku solution.
int validSudoku(int grid[][SIZE]) {
    return checkRows(grid) && checkCols(grid) && checkBoxes(grid);
}

// Pre-condition: grid is SIZE x SIZE and contains only ints 1 - 9.
// Post-conditions: Returns 1 iff each row in grid is a valid Sudoku row.
int checkRows(int grid[][SIZE]) {

    int i,j;

    // Try each row.
    for (i=0; i<SIZE; i++) {

        // Initialize frequencies to 0.
        int freq[SIZE+1];
        for (j=0; j<=SIZE; j++)
            freq[j] = 0;

        // Tally up each item in this row.
        for (j=0; j<SIZE; j++)
            freq[grid[i][j]]++;

        // Make sure each item occurs exactly once.
        for (j=1; j<=SIZE; j++)
            if (freq[j] != 1)
                return 0;
    }

    // If we get here, the rows are valid.
    return 1;
}

int checkCols(int grid[][SIZE]) {

    int i,j;

    // Try each column.
    for (j=0; j<SIZE; j++) {

        // Initialize frequencies to 0.
        int freq[SIZE+1];
        for (i=0; i<=SIZE; i++)
            freq[i] = 0;

        // Tally up each item in this column.
        for (i=0; i<SIZE; i++)
            freq[grid[i][j]]++;

        // Make sure each item occurs exactly once.
        for (i=1; i<=SIZE; i++)
            if (freq[i] != 1)
                return 0;
    }

    // If we get here, the columns are valid.
    return 1;
}

int checkBox(int grid[][SIZE], int startRow, int startCol) {

    // Initialize frequencies to 0.
    int i, j, freq[SIZE+1];
    for (i=0; i<=SIZE; i++)
        freq[i] = 0;

    // Mark each item in this box.
    for (i=startRow; i<startRow+BOXSIZE; i++)
        for (j=startCol; j<startCol+BOXSIZE; j++)
            freq[grid[i][j]]++;

    // Make sure each item occurs exactly once.
    for (i=1; i<=SIZE; i++)
        if (freq[i] != 1)
            return 0;

    // If we get here, we're good.
    return 1;
}

int checkBoxes(int grid[][SIZE]) {

    int i,j;

    // See if any box fails, if so, return 0.
    for (i=0; i<SIZE; i+=BOXSIZE)
        for (j=0; j<SIZE; j+=BOXSIZE)
            if (!checkBox(grid, i, j))
                return 0;

    // If we get here, the boxes are good.
    return 1;
}
