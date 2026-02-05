#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

int maximum(int a, int b, int c)
{
    if(b > a)
    {
        if(b > c)
        {
            return b;
        }
        else
        {
            return c;
        } 
    }
    else if(c > a)
    {
        return c;
    }
    else
    {
        return a;
    }

}

void check_vowel(char c)
{
    int lc = tolower(c);
    
    switch(c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            printf("%c is a vowel.\n", lc);
            break;

        default:
            printf("%c is a consonant.\n", lc);
            break;
    }
}

void check_number(int i)
{
    switch(i)
    {
        case 0:
            printf("%d is 0.\n", i);
            break;

        default:
            if(i < 0)
            {
                printf("%d is negative.\n", i);
            }
            else
            {
                printf("%d is positive.\n", i);
            }

            break;
    }
}

void run_cond()
{
    printf("\n\n/// CONDITIONAL STATEMENTS ///\n\n");

    srand(time(NULL));
    int a = rand() % 100;
    int b = rand() % 100;
    int c = rand() % 100;

    int max = maximum(a, b, c);

    printf("Maximum between (%d, %d, %d) is %d\n", a, b, c, max);

    char c1 = 'a';
    char c2 = 'b';

    check_vowel(c1);
    check_vowel(c2);

    int i1 = -7;
    int i2 = 0;
    int i3 = 9;

    check_number(i1);
    check_number(i2);
    check_number(i3);
}