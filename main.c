#include "SeeSolution/SeeSolution.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    Sudoku *sudoku;
    int N = 9;
    int diff = 0;
    
    int diff_mode;

    printf("Welcome to Sudoku!!\n\n");
    printf("Instructions:\nInput the row number, column number and the element you want to fill the particular cell with.\nYou can type '-1' to open menu where you will be given the choice to either quit the game or see the solution.\nNote: If you see the solution, you will lose the game.\n");

    printf("\nModes:\n1. Easy\n2. Medium\n3. Hard\n");

    // This menu decides the difficulty mode of the game
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
    
    // calculate starting time
    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

    sudoku = createSudoku(N, diff);
    fillValues(sudoku);
    printGrid(sudoku);


    // This menu takes the input from user and solves the game
    int lives = 5;
    int op;
    
    while (lives != 0 && diff != 0) {
        int row, col, num;
        printf("\nEnter row number: ");
        scanf("%d", &row);

        // if input == -1, means either the user wants to quit or see the solution. user also has the option to go back
        if(row==-1) {
            int option = escapeMenu(sudoku);
            if(option == 0)
                break;
            else {
                system("clear");
                printf("~Lives Remaining: %d", lives);
                printf("\n~Cells Remaining: %d\n", diff);
                printGrid(sudoku);
                continue;
            }
        }

        printf("Enter column number: ");
        scanf("%d", &col);

        if(col==-1) {
            int option = escapeMenu(sudoku);
            if(option == 0)
                break;
            else {
                system("clear");
                printf("~Lives Remaining: %d", lives);
                printf("\n~Cells Remaining: %d\n", diff);
                printGrid(sudoku);
                continue;
            }
        }

        printf("Enter number: ");
        scanf("%d", &num);
        printf("\n");

        // verifies that the input is within boundary
        if(checkBounds(row, col, num) == false) {
            system("clear");
            printf("\n=> Input Not Valid. Try Again.\n");
            printf("~Lives Remaining: %d", lives);
            printf("\n~Cells Remaining: %d\n\n", diff);
            printGrid(sudoku);
        }
        else {
            // checks whether a cell is empty or not
            if(sudoku->grid[row][col]!=0) {
                system("clear");        // clears the terminal, makes the ouptut clean
                printf("=> Cell not Empty. Try Again.\n");
                printf("~Lives Remaining: %d", lives);
                printf("\n~Cells Remaining: %d\n\n", diff);
                printGrid(sudoku);
            }

            else {
                if (SolveSudoku(sudoku, row, col, num)) {
                    system("clear");
                    diff--;
                    printf("\n=> Correct");
                    printf("\n~Lives Remaining: %d", lives);
                    printf("\n~Cells Remaining: %d\n\n", diff);
                    printGrid(sudoku);
                }

                else {
                    system("clear");
                    if(lives != 0)
                        printf("\n=> Wrong Input. Try Again\n");
                    lives--;
                    printf("~Lives Left: %d\n", lives);
                    printf("~Cells Remaining: %d\n\n", diff);
                    printGrid(sudoku);
                }
            }
        }
        
    }

    // calculating end time
    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    // freeing the memory
    for (int i = 0; i < N; i++) {
        free(sudoku->grid[i]);
    }
    free(sudoku->grid);
    free(sudoku);

    long long timeTaken = after_millis - before_millis;
    long long totalSec = timeTaken/1000;
    long long minutes = totalSec/60;
    long long seconds = totalSec%60;
    printf("\nTime taken: %llu mins %llu secs\n", minutes, seconds);

    if (lives == 0)
        printf("\nYOU LOST. GAME OVER!\n\n");
    else if(diff==0)
        printf("\nYOU WON! CONGRATULATIONS!\n\n");
    else    
        return 0;    

    return 0;
}