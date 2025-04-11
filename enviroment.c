#include "so_long.h"

void load_sprites(t_game *game)
{
    int h;
    int w;

    h = 64;
    w = 64;
    game->wall = mlx_xpm_file_to_image(game->mlx, "src/wall.xpm", &w, &h);
    if (!game->wall) {
        printf("Failed to load WALL at path: assets/wall.xpm\n");
        exit(1);
    }
    game->player = mlx_xpm_file_to_image(game->mlx, "src/player.xpm", &w, &h);  
    game->floor = mlx_xpm_file_to_image(game->mlx, "src/floor.xpm", &w, &h); 
    game->exit = mlx_xpm_file_to_image(game->mlx, "src/exit.xpm", &w, &h);
    game->collect = mlx_xpm_file_to_image(game->mlx, "src/collect.xpm", &w, &h);
    if(!game->wall || !game->player || !game->floor
        || !game->exit || !game->collect)
    {
        perror("Error: could not load sprite");
        //destroy image
        exit(1);
    }
    game->img_height = h;
    game->img_width = w;
}

void render_map(t_game *game)
{
    int x;
    int y;
    void *sprite;

    y = 0;
    while(y < game->map_h)
    {
        x = 0;
        while(x < game->map_w)
        {
            if(game->map[y][x] == '1')
                sprite = game->wall;
            else if(game->map[y][x] == 'P')
                sprite = game->player;
            else if(game->map[y][x] == 'C')
                sprite = game->collect;
            else if(game->map[y][x] == 'E')
                sprite = game->exit;
            else if(game->map[y][x] == '0')
                sprite = game->floor;
          //  mlx_put_image_to_window(game->mlx, game->win,sprite, x * 64, y * 64);
          printf("%p\n", game->mlx);
          printf("%p\n", game->win);

            x++;
        }
        y++;
    }
}

void start_game(t_game *game)
{
    game->map = map_parsing();
    
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx,  game->map_w * 64, game->map_h * 64, "so_long");
    // load_sprites(game);
    // render_map(game);
    mlx_loop(game->mlx);

}
int main()
{
    t_game *game;

    start_game(game);
}