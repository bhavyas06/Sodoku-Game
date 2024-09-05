#include "SeeSolution.h"

// checks whether the number is present in row
bool UsedInRow(Sudoku *sudoku, int row, int num) {
    for (int col = 0; col < 9; col++)
        if (sudoku->grid[row][col] == num)
            return true;
    return false;
}

// checks whether the number is present in column
bool UsedInCol(Sudoku *sudoku, int col, int num){
    for (int row = 0; row < 9; row++)
        if (sudoku->grid[row][col] == num)
            return true;
    return false;
}

// checks whether the number is present in box
bool UsedInBox(Sudoku *sudoku, int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (sudoku->grid[row + startRow][col + startCol] == num)
                return true;
    return false;
}

// verifies all conditions
bool isSafe(Sudoku *sudoku, int row, int col, int num) {
    return !UsedInRow(sudoku, row, num) && !UsedInCol(sudoku, col, num) && 
           !UsedInBox(sudoku, row - row % 3, col - col % 3, num) && 
           sudoku->grid[row][col] == 0;
}

// checks whether any cell is remaining empty
bool FindLocation(Sudoku *sudoku, int *row, int *col) {
    for (*row = 0; *row < 9; (*row)++)
        for (*col = 0; *col < 9; (*col)++)
            if (sudoku->grid[*row][*col] == 0)
                return true;
    return false;
}

bool FullSolution(Sudoku *sudoku) {
    int row, col;
    if (!FindLocation(sudoku, &row, &col))
        return true;
    for (int num = 1; num <= 9; num++)  {
        if (isSafe(sudoku, row, col, num)) {
            sudoku->grid[row][col] = num;
            if (FullSolution(sudoku))
                return true;
            sudoku->grid[row][col] = 0;
        }
    }
    return false;
}

void seeSolution(Sudoku *sudoku) {
    if(FullSolution(sudoku))
        printGrid(sudoku);
    printf("\nYou lost. Game Over.\n\n");
    return;
}

// provides the menu when user inputs -1.
int escapeMenu(Sudoku *sudoku) {
    int op;
    while(op!=1 || op!=2 || op!=3) {
        printf("\nOptions:\n1. Quit     2. See Solution     3. Go back\n");
        // printf("Press '1' to quit and press '2' to see the solution\n");
        printf("Choose Option: ");
        scanf("%d", &op);
        printf("\n");
        switch(op) {
            case 1: printf("\nYou Quit. Game Over.\n\n"); return 0;
            case 2: seeSolution(sudoku); return 0;
            case 3: return 1;
            default: "\nInvalid Option. Choose Again.\n";
        }
    }
    
}
