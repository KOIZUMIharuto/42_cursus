CC = cc
SANITIZEFRAG = -fsanitize=address
CFLAGS = -Wall -Wextra -Werror

BUFFER_SIZE = 5

LIBFT = libft.a
MANDATORY_NAME = pipex
BONUS_NAME = pipex_bonus
NAME = $(MANDATORY_NAME)

LIBFT_DIR = libft

INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = objs

INCS = pipex.h
SRCS =\
error.c\
exec.c\
free.c\
pipe.c\
split.c
MANDATORY_MAIN = main.c
BONUS_MAIN = main_bonus.c
MAIN = $(MANDATORY_MAIN)

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
MAIN_SRC = $(addprefix $(SRC_DIR)/, $(MAIN))
MAIN_OBJ = $(addprefix $(OBJ_DIR)/, $(MAIN:.c=.o))

ifeq ($(MAKECMDGOALS), bonus)
MAIN = $(BONUS_MAIN)
NAME = $(BONUS_NAME)
endif

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJ) $(MAIN_OBJ) $(LIBFT_DIR)/$(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(addprefix $(INC_DIR)/, $(INCS)) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $< -D BUFFER_SIZE=$(BUFFER_SIZE)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_DIR)/$(LIBFT):
	make -C $(LIBFT_DIR) BUFFER_SIZE=$(BUFFER_SIZE)

bonus: all

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean 
	@rm -f $(MANDATORY_NAME) $(BONUS_NAME) $(LIBFT_DIR)/$(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus