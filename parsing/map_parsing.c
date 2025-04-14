/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:47:06 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/14 20:29:33 by oukadir          ###   ########.fr       */
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

void	fill_map(char **map, char *buffer, int buff_size)
{
	int	row;
	int	col;
	(void) buff_size;
	int	i;

	row = 0;
	col = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' && (buffer[i + 1] && (buffer[i + 1] == '\n')))
			break;
		if (buffer[i] == '\n')
		{
			map[row][col] = '\0';
			row++;
			i++;
			col = 0;
		}
		else
		{
			map[row][col] = buffer[i];
			col++;
			i++;
		}
	}
	map[row][col] = '\0';
	map[row + 1] = NULL;
}

char	**create_map(char *buffer)
{
	char	**map;
	int		row;
	int		col;
	int		buff_size;

	row = row_size(buffer);
	col = col_size(buffer);
	buff_size = buffer_size(buffer);

	map = allocate_map(row, col);
	if (!map)
	{
		free_map(map, row);
		exit_error("Error: memory allocation failed\n");
	}
	fill_map(map, buffer, buff_size);
	return (map);
}

t_map	*map_parsing(char *file_name)
{
	char	*buffer;
	t_map	*g_map;

	buffer = read_file(file_name);
	g_map = malloc(sizeof(t_map));
	if (!g_map)
		exit_error("Error: couldn't create map");
	g_map->cols = col_size(buffer);
	g_map->rows = row_size(buffer);
	g_map->collects = count_collect(buffer);
	g_map->move_count = 0;
	printf("collect: %d\n", g_map->collects);
	g_map->map = create_map(buffer);
	check_chars(buffer);
	check_elements(buffer);
	g_map->rows = ft_strlen2(g_map->map);
	is_rectagular(g_map->map, g_map->rows);
	check_walls(g_map->map, g_map->rows, g_map->cols);
	check_accessible_path(g_map->map, g_map->rows, g_map->cols);
	free(buffer);
	return (g_map);
}
