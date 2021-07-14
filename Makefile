# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 22:17:29 by ahnys             #+#    #+#              #
#    Updated: 2021/07/14 17:30:25 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
TFLAGS = -ltermcap
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

OBJS = $(SRCS:.c=.o)
SRCS = srcs/main.c \
		srcs/program.c \
		srcs/utils.c \
		srcs/utils2.c \
		srcs/utils3.c \
		srcs/termios.c \
		srcs/error/error.c \
		srcs/error/error2.c \
		srcs/parsing/parse_env.c \
		srcs/parsing/parse_first.c \
		srcs/parsing/parse_flags.c \
		srcs/parsing/parse_history.c \
		srcs/parsing/parse_input.c \
		srcs/parsing/parse_quote.c \
		srcs/parsing/parse_save.c \
		srcs/parsing/parse_second.c \
		srcs/parsing/parse_utils.c \
		srcs/env/env_parse.c \
		srcs/env/env_change.c \
		srcs/env/env_utils.c \
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
		srcs/command/find.c \
		srcs/command/redirect.c

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft bonus
	$(CC) $(CFLAGS) -o $(NAME) -L libft -lft $(OBJS) $(TFLAGS)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
