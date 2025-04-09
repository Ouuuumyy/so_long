#ifndef SO_LONG_H   
#define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"


typedef struct s_game
{
    void *mlx;
    void *win;
    char **map;
    int map_h;
    int map_w;
    void *wall;
    void *player;
    void *exit;
    void *floor;
    void *collect;
    int img_height;
    int img_width;

} t_game;

//map_size.c
int buffer_size(char *buffer);
int row_size(char *buffer);
int col_size(char *buffer);

//parsing_functions.c
void check_exit(char *buffer);
void check_start(char *buffer);
void check_collectible(char *buffer);
void check_walls(char **map, int row, int col);
void is_rectagular(char **map, int row);
char **map_parsing();



#endif