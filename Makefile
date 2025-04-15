NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC = game.c\
	player/movement.c\
	rendering/render_map.c\
	rendering/render_utils.c\
	libft/memcpy.c\
	libft/string.c\
	libft/putnbr_fd.c\
	parsing/check_access.c \
	parsing/helper_funcs.c \
	parsing/map_parsing.c \
	parsing/map_utils.c \
	parsing/parsing_functions.c \
	parsing/read_file.c

OBJ = $(SRC:.c=.o)



MLX = -L minilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz 

all: $(NAME)



$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
