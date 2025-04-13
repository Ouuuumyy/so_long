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

int count_collect(char *buffer)
{
    int cols;
    int i;

    i = 0;
    cols = 0;
    while(buffer[cols])
    {
        if(buffer[cols] == 'C')
            i++;
        cols++;
    }
    return i;
}

char **copy_map(char **map, int rows, int cols)
{
    int i;
    char **new_map;

    i = 0;
    new_map = allocate_map(rows, cols);
    if (!new_map)
        return NULL;
    while(i < rows)
    {
        ft_memcpy(new_map[i], map[i], cols + 1);
        i++;
    }
    return new_map;
}

void free_map(char **map, int row_size)
{
    int i;
    i = 0;
    while(i < row_size)
    {
        free(map[i]);
        i++;
    }
    free(map);
}
