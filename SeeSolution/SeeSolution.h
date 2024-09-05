#include "../Solver/Solver.h"

bool UsedInRow(Sudoku *sudoku, int row, int num);
bool UsedInCol(Sudoku *sudoku, int row, int num);
bool UsedInBox(Sudoku *sudoku, int startRow, int startCol, int num);
bool isSafe(Sudoku *sudoku, int row, int col, int num);
bool FindLocation(Sudoku *sudoku, int *row, int *col);
bool FullSolution(Sudoku *sudoku);
void seeSolution(Sudoku *sudoku);
int escapeMenu(Sudoku *sudoku);