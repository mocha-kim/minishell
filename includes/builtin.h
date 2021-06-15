#ifndef BUILTIN_H
# define BUILTIN_H

# include "data.h"
# include "../libft/libft.h"
# include "env.h"
# include <sys/errno.h>
# include <string.h>
# include <stdio.h>
# include "error.h"

void		ft_echo(t_command *cmd);
int			ft_cd(t_command *cmd);
void		ft_pwd(void);
void		ft_exit(t_command *cmd);
int			builtin_execute(t_command cmd);
int			builtin(t_command cmd);
void		set_fork_builtin(t_command cmd);
void		ft_unset(t_command cmd);
int			ft_env(void);
void		ft_export(t_command *cmd);


#endif