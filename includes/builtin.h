#ifndef BUILTIN_H
# define BUILTIN_H

# include "data.h"
# include "../libft/libft.h"
# include <sys/errno.h>
# include <string.h>

void		ft_echo(t_command *cmd);
int			ft_cd(t_command *cmd);
void		ft_pwd(void);
int			builtin(t_command cmd);

#endif