CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC_DIR = srcs
SRCS =\
check_argv__create_stack.c\
check_dup__set_index.c\
check_str__create_stack.c\
counter.c\
do_operation.c\
free_stack__exit.c\
init_stack.c\
is_sorted.c\
join_node_and_list.c\
main.c\
push_swap.c\
push.c\
reverse_rotate.c\
rotate.c\
swap.c\
under_six_sort.c

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean 
	@rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus