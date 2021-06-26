#ifndef COMMAND_H
# define COMMAND_H

# include "../libft/libft.h"
# include "data.h"
# include "builtin.h"
# include "env.h"
# include <dirent.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>

/*
** execute.c
*/
void		execute(t_dlist *cmd);
void		execute_cmd(t_dlist *cmd);
void		path_execute(t_dlist *info);
// char		**make_argv(char **argv, char *arg);

void		set_pipe(t_dlist *info);
void		close_fd(t_dlist *info, int in, int out);
int			builtin_execute(t_dlist *cmd);
int			builtin(t_dlist *cmd);
void		set_fork_builtin(t_dlist *cmd);

/*
** find.c
*/
int			find_command(t_program *cmd);
int			find_simple_command(t_program *cmd, int *type);
void		parse_path(t_list **lst);

int			check_redirection(t_dlist *info);
void		renewal(t_program *cmd);
char		**new_args(t_program *cmd, char **tmp, int cnt);
#endif