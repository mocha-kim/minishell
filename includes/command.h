#ifndef COMMAND_H
# define COMMAND_H

# include "../libft/libft.h"
# include "data.h"
# include "builtin.h"
# include <stdio.h>

void		execute(t_dlist *cmd);
void		execute_cmd(t_dlist *cmd);
void		set_pipe(t_dlist *info);
void		close_fd(t_dlist *info, int in, int out);
int			builtin_execute(t_dlist *cmd);
int			builtin(t_dlist *cmd);
void		set_fork_builtin(t_dlist *cmd);

#endif