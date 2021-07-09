/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:44:30 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/09 16:52:25 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <dirent.h>
# include <sys/stat.h>

# include "builtin.h"
# include "termios.h"
# include "parsing.h"


/*
** execute.c
*/
void		execute(t_dlist *cmd);
void		execute_cmd(t_dlist *cmd);
void		path_execute(t_dlist *info);
void		set_fd(t_dlist *info);

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
/*
** redirect.c
*/
int			check_redirection(t_dlist *info);
void		renewal(t_program *cmd);
char		**new_args(t_program *cmd, char **tmp, int cnt);
void		set_redirect(t_program *pro);
#endif
