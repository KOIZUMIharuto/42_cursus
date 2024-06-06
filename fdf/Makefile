CC = cc
CFLAGS = -Wall -Wextra -Werror
SANITIZEFRAG = -fsanitize=address

BUFFER_SIZE = 10000

LIBFT_NAME = libft.a
MLX_NAME = libmlx.a
MANDATORY_NAME = fdf

LIBFT_DIR = libft
MLX_DIR = minilibx_macos

SRC_DIR = srcs

SRCS =\
affine.c\
error.c\
free.c\
get_map_utils.c\
get_map.c\
main.c\
utils.c\
vector4.c


SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRC:.c=.o)

all: $(MANDATORY_NAME)

$(MANDATORY_NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME) $(MLX_DIR)/$(MLX_NAME)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME) $(MLX_DIR)/$(MLX_NAME) -o $(MANDATORY_NAME) 

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -D BUFFER_SIZE=$(BUFFER_SIZE)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR) BUFFER_SIZE=$(BUFFER_SIZE)

$(MLX_DIR)/$(MLX_NAME):
	@make -C $(MLX_DIR)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
# @make -C $(MLX_DIR) clean

fclean: clean 
	@rm -f $(MANDATORY_NAME)
	@rm -f $(LIBFT_DIR)/$(LIBFT_NAME)
	@make -C $(MLX_DIR) clean
	@rm -f $(MLX_DIR)/$(MLX_NAME)

re: fclean all

.PHONY: all clean fclean re bonus