#include "../Generator/Filling.h"
#include <stdbool.h>

bool FindUnassignedLocation(Sudoku *sudoku, int row, int col);
bool SolveSudoku(Sudoku *sudoku, int row, int col, int num);
bool checkBounds(int row, int col, int num);