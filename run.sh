gcc -o sudoku Sudoku.c Generator/Create.c Generator/Generator.c Generator/IsSafe.c Generator/Filling.c Solver/Solver.c  SeeSolution/SeeSolution.c main.c -lm
./sudoku
rm sudoku