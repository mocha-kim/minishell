NAME = minishell
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

OBJS = $(SRCS:.c=.o)
SRCS = srcs/main.c \
		srcs/utils.c \
		srcs/error/error.c \
		srcs/error/error2.c \
		srcs/parsing/parse.c \
		srcs/parsing/parse_env.c \
		srcs/parsing/parse_utils.c \
		srcs/parsing/parse_first.c \
		srcs/parsing/parse_flags.c \
		srcs/parsing/parse_second.c \
		srcs/parsing/parse_input.c \
		srcs/parsing/parse_quote.c \
		srcs/parsing/parse_history.c \
		srcs/env/env_parse.c \
		srcs/env/env_change.c \
		srcs/builtin/echo.c \
		srcs/builtin/cd.c \
		srcs/builtin/exit.c \
		srcs/builtin/pwd.c \
		srcs/builtin/env.c \
		srcs/builtin/unset.c \
		srcs/builtin/export.c \
		srcs/command/execute.c \
		srcs/command/pipe.c	\
		srcs/command/builtin.c \
		srcs/command/find.c

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
