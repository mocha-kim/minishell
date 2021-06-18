#ifndef ERROR_H
# define ERROR_H

#define ERR_QUOTE 0
#define ERR_SEMICOLONE 1
#define ERR_SEMICOLONE2 2
#define ERR_PIPE 3
#define ERR_PIPE2 4
#define ERR_NEWLINE 5
#define ERR_LAB 6
#define ERR_RAB 7
#define ERR_RAB2 8
#define ERR_MALLOC 0

# define EXIT_CODE 127

# define STD_IN 0
# define STD_OUT 1
# define STD_ERR 2

# include "../libft/libft.h"
# include  "data.h"
# include <errno.h>
# include <string.h>

/*
** error.c
*/

int		print_syntax_error(int errn);
int		print_memory_error(int errn);
int		print_exit_error(char *str, int code);
void	error_export(char *str);
void	execute_error(char *cmd);

/*
** error2.c
*/

void	print_cd_error(char *str);

#endif