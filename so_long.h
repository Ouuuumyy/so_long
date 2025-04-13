#ifndef SO_LONG_H   
#define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"

typedef struct s_map
{
    int rows;
    int cols;
    char **map;
    int collects;
    int move_count;
} t_map;


typedef struct s_img
{
    void *wall;
    void *player;
    void *exit;
    void *floor;
    void *collect;
    int img_hei;
    int img_wid;

} t_img;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_map   *map;
    t_img   *img;

} t_game;


//libft
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *c);
void	*ft_memcpy(void *dst, const void *src, size_t n);

//helper_func.s
void exit_error(char *error_message);

//render_utils.c
void free_textures(t_img *img, void *mlx);

//map_utils.c
int buffer_size(char *buffer);
int row_size(char *buffer);
int col_size(char *buffer);
char **copy_map(char **map, int rows, int cols);
void free_map(char **map, int row_size);
int count_collect(char *buffer);

//parsing_functions.c
void check_exit(char *buffer);
void check_start(char *buffer);
void check_collectible(char *buffer);
void check_walls(char **map, int row, int col);
void is_rectagular(char **map, int row);
t_map *map_parsing();

//map_parsing
char **allocate_map(int row, int col);

//check_access
void check_accessible_path(char **map, int rows, int cols);

//read_file
char *read_file(char *file_name);
void check_elements(char *buffer);

int key_hook(int keycode, t_game *game);
void render_map(void *mlx, void *window, t_map *g_map, t_img *img);
void find_player(char **map, int rows, int *x, int *y);
int close_game(t_game *game);


#endif