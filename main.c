#include "SeeSolution/SeeSolution.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    Sudoku *sudoku;
    int N = 9;
    int diff = 0;
    
    int diff_mode;
    printf("Welcome to Sudoku!!\n\n");
    printf("Instructions:\nInput the row number, column number and the element you want to fill the particular cell with.\nYou can type '-1' to escape where you will be given the choice to either quit the game or see the solution.\n");

    printf("\nModes\n1. Easy\n2. Medium\n3. Hard\n");

    bool flag = true;
    while(flag == true) {
        printf("Choose your mode: ");
        scanf("%d", &diff_mode);
        printf("\n");
        switch(diff_mode) {
            case 1: diff = 20; flag = false; break;
            case 2: diff = 30; flag = false; break;
            case 3: diff = 40; flag = false; break;
            default: printf("\nInvalid Mode. Try Again.\n"); flag = true; break;
        }
    }
    
    sudoku = createSudoku(N, diff);
    fillValues(sudoku);
    printGrid(sudoku);

    int lives = 5;
    int op;

    while (lives != 0 && diff != 0) {
        int row, col, num;
        printf("\nEnter row number: ");
        scanf("%d", &row);

        if(row==-1) {
            escapeMenu(sudoku);
            break;
        }

        printf("Enter column number: ");
        scanf("%d", &col);

        if(col==-1) {
            escapeMenu(sudoku);
            break;
        }

        printf("Enter number: ");
        scanf("%d", &num);
        printf("\n");

        if(checkBounds(row, col, num) == false) {
            printf("\nInput Not Valid. Try Again.\n\n");
            printGrid(sudoku);
        }
        else {
            if(sudoku->grid[row][col]!=0) {
                printf("Cell not Empty. Try Again.\n\n");
                // system("clear");
                printGrid(sudoku);
            }

            else {
                if (SolveSudoku(sudoku, row, col, num)) {
                    printGrid(sudoku);
                    diff--;
                    printf("\nLives Remaining: %d", lives);
                    printf("\nCells Remaining: %d\n", diff);
                }

                else {
                    printf("\nWrong Input. Try Again\n");
                    lives--;
                    printf("Lives Left: %d\n", lives);
                    printf("Cells Remaining: %d\n", diff);
                    printGrid(sudoku);
                }
            }
        }
        
    }


    for (int i = 0; i < N; i++) {
        free(sudoku->grid[i]);
    }
    free(sudoku->grid);
    free(sudoku);

    return 0;
}