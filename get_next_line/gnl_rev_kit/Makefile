NAME_M = gnl
NAME_B = gnl_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

BUFFER_SIZE = 42

MAIN_M = main.c
MAIN_B = main_bonus.c

SRCS_M = ../get_next_line.c ../get_next_line_utils.c

SRCS_B = ../get_next_line_bonus.c ../get_next_line_utils_bonus.c

$(NAME_M): $(SRCS_M) $(MAIN_M)
	cc $(CFLAGS) $(SRCS_M) $(MAIN_M) -o $(NAME_M) -D BUFFER_SIZE=$(BUFFER_SIZE)

$(NAME_B): $(SRCS_B) $(MAIN_B)
	cc $(CFLAGS) $(SRCS_B) $(MAIN_B) -o $(NAME_B) -D BUFFER_SIZE=$(BUFFER_SIZE)

all: $(NAME_M)

m: $(NAME_M)

b: $(NAME_B)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

fclean: 
	rm -f $(NAME_M) $(NAME_B)

rem: fclean m

reb: fclean b

.PHONY: all m b fclean re
