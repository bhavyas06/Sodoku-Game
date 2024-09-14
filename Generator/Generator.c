#include "Generator.h"

int randomGenerator(int num) {
    int n = (int)floor((float)(rand() / (double)RAND_MAX*num+1));
    return n;
}

// removes digits from the grid based on difficulty mode
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