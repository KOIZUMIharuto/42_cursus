CC = cc
CFLAGS = -Wall -Wextra -Werror
SANITIZEFRAG = -fsanitize=address

NAME = push_swap

SRC_DIR = srcs
SRCS =\
counter.c\
create_stack.c\
free_stack__exit.c\
is_sorted.c\
join_node_and_list.c\
main.c\
push_swap.c\
push.c\
reverse_rotate.c\
rotate.c\
swap.c\

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(SANITIZEFRAG)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean 
	@rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus