#include "../so_long.h"

void find_player(char **map, int rows, int *x, int *y)
{
    int i;
    int j;

    i = 0;

    while (i < rows)
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
            {
                *x = i;
                *y = j;
                return;
            }
            j++;
        }
        i++;
    }
}

void flood_fill(char **map, int x, int y)
{
    if (map[x][y] == '1' || map[x][y] == 'X')
        return;

    map[x][y] = 'X';

    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}

void validate_paths(char **map, int rows)
{
    int i;
    int j;

    i = 0;
    while(i < rows)
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'C' || map[i][j] == 'E')
                exit_error("Error: unreachable element on map\n");
            j++;
        }
        i++;
    }
}

void check_accessible_path(char **map, int rows, int cols)
{
    int px;
    int py;
    char **temp;
    
    temp = copy_map(map, rows, cols);
    if (!temp)
        exit_error("Error: Could not duplicate map");
    find_player(temp, rows, &px, &py);
    flood_fill(temp, px, py);
    validate_paths(temp, rows);
    free_map(temp, rows);
}


