#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#include "../main.h"

int* init(int length)
{
    int *new_arr = calloc(length, sizeof(int));
    printf("Array of length %d initiated\n\n", length);
    return new_arr;
}

typedef struct 
{
    int* data;
} Employee;

Employee register_(int ID, int age, int year_of_birth, int salary, int years_of_exp)
{
    Employee emp;
    emp.data = init(5);
    emp.data[0] = ID;
    emp.data[1] = age;
    emp.data[2] = year_of_birth;
    emp.data[3] = salary;
    emp.data[4] = years_of_exp; 
    
    return emp;
}

void fire(Employee emp)
{
    free(emp.data);
}

void display(int *arr, int length)
{
    if(length == 0)
    {
        printf("[]\n\n");
        return;
    }

    printf("[\n\t");

    for(int i = 0; i < length; i++)
    {
        if(i % 10 == 9 || i == length - 1)
        {
            printf("%d", *(arr + i));
        }
        else if(i % 10 == 0 && i != 0)
        {
            printf("\n\t%d, ", *(arr + i));
        }
        else
        {
            printf("%d, ", *(arr + i));
        }
    }

    printf("\n]\n\n");
}

void insert(int **arr, int index, int *length, int value)
{
    if(index < 0 || index > *length)
    {
        errx(EXIT_FAILURE, "Cannot insert value, please select a valid index.");
    }

    int *resize = realloc(*arr, (*length + 1) * sizeof(int));

    for(int i = index; i < *length + 1; i++)
    {
        int temp = *(resize + i);
        *(resize + i) = value;
        value = temp;
    }

    printf("Added value %d at index %d\n\n", *(resize + index), index);

    *arr = resize;
    (*length)++;
}

void update(int *arr, int index, int length, int value)
{
    if(index < 0 || index >= length)
    {
        errx(EXIT_FAILURE, "Cannot update, please select a valid index.");
    }

    *(arr + index) = value;
    printf("Updated value %d at index %d\n\n", value, index);
}

void linear_search(int *arr, int length, int value)
{
    for(int i = 0; i < length; i++)
    {
        if(*(arr + i) == value)
        {
            printf("Found value %d at index %d\n\n", value, i);
            return;
        }
    }

    printf("Didnt found value %d\n\n", value);
}

void delete(int **arr, int *length, int value)
{
    int* deleted = init(*length - 1);
    int* start = deleted;
    int is_found = 0;
    int index = 0;

    for(int i = 0; i < *length; i++)
    {
        if(*(*arr + i) != value)
        {
            if(is_found == 0 && i == *length - 1)
            {
                errx(EXIT_FAILURE, "Cannot delete the value %d, as not found in the array\n", value);
            }

            *deleted = *(*arr + i);
            deleted++;
        }
        else
        {
            is_found = 1;
            index = i;
        }
    }

    free(*arr);
    printf("Value %d deleted at index %d\n\n", value, index);

    *arr = start;
    (*length)--;
}

void sum_array(int *arr, int length)
{
    int sum = 0;

    for(int i = 0; i < length; i++)
    {
        sum += *(arr + i);
    }

    printf("Sum of the array is %d\n\n", sum);
}

void print_emp(Employee emp)
{
    printf("ID number: %d\n", emp.data[0]);
    printf("Age: %d\n", emp.data[1]);
    printf("Year of birth: %d\n", emp.data[2]);
    printf("Salary: %d\n", emp.data[3]);
    printf("Years of experience: %d\n", emp.data[4]);
}

void run_array()
{
    printf("\n\n/// ARRAYS ///\n\n");

    int length = 0;
    int* arr = init(length);
    display(arr, length);

    for(int i = 0; i < 20; i++)
    {
        insert(&arr, i, &length, i);
    }

    display(arr, length);

    update(arr, 7, length, 34);
    display(arr, length);
    
    linear_search(arr, length, 34);
    linear_search(arr, length, 89);

    delete(&arr, &length, 34);
    display(arr, length);

    sum_array(arr, length);

    free(arr);

    Employee emp = register_(12637, 19, 2006, 1200, 2);
    print_emp(emp);
    fire(emp);
}