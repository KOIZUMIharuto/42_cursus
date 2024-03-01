CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC_DIR = srcs
SRCS =\
check_argv_create_stack.c\
check_str_create_stack.c\
free_stack_exit.c\
join_and_check.c\
main.c\
push.c\
reverse_rotate.c\
rotate.c\
swap.c

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