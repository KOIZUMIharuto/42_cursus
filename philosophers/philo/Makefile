NAME = philo

FSANITIZE = -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
PFRAGS = -pthread

INC = philo.h
SRCS = \
free.c\
init.c\
main.c\
mutex.c\
observer.c\
philo.c\
thread.c\
utils.c

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(PFRAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(INC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(PFRAGS) -I ./ -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -fdr $(OBJ_DIR)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re