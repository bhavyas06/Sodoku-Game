# Sudoku Game
This project provides a fully functional Sudoku game which contains a Sudoku Generator and a Sudoku Solver. The generator can create random Sudoku grids with different difficulty modes and the once the game starts the user can solve the game by providing the row number, column number and the digit. The solver efficiently solves the any grid and provides logic to determine whether the inputs or valid or not. The game also gives the user the option to quit the game or see the solution at any point. All the functions are designed with performance and scalability in mind, suitable for small applications or as part of a larger systems or projects.

## Features
-> <ins>Sudoku Generator</ins>: creates a 9X9 sudoku grid and fills it randomly with valid digits. <br/>
-> <ins>Sudoku Solver</ins>: takes inputs from the user and fill the grid accordingly. <br/>
-> <ins>See Solution</ins>: allows the user to see the fully filled grid. <br/>
-> <ins>Error Handling</ins>: verifies the edge test cases and then proceeds further. <br/>

## Installation
1. Clone the repository:
```bash
git clone https://github.com/bhavyas06/Sodoku-Game.git
```
2. Navigate to project directory.
3. Ensure the run.sh file has the execute permissions:
```bash
chmod +x run.sh
```

## Compilation and Running
To compile and execute the project, simply run the following command:
```bash
./run.sh
```
The run.sh script is responsible for compiling the necessary files and executing the program.

## Code Structure
-><ins>Generator</ins>: This folder includes various files which include all the logic required to generate a random 9X9 sudoku grid.
-><ins>Solver</ins>: This folder includes the file which includes the logic to check if the inputs provided by the user are valid or not and further solves the grid.
-><ins>SeeSolution</ins>: This folder contains the logic to solve the whole grid if the user proceeds to choose this option.
-><ins>main.c</ins>: Entry point for the command-line tool and also contains the menu for the project.
-><ins>Sudoku.h</ins>: Contains the struct for the sudoku grid.

## Working
![FolwChart](https://github.com/user-attachments/assets/fa802ecd-fef2-4108-b00d-3e9650740a6d)

