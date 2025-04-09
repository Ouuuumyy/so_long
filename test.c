#include "minilibx-linux/mlx.h"
#include <stdio.h>
int main(void)
{
    void    *mlx;
    void    *win;
    void    *img;
    int     img_width = 64;
    int     img_height = 64;
    
    // 1. Initialize MLX connection
    mlx = mlx_init();
    
    // 2. Create a window
    win = mlx_new_window(mlx, 800, 600, "My first image");
    
    // 3. Load an image (replace "test.xpm" with your file)
    img = mlx_xpm_file_to_image(mlx, "test.xpm", &img_width, &img_height);
    if (!img)
    {
        printf("Error: Could not load image\n");
        return (1);
    }
    
    // 4. Display the image at position (100,100)
    mlx_put_image_to_window(mlx, win, img, 100, 100);
    
    // 5. Keep the window open
    mlx_loop(mlx);
    return (0);
}