#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <threads.h>
#include <stdbool.h>
#include <unistd.h>


#define SIZE 9
#define EMPTY_VALUE 0
int nums[9] = {1,2,3,4,5,6,7,8,9};
int solutions = 1;


// Setting the cursor
void setCursorPosition(int x, int y) {
    printf("\033[%d;%dH", x + 1, y + 1);
}

void sleep_ms(int milliseconds) {
    usleep(milliseconds * 1000);  // usleep expects microseconds
}

// Printing the sodoku
void printGrid(int grid[9][9]) {
    printf("-------------------------\n");
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(j==0)
                printf("| ");
            printf("%d ", grid[i][j]);
            if( (j+1)%3 == 0)
                printf("| ");
        }
        printf("\n");
        if( (i+1)%3 == 0) 
            printf("-------------------------\n");
    }
    printf("\n");
}

bool rows[SIZE][SIZE+1];
bool cols[SIZE][SIZE+1];
bool subgrids[SIZE][SIZE+1];

void initializeHashmaps(int grid[SIZE][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            rows[i][j] = false;
            cols[i][j] = false;
            subgrids[i][j] = false;
        }
    }

    for(int row=0; row<SIZE; row++) {
        for(int col=0; col<SIZE; col++) {
            if(grid[row][col] != 0) {
                int num = grid[row][col];
                rows[row][num] = true;
                cols[col][num] = true;
                subgrids[ (row/3)*3 + col/3][num] = true;
            }
        }
    }
}

bool isSafe(int row, int col, int num) {
    return !rows[row][num] && !cols[col][num] && !subgrids[ (row/3)*3 + col/3][num];
}

bool findEmptyLocation(int grid[SIZE][SIZE] ,int *row, int *col) {
    // for(*row=0; *row<SIZE; (*row)++) {
    //     for(*col=0; *col<SIZE; (*col)++) {
            if(grid[*row][*col] == 0)
                return true;
    //     }
    // }
    return false;
}

bool solveSodoku(int grid[SIZE][SIZE], int num, int row, int col) {
    // int row, col;
    if(!findEmptyLocation(grid, &row, &col)) {
        return true;
    }

    // for(int num=1; num<=9; num++) {
        if(isSafe(row, col, num)) {
            grid[row][col] = num;
            rows[row][num] = true;
            cols[num][col] = true;
            subgrids[ (row/3)*3 + col/3][num] = true;
            if(solveSodoku(grid, num, row, col)) {
                return true;
            }
            grid[row][col] = 0;
            grid[row][num] = false;
            grid[col][num] = false;
            subgrids[ (row/3)*3 + col/3][num] = false;
        }
    // }
    return false;
}


int main() {
    int grid[9][9] = {3,0,0,     8,0,1,   0,0,2,
                      2,0,1,     0,3,0,   6,0,4,
                      0,0,0,     2,0,4,   0,0,0,

                      8,0,9,     0,0,0,   1,0,6,
                      0,6,0,     0,0,0,   0,5,0,
                      7,0,2,     0,0,0,   4,0,9,
                      
                      0,0,0,     5,0,9,   0,0,0,
                      9,0,4,     0,8,0,   7,0,5,
                      6,0,0,     1,0,7,   0,0,3};

    // printGrid(grid);
    int moves = 0, errors = 0;

    printf("Welcome to Sodoku!!\n");
    printf("Instructions: \nType 'q' or 'Q' to quit.\nEnter the value, then row and then column to fill the grid.\n");
    printf("Would you like to play? (Y/N): ");
    char ch;
    scanf("%c", &ch);
    if(ch == 'n' || ch=='N')
        printf("You quit.\n");
    else
        printGrid(grid);

    int val, row, col;
    printf("Enter input: ");
    scanf("%d %d %d", &val, &row, &col);
    printf("\n");

    if(solveSodoku(grid, val, row, col))
        printGrid(grid);
    else {
        printf("Wrong Input. Try again.\n");
        errors++;
    }

    return 0;
}