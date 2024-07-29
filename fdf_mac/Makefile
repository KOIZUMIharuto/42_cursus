CC = cc
CFLAGS = -Wall -Wextra -Werror
SANITIZEFRAG = -fsanitize=address

BUFFER_SIZE = 10000

LIBFT_NAME = libft.a
MANDATORY_NAME = fdf

LIBFT_DIR = libft

MINILIBX_DIR := ./minilibx_macos
MINILIBX := $(MINILIBX_DIR)/libmlx.a

INCLUDES := -I$(MINILIBX_DIR)
LDFLAGS := -L$(MINILIBX_DIR)
LIBS=-lm -lmlx

SRC_DIR = srcs

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



SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRC:.c=.o)

all: $(MANDATORY_NAME)

$(MANDATORY_NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME) $(MINILIBX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME) $(LDFLAGS) $(LIBS) -framework OpenGL -framework AppKit -o $(MANDATORY_NAME) $(MLXFLAGS) $(SANITIZEFRAG)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -D BUFFER_SIZE=$(BUFFER_SIZE)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR) BUFFER_SIZE=$(BUFFER_SIZE)

$(MINILIBX):
	@make -C $(MINILIBX_DIR)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean 
	@rm -f $(MANDATORY_NAME)
	@rm -f $(LIBFT_DIR)/$(LIBFT_NAME)
	@make -C $(MINILIBX_DIR) clean
	@rm -f $(MINILIBX)

re: fclean all

.PHONY: all clean fclean re bonus