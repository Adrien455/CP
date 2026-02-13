#include "../main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <publib.h>

void menu()
{
    int choice;
    char *str = malloc(100);
    printf("Enter a string:\n");
    scanf("%s[^\n]", str);
    printf("\nSelect commmand:\n1. strlen()\n2. strcat()\n3. strcpy()\n4. strcmp()\n5. strrev()\n6. exit\n\n");

    while(choice != 6)
    {
        scanf(" %d", &choice);
        char *str2 = malloc(100);;

        switch(choice)
        {
            case 1:
                printf("Length of %s is %ld\n", str, strlen(str));
                break;

            case 2:
                printf("Enter a string:\n");
                scanf("%s[^\n]", str2);
                printf("Concatenated string = %s\n", strcat(str, str2));
                break;

            case 3:
                printf("Duplicated string = %s\n", strcpy(str2, str));
                break;

            case 4:
                printf("Enter a string:\n");
                scanf("%s[^\n]", str2);
                
                int i = strcmp(str, str2);

                if(i == 0)
                {
                    printf("%s == %s\n", str, str2);
                }
                else if(i > 0)
                {
                    printf("%s > %s\n", str, str2);
                }
                else
                {
                    printf("%s < %s\n", str, str2);
                }
                break;

            case 5:
                printf("Reversed string = %s\n", strrev(str));
                break;

            case 6:
                break;

            default:
                printf("Please select valid index\n");
                break;
        }

        free(str2);
    }

    free(str);
}

void contain()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter a string\n");
    char *input = malloc(4096);
    fgets(input, 4096, stdin);

    printf("Enter a pattern\n");
    char *pattern = malloc(4096);
    fgets(pattern, 4096, stdin);

    char *current_i = input;
    char *position = input;

    char *current_p = pattern;
    int count = 0;

    while(*current_i != '\n')
    {
        if(*current_p == '\n')
        {
            count++;
            current_p = pattern;
            current_i = position + 1;
        }

        if(*current_i == *current_p)
        {
            if(current_p == pattern)
            {
                position = current_i;
            }

            current_p++;
        }
        else if(current_p != pattern)
        {
            current_p = pattern;
            current_i = position;
        }

        current_i++;
    }

    if(*current_p == '\n')
    {
        count++;
    }
        
    printf("The pattern occured %d time(s) in the given string\n", count);
    free(pattern);
    free(input);
}

void run_string()
{
    printf("\n\n/// STRING ///\n\n");
    menu();
    contain();
}