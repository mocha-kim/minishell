NAME = minishell
CFLAGS = -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)
SRCS =

all: $(NAME)

$(NAME): $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
