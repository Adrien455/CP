#include "main.h"

#include <stdio.h>

int facto(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * facto(n - 1);
    }
}

void run_recursive()
{
    printf("\n\n/// RECURSION ///\n\n");
    
    for(int i = 0; i < 10; i++)
    {
        printf("!%d = %d\n", i, facto(i));
    }
}