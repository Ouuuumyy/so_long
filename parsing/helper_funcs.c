/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:46:55 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/15 15:47:53 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_error(char *error_message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error_message, 2);
	exit(2);
}

char	**copy_map(char **map, int rows, int cols)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = allocate_map(rows, cols);
	if (!new_map)
		return (NULL);
	while (i < rows)
	{
		ft_memcpy(new_map[i], map[i], cols + 1);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	free_map(char **map, int row_size)
{
	int	i;

	i = 0;
	while (i < row_size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

t_file	*init_file(char *file_name, t_game *game)
{
	t_file	*file;

	file = malloc(sizeof(t_file));
	file->total_bytes = 0;
	file->buffer_size = 1024;
	file->fd = open_file(file_name, game, file);
	file->buffer = allocate_buffer();
	file->read_bytes = read(file->fd, file->buffer + file->total_bytes,
			file->buffer_size - file->total_bytes - 1);
	return (file);
}

void	print_error(t_game *game, t_map *map)
{
	free_data(map, game);
	exit_error("invalid map\n");
}
