#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <math.h>
#include <time.h>
#include <string.h>

void first_n_sum(int n)
{
    if(n < 0)
    {
        printf("Negative number not relevant.\n");
    }

    int i = 0;
    int sum = 0;

    while(i <= n)
    {
        sum += i;
        i++;
    }

    printf("The sum of %d first naturals numbers is %d.\n", n, sum);

}

void is_amstrong(int n)
{
    int sum = 0;
    int temp = n;

    char* str = malloc(sizeof(char*));
    sprintf(str, "%d", n);
    int power = strlen(str);
    printf("power: %d\n", power);

    while(temp > 0)
    {
        int digit = temp % 10;
        int buff = digit;
        temp /= 10;
        
        for(int i = 0; i < power - 1; i++)
        {   
            buff = buff * digit;
        }

        sum += buff;
    }

    if(sum == n)
    {
        printf("The number %d is Amstrong\n", n);
    }
    else
    {
        printf("The number %d is not Amstrong\n", n);
    }

    free(str);
}

void reverse(int n)
{
    int reverse = 0;
    int i = 1;
    int temp = n;

    while(n > 0)
    {
        reverse *= i;
        int digit = n % 10;
        reverse += digit;
        n /= 10;
        i *= 10;
    }

    printf("n: %d, reverse: %d\n", temp, reverse);
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

void print_pattern_right(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

void print_pattern_left(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int k = n - 1; k > i; k--)
        {
            printf("  ");
        }

        for(int j = 0; j < i; j++)
        {
            printf("* ");
        }

        printf("\n");
    }
}

void print_num_pattern()
{
    for(int i = 1; i < 7; i++)
    {
        int k = 0;

        for(int j = 0; j < 6; j++)
        {
            k += i;
            printf("%d ", k);
        }

        printf("\n");
    }
}

int is_prime(int n)
{
    if(n == 2)
    {
        return 1;
    }

    if(n % 2 == 0)
    {
        return 0;
    }

    if(n == 3)
    {
        return 1;
    }

    for(int i = 3; i * i <= n; i+=2)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int is_perfect(int n)
{
    int sum = 1;

    if(n % 2 == 0)
    {
        sum += 2;
    }

    for(int i = 3; i < n; i++)
    {
        if(n % i == 0)
        {
            sum += i;
        }
    }

    if(sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void run_loop()
{
    printf("\n\n/// LOOPS ///\n\n");

    srand(time(NULL));
    int n = rand() % 100;

    first_n_sum(n);
    is_amstrong(n);
    reverse(n);
    printf("Fibonnaci sequence of n gave: %d\n", fibonacci(n % 10));
    print_pattern_right(n);
    print_pattern_left(n);

    printf("\n");
    print_num_pattern();
    printf("\n");

    printf("%d is %s\n\n", n, is_prime(n) == 1 ? "prime" : "not a prime number.");

    printf("%d is %s\n", n, is_perfect(n) == 1 ? "perfect" : "not a perfect number.");

}