#ifndef ERROR_H
# define ERROR_H

#define ERR_QUOTE 0
#define ERR_SEMICOLONE 1
#define ERR_SEMICOLONE2 2
#define ERR_PIPE 3
#define ERR_PIPE2 4
#define EXIT_CODE 127

#include <unistd.h>

/*
** error.c
*/

int		print_syntax_error(int errno);

#endif