#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <string.h>

#include "../main.h"

int find(char buffer[], int n, char* pattern)
{
    int length = strlen(pattern);
    int index = 0;
    int i = 0;

    for(i; i < n; i++)
    {
        if(index == length)
        {
            return i - length;
        }
        
        if(buffer[i] == *(pattern + index))
        {
            index++;
        }
        else
        {
            index = 0;

            if(buffer[i] == *(pattern + index))
            {
                index++;
            }
        }
    }

    if(index == length)
    {
        return i - length;
    }

    return -1;
}

int aux(int fd_write, char buffer[], int n, char *pattern, char *word)
{
    int occurences = 0;
    int cursor = 0;
    int w_len = strlen(word);
    int p_len = strlen(pattern);

    while(1)
    {
        int i = find(buffer + cursor, n - cursor, pattern);

        if(i == -1)
        {
            break;
        }
        else
        {
            occurences += 1;
        }

        write(fd_write, buffer + cursor, i);
        write(fd_write, word, w_len);

        cursor += i + p_len;
    }

    write(fd_write, buffer + cursor, n - cursor);
    return occurences;
}

void replace(char* filename, char* pattern, char *word)
{
    FILE *file = fopen(filename, "r");
    int occurences = 0;

    if(!file)
    {
        errx(EXIT_FAILURE, "File doesn't exists");
    }
    
    FILE *new_file = fopen("temp.txt", "w");

    int fd_read = fileno(file);
    int fd_write = fileno(new_file);

    int size = 1024;
    char buffer[size];
    ssize_t n = read(fd_read, buffer, size);

    while(n > 0)
    {
        occurences += aux(fd_write, buffer, n, pattern, word);
        n = read(fd_read, buffer, size);
    }

    fclose(file);
    fclose(new_file);

    remove(filename);
    rename("temp.txt", filename);
    printf("The pattern occured %d times\n", occurences);
}

void run_file()
{
    printf("\n/// FILE ///\n");
    printf("The given pattern: 'hello' will be replaced by 'greetings' in stress_text.txt\n");

    char* filename = "stress_test.txt";
    replace(filename, "hello", "greetings");
    replace(filename, "hello", "greetings");  
}