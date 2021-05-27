NAME = minishell
CFLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)
SRCS = gnl/get_next_line.c \
		srcs/main.c \
		srcs/parsing/parse.c

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) -L libft -lft $(OBJS)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
