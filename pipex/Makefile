CC = cc
CFLAGS = -Wall -Wextra -Werror
SANITIZEFRAG = -fsanitize=address

BUFFER_SIZE = 5

LIBFT_NAME = libft.a
MANDATORY_NAME = pipex

LIBFT_DIR = libft

SRC_DIR = srcs

SRCS =\
free.c\
main.c\
pipex.c\
split.c


SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRC:.c=.o)

all: $(MANDATORY_NAME)

$(MANDATORY_NAME): $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(MANDATORY_NAME) $(SANITIZEFRAG)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -D BUFFER_SIZE=$(BUFFER_SIZE)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR) BUFFER_SIZE=$(BUFFER_SIZE)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean 
	@rm -f $(MANDATORY_NAME)
	@rm -f $(LIBFT_DIR)/$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re bonus