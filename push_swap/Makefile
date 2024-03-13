CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC_DIR = srcs
SRCS =\
algorithm_sort.c\
check_argv__create_stack.c\
check_dup__set_index.c\
check_str__create_stack.c\
counter.c\
duplicate_stack.c\
find_min_max_num_index.c\
format_ope_list.c\
free_ope.c\
free_stack__exit.c\
init_stack.c\
is_sorted.c\
join_node_and_list.c\
main.c\
manage_ope_list.c\
push_half.c\
push_swap.c\
push.c\
reverse_rotate.c\
rotate.c\
sort_pa_ra.c\
swap.c\
under_six_sort_utils.c\
under_six_sort.c\
under_three_sort.c

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -fsanitize=address

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean 
	@rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus