/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:47:22 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/15 14:40:38 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_data(t_map *g_map, t_game *game)
{
	free(g_map->buff);
	free_map(g_map->map, g_map->rows);
	free(g_map);
	free(game);
}

void	check_chars(t_map *g_map, t_game *game)
{
	int	i;

	i = 0;
	while (g_map->buff[i])
	{
		if (g_map->buff[i] != 'P' && g_map->buff[i] != 'E'
			&& g_map->buff[i] != 'C' && g_map->buff[i] != '0'
			&& g_map->buff[i] != '1' && g_map->buff[i] != '\n')
		{
			free_data(g_map, game);
			exit_error("invalid characters in map\n");
		}
		i++;
	}
}

void	check_elements(t_map *g_map, t_game *game)
{
	int	i;
	int	e;
	int	c;
	int	p;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (g_map->buff[i])
	{
		if (g_map->buff[i] == 'E')
			e++;
		else if (g_map->buff[i] == 'P')
			p++;
		else if (g_map->buff[i] == 'C')
			c++;
		i++;
	}
	if (e != 1 || p != 1 || c < 1)
	{
		free_data(g_map, game);
		exit_error("1 exit, 1 start, at least 1 coin\n");
	}
}

void	check_walls(t_map *g_map, t_game *game)
{
	int	i;

	i = 0;
	while (g_map->map[0][i] != '\0' && g_map->map[g_map->rows - 1][i] != '\0')
	{
		if (g_map->map[0][i] != '1' || g_map->map[g_map->rows - 1][i] != '1')
		{
			free_data(g_map, game);
			exit_error("map must be surrounded by walls\n");
		}
		else
			i++;
	}
	i = 0;
	while (g_map->map[i])
	{
		if (g_map->map[i][0] != '1' || g_map->map[i][g_map->cols - 1] != '1')
		{
			free_data(g_map, game);
			exit_error("map must be surrounded by walls\n");
		}
		else
			i++;
	}
}

void	is_rectagular(t_map *g_map, t_game *game)
{
	int	col_size;
	int	col;
	int	i;

	col_size = 0;
	col = 0;
	i = 1;
	while (g_map->map[0][col_size] != '\0')
	{
		col_size++;
	}
	while (g_map->map[i])
	{
		while (g_map->map[i][col] != '\0')
			col++;
		if (col == col_size)
			i++;
		else
		{
			free_data(g_map, game);
			exit_error("map is not rectangular\n");
		}
		col = 0;
	}
}
