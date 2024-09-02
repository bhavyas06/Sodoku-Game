#include "Create.h"

Sudoku* createSudoku(int N, int diff) {
    Sudoku* sudoku = (Sudoku*)malloc(sizeof(Sudoku));
    sudoku->N = N;
    sudoku->diff = diff;
    double M1 = sqrt(N);
    sudoku->M = (int)M1;
    sudoku->grid = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        sudoku->grid[i] = (int*)malloc(N * sizeof(int));
        memset(sudoku->grid[i], 0, N * sizeof(int));
    }
    return sudoku;
}

void printGrid(Sudoku *sudoku) {
    for(int i=0; i<sudoku->N; i++) {
        for(int j=0; j<sudoku->N; j++) {
            printf("%d ", sudoku->grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}