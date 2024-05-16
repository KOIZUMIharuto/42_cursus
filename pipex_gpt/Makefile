CC = cc
CFLAGS = -Wall -Wextra -Werror
# SANITIZEFRAG = -fsanitize=address

BUFFER_SIZE = 5

LIBFT_NAME = libft.a
MANDATORY_NAME = pipex
# BONUS_NAME

LIBFT_DIR = libft

SRC_DIR = srcs

SRCS =\
check_argv.c

MANDATORY_MAIN =\
pipex.c

# BONUS_MAIN =\
# checker.c

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRC:.c=.o)
MANDATORY_MAIN_SRC = $(addprefix $(SRC_DIR)/, $(MANDATORY_MAIN))
MANDATORY_MAIN_OBJ = $(MANDATORY_MAIN_SRC:.c=.o)
# BONUS_MAIN_SRC = $(addprefix $(SRC_DIR)/, $(BONUS_MAIN))
# BONUS_MAIN_OBJ = $(BONUS_MAIN_SRC:.c=.o)

all: $(MANDATORY_NAME)

$(MANDATORY_NAME): $(MANDATORY_MAIN_OBJ) $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME)
	@$(CC) $(CFLAGS) $(MANDATORY_MAIN_OBJ) $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(MANDATORY_NAME)

# bonus: $(BONUS_NAME)

# $(BONUS_NAME): $(BONUS_MAIN_OBJ) $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME)
# 	@$(CC) $(CFLAGS) $(BONUS_MAIN_OBJ) $(OBJ) $(LIBFT_DIR)/$(LIBFT_NAME) -o $(BONUS_NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -D BUFFER_SIZE=$(BUFFER_SIZE)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@make -C $(LIBFT_DIR) BUFFER_SIZE=$(BUFFER_SIZE)

clean:
	@rm -f $(OBJ)
	@rm -f $(MANDATORY_MAIN_OBJ)
	# @rm -f $(BONUS_MAIN_OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean 
	@rm -f $(MANDATORY_NAME)
	# @rm -f $(BONUS_NAME)
	@rm -f $(LIBFT_DIR)/$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re bonus