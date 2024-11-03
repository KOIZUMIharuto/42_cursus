NAME = philo

FSANITIZE = -fsanitize=address
CFLAGS = -Wall -Wextra -Werror

INC = philo.h
SRCS = \
atoi.c\
error.c\
main.c\
thread.c

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I ./ $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(INC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I ./ -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re