#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#include "main.h"

int main(int argc, char** argv)
{
    int choice;
    printf("\n/// C PRACTICALS ///\n");

    while(choice != 12)
    {
        printf("\nPlease select option:\n");
        printf("1.  Lab01_Basics\n");
        printf("2.  Lab02_Equations\n");
        printf("3.  Lab03_Conditions\n");
        printf("4.  Lab04_Variables\n");
        printf("5.  Lab05_Loops\n");
        printf("6.  Lab06_Arrays\n");
        printf("7.  Lab07_Matrices\n");
        printf("8.  Lab08_Recursion\n");
        printf("9.  Lab09_Strings\n");
        printf("10. Lab10_Structures\n");
        printf("11. Lab11_Files\n");
        printf("12. Exit\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                run_basics();
                break;

            case 2:
                equations();
                break;

            case 3:
                run_cond();
                break;

            case 4:
                run_var_switch();
                break;

            case 5:
                run_loop();
                break;

            case 6:
                run_array();
                break;

            case 7:
                run_matrix();
                break;

            case 8:
                run_recursive();
                break;

            case 9:
                run_string();
                break;

            case 10:
                run_struct();
                break;

            case 11:
                run_file();
                break;

            case 12:
                break;

            default:
                printf("Please select valid choice\n");
                break;
        }

    }
}