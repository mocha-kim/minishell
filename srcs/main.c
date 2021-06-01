#include "../includes/minishell.h"

int		prompt()
{
	write(1, "minishell$ ", 11);
	return (1);
}

/*
** return 0:success -1:failed 127:exit
*/
int		minishell(t_parse **info, t_list **history)
{
	char	*line;
	char	*processed_line;
	int		nread;
	t_parse	*tmp;

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
				continue ;
			else
				break ;
		}
		if (nread < 0)
			printf("bash: failed to allocate memory.\n");
		// history save
		ft_lstadd_front(history, ft_lstnew(ft_strdup(processed_line)));
		free(processed_line);
		// parsing
		if (!check_quote_close(processed_line))
		{
			print_syntax_error(ERR_QUOTE);
			continue ;
		}
		if (!parse(processed_line, info))
			continue ;
		tmp = *info;
		while (tmp && tmp->next)
		{
			printf("%s ", tmp->cmd.command);
			tmp = tmp->next;
		}
		// excute
		printf("execute\n");
		execute(*info);
	}
	ft_lstclear(history, free);
	return (0);
}

int		main(int argc, char *argv[], char *envp[])
{
	t_parse	*info;
	t_list	*history;

	(void)argc;
	(void)argv;
	(void)envp;
	info = NULL;
	history = NULL;

	// signal
	// minishell
	minishell(&info, &history);
	return (0);
}