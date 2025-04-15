/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:47:06 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/15 15:57:21 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**allocate_map(int row, int col)
{
	char	**map;
	int		i;

	i = 0;
	map = (char **)malloc((row + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (i < row)
	{
		map[i] = malloc((col + 1) * sizeof(char));
		if (!map[i])
		{
			while (i >= 0)
			{
				free(map[i]);
				free(map);
				i--;
			}
			return (NULL);
		}
		i++;
	}
	return (map);
}

void	fill(t_map *m, t_game *game, int row, int col)
{
	int	i;

	i = 0;
	while (m->buff[i])
	{
		if (m->buff[i] == '\n' && (m->buff[i + 1] && (m->buff[i + 1] == '\n')))
			print_error(game, m);
		if (m->buff[i] == '\n')
		{
			m->map[row][col] = '\0';
			row++;
			i++;
			col = 0;
		}
		else if (col <= m->cols)
		{
			m->map[row][col] = m->buff[i];
			col++;
			i++;
		}
		else
			print_error(game, m);
	}
	m->map[row][col] = '\0';
	m->map[row + 1] = NULL;
}

void	fill_map(t_game *game, t_map *g_map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	fill(g_map, game, row, col);
}

char	**create_map(char *buffer, t_game *game, t_map *g_map)
{
	int	row;
	int	col;
	int	buff_size;

	row = row_size(buffer);
	col = col_size(buffer);
	buff_size = buffer_size(buffer);
	g_map->map = allocate_map(row, col);
	if (!g_map->map)
	{
		free_map(g_map->map, row);
		exit_error("memory allocation failed\n");
	}
	fill_map(game, g_map);
	return (g_map->map);
}

t_map	*map_parsing(char *file_name, t_game *game)
{
	char	*buffer;
	t_map	*g_map;

	buffer = read_file(file_name, game);
	g_map = malloc(sizeof(t_map));
	if (!g_map)
		exit_error("couldn't create map");
	g_map->cols = col_size(buffer);
	g_map->rows = row_size(buffer);
	g_map->collects = count_collect(buffer);
	g_map->move_count = 0;
	g_map->buff = buffer;
	g_map->map = create_map(buffer, game, g_map);
	check_chars(g_map, game);
	check_elements(g_map, game);
	g_map->rows = ft_strlen2(g_map->map);
	is_rectagular(g_map, game);
	check_walls(g_map, game);
	check_accessible_path(g_map, game);
	free(buffer);
	return (g_map);
}
