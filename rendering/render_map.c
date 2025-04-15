/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:47:17 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/15 15:51:32 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*create_window(t_map *g_map, void *mlx)
{
	int		w_wid;
	int		w_hei;
	void	*window;

	w_wid = g_map->cols * 64;
	w_hei = g_map->rows * 64;
	if (!mlx)
		exit_error("Error: mlx init failed\n");
	window = mlx_new_window(mlx, w_wid, w_hei, "so long");
	if (!window)
		exit_error("Error: window init failed\n");
	return (window);
}

void	*load_texture(void *mlx, char *filename)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, filename, &img_width, &img_height);
	if (!img)
		exit_error("Error: Could not load texture\n");
	return (img);
}

void	load_sprites(void *mlx, t_img *img)
{
	img->wall = load_texture(mlx, "textures/wall.xpm");
	img->player = load_texture(mlx, "textures/player.xpm");
	img->floor = load_texture(mlx, "textures/floor.xpm");
	img->exit = load_texture(mlx, "textures/exit.xpm");
	img->collect = load_texture(mlx, "textures/collect.xpm");
}

void	render_map(void *mlx, void *win, t_map *g_map, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < g_map->rows)
	{
		y = 0;
		while (y < g_map->cols)
		{
			if (g_map->map[x][y] == '1')
				mlx_put_image_to_window(mlx, win, img->wall, y * 64, x * 64);
			else if (g_map->map[x][y] == 'P')
				mlx_put_image_to_window(mlx, win, img->player, y * 64, x * 64);
			else if (g_map->map[x][y] == 'E')
				mlx_put_image_to_window(mlx, win, img->exit, y * 64, x * 64);
			else if (g_map->map[x][y] == 'C')
				mlx_put_image_to_window(mlx, win, img->collect, y * 64, x * 64);
			else
				mlx_put_image_to_window(mlx, win, img->floor, y * 64, x * 64);
			y++;
		}
		x++;
	}
}
