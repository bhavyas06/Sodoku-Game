#include "Generator.h"

int unUsedInBox(Sudoku* sudoku, int rowStart, int colStart, int num);
int unUsedInRow(Sudoku* sudoku, int i, int num);
int unUsedInCol(Sudoku* sudoku, int j, int num);
int CheckIfSafe(Sudoku* sudoku, int i, int j, int num);