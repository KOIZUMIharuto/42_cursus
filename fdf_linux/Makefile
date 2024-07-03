CC = cc
CFLAGS = -Wall -Wextra -Werror
SANITIZEFRAG = -fsanitize=address

BUFFER_SIZE = 10000

LIBFT_NAME = libft.a
NAME = fdf

LIBFT_DIR = libft

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

LDFLAGS = -L/usr/lib -L$(MLX_DIR)/obj
LIBS = -lXext -lX11 -lm

SRC_DIR = srcs

SRCS =\
draw_utils.c\
draw.c\
error.c\
free.c\
get_map.c\
key.c\
main.c\
mouse.c\
my_mlx.c\
rotate.c\
scale.c\
translate.c\
utils.c\
vector.c


SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT_DIR)/$(LIBFT_NAME) $(LDFLAGS) $(LIBS) -o $(NAME) $(MLXFLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -D BUFFER_SIZE=$(BUFFER_SIZE)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR) BUFFER_SIZE=$(BUFFER_SIZE)

$(MLX):
	@make -j4 -C $(MLX_DIR)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean 
	@rm -f $(NAME)
	@rm -f $(LIBFT_DIR)/$(LIBFT_NAME)
	@make -C $(MLX_DIR) clean
	@rm -f $(MLX)

re: fclean all

.PHONY: all clean fclean re bonus