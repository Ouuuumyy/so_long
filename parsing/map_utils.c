/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:47:16 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/14 20:41:30 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	buffer_size(char *buffer)
{
	int	size;

	size = 0;
	while (buffer[size] != '\0')
	{
		size++;
	}
	return (size);
}

int	row_size(char *buffer)
{
	int	rows;
	int	i;

	rows = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n' && buffer[i + 1] && buffer[i + 1] == '\n')
			break;
		if (buffer[i] == '\n')
			rows++;
		i++;
	}
	if (buffer[i - 1] != '\n')
		rows++;
	return (rows);
}

int	col_size(char *buffer)
{
	int	cols;

	cols = 0;
	while (buffer[cols] != '\n')
	{
		cols++;
	}
	return (cols);
}

int	count_collect(char *buffer)
{
	int	cols;
	int	i;

	i = 0;
	cols = 0;
	while (buffer[cols])
	{
		if (buffer[cols] == 'C')
			i++;
		cols++;
	}
	return (i);
}
