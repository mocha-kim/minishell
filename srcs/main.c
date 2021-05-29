#include "../includes/minishell.h"

int		prompt()
{
	write(1, "minishell$ ", 11);
	return (1);
}

int		minishell(t_parse **info, t_list **history)
{
	char	*line;
	char	*processed_line;
	int		nread;
	t_list	*tmp;

	(void)info;

	while (1)
	{
		// prompt
		prompt();
		// gnl
		processed_line = ft_strnew(0);
		while ((nread = get_next_line(0, &line)) > 0)
		{
			process_backslash(&line, &processed_line);
			if (count_backslash(line) % 2 == ODD_NUM)
				continue;
			else
				break;
		}
		if (nread < 0)
			printf("bash: failed to allocate memory.\n");
		// history save
		ft_lstadd_back(history, ft_lstnew(ft_strdup(processed_line)));
		tmp = (*history);
		while (tmp != NULL)
		{
			printf(">> %p: %d / %s \n", tmp, (int)ft_strlen(tmp->content), tmp->content);
			tmp = tmp->next;
		}
		free(processed_line);
		// parsing
		// parse(processed_line, cmd_lst);
		// excute
		printf("execute\n");
	}
	ft_lstclear(history, free);
	return (0);
}

int		main(int argc, char *argv[], char *envp[])
{
	t_parse *info;
	t_list *history;

	(void)argc;
	(void)argv;
	(void)envp;
	history = NULL;

	// signal
	// minishell
	minishell(&info, &history);
	return (0);
}