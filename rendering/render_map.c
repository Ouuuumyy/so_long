#include "../so_long.h"

void *create_window(t_map *g_map, void *mlx)
{
    int w_wid;
    int w_hei;
    void *window;

    w_wid = g_map->cols * 32;
    w_hei = g_map->rows * 32;
    if(!mlx)
        exit_error("Error: mlx init failed\n");
    window = mlx_new_window(mlx, w_wid, w_hei, "so long");
    if(!window)
        exit_error("Error: window init failed\n");
    return window;
}

void *load_texture(void *mlx, char *filename)
{
    void *img;
    int img_width;
    int img_height;

    img = mlx_xpm_file_to_image(mlx, filename, &img_width, &img_height);
    if (!img)
        exit_error("Error: Could not load texture\n");
    return img;
}

void load_sprites(void *mlx, t_img *img)
{
    img->wall = load_texture(mlx, "assets/wall.xpm");
    img->player = load_texture(mlx, "assets/player.xpm");  
    img->floor = load_texture(mlx, "assets/floor.xpm"); 
    img->exit = load_texture(mlx, "assets/exit.xpm");
    img->collect = load_texture(mlx, "assets/collect.xpm");
}

void render_map(void *mlx, void *window, t_map *g_map, t_img *img)
{
    int row;
    int col;

    row = 0;
    while (row < g_map->rows)
    {
        col = 0;
        while (col < g_map->cols)
        {
            if (g_map->map[row][col] == '1')  
                mlx_put_image_to_window(mlx, window, img->wall, col * 32, row * 32);
            else if (g_map->map[row][col] == 'P') 
                mlx_put_image_to_window(mlx, window, img->player, col * 32, row * 32);
            else if (g_map->map[row][col] == 'E') 
                mlx_put_image_to_window(mlx, window, img->exit, col * 32, row * 32);
            else if (g_map->map[row][col] == 'C') 
                mlx_put_image_to_window(mlx, window, img->collect, col * 32, row * 32);
            else 
                mlx_put_image_to_window(mlx, window, img->floor, col * 32, row * 32);
            col++;
        }
        row++;
    }
}
void game_init(t_game *game, t_map *map, t_img *img, void *mlx, void *win)
{
    game->mlx = mlx;
    game->map = map;
    game->img = img;
    game->win = win;
}

int main()
{
    void *mlx;
    void *window;
    t_map *g_map;
    t_img img;
    t_game game;

    g_map = map_parsing();
    mlx = mlx_init();
    window = create_window(g_map, mlx);
    game_init(&game, g_map, &img, mlx, window);
    load_sprites(mlx, &img);
    render_map(mlx, window, g_map, &img);
    mlx_key_hook(window, key_hook, &game);
    mlx_hook(window, 17, 0, close_game, &game);
    mlx_loop(mlx);
    free_map(g_map->map, g_map->rows);
    free_textures(&img, mlx);
    free(g_map);
    return 0;
}
