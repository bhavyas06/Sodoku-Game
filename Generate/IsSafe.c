#include "IsSafe.h"

int unUsedInBox(Sudoku* sudoku, int rowStart, int colStart, int num) {
    for (int i = 0; i < sudoku->M; i++) {
        for (int j = 0; j < sudoku->M; j++) {
            if (sudoku->grid[rowStart + i][colStart + j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int unUsedInRow(Sudoku* sudoku, int i, int num) {
    for (int j = 0; j < sudoku->N; j++) {
        if (sudoku->grid[i][j] == num) {
            return 0;
        }
    }
    return 1;
}

int unUsedInCol(Sudoku* sudoku, int j, int num) {
    for (int i = 0; i < sudoku->N; i++) {
        if (sudoku->grid[i][j] == num) {
            return 0;
        }
    }
    return 1;
}

int CheckIfSafe(Sudoku* sudoku, int i, int j, int num) {
    return (unUsedInRow(sudoku, i, num) && unUsedInCol(sudoku, j, num) && unUsedInBox(sudoku, i - i % sudoku->M, j - j % sudoku->M, num));
}