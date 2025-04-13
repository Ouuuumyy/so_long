#include "../so_long.h"

void check_chars(char *buffer)
{
    int i;

    i = 0;
    while(buffer[i])
    {
        if(buffer[i] != 'P'&& buffer[i] != 'E' && buffer[i] != 'C'
            && buffer[i] != '0' && buffer[i] != '1' && buffer[i] != '\n')
        {
            exit_error("Error: characters other than P, C, E, 1,0 are not allowed\n");
            free(buffer);
        }
        i++;
    }                                                                                                                                                                                                                   
}
char **allocate_map(int row, int col)
{
    char **map;
    int i;
                        
    i = 0;
    map = (char **)malloc(row * sizeof(char *));
    if(!map)
        return NULL;
    while(i < row)
    {
        map[i] = malloc((col + 1) * sizeof(char));
        if(!map[i])
        {
            while(i >= 0)
            {
                free(map[i]);
                free(map);
                i--;
            }
            return NULL;
        }
        i++;
    }
    return map;
}

void fill_map(char **map, char *buffer, int buff_size)
{
    int row;
    int col;
    int i;

    row = 0;
    col = 0;
    i = 0;
    while (i < buff_size)
    {
        if (buffer[i] == '\n')
        {
            map[row][col] = '\0';
            printf("\n");
            row++;
            i++;
            col = 0;
        }
        else
        {
            map[row][col] = buffer[i];
            printf("%c", map[row][col]);
            col++;
            i++;
        }
    }
    printf("\n");
}



char **create_map(char *buffer)
{
    char **map;
    int row;
    int col;
    int buff_size;

    row = row_size(buffer);
    col = col_size(buffer);
    buff_size = buffer_size(buffer);
    map = allocate_map(row, col);
    if(!map)
    {
        free_map(map, row);
        exit_error("Error: memory allocation failed\n");
    }
    fill_map(map, buffer, buff_size);
    return map;
}

t_map *map_parsing()
{
    char *buffer;
    t_map *g_map;

    buffer = read_file("./map.ber");
    g_map = malloc(sizeof(g_map));
    if(!g_map)
        exit_error("Error: couldn't create map");
    g_map->cols = col_size(buffer);
    g_map->rows = row_size(buffer);
    g_map->collects = count_collect(buffer);
    g_map->move_count = 0;
    printf("collect: %d\n",g_map->collects);
    g_map->map = create_map(buffer);
    check_chars(buffer);
    check_elements(buffer);
    is_rectagular(g_map->map, g_map->rows);
    check_walls(g_map->map, g_map->rows, g_map->cols);
    check_accessible_path(g_map->map, g_map->rows, g_map->cols);
    free(buffer);
    return g_map;
}

// int main()
// {
//     t_map *g_map;

//     g_map = map_parsing();
//     free_map(g_map->map, g_map->rows);
//     free(g_map);
//     return 0;
// }
