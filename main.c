#include "minilibx-linux/mlx.h"
#include "so_long.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

int	main(void)
{
    void *mlx = mlx_init();
    void *window = mlx_new_window(mlx, 800, 600, "test");
    void *img = mlx_new_image(mlx, 800, 600);

    int bpp, line_len, endian;
    char *addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);

    int x = 400;
    int y = 300;
    *(int*)(addr + (y * line_len + x * (bpp/8))) = 0x00FF0000;
    mlx_put_image_to_window(mlx, window, img, 0, 0);
    mlx_loop(mlx);
    return (0);
}
