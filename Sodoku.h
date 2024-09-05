#ifndef _Sodoku_H_
#define _Soduku_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **grid;
    int N;          // size of grid
    int M;          // square root of size to check boxes
    int diff;       // decides not of empty cells
} Sudoku;

#endif /*_Sudoku_H_*/