CC = cc
CFLAGS = -Wall -Wextra -Werror
SANITIZEFRAG = -fsanitize=address

BUFFER_SIZE = 1000

LIBFT_NAME = libft.a
NAME = fdf

LIBFT_DIR = libft

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

LDFLAGS = -L/usr/lib -L$(MLX_DIR)/obj
LIBS = -lXext -lX11 -lm

INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = objs

INCLUDES = fdf.h
SRCS =\
culc_color.c\
draw_line.c\
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

INCLUDE = $(addprefix $(INC_DIR)/, $(INCLUDES))
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT_DIR)/$(LIBFT_NAME) $(LDFLAGS) $(LIBS) -o $(NAME) $(MLXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $< -D BUFFER_SIZE=$(BUFFER_SIZE)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_DIR)/$(LIBFT_NAME):
	make -C $(LIBFT_DIR) BUFFER_SIZE=$(BUFFER_SIZE)

$(MLX):
	make -C $(MLX_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean 
	@rm -f $(NAME)
	@rm -f $(LIBFT_DIR)/$(LIBFT_NAME)
	@make -C $(MLX_DIR) clean
	@rm -f $(MLX)

re: fclean all

.PHONY: all clean fclean re bonus