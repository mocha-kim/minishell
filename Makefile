NAME = minishell
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

OBJS = $(SRCS:.c=.o)
SRCS = gnl/get_next_line.c \
		srcs/main.c \
		srcs/free.c \
		srcs/error/error.c \
		srcs/parsing/parse.c \
		srcs/parsing/parse_input.c \
		srcs/parsing/parse_backslash.c \
		srcs/parsing/parse_key.c \
		srcs/parsing/parse_quote.c \
		srcs/parsing/parse_history.c \
		srcs/parsing/parse_utils.c \
		srcs/parsing/env_parse.c \
		srcs/builtin/builtin.c srcs/builtin/echo.c \
		srcs/builtin/cd.c srcs/builtin/exit.c srcs/builtin/pwd.c \
		srcs/command/execute.c
		# srcs/command/pipe.c
		

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
