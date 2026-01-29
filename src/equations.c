#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <math.h>

void equations()
{
    printf("\n\n// EQUATIONS //\n\n");

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