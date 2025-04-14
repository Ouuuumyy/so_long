/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukadir <oukadir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:53:23 by oukadir           #+#    #+#             */
/*   Updated: 2025/04/14 20:27:01 by oukadir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "parsing/parsing.h"

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

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	*img;

}			t_game;

//libft
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *str);
int ft_strlen2(char **str);

//render_utils.c
void		free_textures(t_img *img, void *mlx);

int			key_hook(int keycode, t_game *game);
void		render_map(void *mlx, void *window, t_map *g_map, t_img *img);
int			close_game(t_game *game);

void		*create_window(t_map *g_map, void *mlx);
void		*load_texture(void *mlx, char *filename);
void		load_sprites(void *mlx, t_img *img);

void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif