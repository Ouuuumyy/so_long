/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:55:52 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/15 14:21:22 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_img	img;
	t_game	*game;
	char	*file_name;

	if (ac != 2)
		exit_error("Error: enter [program_name] [file_name]");
	file_name = av[1];
	game = malloc(sizeof(t_game));
	game->map = map_parsing(file_name, game);
	game->mlx = mlx_init();
	game->win = create_window(game->map, game->mlx);
	load_sprites(game->mlx, &img);
	game->img = &img;
	render_map(game->mlx, game->win, game->map, game->img);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}
