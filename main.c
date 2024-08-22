#include <stdio.h>
#include <stdlib.h>

int main() {
    int grid[9][9] = {0,0,0,     0,0,0,   0,0,0,
                      0,0,0,     0,0,0,   0,0,0,
                      0,0,0,     0,0,0,   0,0,0,

                      0,0,0,     0,0,0,   0,0,0,
                      0,0,0,     0,0,0,   0,0,0,
                      0,0,0,     0,0,0,   0,0,0,
                      
                      0,0,0,     0,0,0,   0,0,0,
                      0,0,0,     0,0,0,   0,0,0,
                      0,0,0,     0,0,0,   0,0,0};

    // int **puzzle = (int**)malloc(sizeof(int)*9);

    // for(int i=0; i<9; i++) {
    //     puzzle[i] = (int *)malloc(sizeof(int)*9);
    //     for(int j=0; j<9; j++) {
    //         puzzle[i][j] = grid[i][j];
    //     }
    // }

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

    return 0;
}