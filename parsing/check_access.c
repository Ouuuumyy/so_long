/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:46:47 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/15 15:52:56 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player(char **map, int rows, int *x, int *y)
{
	int	i;
	int	j;

	(void)rows;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	map[x][y] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	validate_paths(t_map *g_map, t_game *game, char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_map->rows)
	{
		j = 0;
		while (temp[i][j])
		{
			if (temp[i][j] == 'C' || temp[i][j] == 'E')
			{
				free_map(temp, g_map->rows);
				free_data(g_map, game);
				exit_error("unreachable element on map\n");
			}
			j++;
		}
		i++;
	}
}

void	check_accessible_path(t_map *g_map, t_game *game)
{
	int		px;
	int		py;
	char	**temp;

	temp = copy_map(g_map->map, g_map->rows, g_map->cols);
	if (!temp)
		exit_error("Could not duplicate map");
	find_player(temp, g_map->rows, &px, &py);
	flood_fill(temp, px, py);
	validate_paths(g_map, game, temp);
	free_map(temp, g_map->rows);
}
