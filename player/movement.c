/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:54:50 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/14 21:04:15 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_moves(int moves)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(moves, 1);
	ft_putstr_fd("\n", 1);
}

void	exit_game(int collects, t_game *game)
{
	if (collects == 0)
	{
		ft_putstr_fd("🎉 You won!\n", 1);
		close_game(game);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	p_row;
	int	p_col;

	find_player(game->map->map, game->map->rows, &p_row, &p_col);
	if (p_row + dy >= 0 && p_row + dy < game->map->rows && p_col + dx >= 0
		&& p_col + dx < game->map->cols)
	{
		if (game->map->map[p_row + dy][p_col + dx] == '0'
			|| game->map->map[p_row + dy][p_col + dx] == 'C'
			|| game->map->map[p_row + dy][p_col + dx] == 'E')
		{
			if (game->map->map[p_row + dy][p_col + dx] == 'C')
				game->map->collects--;
			if (game->map->map[p_row + dy][p_col + dx] == 'E')
			{
				exit_game(game->map->collects, game);
				return ;
			}
			game->map->map[p_row][p_col] = '0';
			game->map->map[p_row + dy][p_col + dx] = 'P';
			game->map->move_count++;
			print_moves(game->map->move_count);
			render_map(game->mlx, game->win, game->map, game->img);
		}
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_game(game);
	if (keycode == 'w')
		move_player(game, 0, -1);
	if (keycode == 'a')
		move_player(game, -1, 0);
	if (keycode == 's')
		move_player(game, 0, 1);
	if (keycode == 'd')
		move_player(game, 1, 0);
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map->map, game->map->rows);
	free_textures(game->img, game->mlx);
	mlx_destroy_display(game->mlx);
	free(game->map);
	free(game->mlx);
	free(game);
	exit(0);
}
