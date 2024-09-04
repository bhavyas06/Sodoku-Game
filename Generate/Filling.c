#include "Filling.h"

void fillValues(Sudoku *sudoku) {
    fillDiagnols(sudoku);
    fillRemaining(sudoku, 0, sudoku->M);
    removeDigits(sudoku);
}

void fillDiagnols(Sudoku *sudoku) {
    for(int i=0; i<sudoku->N; i = i+sudoku->M)
        fillBox(sudoku, i, i);
}

void fillBox(Sudoku *sudoku, int row, int col) {
    srand(time(NULL));
    int num;
    for(int i=0; i<sudoku->M; i++) {
        for(int j=0; j<sudoku->M; j++) {
            do {
                num = randomGenerator(sudoku->N);
            } while(!unUsedInBox(sudoku, row, col, num));
            sudoku->grid[row+i][col+j] = num;
        }
    }
}

int fillRemaining(Sudoku* sudoku, int i, int j) {
    if (j >= sudoku->N && i < sudoku->N - 1) {
        i = i + 1;
        j = 0;
    }

    if (i >= sudoku->N && j >= sudoku->N)
        return 1;

    if (i < sudoku->M) {
        if (j < sudoku->M)
            j = sudoku->M;
    } 
    else if (i < sudoku->N - sudoku->M) {
        if (j == (int)(i / sudoku->M) * sudoku->M)
            j = j + sudoku->M;
    } 
    else {
        if (j == sudoku->N - sudoku->M) {
            i = i + 1;
            j = 0;
            if (i >= sudoku->N)
                return 1;
        }
    }

    for (int num = 1; num <= sudoku->N; num++) {
        if (CheckIfSafe(sudoku, i, j, num)) {
            sudoku->grid[i][j] = num;
            if (fillRemaining(sudoku, i, j + 1))
                return 1;
            sudoku->grid[i][j] = 0;
        }
    }
    
    return 0;
}