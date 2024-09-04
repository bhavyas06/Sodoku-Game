#include "IsSafe.h"
#include <time.h>

void fillValues(Sudoku *sodoku);
void fillDiagnols(Sudoku *sodoku);
void fillBox(Sudoku *sodoku, int row, int col);
int fillRemaining(Sudoku *sudoku, int i, int j);