#include "../so_long.h"

void check_exit(char *buffer)
{
    int i;
    int find;
    char *temp;

    i = 0,
    find = 0;
    temp = buffer;
    while (temp[i])
    {
        if (temp[i] == 'E')
        {
            find++;
            if (find > 1)
            {
                perror("Error: more than one exit");
                exit(1);
            }
        }
        i++;
    }
    if (find == 0)
    {
        perror("Error: no exit found");
        exit(1);
    }
}

void check_start(char *buffer)
{
    int i;
    int find;
    char *temp;

    i = 0,
    find = 0;
    temp = buffer;
    while (temp[i])
    {
        if (temp[i] == 'P')
        {
            find++;
            if (find > 1)
            {
                perror("Error: more than one Player start position");
                exit(1);
            }
        }
        i++;
    }
    if (find == 0)
    {
        perror("Error: no Player start position found");
        exit(1);
    }
}

void check_collectible(char *buffer)
{
    int i;
    int find;
    char *temp;

    i = 0,
    find = 0;
    temp = buffer;
    while (temp[i])
    {
        if (temp[i] == 'C')
            find++;
        i++;
    }
    if (find == 0)
    {
        perror("Error: no collectible found");
        exit(1);
    }
}

void check_walls(char **map, int row, int col)
{
    int i;

    i = 0;
    while(map[0][i] != '\0' && map[row - 1][i] != '\0')
    {
        if(map[0][i] != '1' || map[row - 1][i] != '1')
        {
            perror("Error: map is not surrounded by walls\n");
            exit(1);
        }
        else
            i++;
    }
    i = 0;
    while(i < row)
    {
        if(map[i][0] != '1' || map[i][col - 1] != '1')
        {
            perror("Error: map is not surrounded by walls\n");
            exit(1);
        }
        else
            i++;
    }
}

void is_rectagular(char **map, int row)
{
    int col_size;
    int col;
    int i;

    col_size = 0;
    col = 0;
    i = 1;
    while(map[0][col_size] != '\0')
    {
        col_size++;
    }
    while(i < row)
    {
        while(map[i][col] != '\0')
            col++;
        if(col == col_size)
            i++;
        else
        {
            perror("Error: map is not rectangular\n");
            exit(1);
        }
        col = 0;
    }
}
//check if the exit and collectibles 