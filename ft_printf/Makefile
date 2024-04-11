NAME = libftprintf.a
LIBFT_NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft

SRCS = ft_printf.c ft_printf_tools.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/$(LIBFT_NAME)
	cp $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT_DIR)/$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re
