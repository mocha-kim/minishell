#include "../../includes/command.h"

static int	find_success(t_program *cmd, char *path, t_list **lst, DIR *dirp)
{
	make_path(cmd, path);
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

void		make_path(t_program *cmd, char *p1)
{
	char	*t1;
	char	*com;

	if (!(t1 = ft_strjoin(p1, "/")))
		exit(1);
	if (!(com = ft_strjoin(t1, cmd->command)))
		exit(1);
	free(cmd->command);
	free(t1);
	cmd->command = com;
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

int			check_redirection(t_dlist *info)
{
	t_program	*cmd;
	t_dlist		*tmp;

	cmd = info->content;
	cmd->fd[0] = 0;
	cmd->fd[1] = 1;
	tmp = info;
	while (tmp->next && cmd->flag > 0 && cmd->flag < 4)
	{
		if (cmd->flag == REDIR_OUT)
			cmd->fd[1] = open(((t_program*)(tmp->next->content))->command,
			O_WRONLY | O_APPEND | O_CREAT, 0644);
		else if (cmd->flag == REDIR_APP)
			cmd->fd[1] = open(((t_program*)(tmp->next->content))->command,
			O_WRONLY | O_TRUNC | O_CREAT, 0644);
		else
			cmd->fd[0] = open(((t_program*)(tmp->next->content))->command,
			O_RDONLY);
		tmp = tmp->next;
	}
	return  (1);
}