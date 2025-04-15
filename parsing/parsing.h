/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:32:03 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/15 15:48:01 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*floor;
	void	*collect;
	int		img_hei;
	int		img_wid;

}			t_img;

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**map;
	char	*buff;
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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	*img;

}			t_game;

//helper_func.s
void		exit_error(char *error_message);
char		**copy_map(char **map, int rows, int cols);
void		fill_map(t_game *game, t_map *g_map);
t_file		*init_file(char *file_name, t_game *game);
void		free_map(char **map, int row_size);
void		print_error(t_game *game, t_map *map);

//map_utils.c
int			buffer_size(char *buffer);
int			row_size(char *buffer);
int			col_size(char *buffer);
int			count_collect(char *buffer);

//parsing_functions.c
void		check_walls(t_map *g_map, t_game *game);
void		check_chars(t_map *map, t_game *game);
void		check_elements(t_map *g_map, t_game *game);
void		is_rectagular(t_map *g_map, t_game *game);
void		free_data(t_map *g_map, t_game *game);

//map_parsing
t_map		*map_parsing(char *file_name, t_game *game);
char		**allocate_map(int row, int col);

//check_access
void		find_player(char **map, int rows, int *x, int *y);
void		check_accessible_path(t_map *g_map, t_game *game);

//read_file
char		*read_file(char *file_name, t_game *game);
int			open_file(char *filename, t_game *game, t_file *file);
char		*allocate_buffer(void);

#endif