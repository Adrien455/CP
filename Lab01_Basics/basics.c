#include "../main.h"

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

    printf("The circumference is: %f\n", 3.14 * radius * 2);
    printf("The area is: %f\n", 3.14 * radius * radius);
}

void operations()
{
    printf("\n\n// OPERATIONS //\n\n");

    int left;
    int right;

    char operator;

    printf("Enter first number: \n");
    scanf("%d", &left);

    printf("Enter second number: \n");
    scanf("%d", &right);

    printf("Enter operator: \n");
    scanf(" %c", &operator);

    switch(operator)
    {
        case '+':
            printf("Result: %d\n", left + right);
            break;

        case '-':
            printf("Result: %d\n", left - right);
            break;

        case '*':
            printf("Result: %d\n", left * right);
            break;

        case '/':
            if(right == 0)
            {
                printf("Error: Cannot divide by zero.\n");
                break;
            }

            printf("Result: %d\n", left / right);
            break;

        default: 
            printf("Wrong operator. Please select a valid one.\n");
            break;              
    }
}

void run_basics()
{
    sum();
    circumference();
    operations();
}