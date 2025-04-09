#include "../so_long.h"

int buffer_size(char *buffer)
{
    int size;
    char *temp;

    size = 0;
    temp = buffer;
    while (buffer[size] != '\0')
    {
        size++;
    }
    return size;
}

int row_size(char *buffer)
{
    int rows;
    int i;

    rows = 0;
    i = 0;
    while(buffer[i])
    {
        if(buffer[i] == '\n')
            rows++;
        i++;
    }
    if(buffer[i - 1] != '\n')
        rows++;
    return rows;
}

int col_size(char *buffer)
{
    int cols;

    cols = 0;
    while(buffer[cols] != '\n')
    {
        cols++;
    }
    return cols;
}