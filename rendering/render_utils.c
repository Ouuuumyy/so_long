/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:54:03 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/13 17:54:04 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_textures(t_img *img, void *mlx)
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
