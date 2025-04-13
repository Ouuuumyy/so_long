#include "../so_long.h"

void exit_game(int collects, void *mlx, void *win)
{
    if (collects == 0)
    {
        printf("🎉 You won!\n");
        mlx_destroy_window(mlx, win);
        exit(0);
    }
}

void move_player(t_map *g_map, t_img *img, void *mlx, void *win, int dx, int dy)
{
    int p_row;
    int p_col;
    
 
    find_player(g_map->map, g_map->rows, &p_row, &p_col);
    if(p_row + dy >= 0 && p_row + dy < g_map->rows && p_col + dx >= 0
         && p_col + dx < g_map->cols)
    {
        if (g_map->map[p_row + dy][p_col + dx] == '0' 
            || g_map->map[p_row + dy][p_col + dx] == 'C'
            || g_map->map[p_row + dy][p_col + dx] == 'E')
        {
            if (g_map->map[p_row + dy][p_col + dx] == 'C')
                g_map->collects--;
            if (g_map->map[p_row + dy][p_col + dx] == 'E')
            {
                exit_game(g_map->collects, mlx, win);
            }
            g_map->map[p_row][p_col] = '0';
            g_map->map[p_row + dy][p_col + dx] = 'P';
            g_map->move_count++;
            printf("Moves: %d\n", g_map->move_count);
            render_map(mlx, win, g_map, img);
        }
    }
}

int key_hook(int keycode, t_game *game)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    if (keycode == 'w')
        move_player(game->map, game->img, game->mlx, game->win, 0, -1);
    if (keycode == 'a')
        move_player(game->map, game->img, game->mlx, game->win, -1, 0);
    if (keycode == 's')
        move_player(game->map, game->img, game->mlx, game->win, 0, 1);
    if (keycode == 'd')
        move_player(game->map, game->img, game->mlx, game->win, 1, 0);
    
    return 0;
}


int close_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    free_map(game->map->map, game->map->rows);
    free_textures(game->img, game->mlx);
    free(game->map);
    exit(0);
}
