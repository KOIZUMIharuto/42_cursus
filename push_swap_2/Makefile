CC = cc
CFLAGS = -Wall -Wextra -Werror
SANITIZEFRAG = -fsanitize=address

BUFFER_SIZE = 4

NAME = push_swap
LIBFT_NAME = libft.a

LIBFT_DIR = libft

SRC_DIR = srcs
SRCS =\
counter.c\
create_stack_utils.c\
create_stack.c\
free_stack__exit.c\
get_index.c\
is_sorted.c\
main.c\
manage_ope_list.c\
push_swap.c\
push.c\
r_rotate.c\
rotate.c\
swap.c\

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(NAME) $(SANITIZEFRAG)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -D BUFFER_SIZE=$(BUFFER_SIZE)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR) BUFFER_SIZE="$(BUFFER_SIZE)"

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean 
	@rm -f $(NAME)
	@rm -f $(LIBFT_DIR)/$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re bonus