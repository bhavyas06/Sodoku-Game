#include <math.h>
#include <string.h>
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

void removeDigits(Sudoku *sudoku) {
    int count = sudoku->diff;
    while (count != 0) {
        int cellId = randomGenerator(sudoku->N * sudoku->N) - 1;
        int i = (cellId / sudoku->N);
        int j = cellId % sudoku->N;
        if (sudoku->grid[i][j] != 0) {
            count--;
            sudoku->grid[i][j] = 0;
        }
    }
}

void printGrid(Sudoku *sudoku) {
    printf("  ");
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0)
            printf("  %d", i);
        else
            printf(" %d", i);
        if (i == 5 || i == 2)
            printf(" ");
    }
    printf("\n");

    for (int i = 0; i < sudoku->N; i++) {
        if (i % 3 == 0)
            printf("  -------------------------\n");
        for (int j = 0; j < sudoku->N; j++) {
            if (j == 0)
                printf("%d ", i);
            if (j % 3 == 0)
                printf("| %d ", sudoku->grid[i][j]);
            else if (j == 8)
                printf("%d |", sudoku->grid[i][j]);
            else
                printf("%d ", sudoku->grid[i][j]);
        }
        printf("\n");
    }
    printf("  -------------------------\n");
}