#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <math.h>

void sum()
{
    int left;
    int right;
    int res;

    printf("// SUM //\n\n");

    printf("Enter first number: ");
    scanf("%d", &left);

    printf("Enter second number: ");
    scanf("%d", &right);

    res = left + right;
    printf("The sum is:\n%d + %d = %d\n", left, right, res);
}


void circumference()
{
    printf("// CIRCLE CIRCUMFERENCE //\n\n");
    float radius;

    printf("Enter radius: ");
    scanf("%f", &radius);

    printf("The circumference is: %f\n", 3.14 * radius * radius);
}

void operations()
{
    printf("// OPERATIONS //\n\n");

    int left;
    int right;
    int res;

    printf("Enter first number: ");
    scanf("%d", &left);

    printf("Enter second number: ");
    scanf("%d", &right);

    char operator;

    printf("Press any operator between addition, substraction, multiplication and division.\n");
    scanf(" %c", &operator);

    switch(operator)
    {
        case '+':
            printf("%d\n", left + right);
            break;

        case '-':
            printf("%d\n", left - right);
            break;

        case '*':
            printf("%d\n", left * right);
            break;

        case '/':
            if(right == 0)
            {
                errx(EXIT_FAILURE, "Cannot divide by zero.\n");
            }

            printf("%d\n", left / right);
            break;

        default: errx(EXIT_FAILURE, "Wrong operator. Please select a valid one.\n");
    }
}

void equations()
{
    printf("// EQUATIONS //\n\n");

    printf("Select an equation to solve between these 4 by entering the correct index:\n");
    printf("1. V = a + bc\n");
    printf("2. S = ab + 1/2 * c * b^2\n");
    printf("3. T = 2 * a + √b + 9c\n");
    printf("4. H = sqrt(a^2 b^2)\n");

    int i;
    scanf(" %d", &i);

    int a;
    int b;
    int c;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    if(i != 4) 
    {
        printf("Enter c: ");
        scanf("%d", &c);
    }

    switch(i)
    {
        case 1:
            printf("%d\n", a + b * c);
            break;

        case 2:
            printf("%f\n", a * b + 0.5 * c * b * b);
            break;

        case 3:

            if(b < 0)
            {
                errx(EXIT_FAILURE, "Cannot square root negative values.\n");
            }

            printf("%f\n", 2 * a + sqrt(b) + 9 * c);
            break;

        case 4:

            printf("%f\n", sqrt(a * a + b * b));
            break;

        default: errx(EXIT_FAILURE, "Wrong index. Please select a valid one between 1 and 4.\n");
    }
}

int** mult_matrices(int **m1, int **m2)
{

}

void printm(int **m)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d", *(*(m + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}


int main(int argc, char** argv)
{
    // sum();
    // circumference();
    // operations();
    // equations();

    int **m1 = malloc(sizeof(int**));

    for(int i = 0; i < 3; i++)
    {
        *(m1 + i) = malloc(sizeof(int*));
        
        for(int j = 0; j < 3; j++)
        {
            *(*(m1 + i) + j) = j + 1;
        }
    }

    int **m2 = malloc(sizeof(int**));

    for(int i = 0; i < 3; i++)
    {
        *(m2 + i) = malloc(sizeof(int*));
        
        for(int j = 0; j < 3; j++)
        {
            *(*(m2 + i) + j) = j + 4;
        }
    }

    printm(m1);
    printm(m2);

    //int **mult = mult_matrices(m1, m2);
    //printm(mult);

    for(int i = 0; i < 3; i++)
    {
        free(*(m1 + i));
        free(*(m2 + i));
    }

    free(m1);
    free(m2);

    return 0;
}