#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <math.h>

void sum()
{
    int left;
    int right;
    int res;

    printf("\n\n// SUM //\n\n");

    printf("Enter first number: ");
    scanf("%d", &left);

    printf("Enter second number: ");
    scanf("%d", &right);

    res = left + right;
    printf("The sum is:\n%d + %d = %d\n", left, right, res);
}


void circumference()
{
    printf("\n\n// CIRCLE CIRCUMFERENCE //\n\n");
    float radius;

    printf("Enter radius: ");
    scanf("%f", &radius);

    printf("The circumference is: %f\n", 3.14 * radius * radius);
}

void operations()
{
    printf("\n\n// OPERATIONS //\n\n");

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