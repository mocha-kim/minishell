#ifndef BUILTIN_H
# define BUILTIN_H

# include "data.h"
# include "../libft/libft.h"

void		ft_echo(t_command *cmd);
int			builtin(t_command cmd);

#endif