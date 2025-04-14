/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:47:22 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/14 21:05:06 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_chars(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] != 'P' && buffer[i] != 'E' && buffer[i] != 'C'
			&& buffer[i] != '0' && buffer[i] != '1' && buffer[i] != '\n')
		{
			free(buffer);
			exit_error("Error: invalid characters in map\n");
		}
		i++;
	}
}

void	check_elements(char *buffer)
{
	int	i;
	int	e;
	int	c;
	int	p;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'E')
			e++;
		else if (buffer[i] == 'P')
			p++;
		else if (buffer[i] == 'C')
			c++;
		i++;
	}
	if (e != 1)
		exit_error("Error: you must have at exactly one exit point\n");
	if (p != 1)
		exit_error("Error: you must have at exactly one start point\n");
	if (c < 1)
		exit_error("Error: you must have at least one collectible point\n");
}

void	check_walls(char **map, int row, int col)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0' && map[row - 1][i] != '\0')
	{
		if (map[0][i] != '1' || map[row - 1][i] != '1')
		{
			perror("Error: map is not surrounded by walls\n");
			exit(1);
		}
		else
			i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][col - 1] != '1')
		{
			perror("Error: map is not surrounded by walls\n");
			exit(1);
		}
		else
			i++;
	}
}

void	is_rectagular(char **map, int row)
{
	int	col_size;
	int	col;
	int	i;
	(void)row;

	col_size = 0;
	col = 0;
	i = 1;
	while (map[0][col_size] != '\0')
	{
		col_size++;
	}
	while (map[i])
	{
		while (map[i][col] != '\0')
			col++;
		if (col == col_size)
			i++;
		else
			exit_error("Error: map is not rectangular\n");
		col = 0;
	}
}
