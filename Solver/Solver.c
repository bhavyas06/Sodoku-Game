#include "Solver.h"

bool FindUnassignedLocation(Sudoku *sudoku, int row, int col) {
    if (row > 8 || col > 8)
        return false;
    if (row < 0 || col < 0)
        return false;
    if (sudoku->grid[row][col] == 0)
        return true;
    return false;
}

bool SolveSudoku(Sudoku *sudoku, int row, int col, int num) {
    if (!FindUnassignedLocation(sudoku, row, col))
        return true;
    if (CheckIfSafe(sudoku, row, col, num)) {
        sudoku->grid[row][col] = num;
        if (SolveSudoku(sudoku, row, col, num))
            return true;
    }
    return false;
}

bool checkBounds(int row, int col, int num) {
    if(row<0 || col<0)
        return false;
    if(row>8 || col>8)
        return false;
    if(num<1 || num>9)
        return false;
    return true;
}