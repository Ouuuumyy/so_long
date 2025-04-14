/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:32:03 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/14 15:02:06 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**map;
	int		collects;
	int		move_count;
}			t_map;

typedef struct s_file
{
	int		fd;
	char	*buffer;
	size_t	read_bytes;
	size_t	total_bytes;
	size_t	buffer_size;
	size_t	new_size;
}			t_file;

//helper_func.s
void		exit_error(char *error_message);
char		**copy_map(char **map, int rows, int cols);
void		free_map(char **map, int row_size);
t_file		*init_file(char *file_name);

//map_utils.c
int			buffer_size(char *buffer);
int			row_size(char *buffer);
int			col_size(char *buffer);
int			count_collect(char *buffer);

//parsing_functions.c
void		check_walls(char **map, int row, int col);
void		check_chars(char *buffer);
void		check_elements(char *buffer);
void		is_rectagular(char **map, int row);

//map_parsing
t_map		*map_parsing(char *file_name);
char		**allocate_map(int row, int col);

//check_access
void		find_player(char **map, int rows, int *x, int *y);
void		check_accessible_path(char **map, int rows, int cols);

//read_file
char		*read_file(char *file_name);
int			open_file(char *filename);
char		*allocate_buffer(void);

#endif