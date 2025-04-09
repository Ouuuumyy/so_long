#include "../so_long.h"

char *read_map(char *file_name)
{
    int fd;
    int read_bytes;
    char *buffer;
    buffer = malloc(1024 * sizeof(char));
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file\n");
        exit(1);
    }
    read_bytes = read(fd, buffer, 1024);
    if (read_bytes <= 0)
    {
        perror("Error reading file\n");
        exit(1);
    }
    close(fd);
    return buffer;
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
    fill_map(map, buffer, buff_size);
    return map;
}

char **map_parsing()
{
    char *buffer;
    char **map;
    int rows;
    int cols;

    
    buffer = read_map("./map.ber");
    cols = col_size(buffer);
    rows = row_size(buffer);
    printf("row size: %d\n",rows);
    printf("col size: %d\n",cols);
    map = create_map(buffer);
    check_collectible(buffer);
    check_exit(buffer);
    check_start(buffer);
    is_rectagular(map, rows);
    check_walls(map, rows, cols);
    free(buffer);
    return map;
}

// int main()
// {
//     char **map;

//     map = map_parsing();
//     return 0;
// }
