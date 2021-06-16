#ifndef ERROR_H
# define ERROR_H

#define ERR_QUOTE 0
#define ERR_SEMICOLONE 1
#define ERR_SEMICOLONE2 2
#define ERR_PIPE 3
#define ERR_PIPE2 4
#define ERR_NEWLINE 5
#define ERR_MALLOC 0

#define EXIT_CODE 127

#define STD_IN 0
#define STD_OUT 1
#define STD_ERR 2

#include "../libft/libft.h"
#include  "data.h"

/*
** error.c
*/

int		print_syntax_error(int errno);
int		print_memory_error(int errno);
int		print_exit_error(char *str, int code);
void	error_export(char *str);

#endif