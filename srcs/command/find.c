/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoahn <yoahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:35:23 by yoahn             #+#    #+#             */
/*   Updated: 2021/07/07 19:35:25 by yoahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/command.h"

extern t_state	g_state;

static int	find_success(t_program *cmd, char *path, t_list **lst, DIR *dirp)
{
	char	*t1;
	char	*com;

	if (!(t1 = ft_strjoin(path, "/")))
		exit(1);
	if (!(com = ft_strjoin(t1, cmd->command)))
		exit(1);
	free(t1);
	free(cmd->args[0]);
	cmd->args[0] = com;
	closedir(dirp);
	ft_lstclear(lst, free);
	return (1);
}

int			find_command(t_program *cmd)
{
	DIR				*dirp;
	struct dirent	*r;
	t_list			*path;
	t_list			*tmp;

	parse_path(&path);
	tmp = path;
	cmd->command = ft_strdup(cmd->args[0]);
	while (path)
	{
		dirp = opendir((char*)path->content);
		while (dirp)
		{
			if (!(r = readdir(dirp)))
				break ;
			else if (!ft_strcmp(r->d_name, ".") || !ft_strcmp(r->d_name, ".."))
				continue ;
			else if (!ft_strcmp(cmd->command, r->d_name))
				return (find_success(cmd, path->content, &tmp, dirp));
		}
		closedir(dirp);
		path = path->next;
	}
	ft_lstclear(&tmp, free);
	return (0);
}

int			find_simple_command(t_program *cmd, int *type)
{
	struct stat	buf;

	if (stat(cmd->args[0], &buf) == 0)
	{
		if (S_ISDIR(buf.st_mode))
		{
			*type = IS_DIR;
			return (0);
		}
		else
			return (1);
	}
	else
	{
		*type = NSFD;
		return (0);
	}
}

void		parse_path(t_list **lst)
{
	char	**path;
	int		i;

	*lst = 0;
	path = ft_split(env_search("PATH"), ':');
	i = 0;
	while (path[i])
	{
		ft_lstadd_front(lst, ft_lstnew(path[i]));
		i++;
	}
	free(path);
}
