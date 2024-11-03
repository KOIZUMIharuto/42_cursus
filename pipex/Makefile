CC = cc
SANITIZEFRAG = -fsanitize=address
CFLAGS = -Wall -Wextra -Werror

BUFFER_SIZE = 5

LIBFT = libft.a
NAME = pipex

LIBFT_DIR = libft

INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = objs

INCS = pipex.h
SRCS =\
error.c\
exec.c\
free.c\
main.c\
pipe.c\
split.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(addprefix $(INC_DIR)/, $(INCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $< -D BUFFER_SIZE=$(BUFFER_SIZE)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_DIR)/$(LIBFT):
	make -C $(LIBFT_DIR) BUFFER_SIZE=$(BUFFER_SIZE)

bonus: all

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean 
	rm -f $(NAME) $(LIBFT_DIR)/$(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus