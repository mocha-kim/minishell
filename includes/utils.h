#ifndef UTILS_H
# define UTILS_H

# include "data.h"
# include "error.h"
# include "../libft/libft.h"
# include <fcntl.h>

/*
** utils.c
*/

int						custom_putchar(int c);
int						skip_whitespace(const char *str, int *i);
void					free_info(t_dlist **programs);
char					*ft_strjoin_null(char const *s1, char const *s2);

#endif