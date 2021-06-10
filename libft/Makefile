# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunhkim <sunhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 17:04:33 by sunhkim           #+#    #+#              #
#    Updated: 2021/06/10 20:52:13 by sunhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_toupper.c ft_tolower.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		  ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		  ft_count_strchr.c \
		  ft_atoi.c ft_itoa.c ft_utoa.c ft_utoa_base.c\
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		  ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c \
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_putchar.c ft_putstr.c ft_strnew.c ft_strdel.c \

SRCS_B	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		  ft_lstmap.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

all:	$(NAME)

bonus:	$(OBJS) $(OBJS_B)
	ar rcs $(NAME) $(OBJS) $(OBJS_B)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean:	clean
	rm -f $(NAME) $(BONUS)

re:		fclean all

.PHONY: all clean fclean re

