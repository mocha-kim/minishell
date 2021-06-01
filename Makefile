NAME = minishell
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)
SRCS = gnl/get_next_line.c \
		srcs/main.c \
		srcs/error/error.c \
		srcs/parsing/parse.c \
		srcs/parsing/parse_gnl.c \
		srcs/parsing/parse_exception.c \
		srcs/parsing/parse_backslash.c \
		srcs/parsing/parse_quote.c \
		srcs/parsing/parse_history.c \
		srcs/builtin/builtin.c srcs/builtin/echo.c \
		srcs/command/execute.c \
		srcs/command/pipe.c
		

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft bonus
	$(CC) $(CFLAGS) -o $(NAME) -L libft -lft $(OBJS)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
