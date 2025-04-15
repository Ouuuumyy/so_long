/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:47:29 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/15 14:37:41 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	open_file(char *filename, t_game *game, t_file *file)
{
	int	fd;
	int	len;

	len = ft_strlen(filename);
	if (ft_strncmp(filename + (len - 4), ".ber", 4) != 0)
	{
		free(file);
		free(game);
		exit_error("Error: Map file must have .ber extention\n");
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(file);
		free(game);
		exit_error("Error: can not open file\n");
	}
	return (fd);
}

char	*allocate_buffer(void)
{
	char	*buffer;

	buffer = malloc(1024 * sizeof(char));
	if (!buffer)
		exit_error("Error: malloc failed\n");
	return (buffer);
}

char	*reallocate_buffer(char *buffer, int old_size, int new_size)
{
	char	*new_buffer;

	new_buffer = malloc(new_size);
	ft_memcpy(new_buffer, buffer, old_size);
	free(buffer);
	return (new_buffer);
}

void	check_read_bytes(int fd, char *buffer, int read_bytes)
{
	if (read_bytes < 0)
	{
		free(buffer);
		close(fd);
		exit_error("Error: Failed to read map file");
	}
}

char	*read_file(char *file_name, t_game *game)
{
	t_file	*file;
	char	*buf;

	file = init_file(file_name, game);
	while (file->read_bytes > 0)
	{
		file->total_bytes += file->read_bytes;
		if (file->total_bytes >= file->buffer_size - 1)
		{
			file->new_size = file->buffer_size * 2;
			file->buffer = reallocate_buffer(file->buffer, file->buffer_size,
					file->new_size);
			file->buffer_size = file->new_size;
		}
		file->read_bytes = read(file->fd, file->buffer + file->total_bytes,
				file->buffer_size - file->total_bytes - 1);
	}
	check_read_bytes(file->fd, file->buffer, file->read_bytes);
	file->buffer[file->total_bytes] = '\0';
	close(file->fd);
	buf = ft_strdup(file->buffer);
	free(file->buffer);
	free(file);
	return (buf);
}
