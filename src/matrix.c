#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <err.h>

#include "main.h"

int** init_matrix(int rows, int cols)
{
    int **m = malloc(rows * sizeof(int*));

    for(int i = 0; i < rows; i++)
    {
        *(m + i) = malloc(cols * sizeof(int));
        
        for(int j = 0; j < cols; j++)
        {
            *(*(m + i) + j) = rand() % 10;
        }
    }

    return m;
}

int** mult_matrices(int **m1, int r1, int c1, int **m2, int r2, int c2)
{
    if(c1 != r2)
    {
        errx(EXIT_FAILURE, "Cannot multiply matrices. The length of columns of the first one must be equal to the length of rows of the second one.\n");
    }

    int **mult = init_matrix(r1, c2);

    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            int sum = 0;

            for(int k = 0; k < c1; k++)
            {
                sum += *(*(m1 + i) + k) * *(*(m2 + k) + j);
            }

            *(*(mult + i) + j) = sum;
        }
    }

    return mult;
}

int** transpose_matrix(int **m, int r, int c)
{
    int **t = init_matrix(c, r);

    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < r; j++)
        {
            *(*(t + i) + j) = *(*(m + j) + i);
        }
    }

    return t;
}

void free_matrix(int **m, int rows)
{
    for(int i = 0; i < rows; i++)
    {
        free(*(m + i));
    }

    free(m);
}

void printm(int **m, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", *(*(m + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

void run_matrix()
{
    srand(time(NULL));
    printf("\n\n/// MATRICES MULT ///\n\n");

    int r1 = (rand() % (4 - 2 + 1)) + 2; // range 2 - 4
    int c1 = (rand() % (4 - 2 + 1)) + 2;

    int r2 = c1;    // hardcoded to let mult work 
    int c2 = (rand() % (4 - 2 + 1)) + 2;

    int **m1 = init_matrix(r1, c1);
    int **m2 = init_matrix(r2, c2);

    printf("/ M1 /\n");
    printm(m1, r1, c1);
    printf("/ M2 /\n");
    printm(m2, r2, c2);

    int **mult = mult_matrices(m1, r1, c1, m2, r2, c2);
    printf("/ MULT /\n");
    printm(mult, r1, c2);

    int **transposed = transpose_matrix(mult, r1, c2);
    printf("/ MULT TRANSPOSED MATRIX /\n");
    printm(transposed, c2, r1);

    free_matrix(m1, r1);
    free_matrix(m2, r2);
    free_matrix(mult, r1);
    free_matrix(transposed, c2);
}