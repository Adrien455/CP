#include "../main.h"

#include <stdio.h>

void switch_variables(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void switch_variables_in_place(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}


void run_var_switch()
{
    printf("\n\n/// SWITCH VAR ///\n\n");

    int a = 67;
    int b = 45;

    printf("a = %d\nb = %d\n\n", a, b);

    switch_variables(&a, &b);

    printf("a = %d\nb = %d\n\n", a, b);

    switch_variables_in_place(&a, &b);

    printf("a = %d\nb = %d\n\n", a, b);
}