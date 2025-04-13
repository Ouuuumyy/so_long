#include "../so_long.h"

void free_textures(t_img *img, void *mlx)
{
    if (img->wall)
        mlx_destroy_image(mlx, img->wall);
    if (img->player)
        mlx_destroy_image(mlx, img->player);
    if (img->floor)
        mlx_destroy_image(mlx, img->floor);
    if (img->exit)
        mlx_destroy_image(mlx, img->exit);
    if (img->collect)
        mlx_destroy_image(mlx, img->collect);
}
