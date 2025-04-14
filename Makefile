NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror# -g3  -fsanitize=address -g3

SRC = game.c\
	player/movement.c\
	rendering/render_map.c\
	rendering/render_utils.c\
	libft/memcpy.c\
	libft/string.c\
	libft/putnbr_fd.c

OBJ = $(SRC:.c=.o)

PARSING_DIR = parsing
PARSING_LIB = $(PARSING_DIR)/parsing.a

MLX = -L minilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz 

all: $(PARSING_LIB) $(NAME)

$(PARSING_LIB):
	$(MAKE) -C $(PARSING_DIR)

$(NAME): $(OBJ) $(PARSING_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(PARSING_LIB) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(PARSING_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(PARSING_DIR)

re: fclean all

.PHONY: all clean fclean re
