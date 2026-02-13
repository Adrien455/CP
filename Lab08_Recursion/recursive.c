#include "../main.h"

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

int sum_digits(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return n % 10 + sum_digits(n / 10);
    }
}

int fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n -2);
    }
}

void run_recursive()
{
    printf("\n\n/// RECURSION ///\n\n");
    
    for(int i = 0; i < 10; i++)
    {
        printf("!%d = %d\n", i, facto(i));
        printf("fibo(%d) = %d\n", i, fibonacci(i));
    }

    int n;
    printf("Enter a number\n");
    scanf("%d", &n);
    printf("Sum of digits: %d\n", sum_digits(n));
}