#ifndef COMMAND_H
# define COMMAND_H

# include "../libft/libft.h"
# include "data.h"
# include "builtin.h"
# include "env.h"
# include <dirent.h>
# include <stdio.h>

void		execute(t_dlist *cmd, char *envp[]);
void		execute_cmd(t_dlist *cmd, char *envp[]);
void		set_pipe(t_dlist *info);
void		close_fd(t_dlist *info, int in, int out);
int			builtin_execute(t_dlist *cmd);
int			builtin(t_dlist *cmd);
void		set_fork_builtin(t_dlist *cmd);
int			find_command(t_program *cmd);
void		make_path(t_program *cmd, char *p1);
void		parse_path(t_list **lst);
void		path_execute(t_dlist *info, char *envp[]);

#endif